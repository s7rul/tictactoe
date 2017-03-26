#include <iostream>

void printboard(int board[3][3]){//printing out the board
    char bordchar[3][3];
    for (int n = 0; n < 3; n++){//converting int board to char board
        for (int a = 0; a < 3; a++){
            if (board[n][a] == 0){bordchar[n][a] = ' ';}
            if (board[n][a] == 1){bordchar[n][a] = 'X';}
            if (board[n][a] == 2){bordchar[n][a] = 'O';}
        }
    }
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

int menu(){//prints menu and returns choice
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

void winM(bool turn){
    char charturn = ' ';

    if (turn == 0){
        charturn = 'X';
    }
    if (turn == 1){
        charturn = 'O';
    }

    std::cout << "#########################\n";
    std::cout << "#                       #\n";
    std::cout << "#      player " << charturn << " won     #\n";
    std::cout << "#                       #\n";
    std::cout << "#########################\n";
}
