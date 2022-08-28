
//  ----------------------------------------------------------------

// CUSTOM BEHAVIOUR IN SETS (stl cpp)

// pii = pair<int,int> 

//just an example
struct comp {
	bool operator()(const pii &p1, const pii &p2) const {
		ll diff1 = p1.ss - p1.ff - 1 ;
		ll diff2 = p2.ss - p2.ff - 1 ;

		if (diff1 == diff2) return p1.ff < p2.ff ;
		return diff1 > diff2 ;
	}
};

set<pii, comp> st;

//--------------------------------------------------------------








// ------------------------------------------------------------
// CUSTOM SORTING IN LIST
typedef pair<int, int> pii;

list<pii> mylist;

mylist.sort([](const pii & a, const pii & b) { return a.first < b.first; });
//-------------------------------------------------------------







/*
    Even Before Odd
    sort(v.begin(), v.end(), [](int a , int b) {
        return a % 2 < b % 2 ;
    });

    stoll       --> string to number
    to_string   --> number to string
    'c' - '0'   --> char to digit
    '0' + i     --> digit to char (i=10 -> ":" , i=11 -> ";" '0' == 48 ascii)
    
    s.append(len,char)

    print chars(A...Z) : 97 + i(0....25)
    print chars(a...z) : 65 + i(0....25)

    cout << fixed << setprecision(9);

*/
