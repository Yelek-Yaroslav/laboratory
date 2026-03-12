#include <iostream>
#include "logic.h"
#include "interface.h"

using namespace std;

int main()
{
    GameController game;

    int size = inputFieldSize();
    initGame(game, size);

    while (!game.isGameOver)
    {
        printField(game.field);

        int move = inputMove();

        if (isValidMove(game.field, move))
        {
            moveTile(game, move);
        }

        if (checkWin(game.field))
        {
            game.isGameOver = true;
        }
    }

    cout << "Вітаємо! Ви виграли!" << endl;

    freeField(game.field);

    return 0;
}