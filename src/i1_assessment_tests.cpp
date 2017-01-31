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
bool suite_ScannerTestSuite_init = false;
#include "/home/liux1366/3081/group/repo-group-TeamAxeEdge/project/src/i1_assessment_tests.h"

static ScannerTestSuite suite_ScannerTestSuite;

static CxxTest::List Tests_ScannerTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ScannerTestSuite( "i1_assessment_tests.h", 8, "ScannerTestSuite", suite_ScannerTestSuite, Tests_ScannerTestSuite );

static class TestDescription_suite_ScannerTestSuite_test_scan_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_empty() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 75, "test_scan_empty" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty(); }
} testDescription_suite_ScannerTestSuite_test_scan_empty;

static class TestDescription_suite_ScannerTestSuite_test_scan_empty_comment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_empty_comment() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 82, "test_scan_empty_comment" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty_comment(); }
} testDescription_suite_ScannerTestSuite_test_scan_empty_comment;

static class TestDescription_suite_ScannerTestSuite_test_scan_lexicalErrors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_lexicalErrors() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 92, "test_scan_lexicalErrors" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_lexicalErrors(); }
} testDescription_suite_ScannerTestSuite_test_scan_lexicalErrors;

static class TestDescription_suite_ScannerTestSuite_test_scan_nums_vars : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_nums_vars() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 113, "test_scan_nums_vars" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_nums_vars(); }
} testDescription_suite_ScannerTestSuite_test_scan_nums_vars;

static class TestDescription_suite_ScannerTestSuite_test_scan_bad_syntax_good_tokens : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_bad_syntax_good_tokens() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 126, "test_scan_bad_syntax_good_tokens" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_bad_syntax_good_tokens(); }
} testDescription_suite_ScannerTestSuite_test_scan_bad_syntax_good_tokens;

static class TestDescription_suite_ScannerTestSuite_test_scan_simple_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_simple_1() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 167, "test_scan_simple_1" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_simple_1(); }
} testDescription_suite_ScannerTestSuite_test_scan_simple_1;

static class TestDescription_suite_ScannerTestSuite_test_scan_simple_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_simple_2() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 170, "test_scan_simple_2" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_simple_2(); }
} testDescription_suite_ScannerTestSuite_test_scan_simple_2;

static class TestDescription_suite_ScannerTestSuite_test_scan_simple_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_simple_3() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 173, "test_scan_simple_3" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_simple_3(); }
} testDescription_suite_ScannerTestSuite_test_scan_simple_3;

static class TestDescription_suite_ScannerTestSuite_test_scan_squares : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_squares() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 176, "test_scan_squares" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_squares(); }
} testDescription_suite_ScannerTestSuite_test_scan_squares;

static class TestDescription_suite_ScannerTestSuite_test_scan_evenSquares : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_evenSquares() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 179, "test_scan_evenSquares" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_evenSquares(); }
} testDescription_suite_ScannerTestSuite_test_scan_evenSquares;

static class TestDescription_suite_ScannerTestSuite_test_scan_matVecMulLiterals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_matVecMulLiterals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 182, "test_scan_matVecMulLiterals" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_matVecMulLiterals(); }
} testDescription_suite_ScannerTestSuite_test_scan_matVecMulLiterals;

static class TestDescription_suite_ScannerTestSuite_test_scan_matVecMul : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_scan_matVecMul() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 185, "test_scan_matVecMul" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_matVecMul(); }
} testDescription_suite_ScannerTestSuite_test_scan_matVecMul;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
