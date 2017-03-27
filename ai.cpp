//this is the amazing player ai
//if player can win in one move >> block
//if ai can win do that first
//otherwise make random move
#include <iostream>
#include <cstdlib>
#include <ctime>

int checkmissing(int board[3][3], int move[2], int mode){//returns 0 mode 1 => can i win? 1 => can he win
    for (int x = 0; x < 3; x++){
       if (board[x][0] == 2 && board[x][1] == mode){
           move[0] = x;
           move[1] = 2;
       }
       if (board[x][0] == 2 && board[x][2] == mode){
           move[0] = x;
           move[1] = 1;
       }
       if (board[x][1] == 2 && board[x][2] == mode){
           move[0] = x;
           move[1] = 0;
       }
    }
    for (int y = 0; y < 3; y++){
       if (board[0][y] == 2 && board[1][y] == mode){
           move[0] = 2;
           move[1] = y;
       }
       if (board[0][y] == 2 && board[2][y] == mode){
           move[0] = 1;
           move[1] = y;
       }
       if (board[1][y] == 2 && board[2][y] == mode){
           move[0] = 0;
           move[1] = y;
       }
    }
    //cross win recoignition
    if (board[0][0] == 2 && board[1][1] == mode){
           move[0] = 2;
           move[1] = 2;
    }
    if (board[0][0] == 2 && board[2][2] == mode){
           move[0] = 1;
           move[1] = 1;
    }
    if (board[1][1] == 2 && board[2][2] == mode){
           move[0] = 0;
           move[1] = 0;
    }

    if (board[2][0] == 2 && board[1][1] == mode){
           move[0] = 0;
           move[1] = 2;
    }
    if (board[2][0] == 2 && board[0][2] == mode){
           move[0] = 1;
           move[1] = 1;
    }
    if (board[0][2] == 2 && board[1][1] == mode){
           move[0] = 2;
           move[1] = 0;
    }
    return 0;
}

int rnd(){
    std::srand(std::time(0));
    int x = std::rand();
    int rndx = (x%2) + 0;
    return rndx;
}

void rndmove(int board[3][3], int move[2]){
    int x = rnd();
    int y = rnd();
    if (board[x][y] == 0){
        move[0] = x;
        move[1] = y;
        return;
    }
    rndmove(board, move);
}

int mainai(int board[3][3]){
    int move[2];
    rndmove(board, move);
    checkmissing(board, move, 1);
    checkmissing(board, move, 2);
    board[move[0]][move[1]] = 2;
    return 0;
}
