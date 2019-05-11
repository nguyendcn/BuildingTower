#include "Game.h"
#include "MenuGame.h"

int main()
{
	resizeConsole(WidthConsoleMenu, HeightConsoleMenu);
	AnConTro();

	vector<Menu> listMenu;

	InMenu(listMenu);

	int dir = 0;
	bool CheckChoose = false;

	while (true)
	{
		drawMenu();
		drawTextTower();

		PrintMenu(listMenu);

		TextColor(10); gotoxy(listMenu[dir].x - 3, listMenu[dir].y); cout << (char)175 << " " << listMenu[dir].data << " "; TextColor(7);

		MoveSelect(listMenu, dir, CheckChoose);

		if (CheckChoose == true)
		{
			CheckChoose = false;

			if (dir == 0) // PlayGame
			{
				PlayGame();	
			}
			else if (dir == 1) // Height Score
			{
				system("cls");
				drawMenu();
				drawTextTower();

				hightScore();

				system("cls");
			}
			else if (dir == 2) // Guide
			{
				system("cls");
				drawMenu();
				drawTextTower();

				Guide();

				system("cls");
			}
			else if (dir == 3) // Info
			{
				system("cls");
				drawMenu();
				drawTextTower();

				Info();

				system("cls");
			}
			else if (dir == 4) // exit
			{
				exit(0);
			}
		}
	}

	system("pause");

	return 0;
}