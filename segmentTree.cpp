
#include<bits/stdc++.h>
using namespace std;

class SGTree {

public:	
	vector<int> seg;

	SGTree(int n) {
		seg.resize(4 * n + 1) ;
	}

	void build(int ind, int low, int high , int arr[]) {

		if (low == high) {
			seg[ind] = arr[low] ;
			return ;
		}

		int mid = (low + high) >> 1 ;
		build(2 * ind + 1, low, mid, arr) ;
		build(2 * ind + 2, mid + 1, high, arr) ;

		//minimum
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]) ;
	}

	int query(int ind, int low, int high, int l, int r) {

		// no overlap
		if (r < low || high < l) return INT_MAX ;

		// complete overlap
		if (low >= l and high <= r) return seg[ind] ;

		//partial overlap then go left and right
		int mid = (low + high) >> 1 ;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);

		//minimum
		return min(left, right) ;
	}


	void update(int ind, int low, int high, int i, int val) {

		if (low == high) {
			seg[ind] = val;
			return ;
		}

		int mid = (low + high) >> 1;

		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val) ;

		//minimum
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}

};

void solve() {

	int n ;
	cin >> n ;
	int arr[n] ;
	for (int i = 0 ; i < n; i++) cin >> arr[i] ;


	SGTree sg1(n); // object of class SGTree
	sg1.build(0, 0, n - 1, arr) ;

	int q ;
	cin >> q ;

	while (q--) {
		// query type : query or update
		int type ; cin >> type ;

		if (type == 1) {
			int l, r ;
			cin >> l >> r ;
			// for zero based indexing
			--l ; --r ;

			cout << sg1.query(0, 0, n - 1, l, r) << endl;
		}
		else {
			int i , val ; // update value at index i with val
			cin >> i >> val ;

			//for zero based indexing
			--i ;

			sg1.update(0, 0, n - 1, i, val) ;
			arr[i] = val ;
		}

	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	solve();


}
