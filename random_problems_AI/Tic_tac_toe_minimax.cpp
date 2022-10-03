/*
    Author : Chetan Shekhar Patil
    Tic_tac_toe game using minimax algorithm
    (never losing AI ;) )
*/

#include<bits/stdc++.h>
#define cout std::cout
#define cin std::cin
#define endl std::endl

class move {
public:
    // a move will have its location(r,c)
    // and score got because of that move
    int r , c , score ;
};


class Tic_Tac_Toe {

public:

    // ai = opponent
    char player , ai ;
    std::vector<std::vector<char>> board ;

    Tic_Tac_Toe() {
        // 3 x 3 tic tac toe grid
        board.assign(3, std::vector<char>(3, ' ')) ;
    }

    // for printing grid
    void print() {
        cout << endl;
        for (int i = 0 ; i < 3 ; i++) {
            if (i > 0) cout << "------------\n";
            for (int j = 0 ; j < 3 ; j++) {
                if (j > 0) cout << "|";
                cout << " ";
                if (board[i][j] == ' ') {
                    // cell number (1 to 9)
                    cout << (3 * i) + j + 1;
                }
                else cout << board[i][j] ;
                cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // check whethers if board current state is win or not
    bool is_win() {
        // all possible win states
        // same symbol in row , column , both diagonals
        int win_states[8][3]  = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7} , {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

        for (int i = 0 ; i < 8; i++) {
            bool win = true ;

            int first_r = win_states[i][0] / 3 ;
            int first_c = win_states[i][0] % 3 ;

            for (int j = 0 ; j < 3 ; j++) {
                int r = win_states[i][j] / 3 ;
                int c = win_states[i][j] % 3 ;

                // all 3 cells should have same symbol to win
                // and cell should not be blank as well
                if (board[first_r][first_c] == ' ' || board[first_r][first_c] != board[r][c]) win = false ;
            }

            if (win) return true ;
        }

        return false ;
    }


    // check whethers if board current state is tie or not
    bool is_tie() {
        if (is_win()) return false ;

        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                // if any one cell is blank then not tie
                // still further moves possible
                if (board[i][j] == ' ') return false ;
            }
        }
        // if no win , no blank cell
        // then definately tie
        return true ;
    }

    // taking input from user for player move
    void player_move() {
        while (true) {
            cout << "\nEnter empty cell number (1-9) : ";
            int cell ; cin >> cell;

            int r = (cell - 1) / 3; // r = x-coordinate
            int c = (cell - 1) % 3; // c = y-coordinate

            if (cell >= 1 and cell <= 9 and board[r][c] == ' ') {
                board[r][c] = player ;
                break;
            }
        }
    }

    // ai/opponent will use minimax algo to do best move
    void ai_move() {
        move best_move = minimax() ;
        board[best_move.r][best_move.c] = ai ;
        // ai = symbol of opponent (O or X)
    }

    // minimax algorithm
    move minimax(bool maximizing_player = true) {

        move best_move ;

        if (is_win()) {

            if (maximizing_player) {
                best_move.score = -1 ;
            }
            else best_move.score = 1 ;

            return best_move ;
        }
        else if (is_tie()) {
            best_move.score = 0 ;
            return best_move ;
        }


        best_move.score = (maximizing_player) ? -2 : 2;

        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                if (board[i][j] == ' ') {

                    board[i][j] = (maximizing_player) ? ai : player ;
                    move board_state = minimax(!maximizing_player);

                    if (maximizing_player) { // max
                        if (board_state.score > best_move.score) {
                            best_move.score = board_state.score;
                            best_move.r = i ;
                            best_move.c = j ;
                        }
                    }
                    else { // min
                        if (board_state.score < best_move.score) {
                            best_move.score = board_state.score;
                            best_move.r = i ;
                            best_move.c = j ;
                        }
                    }

                    board[i][j] = ' ' ;
                }
            }
        }

        return best_move ;
    }


    void start_game() {

        while (true) {
            cout << "\n Choose your Symbol : (X/O) : ";
            cin >> player ;
            if (player == 'X' || player == 'O') break;
            else cout << "\nwrong choice , please Choose again \n";
        }

        ai = (player == 'X') ? 'O' : 'X' ;

        print();

        while (true) {
            player_move() ;
            print();
            if (is_win()) {
                cout << "\n** Congratulations, You won **\n";
                return ;
            }
            else if (is_tie()) {
                cout << "\nGame tied\n" ;
                return ;
            }
            cout << "\nOpponent is making move ... \n" ;
            ai_move();
            print() ;
            if (is_win()) {
                cout << "\n** Opponent wins **\n";
                return ;
            }
            else if (is_tie()) {
                cout << "\nGame tied\n" ;
                return ;
            }
        }
    }

};

int main() {
	
    Tic_Tac_Toe game ;
    game.start_game();

}
