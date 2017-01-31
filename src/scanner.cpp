#include <string>
#include <iostream>

#include "scanner.h"
#include "regex.h"

using namespace std;

//Consume white space function - from lab_03 code
int consumeWhiteSpaceAndComments (regex_t *whiteSpace, 
	regex_t *blockComment,
	regex_t *lineComment,
	const char *text) ;

//Array of all relevant regular expressions
int numRegexes = 51;
//regex_t** regexArray = new regex_t*[numRegexes];

// Create the regular expressions for consumeWhiteSpaceAndComments - from lab_03 code


Scanner::Scanner(){
    initializeArray();
    whiteSpace = makeRegex ("^[\n\t\r ]+") ;
    blockComment = makeRegex ("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");
    lineComment = makeRegex ("^//[^\n]*\n");
}

void Scanner::initializeArray() {
    regexArray = new regex_t*[numRegexes];
    regexArray[letKwd]= makeRegex("^let"); 			//letKwd
    regexArray[inKwd] = makeRegex("^in");			//inKwd
    regexArray[endKwd] = makeRegex("^end");			//endKwd
    regexArray[ifKwd] = makeRegex("^if");			//ifKwd
    regexArray[thenKwd] = makeRegex("^then");		//thenKwd
    regexArray[elseKwd] = makeRegex("^else");		//elseKwd
    regexArray[printKwd] = makeRegex("^print");		//printKwd
    regexArray[readKwd] = makeRegex("^read");		//readKwd
    regexArray[writeKwd] = makeRegex("^write");		//writeKwd
    regexArray[integerKwd] = makeRegex("^Integer");		//integerKwd
    regexArray[floatKwd] = makeRegex("^Float");		//floatKwd
    regexArray[booleanKwd] = makeRegex("^Boolean");	//booleanKwd
    regexArray[stringKwd] = makeRegex("^String");		//stringKwd
    regexArray[trueKwd] = makeRegex("^true");		//trueKwd
    regexArray[falseKwd] = makeRegex("^false");		//falseKwd
    regexArray[headKwd] = makeRegex("^head");		//headKwd
    regexArray[tailKwd] = makeRegex("^tail");		//tailKwd
    regexArray[nullKwd] = makeRegex("^null");		//nullKwd
    regexArray[mapKwd] = makeRegex("^map");		//mapKwd
    regexArray[filterKwd] = makeRegex("^filter");		//filterKwd
    regexArray[foldKwd] = makeRegex("^fold");		//foldKwd
    regexArray[zipKwd] = makeRegex("^zip");		//zipKwd
    regexArray[intConst] = makeRegex("^[0-9]+");		//intConst
    regexArray[floatConst] = makeRegex("^[0-9]*\\.[0-9]+");//floatConst
    regexArray[stringConst] = makeRegex("^\"[^\"]*?\"");		//stringConst
    regexArray[variableName] = makeRegex("^[a-zA-Z_0-9]+");//variableName
    regexArray[leftParen] = makeRegex("^\\(");			//leftParen
    regexArray[rightParen] = makeRegex("^\\)");			//rightParen
    regexArray[leftSquare] = makeRegex("^\\[");			//leftSquare
    regexArray[rightSquare] = makeRegex("^\\]");			//rightSquare
    regexArray[leftAngle] = makeRegex("^<");			//leftAngle
    regexArray[rightAngle] = makeRegex("^>");			//rightAngle
    regexArray[colon] = makeRegex("^:");			//colon
    regexArray[colonColon] = makeRegex("^::");			//colonColon
    regexArray[comma] = makeRegex("^,");			//comma
    regexArray[semiColon] = makeRegex("^;");			//semiColon	
    regexArray[equalsSign] = makeRegex("^=");			//equalsSign
    regexArray[plusSign] = makeRegex("^\\+");			//plusSign
    regexArray[star] = makeRegex("^\\*");			//star
    regexArray[dash] = makeRegex("^-");			//dash
    regexArray[forwardSlash] = makeRegex("^/");			//forwardSlash
    regexArray[percent] = makeRegex("^%");			//percent
    regexArray[backSlash] = makeRegex("^\\\\");			//backSlash
    regexArray[arrow] = makeRegex("^->");			//arrow
    regexArray[equalsEquals] = makeRegex("^==");			//equalsEquals
    regexArray[lessThanEquals] = makeRegex("^<=");			//lessThanEquals
    regexArray[greaterThanEquals] = makeRegex("^>=");			//greaterThanEquals
    regexArray[notEquals] = makeRegex("^!=");			//notEquals
    regexArray[plusPlus] = makeRegex("^\\+\\+");			//plusPlus
    regexArray[dotDot] = makeRegex("^\\.\\.");			//dotDot
    regexArray[tupleOp] = makeRegex("^#[1-9]+[0-9]*");//tupleOp
    //regexArray[51] = makeRegex("");			//endOfFile
    //regexArray[52] = makeRegex("");			//lexicalError
}

//scan function
Token* Scanner::scan(const char* text) {

    Token* head = new Token();
    Token* current = head;

    char* buffer;
    terminal_t matchType;

    //Code from lab_03
    int numMatchedChars = 0 ;
    // Consume leading white space and comments
    numMatchedChars = consumeWhiteSpaceAndComments (whiteSpace, blockComment, lineComment, 
	    text) ;
    /* text is a character pointer that points to the current
       beginning of the array of characters in the input.  Adding an
       integer value to it advances the pointer that many elements in
       the array.  Thus, text is increased so that it points to the
       current location in the input. 
       */
    text = text + numMatchedChars ;

    int maxNumMatchedChars = 0 ;

    while ( text[0] != '\0' ) {
	maxNumMatchedChars = 0 ; matchType = lexicalError ;

	/* maxNumMatchedChars is used to ensure that the regular
	   expression that matched the longest string is the one that
	   we use.  

	   The regexs for word and integerConst cannot match the
	   same text, but if we extend this program to search for
	   specific keywords, then the keyword regex and the
	   word-regex may, in some cases, match the same input text.

	   If two regexs match the same number of characters
	   then the tie has to be broken.  To break the tie, priority
	   is given to the first one that was tried.  Thus the
	   comparison
	   (numMatchedChars > maxNumMatchedChars) 
	   is strictly greater than.  Not greater than or  equal to.
	   */

	//Try to match each regular expressions
	int i;
	for(i = 0; i < numRegexes; i++) {
	    numMatchedChars = matchRegex(regexArray[i], text) ;
	    if ( numMatchedChars > maxNumMatchedChars) {
		maxNumMatchedChars = numMatchedChars ;
		matchType = tokenEnumType(i) ;
	    }
	}

	if (matchType == lexicalError) {
	    buffer = new char[2];
	    buffer[0] = text[0];
	    buffer[1] = '\0';
	    //Advance
	    text = text+1;
	} else {
	    buffer = new char[maxNumMatchedChars+1];
	    int j;
	    for(j = 0; j < maxNumMatchedChars; j++) {
		buffer[j] = text[j];
	    }
	    buffer[j] = '\0';
	    //Advance
	    text = text+maxNumMatchedChars;
	}

	current->terminal = matchType;
	current->lexeme = buffer;
	current->next = new Token();
	//Advance to next Token
	current = current->next;

	//delete[] buffer;

	// Consume white space and comments before trying again for
	// another word or integer.
	numMatchedChars = consumeWhiteSpaceAndComments (whiteSpace, blockComment, lineComment, 
		text) ;
	text = text + numMatchedChars ;

    }

    // Add endOfFile terminal
    current->terminal = endOfFile;
    current->lexeme = "\0";
    current->next = NULL;

    return head;
}

//Code from lab_03
int consumeWhiteSpaceAndComments (regex_t *whiteSpace, 
	regex_t *blockComment, 
	regex_t *lineComment,
	const char *text) {
    int numMatchedChars = 0 ;
    int totalNumMatchedChars = 0 ;
    int stillConsumingWhiteSpace ;

    do {
	stillConsumingWhiteSpace = 0 ;  // exit loop if not reset by a match

	// Try to match white space
	numMatchedChars = matchRegex (whiteSpace, text) ;
	totalNumMatchedChars += numMatchedChars ;
	if (numMatchedChars > 0) {
	    text = text + numMatchedChars ;
	    stillConsumingWhiteSpace = 1 ;
	}

	// Try to match block comments
	numMatchedChars = matchRegex (blockComment, text) ;
	totalNumMatchedChars += numMatchedChars ;
	if (numMatchedChars > 0) {
	    text = text + numMatchedChars ;
	    stillConsumingWhiteSpace = 1 ;
	}

	// Try to match single-line comments
	numMatchedChars = matchRegex (lineComment, text) ;
	totalNumMatchedChars += numMatchedChars ;
	if (numMatchedChars > 0) {
	    text = text + numMatchedChars ;
	    stillConsumingWhiteSpace = 1 ;
	}
    }
    while ( stillConsumingWhiteSpace ) ;    

    return totalNumMatchedChars ;
}
