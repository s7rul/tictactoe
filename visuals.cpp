#include <iostream>

void boardToString(int turn, std::string output[5]){
    std::string xsymb[5];
    xsymb[0] = "X   X";
    xsymb[1] = " X X ";
    xsymb[2] = "  X  ";
    xsymb[3] = " X X ";
    xsymb[4] = "X   X";
    
    std::string osymb[5];
    osymb[0] = " OOO ";
    osymb[1] = "O   O";
    osymb[2] = "O   O";
    osymb[3] = "O   O";
    osymb[4] = " OOO ";

    if (turn == 0){
        for (int n = 0; n < 5; n++){
            output[n] = "     ";
        }
    }

    if (turn == 1){
        for (int n = 0; n < 5; n++){
            output[n] = xsymb[n];
        }
    }
    if (turn == 2){
        for (int n = 0; n < 5; n++){
            output[n] = osymb[n];
        }
    }
}

void printturn(bool turn){
    char charturn;
    if (turn == 0){
        charturn = 'X';
    }
    if (turn == 1){
        charturn = 'O';
    }

    std::cout << "\n";
    std::cout << "turn: " << charturn << "\n";
}

void printboard(int board[3][3]){//printing out the board
    std::string aa[5];
    std::string ba[5];
    std::string ca[5];
    std::string ab[5];
    std::string bb[5];
    std::string cb[5];
    std::string ac[5];
    std::string bc[5];
    std::string cc[5];

    boardToString(board[0][0], aa);
    boardToString(board[1][0], ba);
    boardToString(board[2][0], ca);
    boardToString(board[0][1], ab);
    boardToString(board[1][1], bb);
    boardToString(board[2][1], cb);
    boardToString(board[0][2], ac);
    boardToString(board[1][2], bc);
    boardToString(board[2][2], cc);

    std::cout << "  #   1   #   2   #   3   #\n";
    std::cout << "###########################\n";
    std::cout << "  # " << aa[0] << " # " << ba[0] << " # " << ca[0] << " #\n";
    std::cout << "  # " << aa[1] << " # " << ba[1] << " # " << ca[1] << " #\n";
    std::cout << "a # " << aa[2] << " # " << ba[2] << " # " << ca[2] << " #\n";
    std::cout << "  # " << aa[3] << " # " << ba[3] << " # " << ca[3] << " #\n";
    std::cout << "  # " << aa[4] << " # " << ba[4] << " # " << ca[4] << " #\n";
    std::cout << "###########################\n";
    std::cout << "  # " << ab[0] << " # " << bb[0] << " # " << cb[0] << " #\n";
    std::cout << "  # " << ab[1] << " # " << bb[1] << " # " << cb[1] << " #\n";
    std::cout << "b # " << ab[2] << " # " << bb[2] << " # " << cb[2] << " #\n";
    std::cout << "  # " << ab[3] << " # " << bb[3] << " # " << cb[3] << " #\n";
    std::cout << "  # " << ab[4] << " # " << bb[4] << " # " << cb[4] << " #\n";
    std::cout << "###########################\n";
    std::cout << "  # " << ac[0] << " # " << bc[0] << " # " << cc[0] << " #\n";
    std::cout << "  # " << ac[1] << " # " << bc[1] << " # " << cc[1] << " #\n";
    std::cout << "c # " << ac[2] << " # " << bc[2] << " # " << cc[2] << " #\n";
    std::cout << "  # " << ac[3] << " # " << bc[3] << " # " << cc[3] << " #\n";
    std::cout << "  # " << ac[4] << " # " << bc[4] << " # " << cc[4] << " #\n";
    std::cout << "###########################\n";
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
