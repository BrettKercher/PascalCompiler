%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/* Modified by Brett Kercher - February-May, 2014

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "instvars.c"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */

%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN

%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT

%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH


%%

  program    : header DOT                 { parseresult = $1; }
             ;
			 
  header	 : PROGRAM IDENTIFIER LPAREN argument RPAREN SEMICOLON  lblock 
										{ $$ = makeprogram($1, $2, $4, $7); }
			 ;

 block		 :  BEGINBEGIN statement endpart
                                       { $$ = makeprogn($1,cons($2, $3)); }
			 ;  	
		 
 lblock		 : LABEL labelspecs block			{ $$ = $3; }
			 | LABEL labelspecs vblock			{ $$ = $3; }
			 | LABEL labelspecs tblock			{ $$ = $3; }
			 | LABEL labelspecs cblock			{ $$ = $3; }
			 | cblock
			 ;  

 labelspecs	 : labelgroup SEMICOLON
			 ;	

 labelgroup	 : NUMBER COMMA labelgroup			{ instlabel($1); }
			 | NUMBER							{ instlabel($1); }
			 ;		
			 
 cblock		 : CONST constspecs block			{ $$ = $3; }
			 | CONST constspecs lblock			{ $$ = $3; }
			 | CONST constspecs vblock			{ $$ = $3; }
			 | tblock
			 ;  
 
 constspecs	 : constgroup SEMICOLON constspecs
			 | constgroup SEMICOLON
			 ;	

 constgroup	 : IDENTIFIER EQ factor 			{ instconst($1, $3); }
			 ;			 
			 
		
 tblock		 : TYPE typespecs block			{ $$ = $3; }
			 | TYPE typespecs vblock			{ $$ = $3; }
			 | vblock
			 ;
			 
 typespecs	 : typegroup SEMICOLON typespecs
			 | typegroup SEMICOLON
			 ;	

 typegroup	 : IDENTIFIER EQ type { insttype($1, $2, $3); }
			 ;			 
			 
		
 vblock		 : VAR varspecs block			{ $$ = $3; }
			 | block
			 ;  	

 varspecs	 : vargroup SEMICOLON varspecs
			 | vargroup SEMICOLON
			 ;	
			 
 vargroup	 : idlist COLON type { instvars($1, $3); }
			 ;	
			 
 type		 : simpletype
			 | POINT simpletype				{ $$ =  instpoint($1, $2); }
			 | ARRAY LBRACKET index RBRACKET OF type	{ $$ = instarray($3, $6); }
			// | FILE
			// | SET
			 | RECORD fieldlist END			{ $$ = instrec($1, $2); }
			 ;	
			 
 index		 : simpletype COMMA index		{ $$ = cons($1, $3); }
			 | simpletype
			 
 simpletype	 : IDENTIFIER 					{ $$ = findtype($1); }
			 | LPAREN idlist RPAREN			{ $$ = instenum($1, $2, $3); }
			 | factor DOTDOT factor			{ $$ = instdotdot($1, $2, $3); }
			 ;	
			 
 fieldlist	 : idlist COLON type SEMICOLON fieldlist	{ $$ = cons(instfields($1, $3), $5); }
			 | idlist COLON type						{ $$ = instfields($1, $3); }
			 
 idlist		 : IDENTIFIER COMMA idlist		{ $$ = cons($1, $3); }
			 | IDENTIFIER					{ $$ = cons($1, NULL); }		
			 ;			 

 argument	 : expr COMMA argument { $$ = makeprogn((TOKEN) talloc(), cons($1, $3)); }
			 | expr				{ $$ = makeprogn((TOKEN) talloc(), $1); }
			 ;  
			 
			 
  statement  :  BEGINBEGIN statement endpart			{ $$ = makeprogn($1,cons($2, $3)); }
			 |  IF expr THEN statement endif   			{ $$ = makeif($1, $2, $4, $5); }
			 |  FOR assignment TO expr DO statement		{ $$ = makefor(1, $1, $2, $3, $4, $5, $6); }
			 |  FOR assignment DOWNTO expr DO statement	{ $$ = makefor(-1, $1, $2, $3, $4, $5, $6); }
			 |  REPEAT statements UNTIL expr			{ $$ = makerepeat($1, makeprogn((TOKEN)talloc(), $2), $3, $4); }
			 |  WHILE expr DO statement					{ $$ = makewhile($1, $2, $3, $4); }
			 |  funcall
			 |  assignment
			 |  NUMBER COLON statement					{ $$ = dolabel($1, $2, $3); } 
			 |  GOTO NUMBER								{ $$ = dogoto($1, $2); }
             ;
     
 statements : statement endstates				{ $$ = cons($1, $2); }
	    | statement						
	    ;
	    
 endstates  : SEMICOLON statements				{ $$ = $2; }
	    ;
	    
             
 funcall	 : IDENTIFIER LPAREN funargs RPAREN		{ $$ = makefuncall($2, $1, $3); }
		 ; 
		 
 funargs	 : expr COMMA argument 		{ $$ = cons($1, $3); }
			 | expr				{ $$ = $1; }
			 ; 
			 
  endpart    :  SEMICOLON statement endpart    { $$ = cons($2, $3); }
             |  END                            { $$ = NULL; }
             ;
			 
  endif      :  ELSE statement                 { $$ = $2; }
             |  /* empty */                    { $$ = NULL; }
             ;
			 
  assignment :  variable ASSIGN expr         { $$ = binop($2, $1, $3); }
             ;
	
  expr       :  simexpr EQ simexpr            { $$ = binop($2, $1, $3); }
			 |  simexpr LT simexpr            { $$ = binop($2, $1, $3); }
			 |  simexpr GT simexpr            { $$ = binop($2, $1, $3); }
			 |  simexpr NE simexpr            { $$ = binop($2, $1, $3); }
			 |  simexpr LE simexpr            { $$ = binop($2, $1, $3); }
			 |  simexpr GE simexpr            { $$ = binop($2, $1, $3); }
			 |  simexpr IN simexpr            { $$ = binop($2, $1, $3); }
             |  simexpr 
             ;
	     
  simexpr    :  expr PLUS term                 { $$ = binop($2, $1, $3); }
			 |  expr MINUS term                { $$ = binop($2, $1, $3); }
             |  term  
			 
  term       :  term TIMES factor              { $$ = binop($2, $1, $3); }
             |  factor
             ;
			 
  factor     :  LPAREN expr RPAREN             { $$ = $2; }
             |  variable
             |  NUMBER
			 |	MINUS variable			{ $$ = unaryop($1, $2); }
             |  STRING
			 |	funcall
			 |  NIL						{ $$ = donil($1); }
             ;
			 
 variable	 : IDENTIFIER							{ $$ = findid($1); }
			 | variable DOT IDENTIFIER				{ $$ = arrayref($1, $2, $3, (TOKEN)talloc());}
			 | variable POINT						{ $$ = dopoint($1,$2); }
			 | variable LBRACKET exprlist RBRACKET	{ $$ = arrayref($1, $2, $3, $4);}
			 ;
		 
exprlist	 : expr COMMA exprlist
			 | expr
			 

%%

/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG       	 0             /* set bits here for debugging, 0 = off  */
#define DB_CONS      	 1             /* bit to trace cons */
#define DB_BINOP     	 2             /* bit to trace binop */
#define DB_MAKEIF    	 4             /* bit to trace makeif */
#define DB_MAKEPROGN 	 8             /* bit to trace makeprogn */
#define DB_PARSERES  	16             /* bit to trace parseresult */
#define DB_MAKEPROGRAM	32          /* bit to trace makeprogram */
#define DB_MAKEFOR   	64         	/* bit to trace makefor */
#define DB_MAKEFUNCALL	128
#define DB_INSTALLCONST 256
#define DB_UNARYOP		512

 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int labels[5] = {0,0,0,0,0};

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }
  
TOKEN donil(TOKEN niltok)
{
	niltok->tokentype = NUMBERTOK;
	niltok->datatype = POINTER;
	niltok->intval = 0;
	return niltok;
}  
  
TOKEN findid(TOKEN tok)
{
	SYMBOL toksym = searchst(tok->stringval);
	if(toksym != NULL)
	{
		//If its a constant, smash it into its number
		if(toksym->kind == CONSTSYM)
		{
			tok->tokentype = NUMBERTOK;
			tok->datatype = toksym->basicdt;
			
			switch(toksym->basicdt)
			{
			case REAL:
				tok->realval = toksym->constval.realnum;
			break;
			case INTEGER:
				tok->intval = toksym->constval.intnum;
			break;
			}
		}
		else //If it's not a constant, set up symbol table pointers
		{
			SYMBOL typ = toksym->datatype;
			tok->symentry = toksym;
			tok->symtype = typ;
			tok->datatype = typ->basicdt;
		}
	}
	
	return tok;
}

TOKEN makefloat(TOKEN tok)
{
	/*tok->datatype = REAL;
	
	if(tok->tokentype == NUMBERTOK)
	{
		tok->realval = (float)tok->intval;
		return tok;
	}*/
	
	TOKEN floattok = (TOKEN) talloc();
	floattok->tokentype = OPERATOR;
	floattok->whichval = FLOATOP;
	floattok->datatype = REAL;
	
	return unaryop(floattok, tok);
}

TOKEN makefix(TOKEN tok)
{
	/*
	tok->datatype = INTEGER;
	if(tok->tokentype == NUMBERTOK)
	{
		tok->intval = (int)tok->realval;
		return tok;
	}
	*/

	TOKEN inttok = (TOKEN) talloc();
	inttok->tokentype = OPERATOR;
	inttok->whichval = FIXOP;
	inttok->datatype = INTEGER;
	
	return unaryop(inttok, tok);
}

TOKEN unaryop(TOKEN op, TOKEN lhs)
{
	op->operands = lhs;          /* link operands to operator       */
	lhs->link = NULL;             /* terminate op list    */
	if (DEBUG & DB_UNARYOP)
	{ 
		printf("unaryop\n");
		dbugprinttok(op);
		dbugprinttok(lhs);
	};
return op;
}

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
{ 
	
	
	if(lhs->datatype != rhs->datatype)
	{
		if(op->whichval > 0 && op->whichval <= 4) // +, -, *, /
		{
			if(lhs->datatype == REAL && rhs->datatype == INTEGER)
			{
				rhs = makefloat(rhs);
			}
			else if(lhs->datatype == INTEGER && rhs->datatype == REAL)
			{
				lhs = makefloat(lhs);
			}
		}
		else if(op->whichval == ASSIGNOP)
		{
		      if(lhs->datatype == REAL)
		      {
					rhs = makefloat(rhs);
		      }
		      else if(lhs->datatype == INTEGER)
		      {
				if(lhs->tokentype == NUMBERTOK || lhs->tokentype == IDENTIFIERTOK)
					rhs = makefix(rhs);
		      }
		}
	}
	op->datatype = lhs->datatype;
	op->operands = lhs;          /* link operands to operator       */
	lhs->link = rhs;             /* link second operand to first    */
	rhs->link = NULL;            /* terminate operand list          */
	if (DEBUG & DB_BINOP)
	{ 
		printf("binop\n");
		dbugprinttok(op);
		dbugprinttok(lhs);
		dbugprinttok(rhs);
	};
return op;
}

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }
   
TOKEN makeprogram(TOKEN tok, TOKEN name, TOKEN arguments, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGRAMOP;
     tok->operands = name;
	 name->link = arguments;
	 arguments->link = statements;
     if (DEBUG & DB_MAKEPROGRAM)
       { printf("makeprogram\n");
         dbugprinttok(tok);
         dbugprinttok(name);
		 dbugprinttok(arguments);
		 dbugprinttok(statements);
       };
     return tok;
   }
   
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement)
{  
	int labelnum = labelnumber;
	
	TOKEN i1 = (TOKEN) talloc();
	i1->tokentype = IDENTIFIERTOK;
	i1->symentry = asg->operands->symentry;
	strcpy(i1->stringval, asg->operands->stringval);
	
	TOKEN i2 = (TOKEN) talloc();
	i2->tokentype = IDENTIFIERTOK;
	i2->symentry = asg->operands->symentry;
	strcpy(i2->stringval, asg->operands->stringval);
	
	TOKEN i3 = (TOKEN) talloc();
	i3->tokentype = IDENTIFIERTOK;
	i3->symentry = asg->operands->symentry;
	strcpy(i3->stringval, asg->operands->stringval);
	printf("offs: %i\n", i3->symentry->offset);
	
	// <=
	TOKEN lessthan = (TOKEN) talloc();
	lessthan->tokentype = OPERATOR;
	lessthan->whichval = LE - OPERATOR_BIAS;
	
	// :=
	TOKEN assign = (TOKEN) talloc();
	assign->tokentype = OPERATOR;
	assign->whichval = ASSIGN - OPERATOR_BIAS;
	
	// +
	TOKEN plus = (TOKEN) talloc();
	plus->tokentype = OPERATOR;
	plus->whichval = PLUSOP;
	
	// number token for the number one
	TOKEN one = (TOKEN) talloc();
	one->tokentype = NUMBERTOK;
	one->datatype = INTEGER;
	one->intval = 1;
	
	//i = i + 1 token
	TOKEN temp = (TOKEN) talloc();
	temp = binop(plus, i1, one);
	tok = binop(assign, i2, temp);
	
	
	TOKEN label = makelabel();
	
	TOKEN forstatements = NULL;
	forstatements = cons(makegoto(labelnum), forstatements);
	forstatements = cons(tok , forstatements);
	forstatements = cons(statement, forstatements);
	forstatements = makeprogn((TOKEN) talloc(), forstatements);
	
	TOKEN iftok = makeif(tokb,  binop(lessthan, i3, endexpr), forstatements, NULL);

	iftok = cons(label, iftok);
	iftok = cons(asg, iftok);
	
	
	if (DEBUG & DB_MAKEFOR)
	{ 
		printf("makefor\n");
		dbugprinttok(tok);
		dbugprinttok(asg);
		dbugprinttok(tokb);
		dbugprinttok(endexpr);
		dbugprinttok(tokc);
		dbugprinttok(statement);
	};
	return makeprogn(tokc, iftok);
}	

TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr)
{
      int labelnum = labelnumber;
      
      //label -> statements -> if
      
      TOKEN label = makelabel();
      TOKEN repeat = NULL;
      
      repeat = cons(makeif(tok, expr, makeprogn((TOKEN)talloc(), NULL), makegoto(labelnum)), repeat);
      repeat = cons(statements, repeat);
      repeat = cons(label, repeat);
      
      return makeprogn(tokb, repeat);
}

TOKEN makegoto(int label)
{
	TOKEN gototok = (TOKEN) talloc();
	TOKEN numbertok = (TOKEN) talloc();
	
	gototok->tokentype = OPERATOR;
	gototok->whichval = GOTOOP;
	
	numbertok->tokentype = NUMBERTOK;
	numbertok->datatype = INTEGER;
	numbertok->intval = label;
	
	gototok->operands = numbertok;

	return gototok;
}

TOKEN makelabel()
{
	TOKEN labeltok = (TOKEN) talloc();
	TOKEN numbertok = (TOKEN) talloc();
	
	labeltok->tokentype = OPERATOR;
	labeltok->whichval = LABELOP;
	
	numbertok->tokentype = NUMBERTOK;
	numbertok->datatype = INTEGER;
	numbertok->intval = labelnumber;
	
	labeltok->operands = numbertok;
	
	labelnumber++;
	
	return labeltok;
}

TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args)
{
	SYMBOL funsym = searchst(fn->stringval);

	if(funsym != NULL)
	{
		fn->datatype = (funsym->datatype)->basicdt;
	}
	
	if(strcmp(funsym->namestring, "new") != 0)
	{
		tok->tokentype = OPERATOR;
		tok->whichval = FUNCALLOP;
		tok->datatype = fn->datatype;
		tok->operands= fn;
		fn->link = args;
	}
	else
	{
		tok->tokentype = OPERATOR;
		tok->whichval = FUNCALLOP;
		tok->datatype = fn->datatype;
		tok->operands = fn;
		
		TOKEN sizetok = (TOKEN)talloc();
		sizetok->tokentype = NUMBERTOK;
		sizetok->intval = searchst((((searchst(args->stringval)->datatype)->datatype)->datatype)->namestring)->size;
		fn->link = sizetok;
		
		TOKEN assignop = (TOKEN)talloc();
		assignop->tokentype = OPERATOR;
		assignop->whichval = ASSIGNOP;
		args->datatype = POINTER;
		tok = binop(assignop, args, tok);
	}
	
	if(strcmp(funsym->namestring, "writeln") == 0)
	{
		if(args->tokentype == NUMBERTOK)
		{
			switch(args->datatype)
			{
				case INTEGER:
					strcpy(fn->stringval, "writelni");
				break;
				case REAL:
					strcpy(fn->stringval, "writelnf");
				break;
			}
		}
		else if(args->tokentype == IDENTIFIERTOK)
		{
			//switch(searchst(args->stringval)->basicdt)
			switch(args->symentry->basicdt)
			{
				case INTEGER:
					strcpy(fn->stringval, "writelni");
				break;
				case REAL:
					strcpy(fn->stringval, "writelnf");
				break;
			}
		}
	}
	
	else if(strcmp(funsym->namestring, "write") == 0)
	{
		if(args->tokentype == NUMBERTOK)
		{
			switch(args->datatype)
			{
				case INTEGER:
					strcpy(fn->stringval, "writei");
				break;
				case REAL:
					strcpy(fn->stringval, "writef");
				break;
			}
		}
		else if(args->tokentype == IDENTIFIERTOK)
		{
			switch(searchst(args->stringval)->basicdt)
			{
				case INTEGER:
					strcpy(fn->stringval, "writei");
				break;
				case REAL:
					strcpy(fn->stringval, "writef");
				break;
			}
		}
	}

	if (DEBUG & DB_MAKEFUNCALL)
	{ 
		printf("makefuncall\n");
		dbugprinttok(tok);
		dbugprinttok(fn);
		dbugprinttok(args);
	};
	return tok;
}

/* install variables in symbol table */
void instconst(TOKEN idtok, TOKEN consttok)
{  
	SYMBOL sym;
	
	if (DEBUG & DB_INSTALLCONST)
	{ 
		printf("instconst\n");
		dbugprinttok(idtok);
		dbugprinttok(consttok);
	};
	sym = insertsym(idtok->stringval);
	sym->kind = CONSTSYM;
	
	//sym->size = typesym->size;
	sym->basicdt = consttok->datatype;
	
	switch(consttok->datatype)
	{
		case REAL:
			sym->constval.realnum = consttok->realval;
		break;
		case INTEGER:
			sym->constval.intnum = consttok->intval;
		break;
		case STRINGTYPE:
			//int i;
			//for(i = 0; i < 16; i++)
				//sym->constval.stringconst[i] = consttok->stringval[i];
			strcpy(sym->constval.stringconst, consttok->stringval);
		break;
	}
		
	if (DEBUG & DB_INSTALLCONST) 
		printst();
}   

void  instlabel (TOKEN num)
{
	if(labelnumber < 5)
		labels[labelnumber++] = num->intval;
}

void  insttype(TOKEN typename, TOKEN eqtok, TOKEN typetok)
{
	SYMBOL typesym;
	typesym = searchins(typename->stringval);
	
	typesym->kind = TYPESYM;
	typesym->datatype = typetok->symentry;
	typesym->size = (typetok->symentry)->size;
	
}

TOKEN instenum(TOKEN rparen, TOKEN idlist, TOKEN lparen)
{
	//Smash r paren into a const token
	rparen->tokentype = NUMBERTOK;
	rparen->datatype = INTEGER;
	rparen->intval = 0;
	
	while(idlist != NULL)
	{
		instconst(idlist, rparen);
		(rparen->intval)++;
		idlist = idlist->link;
	}

	return makesubrange(lparen, 0, (rparen->intval) - 1);
}

TOKEN makesubrange(TOKEN tok, int low, int high)
{
	SYMBOL subrange = (SYMBOL)symalloc();

	subrange->kind = SUBRANGE;
	subrange->basicdt = INTEGER;
	subrange->lowbound = low;
	subrange->highbound = high;
	subrange->size = basicsizes[INTEGER];
	
	tok->symentry = subrange;
	
	return tok;
}

TOKEN instfields(TOKEN idlist, TOKEN typetok)
{
	SYMBOL typesym = searchins(typetok->stringval);
	SYMBOL sym;
	TOKEN tempTok = idlist;
	int align = alignsize(typesym);
	
	if(typesym->size == 0)
		typesym->size = 8;
		
	while(tempTok != NULL)
	{
		sym = (SYMBOL)symalloc();
		strcpy(sym->namestring, tempTok->stringval);
		sym->size = typesym->size;
		sym->datatype = typesym;
		sym->basicdt = typesym->basicdt;
		tempTok->symentry = sym;
		
		tempTok = tempTok->link;
	}
	
	return idlist;
}

TOKEN instrec(TOKEN rectok, TOKEN argstok)
{
	SYMBOL recsym = (SYMBOL)symalloc();
	TOKEN tempTok = argstok;
	int size = 0;
	
	//Link argstok symentries together
	while(tempTok->link != NULL)
	{
		(tempTok->symentry)->link = (tempTok->link)->symentry;
		while( size % (tempTok->symentry)->size != 0)
			size += 4;
		size += (tempTok->symentry)->size;
		tempTok = tempTok->link;
	}
	//The last token doesn't get added in the above loop
	while( size % (tempTok->symentry)->size != 0)
			size += 4;
	size += (tempTok->symentry)->size;
	
	recsym->kind = RECORDSYM;
	recsym->datatype = argstok->symentry;
	recsym->size = size;
	
	rectok->symentry = recsym;

	return rectok;
}

TOKEN instpoint(TOKEN tok, TOKEN typename)
{
	SYMBOL pointsym = (SYMBOL)symalloc();
	SYMBOL typenamesym = (SYMBOL)symalloc();
	
	strcpy(typenamesym->namestring, typename->stringval);
	
	pointsym->kind = POINTERSYM;
	pointsym->datatype = typenamesym;
	pointsym->basicdt = POINTER;
	pointsym->size = basicsizes[POINTER];

	tok->symentry = pointsym;
	
	return tok;
}

TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok)
{
	SYMBOL dotsym = (SYMBOL)symalloc();
	
	dotsym->kind = SUBRANGE;
	dotsym->basicdt = INTEGER;
	dotsym->lowbound = lowtok->intval;
	dotsym->highbound = hightok->intval;
	dotsym->size = basicsizes[INTEGER];
	
	dottok->symentry = dotsym;
	
	return dottok;
}

TOKEN instarray(TOKEN bounds, TOKEN typetok)
{
	SYMBOL arrsym = (SYMBOL)symalloc();
	SYMBOL typesym = searchst(typetok->stringval);
	if(bounds->link != NULL)
	{
		TOKEN bound1 = bounds;
		TOKEN bound2 = bounds->link;
		bounds->link = NULL;
		TOKEN newType = instarray(bound2, typetok);
		typesym = newType->symtype;
	}
	arrsym->kind = ARRAYSYM;
	arrsym->datatype = typesym;
	if(bounds->tokentype != IDENTIFIERTOK)
	{
		arrsym->lowbound = (bounds->symentry)->lowbound;
		arrsym->highbound = (bounds->symentry)->highbound;
	}
	else //Hopefully a temporary fix
	{
		arrsym->lowbound = 0;
		arrsym->highbound = 2;
	}
	
	arrsym->size = (arrsym->highbound - arrsym->lowbound + 1) * typesym->size;
	
	typetok->symtype = arrsym;

	return typetok;
}

TOKEN dopoint(TOKEN var, TOKEN tok)
{
	
	tok->tokentype = OPERATOR;
	tok->whichval = POINTEROP;
	tok->symentry = searchst(var->stringval);
	
	//coming from a nested point - var is an aref
	if(tok->symentry == NULL)
	{
		tok->symtype = searchst(var->symtype->datatype->namestring)->datatype;
	}
	else
	{
		// Locate the record sym field lst out of the depths of hell
		//                  John variable->john's type->pointersym->namesym->nameofrec->record->firstfieldentry
		tok->symtype = searchst((tok->symentry)->datatype->datatype->datatype->namestring)->datatype;//->datatype;
	}
	tok = unaryop(tok, var);
	
	
	return tok;
}

TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok)
{
	tok->tokentype = OPERATOR;
	tok->whichval = AREFOP;
	
	return binop(tok, var, off);
}

TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb)
{
	TOKEN ofs = tokb;
	ofs->tokentype = NUMBERTOK;
	ofs->datatype = INTEGER;
	SYMBOL sym = arr->symtype;
	
	if(arr->whichval == AREFOP)
	{
			//go to the first field entry
			sym = sym->datatype;
			
			//locate the proper location in the record
			while( strcmp(sym->namestring, subs->stringval) != 0)
			{
				while( ofs->intval % sym->size != 0)
					ofs->intval += 4;
				ofs->intval +=sym->size;
				
				sym = sym->link;
			}
			while( ofs->intval % sym->size != 0)
				ofs->intval += 4;
			
			
			arr->operands->link->intval+= ofs->intval;
			
			arr->symtype = sym->datatype->datatype;
			return arr;
	}
	else
	{
		if(sym->kind == RECORDSYM)
		{
			//go to the first field entry
			sym = sym->datatype;
			
			//locate the proper location in the record
			while( strcmp(sym->namestring, subs->stringval) != 0)
			{
				while( ofs->intval % sym->size != 0)
					ofs->intval += 4;
				ofs->intval +=sym->size;
				
				sym = sym->link;
			}
			while( ofs->intval % sym->size != 0)
				ofs->intval += 4;
			
			
			
			tok = makearef(arr, ofs, tok);
			
			//set the aref type to the type structure of the field entry
			tok->symtype = sym->datatype->datatype;
			
			return tok;
		}
		else if(sym->kind == ARRAYSYM)
		{
			//(index - low)* size
			if(subs->tokentype == NUMBERTOK)
			{
				ofs->intval = (subs->intval - sym->lowbound) * (sym->datatype->size);
				tok = makearef(arr, ofs, tok);
			}
			else
			{
				TOKEN plustok = (TOKEN)talloc();
				plustok->tokentype = OPERATOR;
				plustok->whichval = PLUSOP;
				
				TOKEN timestok = (TOKEN)talloc();
				timestok->tokentype = OPERATOR;
				timestok->whichval = TIMESOP;
				
				TOKEN term1 = (TOKEN)talloc();
				term1->tokentype = NUMBERTOK;
				term1->intval = -(sym->lowbound) * (sym->datatype->size);
				
				TOKEN elesize = (TOKEN)talloc();
				elesize->tokentype = NUMBERTOK;
				elesize->intval = (sym->datatype->size);
				
				ofs = binop(plustok, term1, binop(timestok, elesize, subs));
				ofs->tokentype = OPERATOR;
				tok = makearef(arr, ofs, tok);
			}
			
			//set the aref type to the type structure of the array entries
			tok->symtype = sym->datatype->datatype;
			
			return tok;
		}

		return tok;
	}
	
}

TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement)
{
	TOKEN label = makelabel();
	labelnumber--;
	int i;
	for(i = 0; i < 50; i++)
		if(labels[i] == labeltok->intval)
			break;
	
	label->operands->intval = i;
	
	cons(label, statement);
	
	return makeprogn(tok, label);
}

TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement)
{
	TOKEN labeltok = makelabel();
	TOKEN whiletok = NULL;
	TOKEN iftok = makeif(tok, expr, makeprogn(tokb, cons(statement, makegoto(labelnumber - 1))), NULL);
	whiletok = cons(iftok, whiletok);
	whiletok = cons(labeltok, whiletok);

	return makeprogn((TOKEN)talloc(), whiletok);
	
}
   
TOKEN findtype(TOKEN tok)
{
	tok->symtype = searchst(tok->stringval);
	return tok;
}

TOKEN dogoto(TOKEN tok, TOKEN labeltok)
{
	int i = 0;
	
	for(i = 0; i < 50; i++)
		if(labels[i] = labeltok->intval)
			break;
	
	return makegoto(i);
}

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
yyerror(s)
  char * s;
  { 
  fputs(s,stderr); putc('\n',stderr);
  }

main()
  { int res;
    initsyms();
    res = yyparse();
    printst();
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
	gencode(parseresult, blockoffs[blocknumber], labelnumber);
  }
