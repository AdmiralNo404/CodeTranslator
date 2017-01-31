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
#include "/home/liux1366/3081/group/repo-group-TeamAxeEdge/project/src/scanner_tests.h"

static ScannerTestSuite suite_ScannerTestSuite;

static CxxTest::List Tests_ScannerTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ScannerTestSuite( "scanner_tests.h", 8, "ScannerTestSuite", suite_ScannerTestSuite, Tests_ScannerTestSuite );

static class TestDescription_suite_ScannerTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 17, "test_setup_code" ) {}
 void runTest() { suite_ScannerTestSuite.test_setup_code(); }
} testDescription_suite_ScannerTestSuite_test_setup_code;

static class TestDescription_suite_ScannerTestSuite_test_terminal_letKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_letKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 42, "test_terminal_letKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_letKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_letKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_inKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_inKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 46, "test_terminal_inKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_inKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_inKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_endKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_endKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 50, "test_terminal_endKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_endKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_endKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_ifKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_ifKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 54, "test_terminal_ifKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_ifKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_ifKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_thenKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_thenKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 58, "test_terminal_thenKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_thenKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_thenKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_elseKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_elseKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 62, "test_terminal_elseKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_elseKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_elseKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_printKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_printKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 66, "test_terminal_printKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_printKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_printKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_readKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_readKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 70, "test_terminal_readKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_readKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_readKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_writeKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_writeKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 74, "test_terminal_writeKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_writeKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_writeKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_integerKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_integerKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 78, "test_terminal_integerKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_integerKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_integerKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_floatKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_floatKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 82, "test_terminal_floatKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_floatKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_floatKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_booleanKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_booleanKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 86, "test_terminal_booleanKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_booleanKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_booleanKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_stringKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_stringKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 90, "test_terminal_stringKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_stringKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_stringKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_trueKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_trueKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 94, "test_terminal_trueKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_trueKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_trueKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_falseKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_falseKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 98, "test_terminal_falseKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_falseKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_falseKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_headKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_headKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 102, "test_terminal_headKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_headKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_headKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_tailKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_tailKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 106, "test_terminal_tailKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_tailKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_tailKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_nullKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_nullKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 110, "test_terminal_nullKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_nullKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_nullKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_mapKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_mapKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 114, "test_terminal_mapKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_mapKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_mapKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_filterKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_filterKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 118, "test_terminal_filterKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_filterKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_filterKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_foldKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_foldKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 122, "test_terminal_foldKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_foldKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_foldKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_zipKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_zipKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 126, "test_terminal_zipKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_zipKwd(); }
} testDescription_suite_ScannerTestSuite_test_terminal_zipKwd;

static class TestDescription_suite_ScannerTestSuite_test_terminal_intConst : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_intConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 132, "test_terminal_intConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_intConst(); }
} testDescription_suite_ScannerTestSuite_test_terminal_intConst;

static class TestDescription_suite_ScannerTestSuite_test_terminal_floatConst : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_floatConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 136, "test_terminal_floatConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_floatConst(); }
} testDescription_suite_ScannerTestSuite_test_terminal_floatConst;

static class TestDescription_suite_ScannerTestSuite_test_terminal_stringConst : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_stringConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 140, "test_terminal_stringConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_stringConst(); }
} testDescription_suite_ScannerTestSuite_test_terminal_stringConst;

static class TestDescription_suite_ScannerTestSuite_test_terminal_variableName : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_variableName() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 146, "test_terminal_variableName" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_variableName(); }
} testDescription_suite_ScannerTestSuite_test_terminal_variableName;

static class TestDescription_suite_ScannerTestSuite_test_terminal_leftParen : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_leftParen() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 152, "test_terminal_leftParen" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftParen(); }
} testDescription_suite_ScannerTestSuite_test_terminal_leftParen;

static class TestDescription_suite_ScannerTestSuite_test_terminal_rightParen : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_rightParen() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 156, "test_terminal_rightParen" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightParen(); }
} testDescription_suite_ScannerTestSuite_test_terminal_rightParen;

static class TestDescription_suite_ScannerTestSuite_test_terminal_leftSqaure : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_leftSqaure() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 160, "test_terminal_leftSqaure" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftSqaure(); }
} testDescription_suite_ScannerTestSuite_test_terminal_leftSqaure;

static class TestDescription_suite_ScannerTestSuite_test_terminal_rightSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_rightSquare() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 164, "test_terminal_rightSquare" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightSquare(); }
} testDescription_suite_ScannerTestSuite_test_terminal_rightSquare;

static class TestDescription_suite_ScannerTestSuite_test_terminal_leftAngle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_leftAngle() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 168, "test_terminal_leftAngle" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftAngle(); }
} testDescription_suite_ScannerTestSuite_test_terminal_leftAngle;

static class TestDescription_suite_ScannerTestSuite_test_terminal_rightAngle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_rightAngle() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 172, "test_terminal_rightAngle" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightAngle(); }
} testDescription_suite_ScannerTestSuite_test_terminal_rightAngle;

static class TestDescription_suite_ScannerTestSuite_test_terminal_colon : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_colon() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 176, "test_terminal_colon" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_colon(); }
} testDescription_suite_ScannerTestSuite_test_terminal_colon;

static class TestDescription_suite_ScannerTestSuite_test_terminal_colonColon : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_colonColon() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 180, "test_terminal_colonColon" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_colonColon(); }
} testDescription_suite_ScannerTestSuite_test_terminal_colonColon;

static class TestDescription_suite_ScannerTestSuite_test_terminal_comma : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_comma() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 184, "test_terminal_comma" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_comma(); }
} testDescription_suite_ScannerTestSuite_test_terminal_comma;

static class TestDescription_suite_ScannerTestSuite_test_terminal_semiColon : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_semiColon() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 188, "test_terminal_semiColon" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_semiColon(); }
} testDescription_suite_ScannerTestSuite_test_terminal_semiColon;

static class TestDescription_suite_ScannerTestSuite_test_terminal_equalsSign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_equalsSign() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 192, "test_terminal_equalsSign" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_equalsSign(); }
} testDescription_suite_ScannerTestSuite_test_terminal_equalsSign;

static class TestDescription_suite_ScannerTestSuite_test_terminal_plusSign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_plusSign() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 196, "test_terminal_plusSign" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_plusSign(); }
} testDescription_suite_ScannerTestSuite_test_terminal_plusSign;

static class TestDescription_suite_ScannerTestSuite_test_terminal_star : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_star() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 200, "test_terminal_star" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_star(); }
} testDescription_suite_ScannerTestSuite_test_terminal_star;

static class TestDescription_suite_ScannerTestSuite_test_terminal_dash : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_dash() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 204, "test_terminal_dash" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_dash(); }
} testDescription_suite_ScannerTestSuite_test_terminal_dash;

static class TestDescription_suite_ScannerTestSuite_test_terminal_forwardSlash : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_forwardSlash() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 208, "test_terminal_forwardSlash" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_forwardSlash(); }
} testDescription_suite_ScannerTestSuite_test_terminal_forwardSlash;

static class TestDescription_suite_ScannerTestSuite_test_terminal_percent : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_percent() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 212, "test_terminal_percent" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_percent(); }
} testDescription_suite_ScannerTestSuite_test_terminal_percent;

static class TestDescription_suite_ScannerTestSuite_test_terminal_backSlash : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_backSlash() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 216, "test_terminal_backSlash" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_backSlash(); }
} testDescription_suite_ScannerTestSuite_test_terminal_backSlash;

static class TestDescription_suite_ScannerTestSuite_test_terminal_arrow : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_arrow() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 220, "test_terminal_arrow" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_arrow(); }
} testDescription_suite_ScannerTestSuite_test_terminal_arrow;

static class TestDescription_suite_ScannerTestSuite_test_terminal_equalsEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_equalsEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 224, "test_terminal_equalsEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_equalsEquals(); }
} testDescription_suite_ScannerTestSuite_test_terminal_equalsEquals;

static class TestDescription_suite_ScannerTestSuite_test_terminal_lessThanEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_lessThanEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 228, "test_terminal_lessThanEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_lessThanEquals(); }
} testDescription_suite_ScannerTestSuite_test_terminal_lessThanEquals;

static class TestDescription_suite_ScannerTestSuite_test_terminal_greaterThanEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_greaterThanEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 232, "test_terminal_greaterThanEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_greaterThanEquals(); }
} testDescription_suite_ScannerTestSuite_test_terminal_greaterThanEquals;

static class TestDescription_suite_ScannerTestSuite_test_terminal_notEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_notEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 236, "test_terminal_notEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_notEquals(); }
} testDescription_suite_ScannerTestSuite_test_terminal_notEquals;

static class TestDescription_suite_ScannerTestSuite_test_terminal_plusPlus : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_plusPlus() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 240, "test_terminal_plusPlus" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_plusPlus(); }
} testDescription_suite_ScannerTestSuite_test_terminal_plusPlus;

static class TestDescription_suite_ScannerTestSuite_test_terminal_dotDot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_dotDot() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 244, "test_terminal_dotDot" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_dotDot(); }
} testDescription_suite_ScannerTestSuite_test_terminal_dotDot;

static class TestDescription_suite_ScannerTestSuite_test_terminal_tupleOp : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_tupleOp() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 248, "test_terminal_tupleOp" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_tupleOp(); }
} testDescription_suite_ScannerTestSuite_test_terminal_tupleOp;

static class TestDescription_suite_ScannerTestSuite_test_terminal_endOfFile : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_endOfFile() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 252, "test_terminal_endOfFile" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_endOfFile(); }
} testDescription_suite_ScannerTestSuite_test_terminal_endOfFile;

static class TestDescription_suite_ScannerTestSuite_test_terminal_lexicalError : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_lexicalError() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 256, "test_terminal_lexicalError" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_lexicalError(); }
} testDescription_suite_ScannerTestSuite_test_terminal_lexicalError;

static class TestDescription_suite_ScannerTestSuite_test_terminal_list1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_terminal_list1() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 261, "test_terminal_list1" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_list1(); }
} testDescription_suite_ScannerTestSuite_test_terminal_list1;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
