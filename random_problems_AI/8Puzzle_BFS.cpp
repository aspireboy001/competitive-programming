/*
    Author : Chetan Shekhar Patil
    8 Puzzle Problem Solution using Breadth First
    Search algorithm

*/

#include<bits/stdc++.h>
using namespace std ;

class node {
public:
    vector<vector<int>> state ; // state is 2D Matrix
    int node_no; // node number
    int parent_no; // parent_number
};

class Eight_Puzzle_BFS {

public:

    // initial state of 8 Puzzle game
    vector<vector<int>> initial;

    // goal state of 8 Puzzle game
    vector<vector<int>> goal;

    int destination_node_number ;

    // stores all states
    node allStates[2000] ;

    // marks visited node to avoid re-exploration
    set<vector<vector<int>>> visited ;

    Eight_Puzzle_BFS() {
        initial.assign(3, vector<int>(3)) ;
        goal.assign(3, vector<int>(3)) ;
        destination_node_number = -1 ;
    }

    // taking input of initial and final state
    // from user
    void input() {

        cout << "Please Input initial state : \n\n";
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                cin >> initial[i][j];
            }
        }

        cout << "\nPlease Input final state : \n\n";
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                cin >> goal[i][j];
            }
        }

    }

    // function to produce successors of current state
    // ( up , down , left , right )
    vector<vector<int>> successors(vector<vector<int>> arr , int r , int c ) {

        // for marking location of empty block
        // empty block means Zero here
        int vacant_i = 0 , vacant_j = 0;

        for (int i = 0 ; i < 3; i++) {
            for (int j = 0 ; j < 3; j++) {
                if (arr[i][j] == 0) {
                    vacant_i = i ;
                    vacant_j = j ;
                    break;
                }
            }
        }

        int access_i = vacant_i + r ;
        int access_j = vacant_j + c ;

        // checking whether generated state will be
        // valid or not
        if (access_j > 2 || access_j < 0 || access_i < 0 || access_i > 2)
            return {{ -1}}; // if invalid
        else {
            swap(arr[access_i][access_j], arr[vacant_i][vacant_j]);
            return arr; // if valid
        }
    }

    // solving using Breadth first search
    void BFS() {

        queue<node> q ;

        //{state , nodeNumber , parentNumber}
        q.push({initial , 1 , 1 }) ;

        int nodeNumber = 2 ;

        while (!q.empty()) {

            node current = q.front();
            q.pop() ;

            // storing state
            allStates[current.node_no] = current ;

            // goal check
            if (current.state == goal) {
                destination_node_number = current.node_no;
                break ;
            }

            // if already visited means already explored
            // also , so skip it
            if (visited.find(current.state) != visited.end()) {
                continue ;
            }

            // mark state visited
            visited.insert(current.state) ;

            int parent = current.node_no ;

            // for storing generated successors
            vector<vector<int>> allChilds[4] ;

            //up
            allChilds[0] = successors(current.state, -1, 0) ;

            //down
            allChilds[1] = successors(current.state, 1, 0) ;

            //left
            allChilds[2] = successors(current.state, 0, -1) ;

            //right
            allChilds[3] = successors(current.state, 0, 1) ;

            for (int i = 0 ; i < 4 ; i++) {
                if (allChilds[i][0][0] != -1) {
                    q.push({ allChilds[i] , ++nodeNumber , parent });
                }
            }
        }
    }

    // for printing final solution stored in allState array
    void print_solution() {

        int start = destination_node_number ;

        vector<vector<vector<int>>> answer ;

        while (true) {
            answer.push_back(allStates[start].state) ;
            if (start == 1) break;
            start = allStates[start].parent_no ;
        }

        reverse(answer.begin(), answer.end()) ;

        cout << "\nSolution is : \n\n";
        for (int i = 0 ; i < answer.size() ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                for (int k = 0 ; k < 3; k++) {
                    cout << answer[i][j][k] << " ";
                }
                cout << endl;
            }

            cout << endl ;
        }
    }
};

int main() {

    Eight_Puzzle_BFS object ;
    object.input();
    object.BFS();
    object.print_solution();

    /*

    inputs:

    1 2 3
    4 5 6
    7 8 0

    4 1 3
    7 2 5
    0 8 6

    */
}
