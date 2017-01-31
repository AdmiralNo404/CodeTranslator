/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#define _CXXTEST_ABORT_TEST_ON_FAIL
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_ParserTestSuite_init = false;
#include "/home/liux1366/3081/group/repo-group-TeamAxeEdge/project/src/parser_tests.h"

static ParserTestSuite suite_ParserTestSuite;

static CxxTest::List Tests_ParserTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ParserTestSuite( "parser_tests.h", 9, "ParserTestSuite", suite_ParserTestSuite, Tests_ParserTestSuite );

static class TestDescription_suite_ParserTestSuite_test_variable_name : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_variable_name() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 27, "test_variable_name" ) {}
 void runTest() { suite_ParserTestSuite.test_variable_name(); }
} testDescription_suite_ParserTestSuite_test_variable_name;

static class TestDescription_suite_ParserTestSuite_test_int_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_int_const() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 33, "test_int_const" ) {}
 void runTest() { suite_ParserTestSuite.test_int_const(); }
} testDescription_suite_ParserTestSuite_test_int_const;

static class TestDescription_suite_ParserTestSuite_test_float_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_float_const() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 39, "test_float_const" ) {}
 void runTest() { suite_ParserTestSuite.test_float_const(); }
} testDescription_suite_ParserTestSuite_test_float_const;

static class TestDescription_suite_ParserTestSuite_test_string_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_string_const() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 45, "test_string_const" ) {}
 void runTest() { suite_ParserTestSuite.test_string_const(); }
} testDescription_suite_ParserTestSuite_test_string_const;

static class TestDescription_suite_ParserTestSuite_test_bollean_const_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_bollean_const_true() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 51, "test_bollean_const_true" ) {}
 void runTest() { suite_ParserTestSuite.test_bollean_const_true(); }
} testDescription_suite_ParserTestSuite_test_bollean_const_true;

static class TestDescription_suite_ParserTestSuite_test_bollean_const_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_bollean_const_false() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 56, "test_bollean_const_false" ) {}
 void runTest() { suite_ParserTestSuite.test_bollean_const_false(); }
} testDescription_suite_ParserTestSuite_test_bollean_const_false;

static class TestDescription_suite_ParserTestSuite_test_type_expr_int : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_expr_int() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 62, "test_type_expr_int" ) {}
 void runTest() { suite_ParserTestSuite.test_type_expr_int(); }
} testDescription_suite_ParserTestSuite_test_type_expr_int;

static class TestDescription_suite_ParserTestSuite_test_type_expr_flt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_expr_flt() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 68, "test_type_expr_flt" ) {}
 void runTest() { suite_ParserTestSuite.test_type_expr_flt(); }
} testDescription_suite_ParserTestSuite_test_type_expr_flt;

static class TestDescription_suite_ParserTestSuite_test_type_expr_str : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_expr_str() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 74, "test_type_expr_str" ) {}
 void runTest() { suite_ParserTestSuite.test_type_expr_str(); }
} testDescription_suite_ParserTestSuite_test_type_expr_str;

static class TestDescription_suite_ParserTestSuite_test_type_expr_bool : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_expr_bool() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 80, "test_type_expr_bool" ) {}
 void runTest() { suite_ParserTestSuite.test_type_expr_bool(); }
} testDescription_suite_ParserTestSuite_test_type_expr_bool;

static class TestDescription_suite_ParserTestSuite_test_type_expr_sq_bracket : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_expr_sq_bracket() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 93, "test_type_expr_sq_bracket" ) {}
 void runTest() { suite_ParserTestSuite.test_type_expr_sq_bracket(); }
} testDescription_suite_ParserTestSuite_test_type_expr_sq_bracket;

static class TestDescription_suite_ParserTestSuite_test_type_binding : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_binding() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 106, "test_type_binding" ) {}
 void runTest() { suite_ParserTestSuite.test_type_binding(); }
} testDescription_suite_ParserTestSuite_test_type_binding;

static class TestDescription_suite_ParserTestSuite_test_type_binding_list_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_binding_list_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 125, "test_type_binding_list_1" ) {}
 void runTest() { suite_ParserTestSuite.test_type_binding_list_1(); }
} testDescription_suite_ParserTestSuite_test_type_binding_list_1;

static class TestDescription_suite_ParserTestSuite_test_type_binding_list_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_binding_list_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 131, "test_type_binding_list_2" ) {}
 void runTest() { suite_ParserTestSuite.test_type_binding_list_2(); }
} testDescription_suite_ParserTestSuite_test_type_binding_list_2;

static class TestDescription_suite_ParserTestSuite_test_type_expr_parr_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_expr_parr_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 140, "test_type_expr_parr_1" ) {}
 void runTest() { suite_ParserTestSuite.test_type_expr_parr_1(); }
} testDescription_suite_ParserTestSuite_test_type_expr_parr_1;

static class TestDescription_suite_ParserTestSuite_test_type_expr_parr_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_expr_parr_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 148, "test_type_expr_parr_2" ) {}
 void runTest() { suite_ParserTestSuite.test_type_expr_parr_2(); }
} testDescription_suite_ParserTestSuite_test_type_expr_parr_2;

static class TestDescription_suite_ParserTestSuite_test_type_expr_list_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_expr_list_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 160, "test_type_expr_list_1" ) {}
 void runTest() { suite_ParserTestSuite.test_type_expr_list_1(); }
} testDescription_suite_ParserTestSuite_test_type_expr_list_1;

static class TestDescription_suite_ParserTestSuite_test_type_expr_list_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_expr_list_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 166, "test_type_expr_list_2" ) {}
 void runTest() { suite_ParserTestSuite.test_type_expr_list_2(); }
} testDescription_suite_ParserTestSuite_test_type_expr_list_2;

static class TestDescription_suite_ParserTestSuite_test_type_expr_paren_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_expr_paren_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 175, "test_type_expr_paren_1" ) {}
 void runTest() { suite_ParserTestSuite.test_type_expr_paren_1(); }
} testDescription_suite_ParserTestSuite_test_type_expr_paren_1;

static class TestDescription_suite_ParserTestSuite_test_type_expr_paren_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_expr_paren_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 182, "test_type_expr_paren_2" ) {}
 void runTest() { suite_ParserTestSuite.test_type_expr_paren_2(); }
} testDescription_suite_ParserTestSuite_test_type_expr_paren_2;

static class TestDescription_suite_ParserTestSuite_test_binary_ops_plus : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_binary_ops_plus() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 209, "test_binary_ops_plus" ) {}
 void runTest() { suite_ParserTestSuite.test_binary_ops_plus(); }
} testDescription_suite_ParserTestSuite_test_binary_ops_plus;

static class TestDescription_suite_ParserTestSuite_test_binary_ops_dash : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_binary_ops_dash() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 214, "test_binary_ops_dash" ) {}
 void runTest() { suite_ParserTestSuite.test_binary_ops_dash(); }
} testDescription_suite_ParserTestSuite_test_binary_ops_dash;

static class TestDescription_suite_ParserTestSuite_test_binary_ops_star : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_binary_ops_star() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 219, "test_binary_ops_star" ) {}
 void runTest() { suite_ParserTestSuite.test_binary_ops_star(); }
} testDescription_suite_ParserTestSuite_test_binary_ops_star;

static class TestDescription_suite_ParserTestSuite_test_binary_ops_slash : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_binary_ops_slash() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 224, "test_binary_ops_slash" ) {}
 void runTest() { suite_ParserTestSuite.test_binary_ops_slash(); }
} testDescription_suite_ParserTestSuite_test_binary_ops_slash;

static class TestDescription_suite_ParserTestSuite_test_expr_list_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_expr_list_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 230, "test_expr_list_1" ) {}
 void runTest() { suite_ParserTestSuite.test_expr_list_1(); }
} testDescription_suite_ParserTestSuite_test_expr_list_1;

static class TestDescription_suite_ParserTestSuite_test_expr_list_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_expr_list_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 236, "test_expr_list_2" ) {}
 void runTest() { suite_ParserTestSuite.test_expr_list_2(); }
} testDescription_suite_ParserTestSuite_test_expr_list_2;

static class TestDescription_suite_ParserTestSuite_test_decl_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_decl_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 252, "test_decl_1" ) {}
 void runTest() { suite_ParserTestSuite.test_decl_1(); }
} testDescription_suite_ParserTestSuite_test_decl_1;

static class TestDescription_suite_ParserTestSuite_test_decl_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_decl_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 259, "test_decl_2" ) {}
 void runTest() { suite_ParserTestSuite.test_decl_2(); }
} testDescription_suite_ParserTestSuite_test_decl_2;

static class TestDescription_suite_ParserTestSuite_test_decl_list_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_decl_list_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 269, "test_decl_list_1" ) {}
 void runTest() { suite_ParserTestSuite.test_decl_list_1(); }
} testDescription_suite_ParserTestSuite_test_decl_list_1;

static class TestDescription_suite_ParserTestSuite_test_decl_list_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_decl_list_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 277, "test_decl_list_2" ) {}
 void runTest() { suite_ParserTestSuite.test_decl_list_2(); }
} testDescription_suite_ParserTestSuite_test_decl_list_2;

static class TestDescription_suite_ParserTestSuite_test_let_epxr_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_let_epxr_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 292, "test_let_epxr_1" ) {}
 void runTest() { suite_ParserTestSuite.test_let_epxr_1(); }
} testDescription_suite_ParserTestSuite_test_let_epxr_1;

static class TestDescription_suite_ParserTestSuite_test_let_epxr_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_let_epxr_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 302, "test_let_epxr_2" ) {}
 void runTest() { suite_ParserTestSuite.test_let_epxr_2(); }
} testDescription_suite_ParserTestSuite_test_let_epxr_2;

static class TestDescription_suite_ParserTestSuite_test_if_then_else_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_if_then_else_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 321, "test_if_then_else_1" ) {}
 void runTest() { suite_ParserTestSuite.test_if_then_else_1(); }
} testDescription_suite_ParserTestSuite_test_if_then_else_1;

static class TestDescription_suite_ParserTestSuite_test_if_then_else_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_if_then_else_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 329, "test_if_then_else_2" ) {}
 void runTest() { suite_ParserTestSuite.test_if_then_else_2(); }
} testDescription_suite_ParserTestSuite_test_if_then_else_2;

static class TestDescription_suite_ParserTestSuite_test_paren_list_expr_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_paren_list_expr_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 341, "test_paren_list_expr_1" ) {}
 void runTest() { suite_ParserTestSuite.test_paren_list_expr_1(); }
} testDescription_suite_ParserTestSuite_test_paren_list_expr_1;

static class TestDescription_suite_ParserTestSuite_test_paren_list_expr_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_paren_list_expr_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 347, "test_paren_list_expr_2" ) {}
 void runTest() { suite_ParserTestSuite.test_paren_list_expr_2(); }
} testDescription_suite_ParserTestSuite_test_paren_list_expr_2;

static class TestDescription_suite_ParserTestSuite_test_optional_expr_list_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_optional_expr_list_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 356, "test_optional_expr_list_1" ) {}
 void runTest() { suite_ParserTestSuite.test_optional_expr_list_1(); }
} testDescription_suite_ParserTestSuite_test_optional_expr_list_1;

static class TestDescription_suite_ParserTestSuite_test_optional_expr_list_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_optional_expr_list_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 361, "test_optional_expr_list_2" ) {}
 void runTest() { suite_ParserTestSuite.test_optional_expr_list_2(); }
} testDescription_suite_ParserTestSuite_test_optional_expr_list_2;

static class TestDescription_suite_ParserTestSuite_test_type_array_expr_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_array_expr_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 369, "test_type_array_expr_1" ) {}
 void runTest() { suite_ParserTestSuite.test_type_array_expr_1(); }
} testDescription_suite_ParserTestSuite_test_type_array_expr_1;

static class TestDescription_suite_ParserTestSuite_test_type_array_expr_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_type_array_expr_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 376, "test_type_array_expr_2" ) {}
 void runTest() { suite_ParserTestSuite.test_type_array_expr_2(); }
} testDescription_suite_ParserTestSuite_test_type_array_expr_2;

static class TestDescription_suite_ParserTestSuite_test_range_expr_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_range_expr_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 386, "test_range_expr_1" ) {}
 void runTest() { suite_ParserTestSuite.test_range_expr_1(); }
} testDescription_suite_ParserTestSuite_test_range_expr_1;

static class TestDescription_suite_ParserTestSuite_test_range_expr_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_range_expr_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 393, "test_range_expr_2" ) {}
 void runTest() { suite_ParserTestSuite.test_range_expr_2(); }
} testDescription_suite_ParserTestSuite_test_range_expr_2;

static class TestDescription_suite_ParserTestSuite_test_function_call_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_function_call_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 401, "test_function_call_1" ) {}
 void runTest() { suite_ParserTestSuite.test_function_call_1(); }
} testDescription_suite_ParserTestSuite_test_function_call_1;

static class TestDescription_suite_ParserTestSuite_test_function_call_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_function_call_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 408, "test_function_call_2" ) {}
 void runTest() { suite_ParserTestSuite.test_function_call_2(); }
} testDescription_suite_ParserTestSuite_test_function_call_2;

static class TestDescription_suite_ParserTestSuite_test_function_call_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_function_call_3() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 417, "test_function_call_3" ) {}
 void runTest() { suite_ParserTestSuite.test_function_call_3(); }
} testDescription_suite_ParserTestSuite_test_function_call_3;

static class TestDescription_suite_ParserTestSuite_test_print_expr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_print_expr() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 427, "test_print_expr" ) {}
 void runTest() { suite_ParserTestSuite.test_print_expr(); }
} testDescription_suite_ParserTestSuite_test_print_expr;

static class TestDescription_suite_ParserTestSuite_test_write_expr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_write_expr() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 434, "test_write_expr" ) {}
 void runTest() { suite_ParserTestSuite.test_write_expr(); }
} testDescription_suite_ParserTestSuite_test_write_expr;

static class TestDescription_suite_ParserTestSuite_test_read_expr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_read_expr() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 442, "test_read_expr" ) {}
 void runTest() { suite_ParserTestSuite.test_read_expr(); }
} testDescription_suite_ParserTestSuite_test_read_expr;

static class TestDescription_suite_ParserTestSuite_test_head_expr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_head_expr() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 450, "test_head_expr" ) {}
 void runTest() { suite_ParserTestSuite.test_head_expr(); }
} testDescription_suite_ParserTestSuite_test_head_expr;

static class TestDescription_suite_ParserTestSuite_test_tail_expr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_tail_expr() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 457, "test_tail_expr" ) {}
 void runTest() { suite_ParserTestSuite.test_tail_expr(); }
} testDescription_suite_ParserTestSuite_test_tail_expr;

static class TestDescription_suite_ParserTestSuite_test_null_expr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_null_expr() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 464, "test_null_expr" ) {}
 void runTest() { suite_ParserTestSuite.test_null_expr(); }
} testDescription_suite_ParserTestSuite_test_null_expr;

static class TestDescription_suite_ParserTestSuite_test_map_expr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_map_expr() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 471, "test_map_expr" ) {}
 void runTest() { suite_ParserTestSuite.test_map_expr(); }
} testDescription_suite_ParserTestSuite_test_map_expr;

static class TestDescription_suite_ParserTestSuite_test_filter_expr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_filter_expr() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 479, "test_filter_expr" ) {}
 void runTest() { suite_ParserTestSuite.test_filter_expr(); }
} testDescription_suite_ParserTestSuite_test_filter_expr;

static class TestDescription_suite_ParserTestSuite_test_fold_expr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_fold_expr() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 487, "test_fold_expr" ) {}
 void runTest() { suite_ParserTestSuite.test_fold_expr(); }
} testDescription_suite_ParserTestSuite_test_fold_expr;

static class TestDescription_suite_ParserTestSuite_test_zip_expr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_zip_expr() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 496, "test_zip_expr" ) {}
 void runTest() { suite_ParserTestSuite.test_zip_expr(); }
} testDescription_suite_ParserTestSuite_test_zip_expr;

static class TestDescription_suite_ParserTestSuite_test_slash_tb_expr_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_slash_tb_expr_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 504, "test_slash_tb_expr_1" ) {}
 void runTest() { suite_ParserTestSuite.test_slash_tb_expr_1(); }
} testDescription_suite_ParserTestSuite_test_slash_tb_expr_1;

static class TestDescription_suite_ParserTestSuite_test_slash_tb_expr_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_slash_tb_expr_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 512, "test_slash_tb_expr_2" ) {}
 void runTest() { suite_ParserTestSuite.test_slash_tb_expr_2(); }
} testDescription_suite_ParserTestSuite_test_slash_tb_expr_2;

static class TestDescription_suite_ParserTestSuite_test_projection_expr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_projection_expr() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 523, "test_projection_expr" ) {}
 void runTest() { suite_ParserTestSuite.test_projection_expr(); }
} testDescription_suite_ParserTestSuite_test_projection_expr;

static class TestDescription_suite_ParserTestSuite_test_program_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_program_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 530, "test_program_1" ) {}
 void runTest() { suite_ParserTestSuite.test_program_1(); }
} testDescription_suite_ParserTestSuite_test_program_1;

static class TestDescription_suite_ParserTestSuite_test_program_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_program_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 537, "test_program_2" ) {}
 void runTest() { suite_ParserTestSuite.test_program_2(); }
} testDescription_suite_ParserTestSuite_test_program_2;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
