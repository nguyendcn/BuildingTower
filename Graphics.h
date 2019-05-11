#pragma once

#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15
#define WidthConsoleMenu        650
#define HeightConsoleMenu       550
#define WidthConsoleGame        750
#define HeightConsoleGame       550
#define WidthGame               40
#define HeightGame              28
#define WidthMenu               74
#define HeightMenu              28
#define   SPEEDFIRST   100
#define   SPEEDLATER   30


void gotoxy(int x, int y);
void TextColor(WORD color);
void setBGColor(WORD);
void resizeConsole(int width, int height);
void clrscr();
void AnConTro();
void HienConTro();

void ColorText(string, int);
void ColorText(char, int);