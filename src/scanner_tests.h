#include <cxxtest/TestSuite.h>

#include "readInput.h"
#include "scanner.h"

using namespace std ;

class ScannerTestSuite : public CxxTest::TestSuite 
{
public:
    /* A Scanner object is created in the test_setup_code method.
       This is a test, beginning with "test_", so that it is executed
       by the testing framework.  The scanner is used in some tests of
       the method "scan".
     */
    Scanner *s ;
    void test_setup_code ( ) {
        s = new Scanner() ;
    }

	//Code from i1_assessment_tests.h
	/* This function checks that the terminal fields in the list of
		   tokens matches a list of terminals.
		 */
		bool sameTerminals (Token *tks, int numTerms, terminal_t *ts) {
			Token *currentToken = tks ;
			int termIndex = 0 ;
			while (currentToken != NULL && termIndex < numTerms ) {
				if (currentToken->terminal != ts[termIndex]) {
					return false ;
				}
				else {
					++ termIndex ;
					currentToken = currentToken->next ;
				}
			}
			return true ;
		}
	
    // Tests for components and functions used by "scan"
    // --------------------------------------------------
    void test_terminal_letKwd() {
		Token * t = s->scan("let");
		TS_ASSERT_EQUALS(t->terminal, letKwd);
    }
    void test_terminal_inKwd() {
		Token * t = s->scan("in");
		TS_ASSERT_EQUALS(t->terminal, inKwd);
    }
    void test_terminal_endKwd() {
		Token * t = s->scan("end");
		TS_ASSERT_EQUALS(t->terminal, endKwd);
    }
    void test_terminal_ifKwd() {
		Token * t = s->scan("if");
		TS_ASSERT_EQUALS(t->terminal, ifKwd);
    }
    void test_terminal_thenKwd() {
		Token * t = s->scan("then");
		TS_ASSERT_EQUALS(t->terminal, thenKwd);
    }
    void test_terminal_elseKwd() {
		Token * t = s->scan("else");
		TS_ASSERT_EQUALS(t->terminal, elseKwd);
    }
    void test_terminal_printKwd() {
		Token * t = s->scan("print");
		TS_ASSERT_EQUALS(t->terminal, printKwd);
    }
    void test_terminal_readKwd() {
		Token * t = s->scan("read");
		TS_ASSERT_EQUALS(t->terminal, readKwd);
    }
    void test_terminal_writeKwd() {
		Token * t = s->scan("write");
		TS_ASSERT_EQUALS(t->terminal, writeKwd);
    }
    void test_terminal_integerKwd() {
		Token * t = s->scan("Integer");
		TS_ASSERT_EQUALS(t->terminal, integerKwd);
    }
    void test_terminal_floatKwd() {
		Token * t = s->scan("Float");
		TS_ASSERT_EQUALS(t->terminal, floatKwd);
    }
    void test_terminal_booleanKwd() {
		Token * t = s->scan("Boolean");
		TS_ASSERT_EQUALS(t->terminal, booleanKwd);
    }
    void test_terminal_stringKwd() {
		Token * t = s->scan("String");
		TS_ASSERT_EQUALS(t->terminal, stringKwd);
    }
    void test_terminal_trueKwd() {
		Token * t = s->scan("true");
		TS_ASSERT_EQUALS(t->terminal, trueKwd);
    }
    void test_terminal_falseKwd() {
		Token * t = s->scan("false");
		TS_ASSERT_EQUALS(t->terminal, falseKwd);
    }
    void test_terminal_headKwd() {
		Token * t = s->scan("head");
		TS_ASSERT_EQUALS(t->terminal, headKwd);
    }
    void test_terminal_tailKwd() {
		Token * t = s->scan("tail");
		TS_ASSERT_EQUALS(t->terminal, tailKwd);
    }
    void test_terminal_nullKwd() {
		Token * t = s->scan("null");
		TS_ASSERT_EQUALS(t->terminal, nullKwd);
    }
    void test_terminal_mapKwd() {
		Token * t = s->scan("map");
		TS_ASSERT_EQUALS(t->terminal, mapKwd);
    }
    void test_terminal_filterKwd() {
		Token * t = s->scan("filter");
		TS_ASSERT_EQUALS(t->terminal, filterKwd);
    }
    void test_terminal_foldKwd() {
		Token * t = s->scan("fold");
		TS_ASSERT_EQUALS(t->terminal, foldKwd);
    }
    void test_terminal_zipKwd() {
		Token * t = s->scan("zip");
		TS_ASSERT_EQUALS(t->terminal, zipKwd);
    }

    // Constants
    void test_terminal_intConst() {
    	Token * t = s->scan("10");
    	TS_ASSERT_EQUALS(t->terminal, intConst);
    }
    void test_terminal_floatConst() {
    	Token * t = s->scan("10.23");
    	TS_ASSERT_EQUALS(t->terminal, floatConst);
    }
    void test_terminal_stringConst() {
    	Token * t = s->scan("\"Hello World\"");
    	TS_ASSERT_EQUALS(t->terminal, stringConst);
    }

    //Names
    void test_terminal_variableName() {
    	Token * t = s->scan("print x");
    	TS_ASSERT_EQUALS(t->next->terminal, variableName);
    }

    // Punctuation
    void test_terminal_leftParen() {
    	Token * t = s->scan("(");
    	TS_ASSERT_EQUALS(t->terminal, leftParen);
    }
    void test_terminal_rightParen() {
    	Token * t = s->scan(")");
    	TS_ASSERT_EQUALS(t->terminal, rightParen);
    }
    void test_terminal_leftSqaure() {
    	Token * t = s->scan("[");
    	TS_ASSERT_EQUALS(t->terminal, leftSquare);
    }
    void test_terminal_rightSquare() {
    	Token * t = s->scan("]");
    	TS_ASSERT_EQUALS(t->terminal, rightSquare);
    }
    void test_terminal_leftAngle() {
    	Token * t = s->scan("<");
    	TS_ASSERT_EQUALS(t->terminal, leftAngle);
    }
    void test_terminal_rightAngle() {
    	Token * t = s->scan(">");
    	TS_ASSERT_EQUALS(t->terminal, rightAngle);
    }
    void test_terminal_colon() {
    	Token * t = s->scan(":");
    	TS_ASSERT_EQUALS(t->terminal, colon);
    }
    void test_terminal_colonColon() {
    	Token * t = s->scan("::");
    	TS_ASSERT_EQUALS(t->terminal, colonColon);
    }
    void test_terminal_comma() {
    	Token * t = s->scan(",");
    	TS_ASSERT_EQUALS(t->terminal, comma);
    }
    void test_terminal_semiColon() {
    	Token * t = s->scan(";");
    	TS_ASSERT_EQUALS(t->terminal, semiColon);
    }
    void test_terminal_equalsSign() {
    	Token * t = s->scan("=");
    	TS_ASSERT_EQUALS(t->terminal, equalsSign);
    }
    void test_terminal_plusSign() {
    	Token * t = s->scan("+");
    	TS_ASSERT_EQUALS(t->terminal, plusSign);
    }
    void test_terminal_star() {
    	Token * t = s->scan("*");
    	TS_ASSERT_EQUALS(t->terminal, star);
    }
    void test_terminal_dash() {
    	Token * t = s->scan("-");
    	TS_ASSERT_EQUALS(t->terminal, dash);
    }
    void test_terminal_forwardSlash() {
    	Token * t = s->scan("/");
    	TS_ASSERT_EQUALS(t->terminal, forwardSlash);
    }
    void test_terminal_percent() {
    	Token * t = s->scan("%");
    	TS_ASSERT_EQUALS(t->terminal, percent);
    }
    void test_terminal_backSlash() {
    	Token * t = s->scan("\\");
    	TS_ASSERT_EQUALS(t->terminal, backSlash);
    }
    void test_terminal_arrow() {
    	Token * t = s->scan("->");
    	TS_ASSERT_EQUALS(t->terminal, arrow);
    }
    void test_terminal_equalsEquals() {
    	Token * t = s->scan("==");
    	TS_ASSERT_EQUALS(t->terminal, equalsEquals);
    }
    void test_terminal_lessThanEquals() {
    	Token * t = s->scan("<=");
    	TS_ASSERT_EQUALS(t->terminal, lessThanEquals);
    }
    void test_terminal_greaterThanEquals() {
    	Token * t = s->scan(">=");
    	TS_ASSERT_EQUALS(t->terminal, greaterThanEquals);
    }
    void test_terminal_notEquals() {
    	Token * t = s->scan("!=");
    	TS_ASSERT_EQUALS(t->terminal, notEquals);
    }
    void test_terminal_plusPlus() {
    	Token * t = s->scan("++");
    	TS_ASSERT_EQUALS(t->terminal, plusPlus);
    }
    void test_terminal_dotDot() {
    	Token * t = s->scan("..");
    	TS_ASSERT_EQUALS(t->terminal, dotDot);
    }
    void test_terminal_tupleOp() {
    	Token * t = s->scan("#1");
    	TS_ASSERT_EQUALS(t->terminal, tupleOp);
    }
    void test_terminal_endOfFile() {
    	Token * t = s->scan("");
    	TS_ASSERT_EQUALS(t->terminal, endOfFile);
    }
    void test_terminal_lexicalError() {
    	Token * t = s->scan("!");
    	TS_ASSERT_EQUALS(t->terminal, lexicalError);
    }

	void test_terminal_list1() {
		Token * t = s->scan("let if end 1.2 3 \"hello world\" \"hi\" () [] @ ==");
		terminal_t terminals[] = {
			letKwd, ifKwd, endKwd, floatConst, intConst, stringConst,
			stringConst, leftParen, rightParen, leftSquare, rightSquare, 
			lexicalError, equalsEquals
		} ;
		TS_ASSERT(sameTerminals(t, 11, terminals));
	}
	
    /* You will need to write several tests to adequately test the
       functions that are called from "scan".  Once you are confident
       that the components used by "scan" work properly, then you can
       run tests on the "scan" method itself.
    */

    // Here you should place tests for these other functions.

    /* Below is one of my tests for these components.  It uses a
       helper function function called "tokenMaker_tester", which you
       have not been given.  You are expected to design your own
       components for "scan" and your own mechanisms for easily
       testing them. The example test can be simplified AND improved
	   upon with respect to good testing principles.

        void xtest_TokenMaker_leftCurly ( ) {
            tokenMaker_tester ("{ ", "^\\{", leftCurly, "{" ) ;
        }

        Note that this test is here named "xtest_Token..." The leading
        "x" is so that cxxTest doesn't scan the line above and think
        it is an actual test that isn't commented out.  cxxTest is
        very simple and doesn't even process block comments.
    */
    // See i1_assessment_tests.h and your CxxTest lab for examples

    /* Remember, you have to write a test for each of the terminal
     * types in the language - each terminal is specified in the 
     * tokenEnumType in scanner.h
     */




} ;





