//tictactoe writen in c++ working on linux and mac

#include <iostream>

//visual funktions declared in visual.cpp
void printboard(int board[3][3]);//printing out the board
int menu();//prints menu and returns choice
void winM(bool turn);//print win funktion
void printturn(bool turn);//prints out turn

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

//main game funktion
void gameloops(){
    int board[3][3];
    int shoice = menu();
    if (shoice == 1){
        bool turn = 0;//x = 0 o=1
        resetBoard(board);
        for (bool win = 0; win == 0;){//main game loop
            printturn(turn);
            printboard(board);
            inputfunk(board, turn);//returns 1 it invalid option
            if (checkWin(board, turn) == 1){
                printturn(turn);
                printboard(board);
                winM(turn);
                win = 1;
            }
            if (turn == 0){turn = 1;}
            else if (turn == 1){turn = 0;}
        }
    }
    if (shoice == 2){//quit part
        std::cout << "quiting\n";
        return;
    }
    else{//loopback if incorect
        gameloops();
    }
}

int main(){
	std::cout << "Welcome to the awesome tictactoe game!\n";
    gameloops();
	return 0;
}
