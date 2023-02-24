#include <iostream>
#include <cstring>
#include <cctype>

using std::cout;

int startupClues = 0;
int boardData[81];
int startupSelectedTile;
int startupGivenValue;

void drawBoard() {
    cout << "\n    1 2 3   4 5 6   7 8 9" << std::endl;
    cout << "  +-------+-------+-------+" << std::endl;
    for (int row = 0; row < 9; row++) {
        cout << row+1 << " | ";
        for (int col = 0; col < 9; col++) {
            int index = (row)*9 + col;
            int value = boardData[index];
            if (value == 0) {
                cout << "0";
            } else {
                cout << value;
            }
            cout << " ";
            if ((col+1) % 3 == 0) {
                cout << "| ";
            }
        }
        cout << std::endl;
        if ((row+1) % 3 == 0) {
            cout << "  +-------+-------+-------+" << std::endl;
        }
    }
}

void boardStartup(){
    drawBoard();
    std::string startupRow, startupCol;
    std::string startupGivenValue;
    
    std::cin >> startupRow >> startupCol;
    bool isNumeric = true;
            for (char x : startupRow){
                if (!isdigit(x)) {
                    isNumeric = false;
                    break;
                }
            }
            for (char y : startupCol){
                if (!isdigit(y)) {
                    isNumeric = false;
                    break;
                }
            }
    if ((startupRow.empty() || (!isNumeric)) &&
        (startupCol.empty() || (!isNumeric))) {
        cout << "Invalid input. Please input an integer.\n";
        boardStartup();
    } else {
        startupSelectedTile = (std::stoi(startupRow) - 1)*9 + std::stoi(startupCol);

        cout << "You have selected row " << startupRow << " and column " << startupCol << ". ";

        if (startupSelectedTile > 0 && startupSelectedTile < 82) {
            std::cin >> startupGivenValue;
            bool isNumeric = true;
            for (char c : startupGivenValue) {
                if (!isdigit(c)) {
                    isNumeric = false;
                    break;
                }
            }
            if (startupGivenValue.empty() || !isNumeric) {
                cout << "Invalid input. Please input an integer.\n";
                boardStartup(); 
            } else if (std::stoi(startupGivenValue) > 0 && std::stoi(startupGivenValue) <= 9){
                boardData[startupSelectedTile - 1] = std::stoi(startupGivenValue);
                cout << "\nTile number " << startupSelectedTile << " has been set to " << startupGivenValue;
                startupClues++;
                cout << "\nNow select another tile.";
                boardStartup();
            } else {
                cout << "Invalid input. Please input an integer between 1 and 9.\n";
                boardStartup();
            }
        } else {
            cout << "Invalid input. Please select a tile between 1 and 81.\n";
            boardStartup();
        }
                
    }
    
    if (startupSelectedTile == 0 && startupClues < 17){//if user tries to quit board setup without enough information.
        cout << "Minimum clues needed to solve sudoku is 17. But you only provided " << startupClues << ". Please provide " << 17 - startupClues << " more\n";
        boardStartup();
    }
    else if (startupClues == 81){//if the board is already solved
        cout << "My brother in christ, this sudoku is fucking solved already.";
    } 
    else if (startupSelectedTile == 0 && startupClues >= 17){//all good.
        cout << "\nThe board has been constructed successfully and can be solved properly.";
    }
    else{//if idk whatever the fuck happens
        cout << "\nBro for the love of god and wellbeing of your loved ones, startupRow something valid.";
        boardStartup();
    }
}

int main(){
    for (int i = 1; i <= 80; i++){
        boardData[i] = 0;
    }
    cout << "Welcome to Sudoku Solver 69! \nLet's set up the board.\nFirst you need to specify a tile, number 1 is bottom left, 81 is top right. \nWhen you're done, startupRow 0.\n";
    boardStartup();

    cout << "if this message is shown, board has been constructed and program continues.\nNow the program will output the board.\n";
    for (int i = 0; i <= 80; i++){
        cout << boardData[i] << std::endl;
    }
}
