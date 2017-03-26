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

    if (count >= 3){
        return 1;
    }
    else return 0;
}

int inputfunk(int board[3][3], bool turn){//handles input and sets board acordingly
    if (treeout(board, turn) == 0){
        char input[2];
        int x;
        int y;
        std::cout << "your choice: ";
        std::cin >> input;

        x = charconvert(input[0]);
        y = charconvert(input[1]);

        if (x == 6){return 1;}
        if (y == 6){return 1;}

        if (checkIfempty(board, x, y) == 1){
            if (turn == 0){
                board[x][y] = 1;
            }
            if (turn == 1){
                board[x][y] = 2;
            }
        }
    }
    else if (treeout(board, turn) == 1){
        char fromInput[2];
        char toInput[2];
        int xfrom;
        int yfrom;
        int xto;
        int yto;
        int intturn = turn + 1;

        std::cout << "move: ";
        std::cin >> fromInput;
        std::cout << "to: ";
        std::cin >> toInput;

        xfrom = charconvert(fromInput[0]);
        yfrom = charconvert(fromInput[1]);
        xto = charconvert(toInput[0]);
        yto = charconvert(toInput[1]);

        if (board[xfrom][yfrom] == intturn){
            board[xfrom][yfrom] = 0;
        }
        if (board[xto][yto] == 0){
            board[xto][yto] = intturn;
        }
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
