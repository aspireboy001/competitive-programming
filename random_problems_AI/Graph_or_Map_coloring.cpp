/*

	Graph/map Coloring using backtracking
*/

#include<bits/stdc++.h>
using namespace std ;

class Graph_coloring {

public:

	int number_of_colors ;
	int number_of_nodes ;
	int number_of_edges ;

	vector<int> graph[20] ;
	vector<int> color ;

	Graph_coloring() {
		color.assign(20, 0) ;
	}

	void input() {

		cout << "\nEnter number of colors : ";
		cin >> number_of_colors ;

		cout << "\nEnter number of nodes in graph : ";
		cin >> number_of_nodes ;

		cout << "\nEnter number of edges in graph : ";
		cin >> number_of_edges ;

		cout << "\n\nEnter edge (u ---- v) : \n";
		for (int i = 0 ; i < number_of_edges ; i++) {
			int u , v ;
			cin >> u >> v ;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
	}

	// checks if adjcent has same colors or not
	bool isSafe(int col , int node) {

		for (auto child : graph[node]) {
			if (color[child] == col) return false ;
		}

		return true ;
	}

	// recursive backtracking function
	bool rec(int node) {

		// if color all nodes
		if (node == number_of_nodes + 1) return true ;

		// try out every color
		for (int col = 1 ; col <= number_of_colors; col++) {
			if (isSafe(col, node)) {
				color[node] = col ;
				if (rec(node + 1)) return true;
				color[node] = 0 ;
			}
		}

		// if tried out all color and not possible
		// to color all nodes then return false
		return false ;
	}

	void color_graph() {

		bool fl = rec(1) ;

		if (!fl) {
			cout << "\ncan't possible to color this graph with " << number_of_colors << " colors" << endl;
		}
		else {
			print() ;
		}
	}

	void print() {
		char letter[4] ;
		letter[1] = 'R';
		letter[2] = 'G';
		letter[3] = 'B';
	
		cout<<"\n\nSolution is : \n\n";
		cout << "node(color)  ---->  node(color)" << endl;
		for (int i = 1 ; i < 20 ; i++) {
			if (graph[i].size() > 0) {
				for (int j = 0 ; j < graph[i].size() ; j++) {
					cout << i << "(" << letter[color[i]] << ")" << " ---> " << graph[i][j] << "(" << letter[color[graph[i][j]]] << ")" << endl;
				}
			}
		}
	}
};

int main() {


	Graph_coloring object ;
	object.input() ;
	object.color_graph();
}
