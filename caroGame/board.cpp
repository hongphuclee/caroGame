#include "Board.h"
#include <iostream>

board::board(int size) {
	this->size = size;
	grid = vector<vector<char>>(size, vector<char>(size, '.'));

}

int board::getSize() const {
	return this->size;
}

vector<vector<char>> board::getGrid() const {
	return this->grid;
}

int board::getCursorX() const {
	return this->cursorX;
}

int board::getCursorY() const {
	return this->cursorY;
}

void board::setCursorX(int x) {
	this->cursorX = x;
}

void board::setCursorY(int y) {
	this->cursorY = y;
}

char board::getCell(int y, int x) {
	return grid[y][x];
}
void board::setCell(int y, int x, char c) {
	this->grid[y][x] = c;
}

int board::getLastMarkX() const {
	return this->lastMarkX;
}
int board::getLastMarkY() const {
	return this->lastMarkY;
}
void board::setLastMarkX(int x) {
	this->lastMarkX = x;
}
void board::setLastMarkY(int y) {
	this->lastMarkY = y;
}

void board::clearGrid() {
	for(int y = 0; y < size; y++) {
		for(int x = 0; x < size; x++) {
			grid[y][x] = '.';
		}
	}
}