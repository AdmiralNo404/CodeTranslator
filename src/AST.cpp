#include "AST.h"
#include "ExtToken.h"
#include <assert.h>
#include <sstream>

//Program
/**
 * Function that creates base program.
 *
 * @param [declList] _declList List of program delcarations
 * @return Program class object
 */
Program::Program(Node* _declList) {
	lst = dynamic_cast<DeclList*>(_declList);
}

/**
 * Unparse Program
 * @return unparse of subnodes formatted for printing
 */
std::string Program::unparse(){
	assert(lst != NULL);
	return lst->unparse();
}

/**
 * Translates Program to cpp code
 * @return cpp code of Program
 */
std::string Program::cppCode(){
	assert(lst != NULL);
	return (string) "#include \"../samples/common_header.h\"\n" +
			"using namespace std;\n" +
			lst->cppCode();
}

//DeclList
/**
 *  Creates a DeclList from a single Decl
 *
 * @param [Decl] _decl Pointer to a declaration node
 * @return DeclList List of declarations
 */
DeclList::DeclList(Node* _decl) {
	decl = dynamic_cast<Decl*>(_decl);
	lst = NULL;
}

/**
 * Unparse DeclList
 * @return unparse of subnodes formatted for printing
 */
std::string DeclList::unparse(){
	if(lst != NULL)
		return decl->unparse() + lst->unparse();
	else
		return decl->unparse();
}

/**
 *  Adds a new Decl node to an existing DeclList
 *
 * @param [Decl] _decl Pointer to a declaration node
 * @param [declList] _declList Pointer to a list of Declarations
 * @return DeclList List of declarations
 */
DeclList::DeclList(Node* _decl, Node* _declList) {
	decl = dynamic_cast<Decl*>(_decl);
	lst = dynamic_cast<DeclList*>(_declList);
}

/**
 * Translates DeclList to cpp code
 * @return cpp code of decl list
 */
std::string DeclList::cppCode(){
	if(lst != NULL)
		return decl->cppCode() + lst->cppCode();
	else
		return decl->cppCode();
}

//Decl
/**
 *  Create a new declaration
 *
 * @param [varName] _varName Pointer to varName node
 * @param [typeExpr] _typeExpr pointer to type expression node
 * @param [expr] _expr pointer to an expression node
 * @return Decl A declaration node
 */
Decl::Decl(Node* _varName, Node* _typeExpr, Node* _expr) {
	varName = dynamic_cast<VariableName*>(_varName);
	texpr = dynamic_cast<TypeExpr*>(_typeExpr);
	expr = dynamic_cast<Expr*>(_expr);
}

/**
 * Unparse Decl
 * @return unparse of subnodes formatted for printing
 */
std::string Decl::unparse(){
	return varName->unparse() + "::" + texpr->unparse() + "=" + expr->unparse() + ";";
}

/**
 * Translates Decl to cpp code
 * @return cpp code of decl
 */
std::string Decl::cppCode() {
	TypeExprPArr *t = dynamic_cast<TypeExprPArr*>(texpr);
	if (t) {
		return t->cppCode(varName) +
				"\treturn " + "(" + expr->cppCode() + ")" + ";" + "\n}\n";
	} else {
		return texpr->cppCode() + " " + varName->cppCode() + " = " + expr->cppCode() + ";\n";
	}
}

//TypeExprSqBracket
/**
 *  New Square Bracket Type Expression
 *
 * @param [typeExpr] _typeExpr pointer to type expression node
 * @return TypeExpr returns a new typeExpression
 */
TypeExprSqBracket::TypeExprSqBracket(Node* _typeExpr) {
	texpr = dynamic_cast<TypeExpr*>(_typeExpr);
}

/**
 * Unparse TypeExprSqBracket
 * @return unparse of subnodes formatted for printing
 */
std::string TypeExprSqBracket::unparse(){
	return "[" + texpr->unparse() + "]";
}

std::string TypeExprSqBracket::cppCode() {
	return " MyList<" + texpr->cppCode() + "> ";
}

//TypeExprPArr
/**
 *  New TypeExprPArr
 *
 * @param[typeBindingList] _TypeBindingList pointer to type typeBindingList node
 * @param[typeExpr] _typeExpr pointer to a typeExpression node
 * @return TypeExprPArr returns a new TypeExprPArr
 */
TypeExprPArr::TypeExprPArr(Node* _typeBindingList, Node* _typeExpr) {
	tblst = dynamic_cast<TypeBindingList*>(_typeBindingList);
	texpr = dynamic_cast<TypeExpr*>(_typeExpr);
}

/**
 * Unparse TypeExprPArr
 * @return unparse of subnodes formatted for printing
 */
std::string TypeExprPArr::unparse(){
	return "(" + tblst->unparse() + ")->" + texpr->unparse();
}

/**
 * Translates TypeExprPArr
 * @return cpp code of TypeExprPArr: TypeExpr VariableName(TypeBindingList)
 */
std::string TypeExprPArr::cppCode(VariableName* varName){
	return texpr->cppCode() + " " + varName->cppCode() + "(" + tblst->cppCode(true, varName);
}

//TypeExprParen
/**
 *  New TypeExprParen
 *
 * @param[typeExprList] _typeExprList pointer to type typeExprList node
 * @return TypeExprParen returns a new TypeExprParen
 */
TypeExprParen::TypeExprParen(Node* _typeExprList) {
	texprlst = dynamic_cast<TypeExprList*>(_typeExprList);
}

/**
 * Unparse TypeExprParen
 * @return unparse of subnodes formatted for printing
 */
std::string TypeExprParen::unparse(){
	return "(" + texprlst->unparse() + ")";
}

std::string TypeExprParen::cppCode() {
	return texprlst->cppCode();
}

//TypeExprList
/**
 *  New TypeExprList from single typeExpr
 *
 * @param[typeExpr] _typeExpr pointer to type typeExpr node
 * @return typeExprList returns a new TypeExprList
 */
TypeExprList::TypeExprList(Node* _typeExpr) {
	texpr = dynamic_cast<TypeExpr*>(_typeExpr);
	texprlst = NULL;
}

/**
 *  Add typeExpr to typeExprList
 *
 * @param[typeExpr] _typeExpr pointer to type typeExpr node
 * @param[typeExprList] _typeExprList pointer to list of typeExpr's
 * @return typeExprList returns a mutated TypeExprList
 */
TypeExprList::TypeExprList(Node* _typeExpr, Node* _typeExprList) {
	texpr = dynamic_cast<TypeExpr*>(_typeExpr);
	texprlst = dynamic_cast<TypeExprList*>(_typeExprList);
}

/**
 * Unparse TypeExprList
 * @return unparse of subnodes formatted for printing
 */
std::string TypeExprList::unparse(){
	if(texprlst != NULL)
		return texpr->unparse() + "," + texprlst->unparse();
	else
		return texpr->unparse();
}

std::string TypeExprList::cppCode() {
	int count = 0;
	TypeExprList* current = this;
	std::string buildString = "< ";
	while(true){
		if(count++>0)
			buildString += ", ";
		buildString += " " + current->texpr->cppCode();
		if(current->texprlst == NULL)
			break;
		current = current->texprlst;
	}
	buildString += " > ";
	if(count == 2)
		buildString = "pair" + buildString;
	return buildString;
	//return "/* Need TypeExprList */";
}

//TypeBindingList
/**
 *  New typeBindingList
 *
 * @param[typeBinding] _typeBinding pointer to type typeBinding node
 * @return typeBindingList returns a new typeBindingList
 */
TypeBindingList::TypeBindingList(Node* _typeBinding) {
	tbinding = dynamic_cast<TypeBinding*>(_typeBinding);
	tblst = NULL;
}

/**
 *  Add typeBinding to existing typeBindingList
 *
 * @param[typeBinding] _typeBinding pointer to type typeBinding node
 * @param[typeBindingList] _typeBindingList pointer to type typeBindingList node
 * @return typeBindingList returns a mutated typeBindingList
 */
TypeBindingList::TypeBindingList(Node* _typeBinding, Node* _typeBindingList) {
	tbinding = dynamic_cast<TypeBinding*>(_typeBinding);
	tblst = dynamic_cast<TypeBindingList*>(_typeBindingList);
}

/**
 * Unparse TypeBindingList
 * @return unparse of subnodes formatted for printing
 */
std::string TypeBindingList::unparse(){
	if(tblst != NULL)
		return tbinding->unparse() + "," + tblst->unparse();
	else
		return tbinding->unparse();
}

/**
 * Translates TypeBindingList
 * @return cpp code of TypeBindingList: TypeBinding, TypeBindingList
 */
std::string TypeBindingList::cppCode(bool fromPArr, VariableName* varName){
	if(tblst != NULL)
		return tbinding->cppCode(fromPArr, false, varName) + "," + tblst->cppCode(fromPArr, varName);
	else
		return tbinding->cppCode(fromPArr, true, varName);
}

//TypeBinding
/**
 * Create a new typeBinding node
 *
 * @param[varName] _varName type variable name
 * @param[texpr] _typeExpr type expression to be assigned to variable
 * @return TypeBinding return a new typbinding with the texpr bound to varName
 */
TypeBinding::TypeBinding(Node* _varName, Node* _typeExpr) {
	varName = dynamic_cast<VariableName*>(_varName);
	texpr = dynamic_cast<TypeExpr*>(_typeExpr);
}

/**
 * Unparse TypeBinding
 * @return unparse of subnodes formatted for printing
 */
std::string TypeBinding::unparse(){
	return varName->unparse() + "::" + texpr->unparse();
}

/**
 * Translates TypeBinding
 * @return cpp code of TypeBinding: TypeExpr VariableName
 */
std::string TypeBinding::cppCode(bool fromPArr, bool list_is_null, VariableName* var){
	TypeExprSqBracket* sq = dynamic_cast<TypeExprSqBracket*>(texpr);
	if (sq) {
		if (fromPArr) {
			if (var->cppCode() == "main") {
				return (string) " int argc, char** argv ) {\n" +
						"\tMyList<string> " + varName->cppCode() + " = mkArgs(argc, argv) ;\n";
			} else {
				return sq->cppCode() + varName->cppCode() + " ) {\n";
			}
		} else {
			return texpr->cppCode() + varName->cppCode();
		}
	} else {
		if (fromPArr && list_is_null) {
			return texpr->cppCode() + " " + varName->cppCode() + " ) {\n";
		} else {
			return texpr->cppCode() + " " + varName->cppCode();
		}
	}
}

//OptionalExprList
/**
 * Create a new Optional expression list
 * @return OptionalExprList an empyt optional expression list
 */
OptionalExprList::OptionalExprList() {
	exists = false;
	exprlst = NULL;
}

/**
 * Create a new Optional expression list
 * @param [_exprList] _exprList to ExprList node
 * @return OptionalExprList a new optional expr list with an existing ExprList
 */
OptionalExprList::OptionalExprList(Node* _exprList) {
	exists = true;
	exprlst = dynamic_cast<ExprList*>(_exprList);
}

/**
 * Unparse OptionalExprList
 * @return unparse of subnodes formatted for printing
 */
std::string OptionalExprList::unparse(){
	if(exists)
		return exprlst->unparse();
	else
		return "";
}

std::string OptionalExprList::cppCode(bool fromArrayExpr) {
	if (exists)
		return exprlst->cppCode(fromArrayExpr);
	else
		return "";
}

//ExprList
/**
 * Create a new ExprList
 * @param [_expr] _expr to Expr node
 * @return ExprList a new expression list with a single element
 */
ExprList::ExprList(Node* _expr) {
	expr = dynamic_cast<Expr*>(_expr);
	exprlst = NULL;
}

/**
 * Create a new ExprList
 * @param [_expr] _expr to Expr node
 * @param [_exprList] to ExprList node
 * @return ExprList a new expression list
 */
ExprList::ExprList(Node* _expr, Node* _exprList) {
	expr = dynamic_cast<Expr*>(_expr);
	exprlst = dynamic_cast<ExprList*>(_exprList);
}

/**
 * Unparse ExprList
 * @return unparse of subnodes formatted for printing
 */
std::string ExprList::unparse(){	
	if(exprlst == NULL)
		return expr->unparse();
	else
		return expr->unparse() + "," + exprlst->unparse();
}

std::string ExprList::cppCode(bool fromArrayExpr) {
	if (fromArrayExpr) {
		if(exprlst == NULL)
			return "\t\ttemp.push_back(" + expr->cppCode() + ") ;\n";
		else
			return "\t\ttemp.push_back(" + expr->cppCode() + ") ;\n" + exprlst->cppCode(true);
	} else {
		if(exprlst == NULL)
			return expr->cppCode();
		else
			return expr->cppCode() + " , " + exprlst->cppCode(false);
	}
}

//VariableName
/**
 * Create a new VariableName
 * @param [input] input to variable name
 * @return VariableName a variable name node with its name set to input
 */
VariableName::VariableName(std::string input) {
	name = input;
}

/**
 * Unparse VariableName
 * @return name
 */
std::string VariableName::unparse(){
	return name;
}

/**
 * Translate VariableName to cpp code
 * @return name
 */
std::string VariableName::cppCode() {
	return name;
}

//IntConst
/**
 * Create a new IntConst
 * @param [input] input to val
 * @return new IntConst with input stored in string format (for ease of parsing)
 */
IntConst::IntConst(std::string input) {
	val = input;
}

/**
 * Unparse IntConst
 * @return string form of val
 */
std::string IntConst::unparse(){
	return val;
}

/**
 * Translate IntConst to cpp code
 * @return val
 */
std::string IntConst::cppCode() {
	return val;
}

//FloatConst
/**
 * Create a new FloatConst
 * @param [input] input to val
 * @return new FloatConst with input stored in string format (for ease of parsing)
 */
FloatConst::FloatConst(std::string input) {
	val = input;
}

/**
 * Unparse FloatConst
 * @return string form of val
 */
std::string FloatConst::unparse(){
	return val;
}

std::string FloatConst::cppCode() {
	return val;
}

//StringConst
/**
 * Create a new StringConst
 * @param [input] input to val
 * @return new StringConst with input stored in string format (for ease of parsing)
 */
StringConst::StringConst(std::string input) {
	val = input;
}

/**
 * Unparse StringConst
 * @return string form of val
 */
std::string StringConst::unparse(){
	return val;
}

std::string StringConst::cppCode() {
	return val;
}

//BooleanConst
/**
 * Create a new BooleanConst
 * @param [input] input to val
 * @return new BooleanConst with input stored in string format (for ease of parsing)
 */
BooleanConst::BooleanConst(std::string input) {
	val = input;
}

/**
 * Unparse BooleanConst
 * @return string form of val
 */
std::string BooleanConst::unparse(){
	return val;
}

std::string BooleanConst::cppCode() {
	return val;
}

//ParenListExpr
/**
 * Create a new ParenListExpr
 * @param [_expr] _expr to Expr node
 * @return ParenListExpr with a single parenthesized expression
 */
ParenListExpr::ParenListExpr(Node* _expr) {
	expr = dynamic_cast<Expr*>(_expr);
	exprlst = NULL;
}

/**
 * Create a new ParenListExpr
 * @param [_expr] _expr to Expr node
 * @param [_exprList] _exprList to ExprList node
 * @return ParenListExpr a list of Expressions in parentheses
 */
ParenListExpr::ParenListExpr(Node* _expr, Node* _exprList) {
	expr = dynamic_cast<Expr*>(_expr);
	exprlst = dynamic_cast<ExprList*>(_exprList);
}

/**
 * Unparse ParenListExpr
 * @return unparse of subnodes formatted for printing
 */
std::string ParenListExpr::unparse(){
	if (exprlst == NULL)
		return "(" + expr->unparse() + ")";
	else
		return "(" + expr->unparse() + "," + exprlst->unparse() + ")";
}

std::string ParenListExpr::cppCode() {
	if (exprlst == NULL)
		return  " (" + expr->cppCode() + ") ";
	return "/* Need ParenListExpr */";
}

//TypeArrayExpr
/**
 * Create a new TypeArrayExpr
 * @param [_typeExpr] _typeExpr to TypeExpr node
 * @param [_optionalExprList] _optionalExprList to OptionalExprList node
 * @return TypeArrayExpr a new node
 */
TypeArrayExpr::TypeArrayExpr(Node* _typeExpr, Node* _optionalExprList) {
	type = dynamic_cast<TypeExpr*>(_typeExpr);
	list = dynamic_cast<OptionalExprList*>(_optionalExprList);
}

/**
 * Unparse TypeArrayExpr
 * @return unparse of subnodes formatted for printing
 */
std::string TypeArrayExpr::unparse(){
	return "[<" + type->unparse() + ">" + list->unparse() + "]";
}

std::string TypeArrayExpr::cppCode() {
	return " ({ MyList<" + type->cppCode() + "> temp; " + list->cppCode(true) +
			" temp; }) ";
}

//RangeExpr
/**
 * Create a new RangeExpr
 * @param [_expr_left] _expr_left to Expr node
 * @param [_expr_right] _expr_right to Expr node
 * @return RangeExpr a new range expression 
 */
RangeExpr::RangeExpr(Node* _expr_left, Node* _expr_right) {
	left = dynamic_cast<Expr*>(_expr_left);
	right = dynamic_cast<Expr*>(_expr_right);
}

/**
 * Unparse RangeExpr
 * @return unparse of subnodes formatted for printing
 */
std::string RangeExpr::unparse(){
	return "[" + left->unparse() + ".." + right->unparse() + "]";
}

std::string RangeExpr::cppCode() {
	return (string) "({ MyList<int> temp(" + left->cppCode() +
			" , " + right->cppCode() + "); temp; }) ";
}

//FunctionCallExpr
/**
 * Create a new FunctionCallExpr
 * @param [_varname] _varName to VariableName node
 * @param [_optionalExprList] _optionalExprList to OptionalExprList node
 * @return new FunctionCallExpr
 */
FunctionCallExpr::FunctionCallExpr(Node* _varName, Node* _optionalExprList) {
	varName = dynamic_cast<VariableName*>(_varName);
	list = dynamic_cast<OptionalExprList*>(_optionalExprList);
}

/**
 * Unparse FunctionCallExpr
 * @return unparse of subnodes formatted for printing
 */
std::string FunctionCallExpr::unparse(){
	return varName->unparse() + "(" + list->unparse() + ")";
}

std::string FunctionCallExpr::cppCode() {
	return varName->cppCode() + "(" + list->cppCode(false) + ")";
}

//BinaryOpsExpr
/**
 * Create a new BinaryOpsExpr
 * @param [_expr_left] _expr_left to Expr node
 * @param [_op] _op to string
 * @param [_expr_right] _expr_right to Expr node
 * @return new BinaryOpsExpr
 */
BinaryOpsExpr::BinaryOpsExpr(Node* _expr_left, std::string _op, Node* _expr_right) {
	left = dynamic_cast<Expr*>(_expr_left);
	op = _op;
	right = dynamic_cast<Expr*>(_expr_right);
}

/**
 * Unparse BinaryOpsExpr
 * @return unparse of subnodes formatted for printing
 */
std::string BinaryOpsExpr::unparse(){
	return  left->unparse() + op +right->unparse();
}

/**
 * Translates BinaryOpsExpr
 * @return cpp code of BinaryOpsExpr: Expr op Expr
 */
std::string BinaryOpsExpr::cppCode(){
	if(op == ":")
	{
		return "( " + right->cppCode() + " ).cons(" + left->cppCode() + ") ";
	}
	return left->cppCode() + " " + op + " " + right->cppCode();
}

//LetExpr
/**
 * Create a new LetExpr
 * @param [_declList] _declList to new DeclList node
 * @param [_expr] _expr to new Expr node
 * @return new LetExpr node
 */
LetExpr::LetExpr(Node* _declList, Node* _expr) {
	decls = dynamic_cast<DeclList*>(_declList);
	expr = dynamic_cast<Expr*>(_expr);
}

/**
 * Unparse LetExpr
 * @return unparse of subnodes formatted for printing
 */
std::string LetExpr::unparse(){
	return "let " + decls->unparse() + " in " + expr->unparse() + " end ";
}

std::string LetExpr::cppCode() {
	return "{" + decls->cppCode() + "(" + expr->cppCode() + ") ; }";
}

//IfThenElseExpr
/**
 * Create a new IfThenElseExpr
 * @param [_cond]
 * @param [_then]
 * @param [_els]
 * @return new IfThenElseExpr
 */
IfThenElseExpr::IfThenElseExpr(Node* _cond, Node* _then, Node* _els) {
	cond = dynamic_cast<Expr*>(_cond);
	then = dynamic_cast<Expr*>(_then);
	els = dynamic_cast<Expr*>(_els); 
}

/**
 * Unparse IfThenElseExpr
 * @return unparse of subnodes formatted for printing
 */
std::string IfThenElseExpr::unparse(){
	return "if " + cond->unparse() + " then " + then->unparse() + " else " + els->unparse();
}

/**
 * Translates IfThenElseExpr
 * @return cpp code of if then else statement
 */
std::string IfThenElseExpr::cppCode(){
	return (string) "(" + cond->cppCode() + ")" + " ? " + "(" + then->cppCode() + ")" + " : " + "(" + els->cppCode() + ")";
}

//PrintExpr
/**
 * Create a new PrintExpr
 * @param [_expr]
 * @return new PrintExpr
 */
PrintExpr::PrintExpr(Node* _expr) {
	expr = dynamic_cast<Expr*>(_expr);
}

/**
 * Unparse PrintExpr
 * @return unparse of subnodes formatted for printing
 */
std::string PrintExpr::unparse(){
	return "print(" + expr->unparse() + ")";
}

std::string PrintExpr::cppCode() {
	return "({ cout << " + expr->cppCode() + " << endl ; cout.good() ? 0 : 1 ; })";
}

//WriteExpr
/**
 * Create a new WriteExpr
 * @param [_expr_writer]
 * @param [_expr_writee]
 * @return new WriteExpr node
 */
WriteExpr::WriteExpr(Node* _expr_writer, Node* _expr_writee) {
	writer = dynamic_cast<Expr*>(_expr_writer);
	writee = dynamic_cast<Expr*>(_expr_writee);
}

/**
 * Unparse WriteExpr
 * @return unparse of subnodes formatted for printing
 */
std::string WriteExpr::unparse(){
	return "write(" + writer->unparse() + "," + writee->unparse() + ")";
}

std::string WriteExpr::cppCode() {
	return "/* Need WriteExpr */";
}

//ReadExpr
/**
 * Create new ReadExpr
 * @param [_typeExpr]
 * @param [_expr]
 * @return new ReadExpr
 */
ReadExpr::ReadExpr(Node* _typeExpr, Node* _expr) {
	type = dynamic_cast<TypeExpr*>(_typeExpr);
	expr = dynamic_cast<Expr*>(_expr);
}

/**
 * Unparse ReadExpr
 * @return unparse of subnodes formatted for printing
 */
std::string ReadExpr::unparse(){
	return "read<" + type->unparse() + ">(" + expr->unparse() + ")";
}

std::string ReadExpr::cppCode() {
	return "({ " + type->cppCode() + " temp ;  ifstream inStream(" + expr->cppCode() + ") ; inStream >> temp ; temp ; }) ";
}

//HeadExpr
/**
 * Create new HeadExpr
 * @param [_expr]
 * @return new HeadExpr
 */
HeadExpr::HeadExpr(Node* _expr) {
	expr = dynamic_cast<Expr*>(_expr);
}

/**
 * Unparse HeadExpr
 * @return unparse of subnodes formatted for printing
 */
std::string HeadExpr::unparse(){
	return "head(" + expr->unparse() + ")";
}

std::string HeadExpr::cppCode() {
	return " " + expr->cppCode() + ".head() ";
}

//TailExpr
/**
 * Create new TailExpr
 * @param [_expr]
 * @return new TailExpr
 */
TailExpr::TailExpr(Node* _expr) {
	expr = dynamic_cast<Expr*>(_expr);
}

/**
 * Unparse TailExpr
 * @return unparse of subnodes formatted for printing
 */
std::string TailExpr::unparse(){
	return "tail(" + expr->unparse() + ")";
}

std::string TailExpr::cppCode() {
	return " " + expr->cppCode() + ".tail() ";
}

//NullExpr
/**
 * Create new NullExpr
 * @param [_expr]
 * @return new NullExpr
 */
NullExpr::NullExpr(Node* _expr) {
	expr = dynamic_cast<Expr*>(_expr);
}

/**
 * Unparse NullExpr
 * @return unparse of subnodes formatted for printing
 */
std::string NullExpr::unparse(){
	return "null(" + expr->unparse() + ")";
}

std::string NullExpr::cppCode() {
	return " " + expr->unparse() + ".null() ";
}

//MapExpr
/**
 * Create new MapExpr
 * @param [_expr1]
 * @param [_expr2]
 * @return new HeadExpr
 */
MapExpr::MapExpr(Node* _expr1, Node* _expr2) {
	arg1 = dynamic_cast<Expr*>(_expr1);
	arg2 = dynamic_cast<Expr*>(_expr2);
}

/**
 * Unparse MapExpr
 * @return unparse of subnodes formatted for printing
 */
std::string MapExpr::unparse(){
	return "map(" + arg1->unparse() + "," + arg2->unparse() + ")";
}

std::string MapExpr::cppCode() {
	return " ( " + arg2->cppCode() + ".map(" + arg1->cppCode() + ") ) ";
	//return "/* Need MapExpr */";
}

//FilterExpr
/**
 * Create new FilterExpr
 * @param [_expr1]
 * @param [_expr2]
 * @return new FilterExpr
 */
FilterExpr::FilterExpr(Node* _expr1, Node* _expr2) {
	arg1 = dynamic_cast<Expr*>(_expr1);
	arg2 = dynamic_cast<Expr*>(_expr2);
}

/**
 * Unparse FilterExpr
 * @return unparse of subnodes formatted for printing
 */
std::string FilterExpr::unparse(){
	std::string holder;
	return "filter(" + arg1->unparse() + "," + arg2->unparse() + ")";
}

std::string FilterExpr::cppCode() {
	return " ( " + arg2->cppCode() + ".filter(" + arg1->cppCode() + ") ) ";
	//return "/* Need FilterExpr */";
}

//FoldExpr
/**
 * Create new FoldExpr
 * @param [_expr1]
 * @param [_expr2]
 * @param [_expr3]
 * @return new FoldExpr
 */
FoldExpr::FoldExpr(Node* _expr1, Node* _expr2, Node* _expr3) {
	arg1 = dynamic_cast<Expr*>(_expr1);
	arg2 = dynamic_cast<Expr*>(_expr2);
	arg3 = dynamic_cast<Expr*>(_expr3);
}

/**
 * Unparse FoldExpr
 * @return unparse of subnodes formatted for printing
 */
std::string FoldExpr::unparse(){
	return "fold(" + arg1->unparse() + "," + arg2->unparse() + "," + arg3->unparse() + ")";
}

std::string FoldExpr::cppCode() {
	//return "/* Need FoldExpr */";
	return " " + arg3->cppCode() + ".fold(" + arg1->cppCode() + "," + arg2->cppCode() + ") ";
}

//ZipExpr
/**
 * Create new ZipExpr
 * @param [_expr1]
 * @param [_expr2]
 * @return new ZipExpr
 */
ZipExpr::ZipExpr(Node* _expr1, Node* _expr2) {
	arg1 = dynamic_cast<Expr*>(_expr1);
	arg2 = dynamic_cast<Expr*>(_expr2);
}

/**
 * Unparse ZipExpr
 * @return unparse of subnodes formatted for printing
 */
std::string ZipExpr::unparse(){
	return "zip(" + arg1->unparse() + "," + arg2->unparse() + ")";
}

std::string ZipExpr::cppCode() {
	//return "/* Need ZipExpr */";
	return "(" + arg1->cppCode() + ".zip(" + arg2->cppCode() + ") ) ";
}

//SlashTBExpr
/**
 * Create new SlashTBExpr
 * @param [_typeBindingList]
 * @param [_expr]
 * @return new SlashTBExpr
 */
SlashTBExpr::SlashTBExpr(Node* _typeBindingList, Node* _expr) {
	tblist = dynamic_cast<TypeBindingList*>(_typeBindingList);
	expr = dynamic_cast<Expr*>(_expr);
}

/**
 * Unparse SlashTBExpr
 * @return unparse of subnodes formatted for printing
 */
std::string SlashTBExpr::unparse(){
	return "\\" + tblist->unparse() + "->" + expr->unparse();
}

std::string SlashTBExpr::cppCode() {
	return "/* Need SlashTBExpr */";
}

//ProjectionExpr
/**
 * Create new ProjectionExpr
 * @param [_tupleOp]
 * @param [_expr]
 * @return new ProjectionExpr
 */
ProjectionExpr::ProjectionExpr(std::string _tupleOp, Node* _expr) {
	tupleop = _tupleOp;
	expr = dynamic_cast<Expr*>(_expr);
}

/**
 * Unparse ProjectionExpr
 * @return unparse of subnodes formatted for printing
 */
std::string ProjectionExpr::unparse(){
	return tupleop + '(' + expr->unparse() + ')';
}

std::string ProjectionExpr::cppCode() {
	return "/* Need ProjectionExpr (TupleOps) */";
}

//TypeExprInt
/**
 * Unparse TypeExprInt
 * @return 'Integer'
 */
std::string TypeExprInt::unparse(){
	return "Integer";
}

/**
 * Translates TypeExprInt
 * @return 'int'
 */
std::string TypeExprInt::cppCode(){
	return "int";
}

//TypeExprFlt
/**
 * Unparse TypeExprFlt
 * @return 'Float'
 */
std::string TypeExprFlt::unparse(){
	return "Float";
}

/**
 * Translates TypeExprFlt
 * @return 'float'
 */
std::string TypeExprFlt::cppCode(){
	return "float";
}

//TypeExprStr
/**
 * Unparse TypeExprStr
 * @return 'String'
 */
std::string TypeExprStr::unparse(){
	return "String";
}

/**
 * Translates TypeExprStr
 * @return 'string'
 */
std::string TypeExprStr::cppCode(){
	return "string";
}

//TypeExprBool
/**
 * Unparse typeExprBool
 * @return unparse of subnodes formatted for printing
 */
std::string TypeExprBool::unparse(){
	return "Boolean";
}

/**
 * Translates typeExprBool
 * @return 'bool'
 */
std::string TypeExprBool::cppCode(){
	return "bool";
}
