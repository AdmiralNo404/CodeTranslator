#ifndef Node_H
#define Node_H

#include <string>
#include <iostream> 
#include <list>
#include <assert.h>

#include "scanner.h"

//$ID$

/**
 * @file AST.h
 * @author Yanbang Liu
 * @author Isaac Martin
 * @author Trevor Riles
 * 
 * @brief This file lays out the formats for all of our basic AST classes.
 * */
// Node
/*! 
 * 		Pure virtual unparse method necesitates a definition for it in all
 * 		subclasses.
 * @brief Node: Abstract class from which all AST classes inherit. <br>
 */
class Node {
public:
    virtual std::string unparse ( )=0;
    virtual std::string cppCode ( ){return NULL;};
} ;

//Expr
/*! 
 * 	@brief Expr: The base class for all Expr derivations. 
 */
class Expr : public Node {
	public:
		virtual std::string unparse(){return NULL;}
		virtual std::string cppCode(){return NULL;}
		Expr(){}
		~Expr(){}
};

//VariableName
/*! 
 * 		Expr ::= variableName 
 * @brief VariableName: Expr subclass designed to hold variable names as distinct from strings.  <br>

 */
class VariableName : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		VariableName(std::string input);
		~VariableName(){}
	private:
		std::string name;
};

//IntConst
/*! 
 * 		Expr ::= intConst 
 * @brief IntConst: Expr subclass holding integer literals.
 */
class IntConst : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		IntConst(std::string input);
		~IntConst(){}
	private:
		std::string val;
};

//FloatConst
/*! 
 * 		Expr ::= floatConst 
 * @brief FloatConst: Expr subclass that holds float literals.<br>
 */
class FloatConst : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		FloatConst(std::string input);
		~FloatConst(){}
	private:
		std::string val;
};

//StringConst
/*! 
 * 		Expr ::= stringConst 
 * @brief StringConst: Expr subclass that holds string literals.<br>
 */
class StringConst : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		StringConst(std::string input);
		~StringConst(){}
	private:
		std::string val;
};

//BooleanConst
/*! 
 * 		Expr ::= trueKwd <br>
		Expr ::= falseKwd <br>
* @brief BooleanConst: Expr subclass that holds boolean literals.<br>
 */
class BooleanConst : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		BooleanConst(std::string input);
		~BooleanConst(){}
	private:
		std::string val;
};

//TypeExpr
/*! 
 * 		TypeExpr ::= 'Integer' <br>
		TypeExpr ::= 'Float' <br>
		TypeExpr ::= 'String' <br>
		TypeExpr ::= 'Boolean' <br>
		TypeExpr ::= '[' TypeExpr ']' <br>
		TypeExpr ::= '(' TypeBindingList ')' '->' TypeExpr <br>
		TypeExpr ::= '(' TypeExprList ')'  <br>
		* @brief TypeExpr: Base class covering all TypeExpr derivations.<br>
 */
class TypeExpr : public Node {
	public:
		virtual std::string unparse(){return NULL;}
		virtual std::string cppCode(){return NULL;}
		~TypeExpr(){}
};

//Decl
/*! 
 * 		Decl ::= variableName '::' TypeExpr '=' Expr ';'
 * @brief Decl: Class which represents the Decl non-terminal in the kix grammar.<br>
 */
class Decl : public Node {
	public:
		std::string unparse ();
		std::string cppCode();
		Decl(Node*, Node*, Node*);
		~Decl(){}
	private:
		VariableName* varName;
		TypeExpr* texpr;
		Expr* expr;
};

//DeclList
/*! 
 * 		DeclList ::= Decl <br>
 *		DeclList ::= Decl DeclList<br>
 * @brief DeclList: Class which is used to build a list of Decl objects. <br>
 */
class DeclList : public Node {
	public:
		std::string unparse ();
		std::string cppCode();
		DeclList(Node*);
		DeclList(Node*, Node*);
		~DeclList(){}
	private:
		Decl* decl;
		DeclList* lst;
};

//Program
/*! 
 * 		Program ::= DeclList<br>
 * @brief Program: Class corresponding to the Program non-terminal.  This is the root node of every concrete syntax tree. 
 */
class Program : public Node {
	public:
		std::string unparse ();
		std::string cppCode();
		Program(Node*);
		~Program(){}
	private:
		DeclList* lst;
} ;

//TypeBinding
/*!	
 * 		TypeBinding ::= variableName '::' TypeExpr<br>
 * @brief TypeBinding: Class associating a variableName with a TypeExpr<br>
 */
class TypeBinding : public Node {
	public:
		std::string unparse();
		std::string cppCode(bool, bool, VariableName*);
		TypeBinding(Node*, Node*);
		~TypeBinding(){}
	private:
		VariableName* varName;
		TypeExpr* texpr;
};

//TypeBindingList
/*! 
 * 		TypeBindingList ::= TypeBinding<br>
 *		TypeBindingList ::= TypeBinding ',' TypeBindingList<br>
 * @brief TypeBindingList: Class used to build a list of multiple TypeBinding statements.<br>
 */
class TypeBindingList : public Node {
	public:
		std::string unparse();
		std::string cppCode(bool, VariableName*);
		TypeBindingList(Node*);
		TypeBindingList(Node*, Node*);
		~TypeBindingList(){}
	private:
		TypeBinding* tbinding;
		TypeBindingList* tblst;
};

//TypeExprList
/*! 
 * 		TypeExprList ::= TypeExpr<br>
 * 		TypeExprList ::= TypeExpr ',' TypeExprList<br>
 * @brief TypeExprList: Represents a list of TypeExpr statements.<br>
 */
class TypeExprList : public Node {
	public:
		std::string unparse ();
		std::string cppCode();
		TypeExprList(Node*);
		TypeExprList(Node*, Node*);
		~TypeExprList(){}
	private:
		TypeExpr* texpr;
		TypeExprList* texprlst;
};

//TypeExprInt
/*! 
 * 		TypeExpr ::= 'Integer'<br>
 * @brief TypeExprInt: TypeExpr subclass corresponding to the 'Integer' terminal.<br>
 */
class TypeExprInt : public TypeExpr {
	public:
		std::string unparse ();
		std::string cppCode();
		~TypeExprInt(){}
};

//TypeExprFlt
/*! 
 * 		TypeExpr ::= 'Float'<br>
 * @brief TypeExprFlt: TypeExpr subclass corresponding to the 'Float' terminal.<br>
 */
class TypeExprFlt : public TypeExpr {
	public:
		std::string unparse ();
		std::string cppCode();
		~TypeExprFlt(){}
};

//TypeExprStr
/*! 
 * 		TypeExpr ::= 'String'<br>
 * @brief TypeExprStr: TypeExpr subclass corresponding to the 'String' terminal.<br>
 */
class TypeExprStr : public TypeExpr {
	public:
		std::string unparse ();
		std::string cppCode();
		~TypeExprStr(){}
};

//TypeExprBool
/*! 
		TypeExpr ::= 'Boolean' <br>
* @brief TypeExprBool: TypeExpr subclass corresponding to the 'Boolean' terminal.<br>
*/
class TypeExprBool : public TypeExpr {
	public:
		std::string unparse ();
		std::string cppCode();
		~TypeExprBool(){}
};

//TypeExprSqBracket
/*! 
 * 		TypeExpr ::= '[' TypeExpr ']'<br>
 * @brief TypeExprSqBracket: TypeExpr subclass holding a TypeExpr in square brackets.<br>
 */
class TypeExprSqBracket : public TypeExpr {
	public:
		std::string unparse ();
		std::string cppCode();
		TypeExprSqBracket(Node*);
		~TypeExprSqBracket(){}
	private:
		TypeExpr* texpr;
};

//TypeExprPArr
/*! 
 * 		TypeExpr ::= '(' TypeBindingList ')' '->' TypeExpr <br>
 * @brief TypeExprPArr: TypeExpr subclass for the following derivation:<br>
 */
class TypeExprPArr : public TypeExpr {
	public:
		std::string unparse ();
		std::string cppCode(VariableName*);
		TypeExprPArr(Node*, Node*);
		~TypeExprPArr(){}
	private:
		TypeBindingList* tblst;
		TypeExpr* texpr;
};

//TypeExprParen
/*! 
 * 		TypeExpr ::= '(' TypeExprList ')'  <br>
 * @brief TypeExprParen: TypeExpr subclass holding a TypeExprList in parentheses<br>
 */
class TypeExprParen : public TypeExpr {
	public:
		std::string unparse ();
		std::string cppCode();
		TypeExprParen(Node*);
		~TypeExprParen(){}
	private:
		TypeExprList* texprlst;
};

//ExprList
/*! 
 * 		TypeExprList ::= TypeExpr<br>
 *		TypeExprList ::= TypeExpr ',' TypeExprList<br>
 * @brief ExprList: Class used to build a list of Expr objects.<br>
 */
class ExprList : public Node {
	public:
		std::string unparse();
		std::string cppCode(bool);
		ExprList(Node*);
		ExprList(Node*, Node*);
		~ExprList(){}
	private:
		Expr* expr;
		ExprList* exprlst;
};

//OptionalExprList
/*! 
 * 		OptionalExprList ::= <<empty>><br>
 *		OptionalExprList ::= ExprList<br>
 * @brief OptionalExprList: A variant of ExprList which may or may not have any Expr statements.<br>
 */
class OptionalExprList : public Node {
	public:
		std::string unparse();
		std::string cppCode(bool);
		OptionalExprList();
		OptionalExprList(Node*);
		~OptionalExprList(){}
	private:
		bool exists;
		ExprList* exprlst;
};

//BinaryOpsExpr
/*! 
 		Expr ::= Expr '+' Expr  <br>
		Expr ::= Expr '*' Expr  <br>
		Expr ::= Expr '-' Expr  <br>
		Expr ::= Expr '/' Expr  <br>
		Expr ::= Expr '%' Expr  <br>
		Expr ::= Expr '==' Expr  <br>
		Expr ::= Expr '<' Expr<br>
		Expr ::= Expr '>' Expr<br>
		Expr ::= Expr '>=' Expr<br>
		Expr ::= Expr '<=' Expr<br>
		Expr ::= Expr '!=' Expr<br>
		Expr ::= Expr ':' Expr  <br>
		Expr ::= Expr '++' Expr   <br>
* @brief BinaryOpsExpr: A broad subclass of Expr designed to hold all binary operations between pairs of Expr statements. <br>
 */
class BinaryOpsExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		BinaryOpsExpr(Node*, std::string, Node*);
		~BinaryOpsExpr(){}
	private:
		Expr *left, *right;
		std::string op;
};

//LetExpr
/*! 
 * 		Expr ::= 'let' DeclList 'in' Expr 'end' 
 * @brief LetExpr: Subclass of Expr covering 'let' expressions in the KIX language.<br>
 */
class LetExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		LetExpr(Node*, Node*);
		~LetExpr(){}
	private:
		DeclList* decls;
		Expr* expr;
};

//IfThenElseExpr
/*! 
 * 		Expr ::= 'if' Expr 'then' Expr 'else' Expr  
 * @brief IfThenElseExpr: Subclass of Expr covering 'if' expressions in KIX.<br>
 */
class IfThenElseExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		IfThenElseExpr(Node*, Node*, Node*);
		~IfThenElseExpr(){}
	private:
		Expr *cond, *then, *els;
};

//ParenListExpr
/*!	
 * 		Expr ::= '(' Expr ')'  <br>
 *		Expr ::= '(' Expr ',' ExprList ')'
 * @brief ParenListExpr: Expr subclass covering the following derivations:<br>
 */
class ParenListExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		ParenListExpr(Node*);
		ParenListExpr(Node*, Node*);
		~ParenListExpr(){}
	private:
		Expr* expr;
		ExprList* exprlst;
};

//TypeArrayExpr
/*! 
 * 		Expr ::= '[' '<' TypeExpr '>' OptionalExprList ']'
 * @brief TypeArrayExpr: Expr subclass covering the following derviation: <br>
 */
class TypeArrayExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		TypeArrayExpr(Node*, Node*);
		~TypeArrayExpr(){}
	private:
		TypeExpr* type;
		OptionalExprList* list;
};

//RangeExpr
/*!
 * 		Expr ::=  '[' Expr '..' Expr ']' 
 * @brief RageExpr: Expr subclass defining an expression of the range between two Expr statements.<br>    
 */
class RangeExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		RangeExpr(Node*, Node*);
		~RangeExpr(){}
	private:
		Expr *left, *right;
};

//FunctionCallExpr
/*!
 * 		Expr ::= variableName '(' OptionnalExprList ')' 
 * @brief FunctionCallExpr: Expr subclass handling a function call statement: <br> 
 */
class FunctionCallExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		FunctionCallExpr(Node*, Node*);
		~FunctionCallExpr(){}
	private:
		VariableName* varName;
		OptionalExprList* list;
};

//PrintExpr
/*!
 * 		Expr ::= 'print' '(' Expr ')'  
 * @brief PrintExpr: Expr subclass handling print statements: <br>
 */
class PrintExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		PrintExpr(Node*);
		~PrintExpr(){}
		//void print();
	private:
		Expr* expr;
};

//WriteExpr
/*!
 * 		Expr ::= 'write' '(' Expr, Expr ')'  
 * @brief WriteExpr: Expr subclass handling write statements: <br>
 */
class WriteExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		WriteExpr(Node*, Node*);
		~WriteExpr(){}
		//void write();
	private:
		Expr *writer, *writee;
};

//ReadExpr
/*!
 * 		Expr ::= 'read' '<' TypeExpr '>' '(' Expr ')'
 * @brief ReadExpr: Expr subclass handling read statements: <br>
 */
class ReadExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		ReadExpr(Node*, Node*);
		~ReadExpr(){}
	private:
		TypeExpr* type;
		Expr* expr;
};

//HeadExpr
/*!
 * 		Expr ::= 'head' '(' Expr ')'
 * @brief HeadExpr: Expr subclass handling calls to head: <br>
 */
class HeadExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		HeadExpr(Node*);
		~HeadExpr(){}
	private:
		Expr* expr;
};

//TailExpr
/*!
 * 		Expr ::= 'tail' '(' Expr ')'
 * @brief TailExpr: Expr subclass handling calls to tail: <br>
 */
class TailExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		TailExpr(Node*);
		~TailExpr(){}
	private:
		Expr* expr;
};

//NullExpr
/*!
 * 		Expr ::= 'null' '(' Expr ')'
 * @brief NullExpr: Expr subclass handling null statements: <br>
 */
class NullExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		NullExpr(Node*);
		~NullExpr(){}
	private:
		Expr* expr;
};

//MapExpr
/*!
 * 		Expr ::= 'map' '(' Expr ',' Expr ')'
 * @brief MapExpr: Expr subclass handling map expressions: <br>
 */
class MapExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		MapExpr(Node*, Node*);
		~MapExpr(){}
	private:
		Expr *arg1, *arg2;
};

//FilterExpr
/*!
 * 		Expr ::= 'filter' '(' Expr ',' Expr ')'
 * @brief FilterExpr: Expr subclass handling filter expressions: <br>
 */
class FilterExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		FilterExpr(Node*, Node*);
		~FilterExpr(){}
	private:
		Expr *arg1, *arg2;
};

//FoldExpr
/*!
 * 		Expr ::= 'fold' '(' Expr ',' Expr ',' Expr ')'
 * @brief FoldExpr: Expr subclass handling fold expressions: <br>
 */
class FoldExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		FoldExpr(Node*, Node*, Node*);
		~FoldExpr(){}
	private:
		Expr *arg1, *arg2, *arg3;
};

//ZipExpr
/*!
 * 		Expr ::= 'zip' '(' Expr ',' Expr ')'
 * @brief ZipExpr: Expr subclass handling zip expressions: <br>
 */
class ZipExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		ZipExpr(Node*, Node*);
		~ZipExpr(){}
	private:
		Expr *arg1, *arg2;
};

//SlashTBExpr
/*! @brief SlashTBExpr: Expr subclass handling lambda expressions: <br>
 * 		Expr ::= '\' TypeBindingList '->' Expr
 */
class SlashTBExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		SlashTBExpr(Node*, Node*);
		~SlashTBExpr();
	private:
		TypeBindingList* tblist;
		Expr* expr;
};

//ProjectionExpr
/*! @brief ProjectionExpr: Expr subclass handling projection expressions: <br>
 * 		Expr ::= tupleOp '(' Expr ')'
 */
class ProjectionExpr : public Expr {
	public:
		std::string unparse();
		std::string cppCode();
		ProjectionExpr(std::string, Node*);
		~ProjectionExpr(){}
	private:
		std::string tupleop;
		Expr* expr;
};

#endif // Node_H
