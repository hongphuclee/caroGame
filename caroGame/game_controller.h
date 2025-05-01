#pragma once
#include"board.h"
#include <iostream>
#include <conio.h> // only Window OS
#include <cstdlib>


class gameController {
public:
	enum gameState { MAIN_MENU, PLAYING, CONFIG };

	char getCurrentPlayerIcon() const;
	void setCurrentPlayerIcon(char c);
	void setCurrentState(gameState state);
	gameState getCurrentState() const;

	board playing(board& mainBoard);
	int inputMainMenu();
	bool checkDirection(board mainBoard, int x, int y, int dx, int dy, char icon);
	bool checkWin(board& mainBoard);

private:
	char currentPlayerIcon = 'X';
	gameState currentState = MAIN_MENU;

};
