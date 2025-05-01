#pragma once
#include<iostream>
#include<string>
using namespace std;

class player {
private:
	char icon;
	string name;
public:
	char getIcon() const;
	void setIcon(char c);
	player(char icon);
};
