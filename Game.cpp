#include "Game.h"


void PlayGame()
{
	system("cls");
	resizeConsole(WidthConsoleGame, HeightConsoleGame);
	
	int level = 1, speed = 100, score = 0;
	bool endGame = false;

	while (!endGame)
	{
		vector<Tower> arrFloor;
		int clickSpace = 2, movefloor = 0, maxGame = 21, sizeFloor = 10;

		Init(arrFloor, HeightGame - 2, 10);

		drawMap();

		Status B = EMPTY;
		AnConTro();

		while (true)
		{
			if (arrFloor.size() == maxGame || endGame)
			{
				level++;
				break;
			}

			moveFloor(arrFloor, B, movefloor, clickSpace, sizeFloor, maxGame, score, endGame);
			Sleep(speed);
			B = EMPTY;

			if (_kbhit())
			{
				int key = _getch();
				if (key == 32) // Space
				{
					B = OK;
					clickSpace++;
				}
				else if (key == 27) // ESC
				{
					exit(0);
				}
			}
			gotoxy(50, 15); cout << "SCORE: " << score;
			gotoxy(50, 13); cout << "LEVEL: " << level;
			gotoxy(50, 11); cout << "SPEED: " << speed << " millisecond";
		}
		if (!endGame)
		{
			clrscr();
			speed -= 20;
			arrFloor.clear();
		}
	}

	if (score > getLowScore())
	{
		FileScore(score);
	}

	exit(0);
}