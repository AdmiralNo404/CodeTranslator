/* A recursive descent parser with operator precedence.

Author: Eric Van Wyk

This algorithms is based on the work of Douglas Crockford in "Top
Down Operator Precedence", a chapter in the book "Beautiful Code".
Mr. Crockford describes in his chapter how his work comes from that
of Based on algorithms described Vaughan Pratt in "Top Down Operator
Precedence", presented at the ACM Symposium on Principles of
Programming Languages.

Douglas Crockford's chapter is available at 
http://javascript.crockford.com/tdop/tdop.html

Vaughan Pratt's paper is available at 
http://portal.acm.org/citation.cfm?id=512931

These are both quite interesting works and worth reading if you
find the problem of parsing to be an interesting one.

Last modified: March 4, 2014.
*/

#include "Parser.h"
#include "scanner.h"
#include "ExtToken.h"
#include "AST.h"

#include <assert.h>

using namespace std ;

/**
 * @file Parser.cpp
 * @author Yanbang Liu
 * @author Isaac Martin
 * @author Trevor Riles
 * 
 * @brief This file manages the parser for our implementation and handles the construction of the concrete syntax tree
 * */

Parser::Parser ( ) { } 

/**
 * @brief Main Parsing Method. Scans tokens and then parses the program.
 *
 * @param text Program source code
 *
 * @return ParseResult
 */
ParseResult Parser::parse (const char *text) {
    assert (text != NULL) ;

    ParseResult pr ;
    try {
	Scanner *s = new Scanner() ;
	tokens = extendTokenList ( this, s->scan (text) ) ;

	assert (tokens != NULL) ;
	currToken = tokens ;
	pr = parseProgram( ) ;
    }
    catch (string errMsg) {
	pr.ok = false ;
	pr.errors = errMsg ;
	pr.ast = NULL ;
    }
    return pr ;
}

/* 
 * parse methods for non-terminal symbols
 * --------------------------------------
 */

// Program DONE
/**
 * @brief Parse Program
 *
 * @return ParseResult
 */
ParseResult Parser::parseProgram () {
    ParseResult pr ;
    // Program ::= DeclList
    ParseResult pe = parseDeclList() ;

    assert(pe.ast != NULL);
    // verify that ast field is a DeclList pointer

    pr.ast = new Program(pe.ast);

    match(endOfFile) ;

    return pr ;
}

// DeclList DONE
/**
 * @brief Parse Declaration list
 *
 * @return ParseResult
 */
ParseResult Parser::parseDeclList () {
    ParseResult pr ;
    // DeclList ::= Decl
    ParseResult pd = parseDecl() ;

    // verify that ast field is a Declt pointer
    if ( nextIs(variableName) ) {
	// DeclList ::= Decl DeclList
	ParseResult pl = parseDeclList() ;
	pr.ast = new DeclList(pd.ast, pl.ast);
	// verify that ast field is a DeclList pointer
    }
    else {
	//emptyList
	pr.ast = new DeclList(pd.ast);
    }

    return pr ;
}

// Decl DONE
/**
 * @brief Parse declaration
 *
 * @return ParseResult
 */
ParseResult Parser::parseDecl () {
    ParseResult pr ;
    // Decl ::= variableName '::' TypeExpr '=' Expr ';'

    match(variableName) ;

    VariableName* varName = new VariableName(prevToken->lexeme);

    match(colonColon) ;

    ParseResult pt = parseTypeExpr() ;

    // verify that ast field is a TypeExpr pointer

    match(equalsSign) ;
    ParseResult pe = parseExpr(0) ;
    //cout << pe.ast->unparse() << ": That's it\n";

    pr.ast = new Decl(varName, pt.ast, pe.ast);

    match(semiColon) ;

    return pr ;
}

// TypeExpr DONE
/**
 * @brief Parse type expression
 *
 * @return ParseResult
 */
ParseResult Parser::parseTypeExpr () {
    ParseResult pr ;
    if ( attemptMatch(integerKwd) ) { 
	// TypeExpr ::= 'Integer' DONE
	pr.ast = new TypeExprInt();
    }

    else if ( attemptMatch(floatKwd) ) {
	// TypeExpr ::= 'Float' DONE
	pr.ast = new TypeExprFlt();
    }

    else if ( attemptMatch(stringKwd) ) {
	// TypeExpr ::= 'String' DONE
	pr.ast = new TypeExprStr();
    }

    else if ( attemptMatch(booleanKwd) ) {
	// TypeExpr ::= 'Boolean' DONE
	pr.ast = new TypeExprBool();
    }

    else if ( attemptMatch(leftSquare) ) {
	// TypeExpr ::= '[' TypeExpr ']' DONE

	ParseResult pt = parseTypeExpr() ;

	match(rightSquare) ;

	pr.ast = new TypeExprSqBracket(pt.ast);

    }

    else if ( attemptMatch(leftParen) ) {
	if ( nextIs(variableName) ) {
	    // TypeExpr ::= '(' TypeBindingList ')' '->' TypeExpr DONE

	    ParseResult ptbl = parseTypeBindingList() ;

	    match(rightParen) ;
	    match(arrow) ;

	    ParseResult pt = parseTypeExpr() ;

	    pr.ast = new TypeExprPArr(ptbl.ast, pt.ast);

	} else {
	    // TypeExpr ::= '(' TypeExprList ')'  DONE

	    ParseResult ptel = parseTypeExprList() ;
	    match(rightParen) ;

	    pr.ast = new TypeExprParen(ptel.ast);

	}
    }
    else {
	throw ( makeErrorMsg ( currToken->terminal ) ) ;
    }

    return pr ;
}

// TypeExprList DONE
/**
 * @brief Parse type expression list
 *
 * @return ParseResult
 */
ParseResult Parser::parseTypeExprList () {
    ParseResult pr ;
    // TypeExprList ::= TypeExpr

    ParseResult pt = parseTypeExpr() ;

    if ( attemptMatch(comma) ) {
	// TypeExprList ::= TypeExpr ',' TypeExprList

	ParseResult ptel = parseTypeExprList () ;
	pr.ast = new TypeExprList(pt.ast, ptel.ast);

    }
    else {
	//no TypeExprs follow the one matched previously in this function. 

	pr.ast = new TypeExprList(pt.ast);

    }

    return pr ;
}

// TypeBindingList DONE
/**
 * @brief Parse type binding list
 *
 * @return ParseResult
 */
ParseResult Parser::parseTypeBindingList () {
    ParseResult pr ;
    // TypeBindingList ::= TypeBinding

    ParseResult ptb = parseTypeBinding () ;


    if ( attemptMatch(comma) ) {
	// TypeBindingList ::= TypeBinding ',' TypeBindingList

	ParseResult ptbl = parseTypeBindingList () ;
	pr.ast = new TypeBindingList(ptb.ast, ptbl.ast);

    }
    else {

	pr.ast = new TypeBindingList(ptb.ast);

    }

    return pr ;
}

// TypeBinding DONE
/**
 * @brief Parse type binding
 *
 * @return ParseResult
 */
ParseResult Parser::parseTypeBinding () {
    ParseResult pr ;
    // TypeBinding ::= variableName '::' TypeExpr
    match(variableName) ;

    VariableName* varName = new VariableName(prevToken->lexeme);

    match(colonColon) ;

    ParseResult ptb = parseTypeExpr () ;

    pr.ast = new TypeBinding(varName, ptb.ast);

    return pr ;
}

// OptionalExprList DONE
/**
 * @brief Parse optional expression list
 *
 * @return ParseResult
 */
ParseResult Parser::parseOptionalExprList () {
    ParseResult pr ;
    if ( nextIs(rightSquare) || nextIs(rightParen) ) {
	// OptionalExprList ::= <<empty>>
	pr.ast = new OptionalExprList();
    } else {
	// OptionalExprList ::= ExprList
	ParseResult pel = parseExprList() ;
	pr.ast = new OptionalExprList(pel.ast);
    }
    return pr ;
}

// ExprList  DONE
/**
 * @brief Parse expression list
 *
 * @return ParseResult
 */
ParseResult Parser::parseExprList () {
    ParseResult pr ;
    // ExprList ::= Expr

    ParseResult pe = parseExpr(0) ;

    if ( attemptMatch(comma) ) {
	// ExprList ::= Expr ',' ExprList
	ParseResult pel = parseExprList() ;
	pr.ast = new ExprList(pe.ast, pel.ast);

    }
    else {
	//empty listExprs
	pr.ast = new ExprList(pe.ast);
    }

    return pr ;
}

// Expr
/**
 * @brief Parse expression
 *
 * @param rbp 
 *
 * @return ParseResult
 */
ParseResult Parser::parseExpr (int rbp) {
    /* Examine current token, without consuming it, to call its
       associated parse methods.  The ExtToken objects have 'nud' and
       'led' methods that are dispatchers that call the appropriate
       parse methods.*/
    ParseResult left = currToken->nud() ;
    while (rbp < currToken->lbp() ) {
	left = currToken->led(left) ;
    }
    return left ;
}

/*
 * parse methods for productions
 * -----------------------------
 */

// Expr ::= variableName DONE
/**
 * @brief Parse variable name
 *
 * @return ParseResult
 */
ParseResult Parser::parseVariableName ( ) {
    ParseResult pr ;
    match ( variableName ) ;
    pr.ast = new VariableName(prevToken->lexeme);
    return pr ;
}

// Expr ::= intConst DONE
/**
 * @brief Parse integer constant
 *
 * @return ParseResult
 */
ParseResult Parser::parseIntConst ( ) {
    ParseResult pr ;
    match ( intConst ) ;
    pr.ast = new IntConst(prevToken->lexeme);
    return pr ;
}

// Expr ::= floatConst DONE
/**
 * @brief Parse float constant
 *
 * @return ParseResult
 */
ParseResult Parser::parseFloatConst ( ) {
    ParseResult pr ;
    match ( floatConst ) ;
    pr.ast = new FloatConst(prevToken->lexeme);
    return pr ;
}

// Expr ::= stringConst DONE
/**
 * @brief Parse string constant
 *
 * @return ParseResult
 */
ParseResult Parser::parseStringConst ( ) {
    ParseResult pr ;
    match ( stringConst ) ;
    pr.ast = new StringConst(prevToken->lexeme);
    return pr ;
}

// Expr ::= trueKwd DONE
/**
 * @brief Parse true keyword
 *
 * @return ParseResult
 */
ParseResult Parser::parseTrueKwd ( ) {
    ParseResult pr ;
    match ( trueKwd ) ;
    pr.ast = new BooleanConst("true");
    return pr ;
}

// Expr ::= falseKwd DONE
/**
 * @brief Parse false keyword
 *
 * @return ParseResult
 */
ParseResult Parser::parseFalseKwd ( ) {
    ParseResult pr ;
    match ( falseKwd ) ;
    pr.ast = new BooleanConst("false");
    return pr ;
}

//Expr ::= '(' Expr ')' || '(' Expr, ExprList ')'
/**
 * @brief Parse Nested or Tuple Expression
 *
 * @return ParseResult
 */
ParseResult Parser::parseNestedOrTupleExpr ( ) {
    ParseResult pr ;
    match ( leftParen ) ;


    // Expr ::= '(' Expr ')'  DONE
    ParseResult pe = parseExpr(0) ; 

    if ( attemptMatch(comma) ) {
	// Expr ::= '(' Expr ',' ExprList ')'  DONE
	ParseResult pel = parseExprList() ;
	pr.ast = new ParenListExpr(pe.ast, pel.ast);
    }
    else {
	//no ExprList to parse 
	pr.ast = new ParenListExpr(pe.ast);
    }

    match(rightParen) ;

    return pr ;
}

// Expr ::= '[' ExprList ']'  Original documentation
// Expr ::= '[' OptionalExprList ']'  Original implementation

// Expr ::= '[' OptionalExprList ']'  before adding TypeExpr to literals
//       |  '[' Expr '..' Expr ']'     

// Expr ::= '[' '<' TypeExpr '>' OptionalExprList ']'  after TypeExpr
//       |  '[' Expr '..' Expr ']'     

/**
 * @brief Parse bracket list expression
 *
 * @return ParseResult
 */
ParseResult Parser::parseBraketListExpr ( ) {
    ParseResult pr ;
    match ( leftSquare ) ;

    if ( attemptMatch(leftAngle) ) {

	ParseResult pt = parseTypeExpr() ;

	match(rightAngle) ;

	ParseResult poe = parseOptionalExprList() ; 

	pr.ast = new TypeArrayExpr(pt.ast, poe.ast);

    }
    else {
	ParseResult pe1 = parseExpr(0); 
	match(dotDot) ; 
	ParseResult pe2 = parseExpr(0); 

	pr.ast = new RangeExpr(pe1.ast, pe2.ast);

    }
    match(rightSquare) ;
    return pr ;
}

// Expr ::= variableName '(' OptionnalExprList ')'  DONE
/**
 * @brief Parse function call
 *
 * @param left Variable Name
 *
 * @return ParseResult
 */
ParseResult Parser::parseFunctionCall ( ParseResult left ) {
    // parser has already matched variableName on left.ast


    ParseResult pr ;

    match ( leftParen ) ;

    ParseResult poe = parseOptionalExprList() ; 

    match(rightParen) ;

    pr.ast = new FunctionCallExpr(left.ast, poe.ast);

    return pr ;
}


// Expr ::= Expr '+' Expr  DONE
/**
 * @brief Parse addition
 *
 * @param left expression to be added
 *
 * @return ParseResult
 */
ParseResult Parser::parseAddition ( ParseResult left ) {
    // parser has already matched left expression 
    ParseResult pr ;
    match ( plusSign ) ;

    ParseResult right = parseExpr( prevToken->lbp() ); 

    pr.ast = new BinaryOpsExpr(left.ast, "+", right.ast);
    return pr ;
}

// Expr ::= Expr '*' Expr  DONE
/**
 * @brief parseMultiplication
 *
 * @param left expression to be multiplied by
 *
 * @return ParseResult
 */
ParseResult Parser::parseMultiplication ( ParseResult left ) {
    // parser has already matched left expression 

    ParseResult pr ;

    match ( star ) ;

    ParseResult right = parseExpr( prevToken->lbp() ); 

    pr.ast = new BinaryOpsExpr(left.ast, "*", right.ast);

    return pr ;
}
// Expr ::= Expr '-' Expr  DONE
/**
 * @brief Parse subtraction expression
 *
 * @param left left expression to be subtracted from
 *
 * @return ParseResult
 */
ParseResult Parser::parseSubtraction ( ParseResult left ) {
    // parser has already matched left expression 

    ParseResult pr ;

    match ( dash ) ;

    ParseResult right = parseExpr( prevToken->lbp() ); 

    pr.ast = new BinaryOpsExpr(left.ast, "-", right.ast);

    return pr ;
}
// Expr ::= Expr '/' Expr  DONE
/**
 * @brief Parse division expression
 *
 * @param left the left input the division equation
 *
 * @return ParseResult
 */
ParseResult Parser::parseDivision ( ParseResult left ) {
    // parser has already matched left expression 
    ParseResult pr ;

    match ( forwardSlash ) ;

    ParseResult right = parseExpr( prevToken->lbp() ); 

    pr.ast = new BinaryOpsExpr(left.ast, "/", right.ast);

    return pr ;
}
// Expr ::= Expr '%' Expr  DONE
/**
 * @brief Parse modulus expression
 *
 * @param left the left input to modulus
 *
 * @return ParseResult
 */
ParseResult Parser::parseModulus ( ParseResult left ) {
    // parser has already matched left expression 

    ParseResult pr ;

    match ( percent ) ;

    ParseResult right = parseExpr( prevToken->lbp() ); 

    pr.ast = new BinaryOpsExpr(left.ast, "%", right.ast);

    return pr ;
}

// Expr ::= Expr '==' Expr  DONE
// Expr ::= Expr '<' Expr
// Expr ::= Expr '>' Expr
// Expr ::= Expr '>=' Expr
// Expr ::= Expr '<=' Expr
// Expr ::= Expr '!=' Expr
/* Notice that for relational operators we use just one parse
   function.  This shows another possible means for implementing
   expressions, as opposed to the method used for arithmetic
   expressions in which each operation has its own parse method.  It
   will depend on what we do in iteration 3 in building an abstract
   syntax tree to decide which method is better.
   */
/**
 * @brief Parse relation expression
 *
 * @param left expression you would like to compare to
 *
 * @return ParseResult
 */
ParseResult Parser::parseRelationalExpr ( ParseResult left ) {
    // parser has already matched left expression 


    ParseResult pr ;
    string lexeme = currToken->lexeme;

    nextToken( ) ;
    // just advance token, since examining it in parseExpr led 
    // to this method being called.


    ParseResult right = parseExpr( prevToken->lbp() ); 

    pr.ast = new BinaryOpsExpr(left.ast, lexeme, right.ast);
    return pr ;
}

// Expr ::= Expr ':' Expr  DONE
/**
 * @brief Parse the cons expression
 *
 * @param left the expression you would like to cons to
 *
 * @return ParseResult
 */
ParseResult Parser::parseConsExpr ( ParseResult left ) {
    // parser has already matched left expression 

    ParseResult pr ;

    match(colon) ; 

    ParseResult right = parseExpr( prevToken->lbp() ); 

    pr.ast = new BinaryOpsExpr(left.ast, ":", right.ast);

    return pr ;
}

// Expr ::= Expr '++' Expr  DONE
/**
 * @brief Parses append expression
 *
 * @param left the expression you would like to append to
 *
 * @return ParseResult
 */
ParseResult Parser::parseAppendExpr ( ParseResult left ) {
    // parser has already matched left expression 

    ParseResult pr ;

    match(plusPlus) ; 

    ParseResult right = parseExpr( prevToken->lbp() ); 

    pr.ast = new BinaryOpsExpr(left.ast, "++", right.ast);

    return pr ;
}
/*
// Expr ::= '[' Expr '..' Expr ']'  DONE
ParseResult Parser::parseDotDotExpr ( ParseResult left ) {
// parser has already matched left expression 
Expr *e1 = dynamic_cast<Expr *>(left.ast) ;
if ( ! e1 ) throw ( (string) "Bad cast of first Expr in ListRange" ) ;

ParseResult pr ;

match(dotDot) ; 

ParseResult prExpr = parseExpr( prevToken->lbp() ); 

Expr *e2 = dynamic_cast<Expr *>(prExpr.ast) ;
if ( ! e2 ) throw ( (string) "Bad cast of second Expr in ListRange" ) ;
//    throw ((string) "IN LIST RANGE");
pr.ast = new ListRange (e1, e2) ;
return pr ;
}
*/

// Expr ::= 'let' DeclList 'in' Expr 'end'  DONE
/**
 * @brief parses let expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parseLetExpr ( ) {
    ParseResult pr ;
    match(letKwd) ; 

    ParseResult pdl = parseDeclList() ;

    match(inKwd) ; 

    ParseResult pe = parseExpr(0); 

    match(endKwd) ; 

    pr.ast = new LetExpr(pdl.ast, pe.ast);

    return pr ;
}

// Expr ::= 'if' Expr 'then' Expr 'else' Expr  DONE
/**
 * @brief Parses if/then/else expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parseIfThenElse ( ) {
    ParseResult pr ;
    match(ifKwd) ;

    ParseResult pe1 = parseExpr(0) ;

    match(thenKwd) ;

    ParseResult pe2 = parseExpr(0) ;

    match(elseKwd);

    ParseResult pe3 = parseExpr(0) ;

    pr.ast = new IfThenElseExpr(pe1.ast, pe2.ast, pe3.ast);

    return pr ;
}

// Expr ::= 'print' '(' Expr ')'  DONE
/**
 * @brief Parses print expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parsePrintExpr ( ) {
    ParseResult pr ;
    match(printKwd) ;
    match(leftParen) ;

    ParseResult pe = parseExpr(0) ;

    match(rightParen) ;

    pr.ast = new PrintExpr(pe.ast);

    return pr ;
}

// Expr ::= 'write' '(' Expr, Expr ')'  
/**
 * @brief Parses write expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parseWriteExpr ( ) {
    ParseResult pr ;
    match(writeKwd) ;

    match(leftParen) ;

    ParseResult pe1 = parseExpr(0) ;

    match(comma) ;

    ParseResult pe2 = parseExpr(0) ;

    match(rightParen) ;

    pr.ast = new WriteExpr(pe1.ast, pe2.ast);

    return pr ;
}

// Expr ::= 'read' '<' TypeExpr '>' '(' Expr ')'
/**
 * @brief Parses read expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parseReadExpr ( ) {
    ParseResult pr ;
    match(readKwd) ;

    match(leftAngle) ;

    ParseResult pt = parseTypeExpr() ;

    match(rightAngle) ;
    match(leftParen) ;

    ParseResult pe = parseExpr(0) ;

    match(rightParen) ;

    pr.ast = new ReadExpr(pt.ast, pe.ast);

    return pr ;
}

// Expr ::= 'head' '(' Expr ')'
/**
 * @brief Parses head expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parseHeadExpr ( ) {
    ParseResult pr ;
    match(headKwd) ;
    match(leftParen) ;

    ParseResult pe = parseExpr(0) ;

    match(rightParen) ;

    pr.ast = new HeadExpr(pe.ast);

    return pr ;
}

// Expr ::= 'tail' '(' Expr ')'
/**
 * @brief Parses tail expressions
 *
 * @return Parse Result
 */
ParseResult Parser::parseTailExpr ( ) {
    ParseResult pr ;
    match(tailKwd) ;
    match(leftParen) ;

    ParseResult pe = parseExpr(0) ;

    match(rightParen) ;

    pr.ast = new TailExpr(pe.ast);

    return pr ;
}

// Expr ::= 'null' '(' Expr ')'
/**
 * @brief Parses null expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parseNullExpr ( ) {
    ParseResult pr ;
    match(nullKwd) ;
    match(leftParen) ;

    ParseResult pe = parseExpr(0) ;

    match(rightParen) ;

    pr.ast = new NullExpr(pe.ast);

    return pr ;
}

// Expr ::= 'map' '(' Expr ',' Expr ')'
/**
 * @brief Parses map expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parseMapExpr ( ) {
    ParseResult pr ;

    match(mapKwd) ;
    match(leftParen) ;

    ParseResult pe1 = parseExpr(0) ;

    match(comma) ;

    ParseResult pe2 = parseExpr(0) ;

    match(rightParen) ;

    pr.ast = new MapExpr(pe1.ast, pe2.ast);

    return pr ;
}

// Expr ::= 'filter' '(' Expr ',' Expr ')'
/**
 * @brief Parses filter expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parseFilterExpr ( ) {
    ParseResult pr ;

    match(filterKwd) ;
    match(leftParen) ;

    ParseResult pe1 = parseExpr(0) ;

    match(comma) ;

    ParseResult pe2 = parseExpr(0) ;

    match(rightParen) ;

    pr.ast = new FilterExpr(pe1.ast, pe2.ast);

    return pr ;
}

// Expr ::= 'fold' '(' Expr ',' Expr ',' Expr ')'
/**
 * @brief Parses Fold Expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parseFoldExpr ( ) {
    ParseResult pr ;

    match(foldKwd) ;
    match(leftParen) ;

    ParseResult pe1 = parseExpr(0) ;

    match(comma) ;

    ParseResult pe2 = parseExpr(0) ;

    match(comma) ;

    ParseResult pe3 = parseExpr(0) ;

    match(rightParen) ;

    pr.ast = new FoldExpr(pe1.ast, pe2.ast, pe3.ast);

    return pr ;
}

// Expr ::= 'zip' '(' Expr ',' Expr ')'
/**
 * @brief parses zip expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parseZipExpr ( ) {
    ParseResult pr ;

    match(zipKwd) ;
    match(leftParen) ;

    ParseResult pe1 = parseExpr(0) ;

    match(comma) ;

    ParseResult pe2 = parseExpr(0) ;

    match(rightParen) ;

    pr.ast = new ZipExpr(pe1.ast, pe2.ast);

    return pr ;
}

// Expr ::= '\' TypeBindingsList 'arrow' Expr
/**
 * @brief Parses lambda expressions
 *
 * @return ParseResult
 */
ParseResult Parser::parseLambdaExpr ( ) {
    ParseResult pr ;
    match(backSlash) ;

    ParseResult ptbl = parseTypeBindingList() ;

    match(arrow) ;

    ParseResult pe = parseExpr(0) ;

    pr.ast = new SlashTBExpr(ptbl.ast, pe.ast);

    return pr ;
}

// Expr ::= tupleOp '(' Expr ')'
/**
 * @brief Parses the tupleOp
 *
 * @return ParseResult
 */
ParseResult Parser::parseProjectionExpr () {
    ParseResult pr ;

    match(tupleOp) ;
    ExtToken *op = prevToken ;

    match(leftParen) ;

    ParseResult pe = parseExpr(0) ;

    match(rightParen) ;

    pr.ast = new ProjectionExpr(op->lexeme, pe.ast);

    return pr ;
}


/**
 * @brief Helper function used by the parser.
 *
 * @param tt a terminal_t object
 */
void Parser::match (terminal_t tt) {
    if (! attemptMatch(tt)) {
	throw ( makeErrorMsgExpected ( tt ) ) ;
    }
}

/**
 * @brief test to see if the current terminal matches tt
 *
 * @param tt a termina_t object
 *
 * @return true if the current terminal matches tt otherwise false
 */
bool Parser::attemptMatch (terminal_t tt) {
    if (currToken->terminal == tt) { 
	nextToken() ;
	return true ;
    }
    return false ;
}

/**
 * @brief check if the next terminal is tt
 *
 * @param tt a termina_t object
 *
 * @return bool true if the next terminal is tt otherwise false
 */
bool Parser::nextIs (terminal_t tt) {
    return currToken->terminal == tt ;
}

/**
 * @brief gets the next token
 */
void Parser::nextToken () {
    if (currToken->terminal == endOfFile && currToken->next == NULL) {
	prevToken = currToken ;
    } else if (currToken->terminal != endOfFile && currToken->next == NULL) {
	throw ( makeErrorMsg ( "Error: tokens end with endOfFile" ) ) ;
    } else {
	prevToken = currToken ;
	currToken = currToken->next ;
    }
}

/**
 * @brief Returns a description of the terminal
 *
 * @param terminal terminal_t object
 *
 * @return string a description of terminal
 */
string Parser::terminalDescription ( terminal_t terminal ) {
    Token *dummyToken = new Token ("",terminal, NULL) ;
    ExtToken *dummyExtToken = extendToken (this, dummyToken) ;
    string s = dummyExtToken->description() ;
    delete dummyToken ;
    delete dummyExtToken ;
    return s ;
}

/**
 * @brief Creates an expected error message
 *
 * @param terminal a terminal_t object
 *
 * @return string error message
 */
string Parser::makeErrorMsgExpected ( terminal_t terminal ) {
    string s = (string) "Expected " + terminalDescription (terminal) +
	" but found " + currToken->description() ;
    return s ;
}

/**
 * @brief Generates an error message from a terminal_t object
 *
 * @param terminal a terminal_t object
 *
 * @return string error message
 */
string Parser::makeErrorMsg ( terminal_t terminal ) {
    string s = "Unexpected symbol " + terminalDescription (terminal) ;
    return s ;
}

/**
 * @brief Generates error messages
 *
 * @param msg the message you want to turn into an error msg
 *
 * @return string returns an error message string
 */
string Parser::makeErrorMsg ( const char *msg ) {
    return msg ;
}

