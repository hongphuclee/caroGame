#include <iostream>
#include <conio.h> // only Window OS
#include <cstdlib>
#include "board.h"
#include "interface.h"
#include "game_controller.h"
#include "player.h"

using namespace std;

int main() {
    board mainBoard(15);
    gameController gameCtr;
    player player1('X');
	player player2('O');

    while (true) {
        switch (gameCtr.getCurrentState()) {
            case gameController::MAIN_MENU:
                showMainMenu(gameCtr);
                break;
            case gameController::PLAYING:
                renderGameplayScreen(gameCtr,mainBoard);
                break;
            case gameController::CONFIG:

                break;
        }
       
    }

    return 0;
}
