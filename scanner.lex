%{
	#include <stdlib.h>
	#include "accounting_aux.hpp"
	#include "parser.tab.hpp"
	#include <string>
%}

%option noyywrap
%option yylineno

item_id				([a-z_]+)
participant_id		([A-Z]([a-z_]*))
number				(0|(-?[1-9][0-9]*)\.?[0-9]*)
whitespace  		([\t\n\r ])

%%
{participant_id}	{
						yylval.id = new string(yytext);
						return PARTICIPANT_ID;
					}

{item_id}			{
						yylval.id = new string(yytext);
						return ITEM_ID;
					}

{number}			{
						yylval.number = std::stod(string(yytext));
						return NUMBER;
					}

NOT					return NOT;

{whitespace}		;

.       			{printf("unexpected character: %s.at line: %d\n", yytext, yylineno); exit(1);};
%%
