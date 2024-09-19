#include <iostream>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;

void drawBoard() {
    cout << "Current board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--|---|--\n";
    }
    cout << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;  // No winner
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;  // At least one spot is free
            }
        }
    }
    return true;  // Board is full
}

void swapPlayer() {
    if (current_player == 1) {
        current_player = 2;
        current_marker = 'O';
    } else {
        current_player = 1;
        current_marker = 'X';
    }
}

void playGame() {
    cout << "Player 1, choose your marker (X or O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    if (marker_p1 == 'X') {
        current_marker = 'X';
    } else {
        current_marker = 'O';
    }

    int winner = 0;
    while (winner == 0 && !checkDraw()) {
        drawBoard();

        cout << "Player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid slot! Try again.\n";
            continue;
        }

        winner = checkWinner();
        if (winner == 0) {
            swapPlayer();
        }
    }

    drawBoard();
    if (winner == 0 && checkDraw()) {
        cout << "It's a draw!\n";
    } else {
        cout << "Player " << winner << " wins!\n";
    }
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        // Reset the board
        board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
        board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
        board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';

        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    return 0;
}