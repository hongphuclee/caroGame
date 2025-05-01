#include"player.h"

char player::getIcon() const {
	return this->icon;
}

void player::setIcon(char c) {
	this->icon = c;
}

player::player(char icon) {
	this->icon = icon;
}