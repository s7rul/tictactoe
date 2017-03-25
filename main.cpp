//tictactoe writen in c++ and working on all platforms
#include <iostream>

void printboard(int board[3][3]){
    //printout gamebord
    char bordchar[3][3];
    for (int n = 0; n < 3; n++){//converting int board to char board
        for (int a = 0; a < 3; a++){
            if (board[n][a] == 0){bordchar[n][a] = ' ';}
            if (board[n][a] == 1){bordchar[n][a] = 'X';}
            if (board[n][a] == 2){bordchar[n][a] = 'O';}
        }
    }
    std::cout << board[0][0] << board[1][0] << board[2][0] << "\n";
    std::cout << board[0][1] << board[1][1] << board[2][1] << "\n";
    std::cout << board[0][2] << board[1][2] << board[2][2] << "\n";
    std::cout << "\n";
    std::cout << "  * 1 * 2 * 3 *\n";
    std::cout << "***************\n";
    std::cout << "A * " << bordchar[0][0] << " * " << bordchar[1][0] << " * " << bordchar[2][0] << " *\n";
    std::cout << "***************\n";
    std::cout << "B * " << bordchar[0][1] << " * " << bordchar[1][1] << " * " << bordchar[2][1] << " *\n";
    std::cout << "***************\n";
    std::cout << "C * " << bordchar[0][2] << " * " << bordchar[1][2] << " * " << bordchar[2][2] << " *\n";
    std::cout << "***************\n";
}

int charconvert(char input){//converts char to appropriate int
    if (input == '1'){return 0;}
    if (input == '2'){return 1;}
    if (input == '3'){return 2;}
    if (input == 'a'){return 0;}
    if (input == 'b'){return 1;}
    if (input == 'c'){return 2;}
    return 6;
}

bool checkIfempty(int board[3][3], int x, int y){
    //check if a plce on the board is empty
    //return 0 => not empty
    //return 1 => empty
    if (board[x][y] == 0){
        return 1;
    }
    else {
        std::cout << "not empty\n";
        return 0;
    }
}

bool checkWin(int board[3][3], bool turn){
    //check if win condition is met
    //reurn 0 if no win && 1 if win
    int intturn = turn + 1;
    std::cout << "turn: " << intturn << "\n";
    for (int x = 0; x < 3; x++){
        if (board[x][0] == intturn && board[x][1] == intturn && board[x][2] == intturn){
            return 1;
        }
    }
    for (int y = 0; y < 3; y++){
        if (board[0][y] == intturn && board[1][y] == intturn && board[2][y] == intturn){
            return 1;
        }
    }
    return 0;
}

int inputfunk(int board[3][3], int turn){//handles input and sets board acordingly
    char input[2];
    int x;
    int y;
    std::cout << "your choice: ";
    std::cin >> input;
    //std::cout << input[0] << "\n" << input[1] << "\n";
    
    x = charconvert(input[0]);
    y = charconvert(input[1]);

    if (x == 6){return 1;}
    if (y == 6){return 1;}

    //std::cout << x << "\n" << y << "\n";

    if (checkIfempty(board, x, y) == 1){
        if (turn == 0){
            board[x][y] = 1;
        }
        if (turn == 1){
            board[x][y] = 2;
        }
    }
    return 0;
}

int menu(){
    int choice;
    //menu text
    std::cout << "***********************\n";
    std::cout << "1 > start 1 player game\n";
    std::cout << "2 > start 2 player game\n";
    std::cout << "3 > quit\n";
    std::cout << "***********************\n";
    std::cout << "Your choice: ";
    std::cin >> choice;
    return choice;
}

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
        int turn = 0;//x = 0 o=1
        std::cout << "one player\n";
        resetBoard(board);
        for (bool win = 0; win == 0;){
            printboard(board);
            inputfunk(board, turn);//returns 1 it invalid option
            if (checkWin(board, turn) == 1){
                std::cout << "somebody won\n";
                win = 1;
            }
            if (turn == 0){turn = 1;}
            else if (turn == 1){turn = 0;}
            std::cout << turn << "\n";
        }
    }
    if (shoice == 1){
        //insert 1p loop here
        resetBoard(board);
        std::cout << "two player\n";
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
