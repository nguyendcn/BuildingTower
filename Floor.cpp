#include "Floor.h"

vector<Information> creatOne(int yfloor, int size) // Trả về 1 tầng nhà gồm kích thước có thể truyền vào.
{
	vector<Information> ArrInf;

	Information AddInf;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			AddInf.tt = RIGHT;
		else
			AddInf.tt = EMPTY;
		AddInf.x = i + 2;
		AddInf.y = yfloor;
		ArrInf.push_back(AddInf);
	}
	return ArrInf;
}

void Init(vector<Tower> &arrFloor, int yfloor, int sizeFloor) //khởi tạo 1 tòa nhà vào vector tòa tháp;
{
	Tower Add;
	Add.Floor = creatOne(yfloor, sizeFloor);
	arrFloor.push_back(Add);
}

void delFloor(vector<Tower> arrFloor, int floor) //Xóa 1 tầng bất kỳ;
{
	int size = arrFloor[floor].Floor.size();
	for (int i = 0; i < size; i++)
	{
		gotoxy(arrFloor[floor].Floor[0].x + i, HeightGame - 2 - floor); cout << " ";
	}
}

int drColor(vector<Tower> &arrFloor, int floor)
{
	int size = arrFloor[floor].Floor.size();
	if (size > 7)
		return 10;
	else if (size <= 7 && size > 4)
		return 2;
	else if (size <= 4 && size > 1)
		return 4;
	else
		return 12;
}

void drawFloor(vector<Tower> &arrFloor, int floor, char dmap, int color) // Vẽ tầng bất kì theo hướng di chuyển có sẵn.
{

	int size = arrFloor[floor].Floor.size();
	//In body.
	for (int i = 0; i < size; i++)
	{
		gotoxy(arrFloor[floor].Floor[i].x, arrFloor[floor].Floor[i].y);  ColorText(dmap, color);
	}

	//Xóa đuôi.
	if (arrFloor[floor].Floor[0].tt == RIGHT)
	{
		gotoxy(arrFloor[floor].Floor[0].x - 1, arrFloor[floor].Floor[0].y); cout << " ";
	}
	else if (arrFloor[floor].Floor[0].tt == LEFT)
	{
		gotoxy(arrFloor[floor].Floor[0].x + size, arrFloor[floor].Floor[0].y); cout << " ";
	}
}

void moveFloor(vector<Tower> &arrFloor, Status B, int &floor, int &clickSpace, int &sizeFloor, int maxGame, int &score, bool &endGame)
{

	if (B == OK) //Nhấn SPACE
	{
		if (floor == 0)
		{
			score += 100;
		}
		if (floor != 0)
		{
			//   000000             hoặc                000000    => endGame k phụ thuộc vào khoảng cách chênh chỉ cần lệch => endGame luôn;
			//           00000               00000

			int size1 = arrFloor[floor - 1].Floor.size();
			int size2 = arrFloor[floor].Floor.size();
			if ((arrFloor[floor].Floor[0].x > arrFloor[floor - 1].Floor[size1 - 1].x) || (arrFloor[floor].Floor[size2 - 1].x < arrFloor[floor - 1].Floor[0].x))
			{
				endGame = true;
				return;
			}

			// endGame == false;
			delFloor(arrFloor, floor);
			int a = abs((arrFloor[floor - 1].Floor[0].x - arrFloor[floor].Floor[0].x)); // Tính độ lệch;
			sizeFloor -= a;
			score += (sizeFloor * 10);
			arrFloor[floor].Floor.resize(sizeFloor);

			//    00000             =>  00
			//       00000              00000
			if (arrFloor[floor - 1].Floor[0].x > arrFloor[floor].Floor[0].x)
			{
				//Sửa vị trí x mới cho đầu vì đã cắt đầu rồi;
				for (int i = 0; i < sizeFloor; i++)
				{
					arrFloor[floor].Floor[i].x += a;
				}
			}
			if (arrFloor.size() == maxGame - 1)
			{
				drawFloor(arrFloor, floor, 208, drColor(arrFloor, floor));
			}
			else
				drawFloor(arrFloor, floor, 219, drColor(arrFloor, floor));
		}
		// Tạo tầng mới;
		Init(arrFloor, HeightGame - clickSpace, sizeFloor);
		floor++;

	}
	else //Không nhấn SPACE;
	{
		int size = arrFloor[floor].Floor.size();

		// Xử lý chạm biên;
		if (arrFloor[floor].Floor[0].x + arrFloor[floor].Floor.size() == WidthGame - 1 && arrFloor[floor].Floor[0].tt == RIGHT)
		{
			arrFloor[floor].Floor[0].tt = LEFT;
		}
		else if (arrFloor[floor].Floor[0].x - 2 == 0 && arrFloor[floor].Floor[0].tt == LEFT)
		{
			arrFloor[floor].Floor[0].tt = RIGHT;
		}

		// Xử lý di chuyển;
		if (arrFloor[floor].Floor[0].tt == RIGHT)
		{
			for (int i = 0; i < size; i++)
			{
				arrFloor[floor].Floor[i].x += 1;
			}
		}
		else if (arrFloor[floor].Floor[0].tt == LEFT)
		{
			for (int i = 0; i < size; i++)
			{
				arrFloor[floor].Floor[i].x -= 1;
			}
		}

		if (arrFloor.size() == maxGame - 1)
		{
			drawFloor(arrFloor, floor, 208, drColor(arrFloor, floor)); // thả ngọn tháp.
		}
		else
			drawFloor(arrFloor, floor, 219, drColor(arrFloor, floor)); // tầng bình thường.
	}
}