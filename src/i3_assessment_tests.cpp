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
bool suite_AstTestSuite_init = false;
#include "/home/liux1366/3081/group/repo-group-TeamAxeEdge/project/src/i3_assessment_tests.h"

static AstTestSuite suite_AstTestSuite;

static CxxTest::List Tests_AstTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_AstTestSuite( "i3_assessment_tests.h", 14, "AstTestSuite", suite_AstTestSuite, Tests_AstTestSuite );

static class TestDescription_suite_AstTestSuite_test_ast_simple_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AstTestSuite_test_ast_simple_1() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 96, "test_ast_simple_1" ) {}
 void runTest() { suite_AstTestSuite.test_ast_simple_1(); }
} testDescription_suite_AstTestSuite_test_ast_simple_1;

static class TestDescription_suite_AstTestSuite_test_ast_simple_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AstTestSuite_test_ast_simple_2() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 99, "test_ast_simple_2" ) {}
 void runTest() { suite_AstTestSuite.test_ast_simple_2(); }
} testDescription_suite_AstTestSuite_test_ast_simple_2;

static class TestDescription_suite_AstTestSuite_test_ast_simple_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AstTestSuite_test_ast_simple_3() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 102, "test_ast_simple_3" ) {}
 void runTest() { suite_AstTestSuite.test_ast_simple_3(); }
} testDescription_suite_AstTestSuite_test_ast_simple_3;

static class TestDescription_suite_AstTestSuite_test_ast_squares : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AstTestSuite_test_ast_squares() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 105, "test_ast_squares" ) {}
 void runTest() { suite_AstTestSuite.test_ast_squares(); }
} testDescription_suite_AstTestSuite_test_ast_squares;

static class TestDescription_suite_AstTestSuite_test_ast_evenSquares : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AstTestSuite_test_ast_evenSquares() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 108, "test_ast_evenSquares" ) {}
 void runTest() { suite_AstTestSuite.test_ast_evenSquares(); }
} testDescription_suite_AstTestSuite_test_ast_evenSquares;

static class TestDescription_suite_AstTestSuite_test_ast_matVecMul : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AstTestSuite_test_ast_matVecMul() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 111, "test_ast_matVecMul" ) {}
 void runTest() { suite_AstTestSuite.test_ast_matVecMul(); }
} testDescription_suite_AstTestSuite_test_ast_matVecMul;

static class TestDescription_suite_AstTestSuite_test_ast_matVecMulLiterals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AstTestSuite_test_ast_matVecMulLiterals() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 114, "test_ast_matVecMulLiterals" ) {}
 void runTest() { suite_AstTestSuite.test_ast_matVecMulLiterals(); }
} testDescription_suite_AstTestSuite_test_ast_matVecMulLiterals;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
