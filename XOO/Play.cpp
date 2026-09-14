#include "Play.h"
#include <iostream>


using namespace std;

Play::Play() {
    while (!gamefow) {
        char player1 = 'X', player2 = 'O';

        printBoard(xo);
        if (movePlayer(player1, xo)) {
            cout << "\nПобеда X!\n";
            gamefow = true;
            continue;
        }
        count++;

        if (count == 9)
            break;

        printBoard(xo);
        if (movePlayer(player2, xo)) {
            cout << "\nПобеда O!\n";
            gamefow = true;
            continue;
        }

        count++;
        system("cls");
    }

    if (!gamefow) cout << "\nНичья!\n";

}

void Play::printBoard(char xo[3][3]) {

    for (int i = 0; i < 3; ++i) {
        cout << "\n";
        for (int j = 0; j < 3; ++j) {
            cout << xo[i][j] << " ";
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---";
    }
    cout << endl;
}


bool Play::checkWin(char xo[3][3], char plaeyr) {
    //столбцы
    for (int i = 0; i < 3; i++) {
        if (xo[i][0] == plaeyr && xo[i][1] == plaeyr && xo[i][2] == plaeyr)
            return true;
        if (xo[0][i] == plaeyr && xo[1][i] == plaeyr && xo[2][i] == plaeyr)
            return true;
    }
    //на искосок
    if (xo[0][0] == plaeyr && xo[1][1] == plaeyr && xo[2][2] == plaeyr)
        return true;
    if (xo[0][2] == plaeyr && xo[1][1] == plaeyr && xo[2][0] == plaeyr)
        return true;

    return false;
}

bool Play::movePlayer(char player, char xo[3][3]) {

    int rov = 0, col = 0;
    cout << "Игрок " << player << " выберите поле: ";
    cin >> rov >> col;
    if (rov >= 1 && rov <= 3 && col >= 1 && col <= 3) {
        bool game = false;
        if (xo[rov - 1][col - 1] == ' ') {
            xo[rov - 1][col - 1] = player;
        }
        else {
            while (!game) {
                cout << "Поле занято, попробуй еще: ";
                cin >> rov >> col;
                if (xo[rov - 1][col - 1] == ' ') {
                    xo[rov - 1][col - 1] = player;
                    game = true;
                }
            }
        }

    }
    else
    {
        cout << "Поле вне зоны";
    }
    return checkWin(xo, player);
};