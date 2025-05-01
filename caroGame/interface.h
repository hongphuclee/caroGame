#pragma once
#include"Board.h"
#include"game_controller.h"
#include<iostream>
#include <conio.h> 
#include <windows.h> // For Sleep function

void showMainMenu(gameController& gameCtr);
void draw(board& mainBoard);
void showBoardNotification();
void renderGameplayScreen(gameController& gameCtr, board& mainBoard);