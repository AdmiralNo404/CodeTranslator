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
#include "/home/liux1366/3081/group/repo-group-TeamAxeEdge/project/src/i2_assessment_tests.h"

static ParserTestSuite suite_ParserTestSuite;

static CxxTest::List Tests_ParserTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ParserTestSuite( "i2_assessment_tests.h", 11, "ParserTestSuite", suite_ParserTestSuite, Tests_ParserTestSuite );

static class TestDescription_suite_ParserTestSuite_test_scan_nums_vars : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_scan_nums_vars() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 44, "test_scan_nums_vars" ) {}
 void runTest() { suite_ParserTestSuite.test_scan_nums_vars(); }
} testDescription_suite_ParserTestSuite_test_scan_nums_vars;

static class TestDescription_suite_ParserTestSuite_test_parse_dcl : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_parse_dcl() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 55, "test_parse_dcl" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_dcl(); }
} testDescription_suite_ParserTestSuite_test_parse_dcl;

static class TestDescription_suite_ParserTestSuite_test_parse_dcl_fail : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_parse_dcl_fail() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 60, "test_parse_dcl_fail" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_dcl_fail(); }
} testDescription_suite_ParserTestSuite_test_parse_dcl_fail;

static class TestDescription_suite_ParserTestSuite_test_parse_dcls : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_parse_dcls() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 65, "test_parse_dcls" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_dcls(); }
} testDescription_suite_ParserTestSuite_test_parse_dcls;

static class TestDescription_suite_ParserTestSuite_test_parse_dcls_fail : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_parse_dcls_fail() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 70, "test_parse_dcls_fail" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_dcls_fail(); }
} testDescription_suite_ParserTestSuite_test_parse_dcls_fail;

static class TestDescription_suite_ParserTestSuite_test_parse_simple_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_parse_simple_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 84, "test_parse_simple_1" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_simple_1(); }
} testDescription_suite_ParserTestSuite_test_parse_simple_1;

static class TestDescription_suite_ParserTestSuite_test_parse_simple_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_parse_simple_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 87, "test_parse_simple_2" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_simple_2(); }
} testDescription_suite_ParserTestSuite_test_parse_simple_2;

static class TestDescription_suite_ParserTestSuite_test_parse_simple_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_parse_simple_3() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 90, "test_parse_simple_3" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_simple_3(); }
} testDescription_suite_ParserTestSuite_test_parse_simple_3;

static class TestDescription_suite_ParserTestSuite_test_parse_squares : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_parse_squares() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 93, "test_parse_squares" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_squares(); }
} testDescription_suite_ParserTestSuite_test_parse_squares;

static class TestDescription_suite_ParserTestSuite_test_parse_evenSquares : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_parse_evenSquares() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 96, "test_parse_evenSquares" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_evenSquares(); }
} testDescription_suite_ParserTestSuite_test_parse_evenSquares;

static class TestDescription_suite_ParserTestSuite_test_parse_matVecMul : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_parse_matVecMul() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 99, "test_parse_matVecMul" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_matVecMul(); }
} testDescription_suite_ParserTestSuite_test_parse_matVecMul;

static class TestDescription_suite_ParserTestSuite_test_parse_matVecMulLiterals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ParserTestSuite_test_parse_matVecMulLiterals() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 102, "test_parse_matVecMulLiterals" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_matVecMulLiterals(); }
} testDescription_suite_ParserTestSuite_test_parse_matVecMulLiterals;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
