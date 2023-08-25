/*
 * Ronan Buck
 * 6/26/2023
 * A game of TicTacToe, primarily designed to be a small project to learn pointers
 * All code written myself
 * References only used to learn pointers
 * One of my first solo projects
 * Will be adapted for use with a GUI
 */

/*
 * Import random to randomize starting person
 */

#include <iostream>
#include <random>
using namespace std;


class Board{
private:
    int turn;
    int ending;
    string boardCoords[3][3] ={
            {"1", "2", "3"},
            {"4", "5", "6"},
            {"7", "8", "9"}
    };

    // Displays the board to the players
    // Shown after every move and with the instructions
    void DisplayBoard(){
        for(int k = 0; k <= 2; k++){
            for(int i = 0; i <= 2; i++){
                cout << boardCoords[k][i];
                if(i < 2)
                    cout << "|";
            }
            cout << endl;
            if(k < 2)
                cout << "-----" << endl;
        }
    }

    // Given that a move can be made, updates the board with given move
    void UpdateBoard(string box, int turn){
        string* compare;
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 3; i++) {
                compare = (*(boardCoords + j) + i);
                if (*compare == box) {
                    break;
                }
            }
            if (*compare == box) {
                break;
            }
        }

        if (turn == 1) {
            *compare = "X";
        }
        else if (turn == 2) {
            *compare = "O";
        }
    }

    // Ensures that box isn't already occupied by a move
    bool checkValidMove(string box) {
        if (box >= "1" && box <= "9") {
            string *compare;
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    compare = (*(boardCoords + j) + i);
                    // compares the value at address of a box to wanted box
                    if (*compare == box) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void isGameOver() {
        if (ending == 1) {
            cout << "There are no more possible moves to make. Game Over! No one Wins!";
        }
        else if (ending == 2 && turn == 1) {
            cout << "Game Over! Player One (X) Wins!";
        }
        else if (ending == 2 && turn == 2) {
            cout << "Game Over! Player Two (O) Wins!";
        }
    }

    bool checkGameOver(){
        int openBox = 9;
        string *block;
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 3; i++) {
                block = (*(boardCoords + j) + i);
                if(*block >= "1" && *block <= "9"){
                    openBox--;
                }
            }
        }
        if(openBox == 9){
            ending = 1;
            return true;
        }

        // checks for a horizontal win
        for(int i = 0; i < 3; i++){
            if((*(*(boardCoords + i)) == (*(*(boardCoords + i) + 1))) &&
                    (*(*(boardCoords + i) + 1) == (*(*(boardCoords + i) + 2)))){
                ending = 2;
                return true;
            }
        }

        // checks for a vertical win
        for(int i = 0; i < 3; i++){
            if((*(*(boardCoords) + i) == (*(*(boardCoords + 1) + i))) &&
               (*(*(boardCoords + 1) + i) == (*(*(boardCoords + 2) + i)))){
                ending = 2;
                return true;
            }
        }

        // checks diagonal top left to bot right?
        if((*(*(boardCoords)) == (*(*(boardCoords + 1) + 1))) &&
                (*(*(boardCoords)) == (*(*(boardCoords + 2) + 2)))){
            ending = 2;
            return true;
        }

        // checks diagonal bot left to top right?
        if((*(*(boardCoords + 2)) == (*(*(boardCoords + 1) + 1))) &&
           (*(*(boardCoords + 2)) == (*(*(boardCoords) + 2)))){
            ending = 2;
            return true;
        }

        // default if no ending is true
        return false;
    }


public:
    // Displays instructions and the board
    Board(){
    cout << "Welcome to a game of TicTacToe!" << endl;
    cout << "We will start with the player using \"X\" for their moves" << endl;
    cout << "To enter a move, please enter the number associated with"
            " the box you would like" << endl;
    cout << "Numbers will appear in boxes that you are able to make a move in" << endl;
    turn = 1;
    DisplayBoard();
}

    // Function that ensure turns take place
    void Play(){
        string box;

        // game loop for player one
        if(turn == 1){
            cout << "Player One (X) what box would you like to enter a move?";
            cin >> box;
            if(checkValidMove(box)){
                UpdateBoard(box, turn);
                DisplayBoard();
                if(!checkGameOver()){
                    turn++;
                    Play();
                }
                else{
                    isGameOver();
                }
            }
            else{
                cout << "Please enter a valid move" << endl;
                Play();
            }

        }

        // game loop for player two
        else if(turn == 2){
            cout << "Player Two (O) what box would you like to enter a move?";
            cin >> box;
            if(checkValidMove(box)){
                UpdateBoard(box, turn);
                DisplayBoard();
                if(!checkGameOver()){
                    turn--;
                    Play();
                }
                else{
                    isGameOver();
                }
            }
            else{
                cout << "Please enter a valid move" << endl;
                Play();
            }
        }
    }
};

int main() {
    cout << (rand() % 2) + 1 << endl;
    Board game;
    game.Play();
    return 0;
}