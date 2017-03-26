#include <iostream>

int charconvert(char input){//converts char to appropriate int
    if (input == '1'){return 0;}
    if (input == '2'){return 1;}
    if (input == '3'){return 2;}
    if (input == 'a'){return 0;}
    if (input == 'b'){return 1;}
    if (input == 'c'){return 2;}
    return 6;
}

bool treeout(int board[3][3], bool turn){
    int count = 0;
    int intturn = turn + 1;

    for (int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){
            if (board[x][y] == intturn){
                count++;
            }
        }
    }

    if (count < 4){
        return 1;
    }
    else return 0;
}

void extrude(int board[3][3], int turn){
    int x;
    int y;
    char input[2];
    std::cout << "Extrude: ";
    std::cin >> input;
    x = charconvert(input[0]);
    y = charconvert(input[1]);

    if (board[x][y] == turn){
        board[x][y] = 0;
    }
    //else extrude(board, turn);
}

void insert(int board[3][3], int turn){
    int x;
    int y;
    char input[2];
    std::cout << "Insert: ";
    std::cin >> input;
    x = charconvert(input[0]);
    y = charconvert(input[1]);

    if (board[x][y] == 0){
        board[x][y] = turn;
    }
    //else insert(board, turn);
}

int inputfunk(int board[3][3], bool turn){//handles input and sets board acordingly
    int intturn = turn + 1;
    if (treeout(board, turn) == 1){
        insert(board, intturn);
    }
    else if (treeout(board, turn) == 0){
        extrude(board, intturn);
        insert(board, intturn);
    }
    return 0;
}

bool checkWin(int board[3][3], bool turn){
    //check if win condition is met
    //reurn 0 if no win && 1 if win
    int intturn = turn + 1;
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
    if (board[0][0] == intturn && board[1][1] == intturn && board[2][2] == intturn){
        return 1;
    }
    if (board[2][0] == intturn && board[1][1] == intturn && board[0][2] == intturn){
        return 1;
    }
    return 0;
}
