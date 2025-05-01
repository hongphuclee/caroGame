#include"game_controller.h"

char gameController::getCurrentPlayerIcon() const {
    return this->currentPlayerIcon;
}
void gameController::setCurrentPlayerIcon(char c) {
    this->currentPlayerIcon = c;
}


void gameController::setCurrentState(gameState state) {
    this->currentState = state;

}
gameController::gameState gameController::getCurrentState() const {
    return this->currentState;
}

int gameController::inputMainMenu() {
    int op;
    cin >> op;
    return op;
}

board gameController::playing(board& mainBoard) {

    int currentCursorX = mainBoard.getCursorX();
    int currentCursorY = mainBoard.getCursorY();

    int ch = _getch();
    if(currentPlayerIcon == 'X'){
        if (ch == 27) currentState = gameController::MAIN_MENU; // ESC
        if (ch == 224) {
            int key = _getch();
            switch (key) {
            case 72:
                if (currentCursorY > 0) {
                    mainBoard.setCursorY(currentCursorY - 1);        // ↑
                }
                break;
            case 80:
                if (currentCursorY < mainBoard.getSize() - 1) {
                    mainBoard.setCursorY(currentCursorY + 1);        // ↓
                }
                break;
            case 75:
                if (currentCursorX > 0) {
                    mainBoard.setCursorX(currentCursorX - 1);          // ←
                }
                break;
            case 77:
                if (currentCursorX < mainBoard.getSize() - 1) {
                    mainBoard.setCursorX(currentCursorX + 1);          // →
                }
                break;    
            }
        }
        if (ch == 13 && mainBoard.getCell(currentCursorY, currentCursorX) == '.') { // Enter
            mainBoard.setCell(mainBoard.getCursorY(), mainBoard.getCursorX(), currentPlayerIcon);
            mainBoard.setLastMarkY(mainBoard.getCursorY());
            mainBoard.setLastMarkX(mainBoard.getCursorX());
            if (checkWin(mainBoard) != true) {
                currentPlayerIcon = 'O';
            }
        }
    }

    if (currentPlayerIcon == 'O') {
        if (ch == 27) currentState = gameController::MAIN_MENU; // ESC
        switch (ch) {
        case 'w':
            if (currentCursorY > 0) {
                mainBoard.setCursorY(currentCursorY - 1);        // ↑
            }
            break;
        case 's':
            if (currentCursorY < mainBoard.getSize() - 1) {
                mainBoard.setCursorY(currentCursorY + 1);        // ↓
            }
            break;
        case 'a':
            if (currentCursorX > 0) {
                mainBoard.setCursorX(currentCursorX - 1);          // ←
            }
            break;
        case 'd':
            if (currentCursorX < mainBoard.getSize() - 1) {
                mainBoard.setCursorX(currentCursorX + 1);          // →
            }
            break;
        case 32:
            if (mainBoard.getCell(currentCursorY, currentCursorX) == '.') { // Enter
                mainBoard.setCell(mainBoard.getCursorY(), mainBoard.getCursorX(), currentPlayerIcon);
                mainBoard.setLastMarkY(mainBoard.getCursorY());
                mainBoard.setLastMarkX(mainBoard.getCursorX());
                if (checkWin(mainBoard) != true) {
                    currentPlayerIcon = 'X';
                }
            }
            break;
        }
    }


    
    return mainBoard;
}

bool gameController::checkDirection(board mainBoard, int x, int y, int dx, int dy, char icon) {
    int cnt = 0, size = mainBoard.getSize();
    int tmpX = x - dx, tmpY = y - dy;
    while (x < size && x >= 0 && y < size && y >= 0 && mainBoard.getCell(y, x) == icon) {
        cnt++;
        x += dx;
        y += dy;
    }
    while (tmpX < size && tmpX >= 0 && tmpY < size && tmpY >= 0 && mainBoard.getCell(tmpY, tmpX) == icon) {
        cnt++;
        tmpX -= dx;
        tmpY -= dy;
    }
    if(cnt >= 5) {
        return true;
	}
    return false;
}

bool gameController::checkWin(board& mainBoard) {
	int x = mainBoard.getLastMarkX();
	int y = mainBoard.getLastMarkY();
    if (x < 0 && y < 0) return false;
	char icon = mainBoard.getCell(y, x);
    if (checkDirection(mainBoard, x, y, 0, 1, icon) || // horizontal
        checkDirection(mainBoard, x, y, 1, 0, icon) || // vertical
        checkDirection(mainBoard, x, y, 1, 1, icon) || // diagonal 
        checkDirection(mainBoard, x, y, -1, 1, icon)) { // diagonal /
        return true;
    }
	return false;
}
