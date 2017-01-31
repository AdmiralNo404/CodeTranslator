#ifndef SCANNER_H
#define SCANNER_H

#include <regex.h>
#include <string>

using namespace std;

class Token ;

/* This enumerated type is used to keep track of what kind of
   construct was matched. 
*/
enum tokenEnumType { 

    // Keywords
    letKwd, inKwd, endKwd, ifKwd, thenKwd, elseKwd, 
    printKwd, readKwd, writeKwd, 
    integerKwd, floatKwd, booleanKwd, stringKwd, 
    trueKwd, falseKwd, 

    headKwd, tailKwd, nullKwd, 
    mapKwd, filterKwd, foldKwd, 
    zipKwd,

    // Constants
    intConst, floatConst, stringConst, 

    // Names
    variableName ,

    // Punctuation
    leftParen, rightParen, 
    leftSquare, rightSquare, leftAngle, rightAngle,
    colon, colonColon, comma, semiColon, 
    equalsSign, 

    plusSign, star, dash, forwardSlash, percent, 
    backSlash, arrow, 
    equalsEquals, 
    lessThanEquals, greaterThanEquals, notEquals, 
    plusPlus, dotDot, 
    tupleOp,

    endOfFile ,
    lexicalError
} ;
typedef enum tokenEnumType terminal_t ;

// From previoius lab
int consumeWhiteSpaceAndComments (regex_t *whiteSpace, 
                                  regex_t *blockComment,
                                  regex_t *lineComment,
                                  const char *buffer) ;

// Below you need to write your class definitions for Token and Scanner.

class Token {
	public:
	Token(){};
	terminal_t terminal;
	string lexeme;
	Token* next;
	Token (const char* lex, terminal_t type, Token* nextToken)
	{
		lexeme = lex;
		terminal = type;
		next = nextToken;
	};

} ;

class Scanner {
	private:
	regex_t** regexArray;
	regex_t* whiteSpace;// = makeRegex ("^[\n\t\r ]+") ;
    regex_t* blockComment;// = makeRegex ("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");
    regex_t* lineComment;// = makeRegex ("^//[^\n]*\n");
	public:
	Token *scan (const char*) ;
	void initializeArray();
	Scanner();
} ;
// Below you need to write your class declarations for Token and Scanner.

#endif /* SCANNER_H */
