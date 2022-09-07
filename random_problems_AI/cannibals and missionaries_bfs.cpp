
#include<bits/stdc++.h>
using namespace std ;

// GL = giants on left edge    GR = giants on right edge
// HL = humans on left edge    HR = humans on right edge
// edge : 0 = left , 1 = right

int visited[4][4][4][4][4] ;

int destiNation_node = 0 ;

class node {
public:
	int GL , HL , GR , HR , edge , no, pt ;
	// no = node number in graph
	// pt = parent of current node
};


node allStates[150] ;

void print(node &child) {
	cout << child.GL << "  " << child.HL << "  " << child.GR << "  " << child.HR << "  " << child.edge << endl;
}

bool is_valid(node &child) {

	if (visited[child.GL][child.HL][child.GR][child.HR][child.edge] == 1) return false;

	if ((child.GL > child.HL and child.HL != 0) || (child.GR > child.HR and child.HR != 0)) return false ;

	if ( child.GL <= 3 and child.GL >= 0 and child.HL <= 3 and child.HL >= 0 and child.HR <= 3 and child.HR >= 0 and child.GR <= 3 and child.GR >= 0) return true;

	return false ;
}

void update(node &child, int a, int b, int c , int d, int e , int p , int n) {
	child.GL += a ;
	child.HL += b ;
	child.GR += c ;
	child.HR += d ;
	child.edge = e ;
	child.no = n ;
	child.pt = p ;
}


void bfs() {

	queue<node> q ;

	//		GL HL GR HR Edg No par
	q.push({3, 3, 0, 0, 0 , 1 , 0});

	int last = 2 ;

	while (!q.empty()) {

		node parent = q.front() ;
		q.pop();

		allStates[parent.no] = parent ;

		if (parent.GR == 3 and parent.HR == 3) {
			destiNation_node = parent.no;
			return ;
		}

		visited[parent.GL][parent.HL][parent.GR][parent.HR][parent.edge] = 1 ;

		node child1 = parent , child2 = parent , child3 = parent, child4 = parent , child5 = parent ;

		if (parent.edge == 0) {
			update(child1, -1, -1, 1, 1, 1 , parent.no, last++ ) ;
			update(child2, -1, 0, 1, 0, 1 , parent.no, last++ ) ;
			update(child3, 0, -1, 0, 1, 1, parent.no, last++ ) ;
			update(child4, -2, 0, 2, 0, 1, parent.no, last++ ) ;
			update(child5, 0, -2, 0, 2, 1, parent.no, last++ ) ;
		}
		else {
			update(child1, 1, 1, -1, -1, 0, parent.no, last++ ) ;
			update(child2, 1, 0, -1, 0, 0, parent.no, last++ ) ;
			update(child3, 0, 1, 0, -1, 0, parent.no, last++ ) ;
			update(child4, 2, 0, -2, 0, 0, parent.no, last++ ) ;
			update(child5, 0, 2, 0, -2, 0, parent.no, last++ ) ;
		}


		if (is_valid(child1)) q.push(child1) ;
		if (is_valid(child2)) q.push(child2) ;
		if (is_valid(child3)) q.push(child3) ;
		if (is_valid(child4)) q.push(child4) ;
		if (is_valid(child5)) q.push(child5) ;

	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	bfs() ;

	int i = destiNation_node ;

	vector<node> ans ;

	while (i > 0) {
		ans.push_back(allStates[i]);
		i = allStates[i].pt;
	}

	reverse(ans.begin() , ans.end()) ;

	cout << "GL HL GR HR Edge\n";
	for (int i = 0 ; i < ans.size() ; i++) {
		print(ans[i]);
	}

}