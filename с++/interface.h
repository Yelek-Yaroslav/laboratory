#ifndef INTERFACE_H
#define INTERFACE_H

#include "logic.h"

// введення розміру поля
int inputFieldSize();

// введення ходу
int inputMove();

// виведення поля
void printField(const GameField& field);

#endif