#include<iostream>
#include<vector>

#include"interface.h"

using namespace std;

void showMainMenu(gameController& gameCtr) {
	system("cls");
	cout << "\t\t1.Start game." << endl;
	cout << "\t\t2.Config" << endl;
	cout << "\t\tEnter your choice: ";
	int  op = gameCtr.inputMainMenu();
	if (op > 0 && op < 3) {
		switch (op) {
		case 1:
			gameCtr.setCurrentState(gameController::PLAYING);
			break;
		case 2:
			gameCtr.setCurrentState(gameController::CONFIG);
			break;
		}
	}
	else {
		cout << "Invalid choice. Please try again.\n";
	}
}

void draw(board& mainBoard) {
	for (int y = 0; y < mainBoard.getSize(); y++) {
		cout << "\t\t\t\t";
		for (int x = 0; x < mainBoard.getSize(); x++) {
			if (x == mainBoard.getCursorX() && y == mainBoard.getCursorY()) {
				cout << "[*]";
			}
			else if (mainBoard.getGrid()[y][x] == '.') {
				cout << "[ ]";
			}
			else {
				cout << "[" << mainBoard.getCell(y, x) << "]";
			}
		}
		cout << endl;
	}
}

void renderGameplayScreen(gameController& gameCtr, board& mainBoard) {
	showBoardNotification();
	draw(mainBoard);
	if (gameCtr.checkWin(mainBoard) == true) { // if any player wins
		cout << endl << endl;
		cout << "\t\t\t\tPlayer " << gameCtr.getCurrentPlayerIcon() << " wins!\n";
		cout << "\t\t\t\tPress ESC to return to the main menu.\n";
		int key = _getch();
		while (key != 27) { // wait for ESC key
			key = _getch();
		}
		mainBoard.clearGrid();
		mainBoard.setLastMarkX(-1); //reset last mark
		mainBoard.setLastMarkY(-1);
		gameCtr.setCurrentState(gameController::MAIN_MENU);
	}
	gameCtr.playing(mainBoard);
}

void showBoardNotification() {
	system("cls");
	cout << "\t\tUse arrow keys to move. Press ENTER to place " << ". ESC to quit.\n\n";
}