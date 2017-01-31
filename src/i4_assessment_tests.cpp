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
bool suite_CodeGenTestSuite_init = false;
#include "/home/liux1366/3081/group/repo-group-TeamAxeEdge/project/src/i4_assessment_tests.h"

static CodeGenTestSuite suite_CodeGenTestSuite;

static CxxTest::List Tests_CodeGenTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_CodeGenTestSuite( "i4_assessment_tests.h", 17, "CodeGenTestSuite", suite_CodeGenTestSuite, Tests_CodeGenTestSuite );

static class TestDescription_suite_CodeGenTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 22, "test_setup_code" ) {}
 void runTest() { suite_CodeGenTestSuite.test_setup_code(); }
} testDescription_suite_CodeGenTestSuite_test_setup_code;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_simple_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_simple_1() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 93, "test_codeGen_simple_1" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_simple_1(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_simple_1;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_simple_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_simple_2() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 97, "test_codeGen_simple_2" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_simple_2(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_simple_2;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_simple_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_simple_3() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 100, "test_codeGen_simple_3" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_simple_3(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_simple_3;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_simple_4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_simple_4() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 103, "test_codeGen_simple_4" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_simple_4(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_simple_4;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_print_int_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_print_int_1() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 107, "test_codeGen_print_int_1" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_print_int_1(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_print_int_1;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_print_int_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_print_int_2() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 113, "test_codeGen_print_int_2" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_print_int_2(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_print_int_2;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_read_int : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_read_int() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 119, "test_codeGen_read_int" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_read_int(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_read_int;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_lists_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_lists_1() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 125, "test_codeGen_lists_1" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_lists_1(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_lists_1;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_lists_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_lists_2() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 131, "test_codeGen_lists_2" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_lists_2(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_lists_2;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_lists_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_lists_3() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 137, "test_codeGen_lists_3" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_lists_3(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_lists_3;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_squareData : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_squareData() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 143, "test_codeGen_squareData" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_squareData(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_squareData;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_squareFile : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_squareFile() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 149, "test_codeGen_squareFile" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_squareFile(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_squareFile;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_squaresMap : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_squaresMap() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 155, "test_codeGen_squaresMap" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_squaresMap(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_squaresMap;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_vecSum : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_vecSum() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 161, "test_codeGen_vecSum" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_vecSum(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_vecSum;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_evenSquares : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_evenSquares() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 167, "test_codeGen_evenSquares" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_evenSquares(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_evenSquares;

static class TestDescription_suite_CodeGenTestSuite_test_codeGen_pairs : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CodeGenTestSuite_test_codeGen_pairs() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 174, "test_codeGen_pairs" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_pairs(); }
} testDescription_suite_CodeGenTestSuite_test_codeGen_pairs;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
