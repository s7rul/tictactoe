//tictactoe writen in c++ working on linux
#include <iostream>

//visual funktions declared in visual.cpp
void printboard(int board[3][3]);//printing out the board
int menu();//prints menu and returns choice
void winM(bool turn);//print win funktion

//logic funktions declared in logic.cpp
int inputfunk(int board[3][3], bool turn);//handels input and changing board array
bool checkWin(int board[3][3], bool turn);//checks if anybody has won
void insert(int board[3][3], int turn);

//funktions deklared in ai.cpp
int mainai(int board[3][3]);

void resetBoard(int board[3][3]){
    for(int n = 0; n < 3; n++){
        for(int a = 0; a < 3; a++){
            board[n][a] = 0;
        }
    }
}

void gameloops(){
    int board[3][3];
    int shoice = menu();
    if (shoice == 2){
        //insert 2p loop here
        bool turn = 0;//x = 0 o=1
        resetBoard(board);
        for (bool win = 0; win == 0;){
            printboard(board);
            inputfunk(board, turn);//returns 1 it invalid option
            if (checkWin(board, turn) == 1){
                printboard(board);
                winM(turn);
                win = 1;
            }
            if (turn == 0){turn = 1;}
            else if (turn == 1){turn = 0;}
        }
    }
    if (shoice == 1){
        //insert 1p loop here
        for (bool win = 0; win == 0;){
            resetBoard(board);
            printboard(board);
            insert(board, 1);
            if (checkWin(board, 0) == 1){
                printboard(board);
                winM(0);
                win = 1;
            }
            mainai(board);
            if (checkWin(board, 1) == 1){
                printboard(board);
                winM(1);
                win = 1;
            }
        }
    }
    if (shoice == 3){
        std::cout << "quiting\n";
        return;
    }
    else{
        gameloops();
    }
}

int main(){
	std::cout << "Welcome to the awesome tictactoe game!\n";
    gameloops();
	return 0;
}
