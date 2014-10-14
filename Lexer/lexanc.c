/* use lexandr.c instead.  See the makefile .    */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"

#define NUMRESERVEDWORDS	29
#define NUMBEROPS	19
#define MAXINT	2147483647
/* This file will work as given with an input file consisting only
   of integers separated by blanks:
   make lex1
   lex1
   12345 123    345  357
   */
   
 static char *reservedWords[] = { " ", "array", "begin", "case", "const", "do",
                           "downto", "else", "end", "file", "for",
		           "function", "goto", "if", "label", "nil",
                           "of", "packed", "procedure", "program", "record",
                           "repeat", "set", "then", "to", "type",
		           "until", "var", "while", "with" };
				   
static char *operators[]  = {" ", "+", "-", "*", "/", ":=", "=", "<>", "<", "<=",
                          ">=", ">",  "^", ".", "and", "or", "not", "div",
                          "mod", "in"};
				   
float tenTable[38];

initTenTable()
{
	int i = 0;
	tenTable[0] = 1.0;
	for(i = 1; i < 38; i++)
		tenTable[i] = tenTable[i - 1] * 10.0;
}

/* Skip blanks and whitespace.  Expand this function to skip comments too. */
void skipblanks ()
{
    int c;
    while ((c = peekchar()) != EOF && (c == ' ' || c == '\n' || c == '\t' || c == '{' || (c == '(' && peek2char() == '*')))
	{
		if(c == '{')
		{
			while(c != '}')
				c = getchar();
		}
		if(c == '(')
		{
			getchar(); // (
			getchar(); // *
			while(1)
			{
				c = getchar();
				if(c == '*' && peekchar() == ')')
				{
					getchar(); // )
					break;
				}
			}
		}
		else
			getchar();
	}
}

int isReserved(char * string)
{
	int i = 0;
	
	for(i = 0; i <= NUMRESERVEDWORDS; i++)
		if(!strcmp(string, reservedWords[i]))
			return i;
	return 0;
}

int isOperator(char * string)
{
	int i = 0;
	
	for(i = 0; i <= NUMBEROPS; i++)
		if(!strcmp(string, operators[i]))
			return i;
	return 0;
}

/* Get identifiers and reserved words */
TOKEN identifier (TOKEN tok)
{
	int c, i, j;
	char string[16];
	i = 0;
	while( (c = peekchar()) != EOF && (CHARCLASS[c] == ALPHA || CHARCLASS[c] == NUMERIC))
	{
		getchar();
		if(i < 15)
		{
			string[i] = c;
			i++;
		}
	}
	string[i] = '\0';
	
	int reserved = isReserved(string);
	int operator = isOperator(string);
	if(reserved != 0)
	{
		tok->tokentype = RESERVED;
		tok->whichval = reserved;
	}
	else if(operator != 0)
	{
		tok->tokentype = OPERATOR;
		tok->whichval = operator;
	}
	else
	{
		tok->tokentype = IDENTIFIERTOK;
		for(j = 0; j <= i; j++)
			tok->stringval[j] = string[j];
	}
}

TOKEN getstring (TOKEN tok)
{
	int c;
	char string[16];
	int i = 0;
	int j;
	int done = 0;
	getchar(); //Skip the first quote
	while( (c = peekchar()) != EOF && !done)
	{
		getchar();
		if(i >= 15) //String is more than 15 characters long
		{
			while(!done)
			{
				c = getchar();
				if(c == '\'')
				{
					if(peekchar() != '\'')
					{
						done = 1;
						break;
					}
					else
						c = getchar();
				}
			}
			break;
		}
		if(c == '\'') //If we run in to another quote, check if it's an escape sequence and handle it accordingly
		{
			if(peekchar() != '\'')
			{
				done = 1;
				continue;
			}
			else
				c = getchar();
		}
		string[i] = c;
		i++;
	}
	string[i] = '\0'; //Finish the string off with a null terminator
	
	
	tok->tokentype = STRINGTOK;
	
	
	for(j = 0; j <= i; j++)
		tok->stringval[j] = string[j];
}

TOKEN special (TOKEN tok)
{
	int c, tokType, value;
	c = getchar();
	
	if(c == '+')
	{
		tokType = OPERATOR;
		value = PLUSOP;
	}
	else if (c =='-')
	{
		tokType = OPERATOR;
		value = MINUSOP;
	}
	else if (c =='*')
	{
		tokType = OPERATOR;
		value = TIMESOP;
	}
	else if (c =='/')
	{
		tokType = OPERATOR;
		value = DIVIDEOP;
	}
	else if (c ==':' && peekchar() == '=')
	{
		getchar(); //get the extra ='s sign
		tokType = OPERATOR;
		value = ASSIGNOP;
	}
	else if (c =='=')
	{
		tokType = OPERATOR;
		value = EQOP;
	}
	else if (c =='<')
	{
		c = peekchar();
		
		if(c == '>')
		{
			getchar();
			tokType = OPERATOR;
			value = NEOP;
		}
		else if(c == '=')
		{
			getchar();
			tokType = OPERATOR;
			value = LEOP;
		}
		else
		{
			tokType = OPERATOR;
			value = LTOP;
		}
	}
	else if (c =='>')
	{
		c = peekchar();
		if(c == '=')
		{
			getchar();
			tokType = OPERATOR;
			value = GEOP;
		}
		else
		{
			tokType = OPERATOR;
			value = GTOP;
		}
	}
	else if (c =='^')
	{
		tokType = OPERATOR;
		value = POINTEROP;
	}
	else if (c =='.')
	{
		if(peekchar() == '.')
		{
		    getchar();
		    tokType = DELIMITER;
		    value = DOTDOT - DELIMITER_BIAS;
		}
		else
		{
		    tokType = OPERATOR;
		    value = DOTOP;
		}

	}
	else if(c == ',')
	{
		tokType = DELIMITER;
		value = COMMA - DELIMITER_BIAS;
	}
	else if(c == ';')
	{
		tokType = DELIMITER;
		value = SEMICOLON - DELIMITER_BIAS;
	}
	else if(c == ':')
	{
		tokType = DELIMITER;
		value = COLON - DELIMITER_BIAS;
	}
	else if(c == '(')
	{
		tokType = DELIMITER;
		value = LPAREN - DELIMITER_BIAS;
	}
	else if(c == ')')
	{
		tokType = DELIMITER;
		value = RPAREN - DELIMITER_BIAS;
	}
	else if(c == '[')
	{
		tokType = DELIMITER;
		value = LBRACKET - DELIMITER_BIAS;
	}
	else if(c == ']')
	{
		tokType = DELIMITER;
		value = RBRACKET - DELIMITER_BIAS;
	}
	else
	{
		tokType = OPERATOR;
		value = 0;
	}
	
	tok->tokentype = tokType;
	tok->whichval = value;

}

/* Get and convert unsigned numbers of all types. */
TOKEN number (TOKEN tok)
{ 
    long num;
	long tempNum;
    int  c, charval, cc;
    num = 0;
	int overflow = 0;
	
	int sigfigs = 0;
	
	int type = 0; //0 For Integer, 1 for Float
	
	int expo = 0;
	int sign = 0;
	
	int intPlaces = 0;
	int decimalPlaces = 0; //Start incrementing after decimal has been found
	int insigDec = 0; //Number of values after the first 8 significant
	float fNum = 0.0;
	
	initTenTable();
	
	
	while( (c = peekchar()) == '0') //skip leading insignificant 0's
		getchar();
	
	if(c == '.')
	{
		type = 1;
		getchar();
		while( (c = peekchar()) == '0') //Take care of leading zeros if they expand into the decimal places
		{
			decimalPlaces++;
			getchar();
		}
	}
	
	
    while ( (c = peekchar()) != EOF && (CHARCLASS[c] == NUMERIC || c == '.'))
    {   
      	if(c == '.')
		{
			if(type == 0)
			{
				if(peek2char() == '.') // dotdot operator
					break;
				else
				{
					type = 1;
					getchar(); //Skip over the decimal
					continue;
				}
			}
			else
			{
				fprintf(stderr, "Error with number syntax - ignoring second decimal\n");
				getchar(); //eat the extra decimal and keep going
				continue;
			}
		}
		c = getchar();
		
		if(sigfigs < 8 || type == 0)
		{
			charval = (c - '0');

			if(num < (MAXINT / 10))
				num = num * 10 + charval;
			
			else
			{
				overflow = 1;
				insigDec++;
			}
			
			if(type == 1)
				decimalPlaces++;
			else
				intPlaces++;
			
		}
			
		sigfigs++;
		
    }
	
	c = peekchar();
	if((c == 'E' || c == 'e'))
	{
		type = 1;
		getchar(); //Eat up the e
		
		cc = peekchar(); //See if its a positive or negative expo
		
		if(cc == '-')
		{
			sign = -1;
			getchar(); //Eat the -
		}
		else if(cc == '+')
		{
			sign = 1;
			getchar(); //Eat the +
		}
		else //If there's a number after the E, it must be positive
			sign = 1;

		while ( (c = peekchar()) != EOF && CHARCLASS[c] == NUMERIC)
		{  
			getchar();
			charval = (c - '0');
			expo = expo * 10 + charval;
		}
			expo *= sign;
	}
	
	if(type == 1)
	{
		fNum = num;
		expo -= decimalPlaces;
		expo += insigDec;
		expo += (sigfigs - intPlaces);

			
		if(expo >= 38)
		{
			expo = 0;
			fNum = 0;
			printf("Floating number out of range\n");
		}
		else if(expo <= -38)
		{
			fNum = 0;
			expo = 0;
			printf("Floating number out of range\n");
		}
		else
			expo -= (sigfigs - intPlaces);

		if(expo < -38 || expo > 38)
		{
			fNum = fNum / tenTable[decimalPlaces];
			expo+= decimalPlaces;
		}
		if(expo < 0)
			fNum = fNum / tenTable[-expo];
		else
			fNum = fNum * tenTable[expo];
	}
	
	tok->tokentype = NUMBERTOK;
	tok->datatype = type;
	
	if(type == 0)
	{
		if(overflow)
		{
			printf("Integer number out of range\n");
		}
		else
			tok->intval = num;
	}
	else
	{
		tok->realval = fNum;
	}

return (tok);
}
  
  
  
  