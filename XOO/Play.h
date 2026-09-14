#pragma once
#include <iostream>


using namespace std;
class Play
{
private:
    char xo[3][3] = { {' ',' ',' '},
                      {' ',' ',' '},
                      {' ',' ',' '} };
    int temp = 0;
    bool gamefow = false;
    int count = 0;

public:

    Play();
	void printBoard(char xo[3][3]);

	bool checkWin(char xo[3][3], char plaeyr);
	bool movePlayer(char player, char xo[3][3]);
};

