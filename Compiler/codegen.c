/* codgen.c       Generate Assembly Code for x86         15 May 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and The University of Texas at Austin
    */

/* Starter file for CS 375 Code Generation assignment.           */
/* Written by Gordon S. Novak Jr.                  */

/* This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License (file gpl.text) for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "symtab.h"
#include "genasm.h"
#include "codegen.h"

void genc(TOKEN code);

/* Set DEBUGGEN to 1 for debug printouts of code generation */
#define DEBUGGEN 0

int nextlabel;    /* Next available label number */
int stkframesize;   /* total stack frame size */

int reg_map[FMAX + 1];
								  //6    7   8    9   10   11
int broptbl[] = { 0, 0, 0, 0, 0, 0, JE, JNE, JL, JLE, JGE, JG, 0, 0, 0 };

/* Top-level entry for code generator.
   pcode    = pointer to code:  (program foo (output) (progn ...))
   varsize  = size of local storage in bytes
   maxlabel = maximum label number used so far

Add this line to the end of your main program:
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
The generated code is printed out; use a text editor to extract it for
your .s file.
         */

void gencode(TOKEN pcode, int varsize, int maxlabel)
  {  TOKEN name, code;
     name = pcode->operands;
     code = name->link->link;
     nextlabel = maxlabel + 1;
     stkframesize = asmentry(name->stringval,varsize);
     genc(code);
     asmexit(name->stringval);
  }

/* Trivial version: always returns RBASE + 0 */
/* Get a register.   */
/* Need a type parameter or two versions for INTEGER or REAL */
int getreg(int kind)
  {
	int i;
	
    switch(kind)
	{
		case WORD:
			for(i = RBASE; i < RMAX; i++)
				if(reg_map[i] == 0)
				{
					reg_map[i] = 1;
					return i;
				}
			printf("ERROR: Out of usable registers\n");
		break;
		case FLOAT:
			for(i = FBASE; i < FMAX; i++)
				if(reg_map[i] == 0)
				{
					reg_map[i] = 1;
					return i;
				}
		break;
	}
	
     return RBASE;
  }

/* Trivial version */
/* Generate code for arithmetic expression, return a register number */
int genarith(TOKEN code)
{   
	int num, reg;
	float fnum;
	TOKEN lhs, rhs;
	int reg1, reg2, freg;
	int offs;
	
	if (DEBUGGEN)
	{ 
		printf("genarith\n");
		dbugprinttok(code);
	};
	
	//printf("tokentype: %i\n", code->tokentype);
	
	switch ( code->tokentype )
	{ 
		case NUMBERTOK:
		
			switch (code->datatype)
			{ 
				case INTEGER:
					num = code->intval;
					reg = getreg(WORD);
					if ( num >= MINIMMEDIATE && num <= MAXIMMEDIATE )
						asmimmed(MOVL, num, reg);
				break;
				case REAL:
					fnum = code->realval;
					reg = getreg(FLOAT);
					makeflit(fnum, nextlabel);
					asmldflit(MOVSD, nextlabel, reg);
					nextlabel++;
				break;
				case POINTER:
					num = 0;
					reg = getreg(WORD);
					asmimmed(MOVQ, num, reg);
				break;
			}
		break;
		
		case IDENTIFIERTOK:
		
			offs = code->symentry->offset - stkframesize; /* net offset of the var   */
			
			switch(code->datatype)
			{
				case INTEGER:
					reg = getreg(WORD);
					//printf("kind: %i\n", code->symtype->datatype->kind);
					if(code->symtype == NULL || code->symtype->kind == BASICTYPE)
						asmld(MOVL, offs, reg, code->stringval);
					else
						asmld(MOVQ, offs, reg, code->stringval);
				break;
				case REAL:
					reg = getreg(FLOAT);
					asmld(MOVSD, offs, reg, code->stringval);
				break;
			}
		break;
		
		case OPERATOR:
			if(code->whichval != FUNCALLOP && code->whichval != AREFOP)
			{
				lhs = code->operands;
				rhs = lhs->link;
				
				if(code->datatype == REAL)
				{
					reg1 = genarith( lhs );
					if(rhs != NULL)
					{
						if(rhs->tokentype == OPERATOR && rhs->whichval == FUNCALLOP)
						{
							
							asmsttemp(reg1);
							reg_map[reg1] = 0;
							
							reg2 = genarith( rhs );
							reg1 = getreg(FLOAT);
							asmldtemp(reg1);
						}
						else
						{
							reg2 = genarith( rhs );
						}
					}
				}
				else
				{
					reg1 = genarith( lhs );
					if(rhs != NULL)
						reg2 = genarith( rhs );
				}
			}
			switch(code->whichval)
			{
				case PLUSOP:
					if(code->datatype == INTEGER)
						asmrr(ADDL, reg2, reg1);
					else
						asmrr(ADDSD, reg2, reg1);
					reg = reg1;
				break;
				case MINUSOP:
					if(rhs != NULL)
					{
						if(code->datatype == INTEGER)
							asmrr(SUBL, reg2, reg1);
						else
							asmrr(SUBSD, reg2, reg1);
					}
					else
					{
						reg2 = getreg(FLOAT);
						asmfneg(reg1, reg2);
						reg_map[reg2] = 0;
					}
						
					reg = reg1;
				break;
				case TIMESOP:
					if(code->datatype == INTEGER)
						asmrr(IMULL, reg2, reg1);
					else
						asmrr(MULSD, reg2, reg1);
					reg = reg1;
				break;
				case DIVIDEOP:
					if(code->datatype == INTEGER)
						asmrr(DIVL, reg2, reg1);
					else
						asmrr(DIVSD, reg2, reg1);
					reg = reg1;
				break;
				case EQOP:
				case NEOP:
				case LTOP:
				case LEOP:
				case GEOP:
				case GTOP:
					asmrr(CMPL, reg2, reg1);
					reg = reg1;
				break;
				case FLOATOP:
					freg = getreg(FLOAT);
					asmfloat(reg1, freg);
					reg_map[reg1] = 0;
					reg = freg;
				break;
				case FIXOP:
					reg2 = getreg(WORD);
					asmfix(reg1, reg2);
					reg_map[freg] = 0;
					reg = reg2;
				break;
				case FUNCALLOP:
					reg = genfun(code);
				break;
				case AREFOP:
					reg = genaref(code, FBASE);
				break;
				
			}
		break;
		
		case STRINGTOK:
			makeblit(code->stringval, nextlabel);
			return nextlabel++;
		break;
	};
	
	return reg;
}


/* Generate code for a Statement from an intermediate-code form */
void genc(TOKEN code)
{  
	TOKEN tok, lhs, rhs;
	int reg, reg2, offs;
	int thenlbl, elselbl;
	SYMBOL sym;
	
	if (DEBUGGEN)
	{ 
		printf("genc\n");
		dbugprinttok(code);
	};
	if ( code->tokentype != OPERATOR )
	{ 
		printf("Bad code token");
		dbugprinttok(code);
	};
	
	clearreg();
	
	switch ( code->whichval )
	{ 
		case PROGNOP:
			tok = code->operands;
			while ( tok != NULL )
			{  
				genc(tok);
				tok = tok->link;
			};
		break;
		
		case ASSIGNOP:                
			lhs = code->operands;
			if(lhs->whichval == AREFOP)
			{
				
				rhs = lhs->link;
				reg = genarith(rhs);              /* generate rhs into a register */
				reg2 = genaref(lhs, reg);
				//asmst(MOVL, reg, offs, lhs->stringval);
			}
			else
			{
				sym = lhs->symentry;              /* assumes lhs is a simple var  */
				offs = sym->offset - stkframesize; /* net offset of the var   */
				rhs = lhs->link;
				reg = genarith(rhs);              /* generate rhs into a register */
				switch (code->datatype)            /* store value into lhs  */
				{ 
					case INTEGER:
						asmst(MOVL, reg, offs, lhs->stringval);
					break;
					case REAL:
						asmst(MOVSD, reg, offs, lhs->stringval);
					break;
					case STRINGTYPE:
						asmst(MOVL, reg, offs, lhs->stringval);
					break;
					case BOOLETYPE:
						asmst(MOVL, reg, offs, lhs->stringval);
					break;
					case POINTER:
						asmst(MOVQ, reg, offs, lhs->stringval);
					break;
				};
			}
			
		break;
		
		case GOTOOP:
			asmjump(JMP, code->operands->intval);
		break;
		
		case LABELOP:
			asmlabel(code->operands->intval);
		break;
		
		case IFOP:
			thenlbl = nextlabel++;
			elselbl = nextlabel++;
			
			genarith(code->operands); //genarith on condition
			
			asmjump(broptbl[code->operands->whichval], thenlbl); //branch to then
			
			if(((code->operands)->link)->link != NULL) //gen else
				genc(((code->operands)->link)->link);
				
			asmjump(JMP, elselbl);
			
			asmlabel(thenlbl);
			
			genc((code->operands)->link); //genthen
			
			asmlabel(elselbl);
		break;
		
		case FUNCALLOP:
			genfun(code);
		break;
	};
}



void clearreg()
{
	int i;
	for(i = 0; i < FMAX + 1; i++)
	{
		reg_map[i] = 0;
	}
}

int genfun(TOKEN code)
{
	int reg;
	//Load args
	//printf("here\n");
	
	
	if((code->operands)->link != NULL)
	{
		reg = genarith((code->operands)->link);
		
		if(((code->operands)->link)->tokentype == STRINGTOK)
		{
			asmlitarg(reg, EDI);
		}
		else if(((code->operands)->link)->tokentype == NUMBERTOK && ((code->operands)->link)->datatype == INTEGER)
		{
			asmrr(MOVL, reg, EDI);
			reg_map[reg] = 0;
			reg = EDI;
		}
		else if(((code->operands)->link)->tokentype == IDENTIFIERTOK)
		{
			asmrr(MOVL, reg, EDI);
			reg_map[reg] = 0;
			reg = EDI;
		}
		clearreg();
		reg_map[reg] = 1;
	}
	
	savereg();
	
	asmcall(code->operands->stringval);
	
	restorereg();
	
	
	if(code->datatype == REAL)
		return FBASE;
	else if(code->datatype == INTEGER)
		return RAX;
}


void savereg()
{
	int i;
	for(i = FBASE + 1; i < FMAX; i++)
		if(reg_map[i] == 1)
		{
			reg_map[i] = 0;
			asmsttemp(i);
		}
}

void restorereg()
{
	int i;
	for(i = FBASE + 1; i < FMAX; i++)
		if(reg_map[i] == 1)
		{
			asmldtemp(i);
		}
}

int genaref(TOKEN code, int storereg)
{
	int reg;
	
	if(code->operands->tokentype == OPERATOR)
	{
		if(code->link != NULL)
		{
			if(code->operands->operands->whichval == AREFOP)
			{
				asmstr(MOVL, storereg, 0, ECX, "^. ");
				return 0;
			}
				
			int ofs = ((code->operands))->operands->symentry->offset - stkframesize;
			int ofs2 = ((code->operands)->link)->intval;
			asmld(MOVQ, ofs, ECX, ((code->operands)->operands)->stringval);
			
			if(code->link != NULL && code->link->tokentype != IDENTIFIERTOK && code->link->datatype != POINTER)
				asmstr(MOVL, storereg, ofs2, ECX, "^. ");
			else
				asmstr(MOVQ, storereg, ofs2, ECX, "^. ");
		}
		else
		{
			int ofs = ((code->operands))->operands->symentry->offset - stkframesize;
			int ofs2 = ((code->operands)->link)->intval;
			asmld(MOVQ, ofs, ECX, ((code->operands)->operands)->stringval);
			asmstr(MOVL, storereg, ofs2, ECX, "^. ");
			return ECX;
		}
	}
	else if(code->operands->tokentype == IDENTIFIERTOK)
	{
		int arofs = code->operands->symentry->offset - stkframesize;
		reg = genarith(code->operands->link);
		asmop(CLTQ);
		asmstrr(MOVSD, storereg, arofs, ECX, "^. ");
	}
}






