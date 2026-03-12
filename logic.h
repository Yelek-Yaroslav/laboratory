#ifndef LOGIC_H
#define LOGIC_H

// межі розміру поля
#define MIN_FIELD_SIZE 3
#define MAX_FIELD_SIZE 10

// структура ігрового поля
struct GameField
{
    int** field;
    int size;
    int emptyRow;
    int emptyCol;
};

// структура керування грою
struct GameController
{
    GameField field;
    int movesCount;
    bool isGameOver;
};

// функції логіки гри
void initGame(GameController& game, int size);
bool isValidMove(const GameField& field, int tile);
void moveTile(GameController& game, int tile);
bool checkWin(const GameField& field);
void freeField(GameField& field);

#endif