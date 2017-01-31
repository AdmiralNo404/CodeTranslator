#include <iostream>
#include <fstream>
#include <list>
#include <stdlib.h>
#include <utility>

using namespace std;

template <typename T>
class MyList {
	public:
		MyList() { }
		MyList(int s, int e) { for (int i = s; i <= e; i++) data.push_back(i);}
		MyList( list<T> l ) : data(l) { } ;
		MyList( const MyList &l ) : data(l.data) { } ;
		~MyList() { }
		
		template <typename TT>
		friend ostream& operator<<(ostream &, MyList<TT> &) ;

		template <typename TT>
		friend istream& operator>>(istream &, MyList<TT> &) ;
		
		//template <typename TT>
		//friend ifstream& operator>>(ifstream &, MyList<TT> &) ;
		
		template <typename TT>
		MyList<TT> operator+ (MyList<TT> &l) {
			T n;
			MyList<TT> nl = MyList<TT>( data );
			typename list<TT>::const_iterator itr = l.data.begin() ;
			while ( itr != l.data.end() ) {
				n = *itr ;
				nl.push_back( n );
				itr ++ ;
			}
			return nl;
		}
		
		T head() {
			typename list<T>::const_iterator itr = data.begin() ;
			return (*itr);
		}
		
		MyList<T> tail() {
			MyList<T> ret = MyList(data);
			ret.pop_front();
			return ret;
		}
		
		MyList<T> cons( const T t ) {
			MyList<T> ret = MyList(data);
			ret.push_front(t);
			return ret;
		}
		
		bool null() { return data.empty(); }
		
		MyList<T> filter(bool (*funcp)(T)){
			MyList<T> outList;
			T n;
			typename list<T>::const_iterator itr = data.begin();
			while(itr != data.end()){
				n = *itr;
				if((*funcp)(n))
					outList.push_back(n);
				itr++;
			}
			return outList;
		}
		
		template <typename TT>
		MyList< pair<T,TT> > zip( MyList<TT> lista ){
			MyList< pair<T,TT> > outList;
			T n;
			TT m;
			typename list<T>::const_iterator itr1 = data.begin();
			typename list<TT>::const_iterator itr2 = lista.data.begin();
			while(itr1 != data.end() && itr2 != lista.data.end()){
				n = *itr1;
				m = *itr2;
				pair<T,TT> outpair (n,m);
				outList.push_back(outpair);
				itr1++;
				itr2++;
			}
			return outList;
		}
		
		MyList<T> map(T (*funcp)(T)){
			MyList<T> outList;
			T n;
			typename list<T>::const_iterator itr = data.begin();
			while(itr != data.end()){
				n = *itr;
				outList.push_back((*funcp)(n));
				itr++;
			}
			return outList;
		}
		
		T fold(T (*funcp)(T,T),T start){
			T n = start, m;
			typename list<T>::const_iterator itr = data.begin();
			while(itr != data.end()){
				m = *itr;
				n = (*funcp)(n, m);
				itr++;
			}
			return n;
		}
		
		void push_front ( const T t ) { data.push_front (t) ; }
		void push_back( const T t ) { data.push_back(t) ; }
		void pop_front ( ) { data.pop_front() ; }

	private:
		list<T> data;
};

//overload the output operator
template <typename T>
ostream &operator<<(ostream &os, MyList<T> &l) {
    os << "[ " ;
    T n ;
    typename list<T>::const_iterator itr = l.data.begin() ;
    while ( itr != l.data.end() ) {
        n = *itr ;
        os << n ; //(*itr) doesn't work! ;

        itr ++ ;

        if (itr != l.data.end() ) {
            os << ", " ;
        }
    }
    os << " ]";
    return os;
}

template <typename T>
istream& operator>>(istream &is, MyList<T> &l) {
	string n ;
	while ( !is.eof() ) {
		is >> n;
		if (is.eof()) { break; }
		if ((n != "[") && (n != "]")) { l.push_back( atoi( n.c_str() )); }
	}
	return is;
}

template <typename T, typename TT>
ostream& operator<<(ostream &os, pair<T,TT> &p) {
	T n = p.first;
	TT m = p.second;
	os << "( " << n << ", " << m << " )";
	return os;
}

/*
template <typename T>
ifstream& operator>>(ifstream &ifs, MyList<T> &l) {
	string n ;
	while ( !ifs.eof() ) {
		ifs >> n;
		l.push_back( atoi( n.c_str() ) );
	}
	return ifs;
}
*/

MyList<string> mkArgs(int argc, char** argv) {
	MyList<string> r;
	for (int i=1; i<argc; i++) {
		string s(argv[i]);
		r.push_back(s);
	}
	return r;
}
