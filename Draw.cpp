#include "Draw.h"

void drawMenu()
{
	for (int i = 0; i <= HeightMenu; i++)
	{
		for (int j = 0; j <= WidthMenu; j++)
		{
			if (i == 0 || i == HeightMenu || j == 0 || j == WidthMenu)
			{
				gotoxy(j, i); cout << (char)219;
			}
		}
	}
}

void drawTextTower()
{
	ifstream FileIn("Text.IN", ios::in);
	if (FileIn.fail())
	{
		cout << "ERROR file text";
		Sleep(5000);
		exit(0);
	}

	int line = 1;
	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);
		gotoxy(2, line++); cout << text;
	}
	FileIn.close();
}

void drawMap() //vẽ map game;
{
	char dmap = 219; 
	for (int i = 0; i < HeightGame; i++)
	{
		gotoxy(WidthGame, i); cout << dmap;
		gotoxy(0, i); cout << dmap;
	}
	for (int i = 0; i <= WidthGame; i++)
	{
		gotoxy(i, 0); cout << dmap;
		gotoxy(i, HeightGame); cout << dmap;
	}

	gotoxy(50, 22); cout << "ESC: exit game.";
	gotoxy(50, 20); cout << "SPACE: play game.";
	gotoxy(55, 17); cout << "___GUIDE___";
}

