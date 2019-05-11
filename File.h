#pragma once
#include "Graphics.h"
#include "MenuGame.h"


typedef struct Score
{
	string name;
	int score;
}SCORE;

void permutation(SCORE &, SCORE &);
void arrange(vector<SCORE> &);
void File(int);
void hightScore();
int getLowScore();
void FileScore(int hightScore);
