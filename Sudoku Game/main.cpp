

#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
#define ld long double
//#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

// const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;



const int SIZE = 9;

vector<vector<int>> board(11, vector<int>(11, 0));

void displayBoard() {

    system("cls"); //// use "clear" if on Linux/macOS

    cout << "-------------------------\n";
    for (int i = 1 ; i <= SIZE; i++) {
        cout << "| ";

        for (int j = 1; j <= SIZE; j++) {

            if (board[i][j] == 0)

                cout << ". ";
            else
                cout << board[i][j] << " ";

            if ((j+0) % 3 == 0) cout << "| ";
        }
        cout << "\n";

        if ((i + 0) % 3 == 0)

            cout << "-------------------------\n";
    }

}


///*******************************************************************************************///

//// Check if placing val at board[row][col] is valid (1-based) ////

bool isValidMove(int row, int col, int val) {

    //// Check row ////
    for (int j = 1; j <= SIZE; j++) {

        if (board[row][j] == val) return false;

    }
    //// Check column ////
    for (int i = 1; i <= SIZE; i++) {

        if (board[i][col] == val) return false;
    }

    //// Check 3x3 box ////

    int startRow = (( row - 1) / 3) * 3 + 1;  //// 1-based start

    int startCol = ((col - 1) / 3) * 3 + 1;  //// 1-based start

    for (int i = startRow ; i < startRow + 3; i++) {

        for (int j = startCol; j < startCol + 3; j++) {

            if (board[i][j] == val)

                return false;
        }
    }
    return true ;
}

/// ********************************************************************************************///

////  Let user enter a move (1-based) ////

void userMove() {

    int row, col, val;
    cout << "Enter row (1-9), col (1-9), value (1-9): ";

    cin >> row >> col >> val;

    //// Check input range for 1-based indexing ////

    if (row < 1 || row > SIZE || col < 1 || col > SIZE || val < 1 || val > 9) {
        cout << "Invalid input range!\n";
        return;
    }

    //// Check if the cell is already filled ////

    if (board[row][col] != 0) {
        cout << "Cell already filled!\n";
        return;
    }

    //// Check if the move is valid according to Sudoku rules ////

    if ( !isValidMove(row, col, val) ) {

        cout << "Move violates Sudoku rules!\n";
        return;
    }

    //// Make the move  ////
    board[row][col] = val;
    cout << "Move accepted!\n";

}



///****************************************************************************************************////

//// Backtracking Sudoku solver (1-based) ////
bool solveSudoku() {

    for (int i = 1; i <= SIZE; i++) {         //// rows 1 to SIZE///

        for (int j = 1; j <= SIZE; j++) {     ////  cols 1 to SIZE

            if (board[i][j] == 0) {           //// empty cell ////

                for (int val = 1; val <= 9; val++) {

                    //// Base Case ////
                    if ( isValidMove(i, j, val) ) {

                        //// Transition ////

                        board[i][j] = val ;

                        if ( solveSudoku() ) return true ; //// recursive call ///

                        board[i][j] = 0;               //// backtrack ////
                    }
                }

                return false; //// no valid number found ////
            }
        }
    }

    return true; //// all cells filled ////
}


///************************************************************************************************///

void generatePuzzle( string difficulty ) {

    //// Step 1: Clear board ////

    for (auto &row : board)

        fill(row.begin(), row.end(), 0);

    //// Step 2: Fill some random cells for variability ////

    random_device rd; //// standard C++ library tools ////
    mt19937 gen(rd());
    uniform_int_distribution<> disVal(1, 9);   //// value 1-9 ////
    uniform_int_distribution<> disCell(1, 9);  //// row/col 1-9 ////

    //  int filled = 0;

    //while ( filled < 10 ) {   //// fill 10 random cells ////

    //  int r = disCell(gen);   //// 1-9 ////

    // int c = disCell(gen);   //// 1-9 ////

    //int val = disVal(gen);  //// 1-9 ////

    // if (board[r][c] == 0 && isValidMove (r, c, val) ) {

    // board[r][c] = val ;

    // filled++;

    // }

    // }

    //// Step 3: Solve board completely ////

    solveSudoku();

    //// Step 4: Remove numbers according to difficulty ////

    int removeCount;
    if (difficulty == "easy") removeCount = 30 ;

    else if (difficulty == "medium") removeCount = 45 ;

    else removeCount = 55 ;  //// hard ///

    while (removeCount > 0) {

        int r = disCell(gen ) ;

        int c = disCell(gen ) ;

        if ( board[r][c] != 0 ) {

            board[r][c] = 0 ;

            removeCount-- ;

        }
    }
}

///***************************************************************************************************************///

void printMenu() {

    cout << "\nMENU:\n";
    cout << "1. Enter a move\n";
    cout << "2. Solve automatically\n";
    cout << "3. Generate new puzzle\n";
    cout << "4. Exit\n";
    cout << "Choose: ";

}



int main() {


    string diff;

    while ( true ) {

        displayBoard();
        printMenu();

        int choice;
        cin >> choice;

        if (choice == 1) {  //// Enter a move ////

            userMove();

            system("pause"); //// Wait for user to see messages ////
        }

        else if (choice == 2) {  //// Solve automatically ////

            if ( solveSudoku() ) {

                displayBoard();

                cout << "Puzzle solved successfully!\n";

            } else {

                cout << "No solution exists!\n";

            }

            system("pause");
        }

        else if (choice == 3) {  //// Generate new puzzle ////

            while (true) {

                cout << "Select difficulty (easy / medium / hard): ";

                cin >> diff;

                if (diff == "easy" || diff == "medium" || diff == "hard") break;

                else cout << "Invalid choice!\n";

            }

            generatePuzzle(diff);

        }
        else if (choice == 4) {  //// Exit ////

            cout << "Thanks for playing!\n";

            break;

        }

        else {

            cout << "Invalid choice!\n";

            system("pause");

        }
    }


    return 0 ;

}






