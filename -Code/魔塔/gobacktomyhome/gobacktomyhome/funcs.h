//struct Hero
//{
//	int posx;
//	int posy;
//	char name[11];
//	int lv;
//	int hp;
//	int exp;
//	int atk;
//	int def;
//	int money;
//	Bag bag;
//};
//struct Monster
//{
//	char name[20];
//	int hp;
//	int expup;
//	int atk;
//	int def;
//	int moneyup;
//};
#ifndef aaa
#define aaa
#include "Map.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
//void speak(bool isspeak, char *a)
//{
//	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD coord;
//	coord.X = 1;
//	coord.Y = 15;
//	SetConsoleCursorPosition(hout, coord);
//	cout << "\t\t\t\t\t┌┐" << endl;
//	cout << "\t\t\t\t\t└┼┴───────────────────────────────┴────┐ " << endl;
//	cout << "\t\t\t\t\t │                                     │ " << endl;
//	cout << a << endl;
//	cout << "\t\t\t\t\t │                                     │ " << endl;
//	cout << "\t\t\t\t\t │                                  △ │ " << endl;
//	cout << "\t\t\t\t\t └─────────────────────────────────────┼┐ " << endl;
//	cout << "\t\t\t\t\t                                       └┘" << endl;
//	coord.X = 41;
//	coord.Y = 20;
//	SetConsoleCursorPosition(hout, coord);
//	cout << "┤";
//	coord.X = 79;
//	SetConsoleCursorPosition(hout, coord);
//	cout << "├";
//	coord.X = 1;
//	coord.Y = 1;
//	SetConsoleCursorPosition(hout, coord);
//	if (isspeak == true)
//	{
//		char w = _getch();
//		if (!isascii(w))
//		{
//			_getch();
//		}
//		coord.X = 1;
//		coord.Y = 22;
//		SetConsoleCursorPosition(hout, coord);
//		cout << "\t\t\t\t                                                                                "
//			<< endl << "\t\t\t\t                                                                                "
//			<< endl << "\t\t\t\t                                                                                ";
//	}
//	return;
//}

enum ARMORTYPE
{
	FROK,  //上衣
	PANTS,  //下装
	BELT,   //腰带
	SHOSE,   //鞋子
	SHOULDER,   //护肩
	WEAPON
};
struct Keys
{
	int red;
	int yellow;
	int blue;
};
struct Pos
{
	int x;
	int y;
};
void head();
void doge();
#endif