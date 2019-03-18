# comp
projecto de compiladores

"void"          return VOID;
"integer"       return INTEGER;
"string"        return STRING;
"public"        return PUBLIC;
"number"        return NUMBER;
"const"         return CONST;
"if"            return IF;
"then"          return THEN;
"else"          return ELSE;
"while"         return WHILE;
"do"            return DO;
"for"           return FOR;
"in"            return IN;
"step"          return STEP;
"upto"          return UPTO;
"downto"        return DOWNTO;
"break"         return BREAK;
"continue"      return CONTINUE;

"="	            return EQ;
">="	        return GE;
"<="	        return LE;
"<>"	        return NE;
":="	        return ASSIGN;
"++"            return INC;
"--"	        return DEC;
	
[-+*/%!&|~^<>()?:;,\[\]{}#]	return *yytext;