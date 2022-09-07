
#include<bits/stdc++.h>
using namespace std ;

// GL = giants on left edge    GR = giants on right edge
// HL = humans on left edge    HR = humans on right edge
// edge : 0 = left , 1 = right

int visited[4][4][4][4][4] ;
vector<vector<int>> store ;


void insert(int a, int b , int c, int d, int e) {
	store.push_back({a, b, c, d, e});
}


bool f(int GL , int HL , int GR , int HR , int edge ) {

	if ((GL > HL and HL != 0) || (GR > HR and HR != 0) || (GL < 0 || GL > 3 || HL < 0 || HL > 3)) return false ;


	if (GR == 3 and HR == 3) return true ;


	if (visited[GL][HL][GR][HR][edge] == 1) return false ;


	visited[GL][HL][GR][HR][edge] = 1 ;


	bool f1 = 0 , f2 = 0 , f3 = 0 , f4 = 0 , f5 = 0 ;
	//11,10,01,20,02

	if (edge == 0) { // boat on the left edge of river

		f1 = f(GL - 1 , HL - 1 , GR + 1 , HR + 1 , 1) ;
		if (f1)
			insert(GL - 1 , HL - 1 , GR + 1 , HR + 1 , 1 ) ;


		f2 = f(GL - 1 , HL , GR + 1 , HR , 1 ) ;
		if (f2)
			insert(GL - 1 , HL , GR + 1 , HR , 1 ) ;


		f3 = f(GL , HL - 1 , GR , HR + 1 , 1 ) ;
		if (f3)
			insert(GL , HL - 1 , GR , HR + 1 , 1 ) ;


		f4 = f(GL - 2, HL , GR + 2 , HR , 1 ) ;
		if (f4)
			insert(GL - 2, HL , GR + 2 , HR , 1 ) ;

		f5 = f(GL , HL - 2 , GR , HR + 2 , 1 ) ;
		if (f5)
			insert(GL , HL - 2 , GR , HR + 2 , 1 ) ;

	}
	else { // boat on right edge of river


		f1 = f(GL + 1 , HL + 1 , GR - 1 , HR - 1 , 0 ) ;
		if (f1)
			insert(GL + 1 , HL + 1 , GR - 1 , HR - 1 , 0 ) ;

		f2 = f(GL + 1 , HL , GR - 1 , HR , 0 ) ;
		if (f2)
			insert(GL + 1 , HL , GR - 1 , HR , 0 ) ;

		f3 = f(GL , HL + 1 , GR , HR - 1 , 0 ) ;
		if (f3)
			insert(GL , HL + 1 , GR , HR - 1 , 0 ) ;

		f4 = f(GL + 2, HL , GR - 2 , HR , 0 ) ;
		if (f4)
			insert(GL + 2, HL , GR - 2 , HR , 0 ) ;

		f5 = f(GL , HL + 2 , GR , HR - 2 , 0 ) ;
		if (f5)
			insert(GL , HL + 2 , GR , HR - 2 , 0 ) ;

	}

	return (f1 | f2 | f3 | f4 | f5) ;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	bool done = false ;

	f(3, 3, 0, 0, 0) ;

	cout << "GL\tHL\tGR\tHR\tEdge\n\n";


	cout << "3\t3\t0\t0\t0" << endl;
	for (int i = store.size() - 1; i >= 0 ; i--) {
		for (int j = 0 ; j < 5; j++) {
			cout << store[i][j] << "\t";
			if (store[i][2] == 3 and store[i][3] == 3) done = 1;
		}
		cout << endl;
		if (done) break;
	}

}