#pragma once
#include "Graphics.h"

enum Status { LEFT, RIGHT, OK, EMPTY, EXIT };

struct Information
{
	int x, y;
	Status tt;
};
struct Tower
{
	vector<Information> Floor;
};

void Init(vector<Tower> &arrFloor, int yfloor, int sizeFloor);

void moveFloor(vector<Tower> &arrFloor, Status B, int &floor, int &clickSpace, int &sizeFloor, int maxGame, int &score, bool &endGame);