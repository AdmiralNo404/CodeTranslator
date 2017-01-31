#include <cxxtest/TestSuite.h>

#include "readInput.h"
#include "scanner.h"
#include "Parser.h"

using namespace std ;

class ParserTestSuite : public CxxTest::TestSuite 
{
	public:
		Scanner *s ;
		Parser *p ;
		void setUp ( ) {
			s = new Scanner() ;
			p = new Parser() ;
		}

		void tearDown() {
			delete s;
			delete p;
		}

	// your tests here!
		
	//VariableName Test
	void test_variable_name() {
		VariableName* name = new VariableName("a");
		TS_ASSERT_EQUALS(name->unparse(), "a");
	}
	
	//IntConst Test
	void test_int_const() {
		IntConst *i = new IntConst("1");
		TS_ASSERT_EQUALS(i->unparse(), "1");
	}
	
	//FloatConst Test
	void test_float_const() {
		FloatConst *f = new FloatConst("1.1");
		TS_ASSERT_EQUALS(f->unparse(), "1.1");
	}
	
	//StringConst Test
	void test_string_const() {
		StringConst *str = new StringConst("A Lannister always pays his debts.");
		TS_ASSERT_EQUALS(str->unparse(), "A Lannister always pays his debts.");
	}
	
	//BooleanConst Tests
	void test_bollean_const_true() {
		BooleanConst *bl = new BooleanConst("true");
		TS_ASSERT_EQUALS(bl->unparse(), "true");
	}
	
	void test_bollean_const_false() {
		BooleanConst *bl = new BooleanConst("false");
		TS_ASSERT_EQUALS(bl->unparse(), "false");
	}
		
	//TypeExprInt Tests
	void test_type_expr_int() {
		TypeExprInt *i = new TypeExprInt();
		TS_ASSERT_EQUALS(i->unparse(), "Integer");
	}
	
	//TypeExprFlt Tests
	void test_type_expr_flt() {
		TypeExprFlt *f = new TypeExprFlt();
		TS_ASSERT_EQUALS(f->unparse(), "Float");
	}
	
	//TypeExprStr Tests
	void test_type_expr_str() {
		TypeExprStr *s = new TypeExprStr();
		TS_ASSERT_EQUALS(s->unparse(), "String");
	}
	
	//TypeExprBool Tests
	void test_type_expr_bool() {
		TypeExprBool *b = new TypeExprBool();
		TS_ASSERT_EQUALS(b->unparse(), "Boolean");
	}
	
	//TypeExprSqBracket Tests
	//Utility Function
	TypeExprSqBracket* MakeTypeExprSqBracket() {
		TypeExprStr *s = new TypeExprStr();
		return new TypeExprSqBracket(s);
	}
	
	//Tests
	void test_type_expr_sq_bracket() {
		TypeExprSqBracket *sqb = MakeTypeExprSqBracket();
		TS_ASSERT_EQUALS(sqb->unparse(), "[String]");
	}
	
	//TypeBinding Tests
	//Utility Function
	TypeBinding* MakeTypeBinding(string n, TypeExpr* type) {
		VariableName* name = new VariableName(n);
		return new TypeBinding(name, type);
	}
	
	//Tests
	void test_type_binding() {
		TypeExprInt *i = new TypeExprInt();
		TypeBinding *tb = MakeTypeBinding("a", i);
		TS_ASSERT_EQUALS(tb->unparse(), "a::Integer");
	}
	
	//TypeBindingList Tests
	//Utility Function
	TypeBindingList* MakeTypeBindingList(string varName, TypeExpr* type) {
		TypeBinding *tb = MakeTypeBinding(varName, type);
		return new TypeBindingList(tb);
	}
	
	TypeBindingList* AppendTypeBindingList(string varName, TypeExpr* type, TypeBindingList* _tbl) {
		TypeBinding *tb = MakeTypeBinding(varName, type);
		return new TypeBindingList(tb, _tbl);
	}
	
	//Tests
	void test_type_binding_list_1() {
		TypeExprInt *i = new TypeExprInt();
		TypeBindingList *tbl = MakeTypeBindingList("a", i);
		TS_ASSERT_EQUALS(tbl->unparse(), "a::Integer");
	}
	
	void test_type_binding_list_2() {
		TypeExprInt *i = new TypeExprInt();
		TypeBindingList *tbl1 = MakeTypeBindingList("a", i);
		TypeExprFlt *f = new TypeExprFlt();		
		TypeBindingList *tbl2 = AppendTypeBindingList("b", f, tbl1);
		TS_ASSERT_EQUALS(tbl2->unparse(), "b::Float,a::Integer");
	}
	
	//TypeExprPArr Tests
	void test_type_expr_parr_1() {
		TypeExprInt *i = new TypeExprInt();
		TypeBindingList *tbl = MakeTypeBindingList("a", i);
		TypeExprStr *s = new TypeExprStr();
		TypeExprPArr *pa = new TypeExprPArr(tbl, s);
		TS_ASSERT_EQUALS(pa->unparse(), "(a::Integer)->String");
	}
	
	void test_type_expr_parr_2() {
		TypeExprInt *i = new TypeExprInt();
		TypeExprFlt *f = new TypeExprFlt();
		TypeBindingList *tbl1 = MakeTypeBindingList("a", i);
		TypeBindingList *tbl2 = AppendTypeBindingList("b", f, tbl1);
		TypeExprStr *s = new TypeExprStr();
		TypeExprPArr *pa = new TypeExprPArr(tbl2, s);
		TS_ASSERT_EQUALS(pa->unparse(), "(b::Float,a::Integer)->String");
	}
	
	//TypeExprList Tests
	//Tests
	void test_type_expr_list_1() {
		TypeExprInt *i = new TypeExprInt();
		TypeExprList *tel = new TypeExprList(i);
		TS_ASSERT_EQUALS(tel->unparse(), "Integer");
	}
	
	void test_type_expr_list_2() {
		TypeExprInt *i = new TypeExprInt();
		TypeExprStr *s = new TypeExprStr();
		TypeExprList *tel1 = new TypeExprList(i);
		TypeExprList *tel2 = new TypeExprList(s, tel1);
		TS_ASSERT_EQUALS(tel2->unparse(), "String,Integer");
	}
	
	//TypeExprParen Tests
	void test_type_expr_paren_1() {
		TypeExprInt *i = new TypeExprInt();
		TypeExprList *tel = new TypeExprList(i);
		TypeExprParen *ep = new TypeExprParen(tel);
		TS_ASSERT_EQUALS(ep->unparse(), "(Integer)");
	}
	
	void test_type_expr_paren_2() {
		TypeExprInt *i = new TypeExprInt();
		TypeExprStr *s = new TypeExprStr();
		TypeExprList *tel1 = new TypeExprList(i);
		TypeExprList *tel2 = new TypeExprList(s, tel1);
		TypeExprParen *ep = new TypeExprParen(tel2);
		TS_ASSERT_EQUALS(ep->unparse(), "(String,Integer)");
	}
	
	//BinaryOpsExpr Tests
	//Utility Functions
	/* This function can only handle int constant, dont put letters or float please.. */
	BinaryOpsExpr* MakeBinaryOpsExpr(string left, string op, string right) {
		IntConst *i1, *i2;
		i1 = new IntConst(left);
		i2 = new IntConst(right);
		BinaryOpsExpr* e = new BinaryOpsExpr(i1, op, i2);
		return e;
	}
	
	/* This variation handles expressions that are passed to it */
	BinaryOpsExpr* MakeBinaryOpsExpr(Expr* left, string op, Expr* right) {
		BinaryOpsExpr* e = new BinaryOpsExpr(left, op, right);
		return e;
	}
	
	//Tests
	void test_binary_ops_plus() {
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "+", "2");
		TS_ASSERT_EQUALS(e->unparse(), "1+2");
	}
	
	void test_binary_ops_dash() {
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "-", "2");
		TS_ASSERT_EQUALS(e->unparse(), "1-2");
	}
	
	void test_binary_ops_star() {
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "*", "2");
		TS_ASSERT_EQUALS(e->unparse(), "1*2");
	}
	
	void test_binary_ops_slash() {
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "/", "2");
		TS_ASSERT_EQUALS(e->unparse(), "1/2");
	}
	
	//ExprList Tests
	void test_expr_list_1() {
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "+", "2");
		ExprList* el = new ExprList(e);
		TS_ASSERT_EQUALS(el->unparse(), "1+2");
	}
	
	void test_expr_list_2() {
		BinaryOpsExpr* e1 = MakeBinaryOpsExpr("1", "+", "2");
		BinaryOpsExpr* e2 = MakeBinaryOpsExpr("1", "-", "2");
		ExprList* el1 = new ExprList(e1);
		ExprList* el2 = new ExprList(e2, el1);
		TS_ASSERT_EQUALS(el2->unparse(), "1-2,1+2");
	}
	
	//Decl Tests
	//Utility Functions
	Decl* MakeDecl(string varName, TypeExpr* type, Expr* e) {
		VariableName* name = new VariableName(varName);
		return new Decl(name, type, e);
	}
	
	//Tests
	void test_decl_1() {
		TypeExprInt *i = new TypeExprInt();
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "+", "2");
		Decl *d = MakeDecl("a", i, e);
		TS_ASSERT_EQUALS(d->unparse(), "a::Integer=1+2;");
	}
	
	void test_decl_2() {
		TypeExprInt *i = new TypeExprInt();
		BinaryOpsExpr* e = MakeBinaryOpsExpr(MakeBinaryOpsExpr("1", "*", "2"), 
												"+", MakeBinaryOpsExpr("1", "/", "2"));
		Decl *d = MakeDecl("a", i, e);
		TS_ASSERT_EQUALS(d->unparse(), "a::Integer=1*2+1/2;");
	}
	
	//DeclList Tests
	//Tests
	void test_decl_list_1() {
		TypeExprInt *i = new TypeExprInt();
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "+", "2");
		Decl *d = MakeDecl("a", i, e);
		DeclList *dl = new DeclList(d);
		TS_ASSERT_EQUALS(dl->unparse(), "a::Integer=1+2;");
	}
	
	void test_decl_list_2() {
		//DeclList1
		TypeExprInt *i = new TypeExprInt();
		BinaryOpsExpr* e1 = MakeBinaryOpsExpr("1", "+", "2");
		Decl *d1 = MakeDecl("a", i, e1);
		DeclList *dl1 = new DeclList(d1);
		//DeclList2(Append)
		TypeExprInt *f = new TypeExprInt();
		BinaryOpsExpr* e2 = MakeBinaryOpsExpr("2", "-", "1");
		Decl *d2 = MakeDecl("b", f, e2);
		DeclList *dl2 = new DeclList(d2, dl1);
		TS_ASSERT_EQUALS(dl2->unparse(), "b::Integer=2-1;a::Integer=1+2;");
	}
	
	//LetExpr Tests
	void test_let_epxr_1() {
		TypeExprInt *i = new TypeExprInt();
		BinaryOpsExpr* e1 = MakeBinaryOpsExpr("1", "+", "2");
		Decl *d = MakeDecl("a", i, e1);
		DeclList *dl = new DeclList(d);
		BinaryOpsExpr* e2 = MakeBinaryOpsExpr("3", "-", "4");
		LetExpr *le = new LetExpr(dl, e2);
		TS_ASSERT_EQUALS(le->unparse(), "let a::Integer=1+2; in 3-4 end ");
	}
	
	void test_let_epxr_2() {
		//DeclList1
		TypeExprInt *i = new TypeExprInt();
		BinaryOpsExpr* e1 = MakeBinaryOpsExpr("1", "+", "2");
		Decl *d1 = MakeDecl("a", i, e1);
		DeclList *dl1 = new DeclList(d1);
		//DeclList2(Append)
		TypeExprInt *f = new TypeExprInt();
		BinaryOpsExpr* e2 = MakeBinaryOpsExpr("2", "-", "1");
		Decl *d2 = MakeDecl("b", f, e2);
		DeclList *dl2 = new DeclList(d2, dl1);
		//Let
		BinaryOpsExpr* e3 = MakeBinaryOpsExpr(MakeBinaryOpsExpr("3", "*", "4"), 
												"-", MakeBinaryOpsExpr("3", "/", "4"));
		LetExpr *le = new LetExpr(dl2, e3);
		TS_ASSERT_EQUALS(le->unparse(), "let b::Integer=2-1;a::Integer=1+2; in 3*4-3/4 end ");
	}
	
	//IfThenElseExpr Tests
	void test_if_then_else_1() {
		BinaryOpsExpr* e1 = MakeBinaryOpsExpr("1", "-", "2");
		BinaryOpsExpr* e2 = MakeBinaryOpsExpr("3", "-", "4");
		BinaryOpsExpr* e3 = MakeBinaryOpsExpr("5", "-", "6");
		IfThenElseExpr* itee = new IfThenElseExpr(e1, e2, e3);
		TS_ASSERT_EQUALS(itee->unparse(), "if 1-2 then 3-4 else 5-6");
	}
	
	void test_if_then_else_2() {
		BinaryOpsExpr* e1 = MakeBinaryOpsExpr(MakeBinaryOpsExpr("1", "+", "2"), 
												"-", MakeBinaryOpsExpr("1", "+", "2"));
		BinaryOpsExpr* e2 = MakeBinaryOpsExpr(MakeBinaryOpsExpr("3", "+", "4"), 
												"-", MakeBinaryOpsExpr("3", "+", "4"));
		BinaryOpsExpr* e3 = MakeBinaryOpsExpr(MakeBinaryOpsExpr("5", "+", "6"),
												"-", MakeBinaryOpsExpr("5", "+", "6"));
		IfThenElseExpr* itee = new IfThenElseExpr(e1, e2, e3);
		TS_ASSERT_EQUALS(itee->unparse(), "if 1+2-1+2 then 3+4-3+4 else 5+6-5+6");
	}
	
	//ParenListExpr Tests
	void test_paren_list_expr_1() {
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "+", "2");
		ParenListExpr* pel = new ParenListExpr(e);
		TS_ASSERT_EQUALS(pel->unparse(), "(1+2)");
	}
	
	void test_paren_list_expr_2() {
		BinaryOpsExpr* e1 = MakeBinaryOpsExpr("1", "+", "2");
		BinaryOpsExpr* e2 = MakeBinaryOpsExpr("1", "-", "2");
		ExprList* el = new ExprList(e1);
		ParenListExpr* pel = new ParenListExpr(e2, el);
		TS_ASSERT_EQUALS(pel->unparse(), "(1-2,1+2)");
	}
	
	//OptionalExprList Tests
	void test_optional_expr_list_1() {
		OptionalExprList* oel = new OptionalExprList();
		TS_ASSERT_EQUALS(oel->unparse(), "");
	}
	
	void test_optional_expr_list_2() {
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "+", "1");
		ExprList* el = new ExprList(e);
		OptionalExprList* oel = new OptionalExprList(el);
		TS_ASSERT_EQUALS(oel->unparse(), "1+1");
	}
	
	//TypeArrayExpr Tests
	void test_type_array_expr_1() {
		TypeExpr* i = new TypeExprInt();
		OptionalExprList* oel = new OptionalExprList();
		TypeArrayExpr* tae = new TypeArrayExpr(i, oel);
		TS_ASSERT_EQUALS(tae->unparse(), "[<Integer>]");
	}
	
	void test_type_array_expr_2() {
		TypeExpr* i = new TypeExprInt();
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "+", "1");
		ExprList* el = new ExprList(e);
		OptionalExprList* oel = new OptionalExprList(el);
		TypeArrayExpr* tae = new TypeArrayExpr(i, oel);
		TS_ASSERT_EQUALS(tae->unparse(), "[<Integer>1+1]");
	}
	
	//RangeExpr Tests
	void test_range_expr_1() {
		IntConst *i1 = new IntConst("1");
		IntConst *i2 = new IntConst("10");
		RangeExpr *re = new RangeExpr(i1, i2);
		TS_ASSERT_EQUALS(re->unparse(), "[1..10]");
	}
	
	void test_range_expr_2() {
		BinaryOpsExpr *e1 = MakeBinaryOpsExpr("2" , "+", "1");
		BinaryOpsExpr *e2 = MakeBinaryOpsExpr("4" , "+", "6");
		RangeExpr *re = new RangeExpr(e1, e2);
		TS_ASSERT_EQUALS(re->unparse(), "[2+1..4+6]");
	}
	
	//FunctionCallExpr Tests
	void test_function_call_1() {
		VariableName* n = new VariableName("a");
		OptionalExprList* oel = new OptionalExprList();
		FunctionCallExpr *fce = new FunctionCallExpr(n, oel);
		TS_ASSERT_EQUALS(fce->unparse(), "a()");
	}
	
	void test_function_call_2() {
		VariableName* n = new VariableName("a");
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "+", "1");
		ExprList* el = new ExprList(e);
		OptionalExprList* oel = new OptionalExprList(el);
		FunctionCallExpr *fce = new FunctionCallExpr(n, oel);
		TS_ASSERT_EQUALS(fce->unparse(), "a(1+1)");
	}
	
	void test_function_call_3() {
		VariableName* n = new VariableName("a");
		ExprList* el1 = new ExprList(new IntConst("1"));
		ExprList* el2 = new ExprList(new IntConst("3"), el1);
		OptionalExprList* oel = new OptionalExprList(el2);
		FunctionCallExpr *fce = new FunctionCallExpr(n, oel);
		TS_ASSERT_EQUALS(fce->unparse(), "a(3,1)");
	}
	
	//PrintExpr Tests
	void test_print_expr() {
		IntConst* i = new IntConst("1");
		PrintExpr* pe = new PrintExpr(i);
		TS_ASSERT_EQUALS(pe->unparse(), "print(1)");
	}
	
	//WriteExpr Tests
	void test_write_expr() {
		VariableName *n1 = new VariableName("writer");
		VariableName *n2 = new VariableName("writee");
		WriteExpr * we = new WriteExpr(n1, n2);
		TS_ASSERT_EQUALS(we->unparse(), "write(writer,writee)");
	}
	
	//ReadExpr Tests
	void test_read_expr() {
		TypeExprInt* t = new TypeExprInt();
		IntConst* i = new IntConst("10");
		ReadExpr* re = new ReadExpr(t, i);
		TS_ASSERT_EQUALS(re->unparse(), "read<Integer>(10)");
	}
	
	//HeadExpr Tests
	void test_head_expr() {
		IntConst* i = new IntConst("1");
		HeadExpr* he = new HeadExpr(i);
		TS_ASSERT_EQUALS(he->unparse(), "head(1)");
	}
	
	//TailExpr Tests
	void test_tail_expr() {
		IntConst* i = new IntConst("1");
		TailExpr* te = new TailExpr(i);
		TS_ASSERT_EQUALS(te->unparse(), "tail(1)");
	}
	
	//NullExpr Tests
	void test_null_expr() {
		IntConst* i = new IntConst("1");
		NullExpr* ne = new NullExpr(i);
		TS_ASSERT_EQUALS(ne->unparse(), "null(1)");
	}
	
	//MapExpr Tests
	void test_map_expr() {
		IntConst* i1 = new IntConst("1");
		IntConst* i2 = new IntConst("2");
		MapExpr* me = new MapExpr(i1, i2);
		TS_ASSERT_EQUALS(me->unparse(), "map(1,2)");
	}
	
	//FilterExpr Tests
	void test_filter_expr() {
		IntConst* i1 = new IntConst("1");
		IntConst* i2 = new IntConst("2");
		FilterExpr* fe = new FilterExpr(i1, i2);
		TS_ASSERT_EQUALS(fe->unparse(), "filter(1,2)");
	}
	
	//FoldExpr Tests
	void test_fold_expr() {
		IntConst* i1 = new IntConst("1");
		IntConst* i2 = new IntConst("2");
		IntConst* i3 = new IntConst("3");
		FoldExpr* fe = new FoldExpr(i1, i2, i3);
		TS_ASSERT_EQUALS(fe->unparse(), "fold(1,2,3)");
	}
	
	//ZipExpr Tests
	void test_zip_expr() {
		IntConst* i1 = new IntConst("1");
		IntConst* i2 = new IntConst("2");
		ZipExpr* ze = new ZipExpr(i1, i2);
		TS_ASSERT_EQUALS(ze->unparse(), "zip(1,2)");
	}
	
	//SlashTBExpr Tests
	void test_slash_tb_expr_1() {
		TypeExprInt* t = new TypeExprInt();
		TypeBindingList* tbl = MakeTypeBindingList("a", t);
		VariableName* n = new VariableName("b");
		SlashTBExpr* stbe = new SlashTBExpr(tbl, n);
		TS_ASSERT_EQUALS(stbe->unparse(), "\\a::Integer->b");
	}
	
	void test_slash_tb_expr_2() {
		TypeExprInt* t1 = new TypeExprInt();
		TypeBindingList* tbl1 = MakeTypeBindingList("a", t1);
		TypeExprFlt* t2 = new TypeExprFlt();
		TypeBindingList* tbl2 = AppendTypeBindingList("b", t2, tbl1);
		BinaryOpsExpr* e = MakeBinaryOpsExpr("1", "/", "1");
		SlashTBExpr* stbe = new SlashTBExpr(tbl2, e);
		TS_ASSERT_EQUALS(stbe->unparse(), "\\b::Float,a::Integer->1/1");
	}
	
	//ProjectionExpr Tests
	void test_projection_expr() {
		IntConst* i = new IntConst("11037");
		ProjectionExpr* pe = new ProjectionExpr("#3", i);
		TS_ASSERT_EQUALS(pe->unparse(), "#3(11037)");
	}
	
	//Program Tests
	void test_program_1() {
		Decl* d = MakeDecl("a", new TypeExprInt(), MakeBinaryOpsExpr("1", "+", "2"));
		DeclList* dl = new DeclList(d);
		Program* p = new Program(dl);
		TS_ASSERT_EQUALS(p->unparse(), "a::Integer=1+2;");
	}
	
	void test_program_2() {
		Decl* d1 = MakeDecl("a", new TypeExprInt(), MakeBinaryOpsExpr("1", "+", "2"));
		Decl* d2 = MakeDecl("b", new TypeExprInt(), MakeBinaryOpsExpr("2", "-", "1"));
		DeclList* dl1 = new DeclList(d1);
		DeclList* dl2 = new DeclList(d2, dl1);
		Program* p = new Program(dl2);
		TS_ASSERT_EQUALS(p->unparse(), "b::Integer=2-1;a::Integer=1+2;");
	}

} ;
