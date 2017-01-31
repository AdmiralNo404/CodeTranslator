#include "../samples/common_header.h"
using namespace std;
int main( int argc, char** argv ) {
	MyList<string> args = mkArgs(argc, argv) ;
	return ({ MyList<int>  xs = ({ MyList<int> temp(1 , 10); temp; }) ;
 MyList<int>  ys = ({ MyList<int> temp(11 , 20); temp; }) ;
 MyList<pair<  int,  int > >  ps = (xs.zip(ys) ) ;
(({ cout << ps << endl ; cout.good() ? 0 : 1 ; })) ; });
}

