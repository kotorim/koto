#include <iostream>
#include <conio.h>
#include <time.h>
#include<Windows.h>
#include <cstring>
#include "funcs.h"
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void mainUI(int &mapx, int &mapy, int **map)
{
	int choose = 1;//主菜单界面滚动
	int boom = 0;
	while (10086)
	{
		system("cls");
		cout << "\t\t\t\t\t\t   连连看v1.0" << endl << endl << endl;
		switch (choose)
		{
		case 1:
			cout << "\t\t\t\t\t\t  ▲ 简单" << endl;
			cout << "\t\t\t\t\t\t     中等" << endl;
			cout << "\t\t\t\t\t\t     困难" << endl;
			cout << "\t\t\t\t\t\t    自定义" << endl;
			cout << "\t\t\t\t\t\t     退出" << endl;
			break;
		case 2:
			cout << "\t\t\t\t\t\t     简单" << endl;
			cout << "\t\t\t\t\t\t  ▲ 中等" << endl;
			cout << "\t\t\t\t\t\t     困难" << endl;
			cout << "\t\t\t\t\t\t    自定义" << endl;
			cout << "\t\t\t\t\t\t     退出" << endl;
			break;
		case 3:
			cout << "\t\t\t\t\t\t     简单" << endl;
			cout << "\t\t\t\t\t\t     中等" << endl;
			cout << "\t\t\t\t\t\t  ▲ 困难" << endl;
			cout << "\t\t\t\t\t\t    自定义" << endl;
			cout << "\t\t\t\t\t\t     退出" << endl;
			break;
		case 4:
			cout << "\t\t\t\t\t\t     简单" << endl;
			cout << "\t\t\t\t\t\t     中等" << endl;
			cout << "\t\t\t\t\t\t     困难" << endl;
			cout << "\t\t\t\t\t\t  ▲自定义" << endl;
			cout << "\t\t\t\t\t\t     退出" << endl;
			break;
		case 5:
			cout << "\t\t\t\t\t\t     简单" << endl;
			cout << "\t\t\t\t\t\t     中等" << endl;
			cout << "\t\t\t\t\t\t     困难" << endl;
			cout << "\t\t\t\t\t\t    自定义" << endl;
			cout << "\t\t\t\t\t\t  ▲ 退出" << endl;
			break;
		}
		cout << endl << "\t\t\t\t\tws或上下移动光标,空格或回车确定选择" << endl;
		int a = _getch();
		if (isascii(a))
		{
			switch (a)
			{
			case'w':case'W':
				if (choose > 1)
				{
					choose--;
				}
				break;
			case's':case'S':
				if (choose < 5)
				{
					choose++;
				}
				break;
			case '\r':case 32:
				boom = 1;
				break;
			}
		}
		else
		{
			switch (_getch())
			{
			case 72:
				if (choose > 1)
				{
					choose--;
				}
				break;
			case 80:
				if (choose < 5)
				{
					choose++;
				}
				break;
			}
		}
		if (boom == 1)
		{
			break;
		}
	}

	switch (choose)
	{
	case 1:
		mapx = 11;
		mapy = 11;
		break;
	case 2:
		mapx = 18;
		mapy = 18;
		break;
	case 3:
		mapx = 18;
		mapy = 32;
		break;
	case 4:
		cout << endl << endl;
		system("cls");
		cout << "请输入行" << endl;
		while (1)
		{
			cin >> mapx;
			if (mapx > 4 && mapx < 40)
			{
				break;
			}
			else
			{
				cout << "本游戏只支持5~40格以内的地图大小,请重新输入行数" << endl;
			}
		}
		system("cls");
		cout << endl << endl;
		cout << "请输入列" << endl;
		while (1)
		{
			cin >> mapy;
			if (mapy > 4 && mapy < 40)
			{
				break;
			}
			else
			{
				cout << "本游戏只支持5~40格地图大小,请重新输入列数" << endl;
			}
		}
		break;
	case 5:
		for (int x = 0; x < mapx; x++)
		{
			delete[] map[x];
		}
		delete[] map;
		exit(0);
		break;
	}
	system("cls");
}
void buildemptymap(int **map,int mapx, int mapy,int inside[])
{
	int count = 15;
	for (int x = 0; x < mapx + 2; x++)
	{
		for (int y = 0; y < mapy + 2; y++)
		{
			if (x == 0 || x == mapx+1 || y == 0 || y == mapy+1)
			{
				map[x][y] = 0;
			}
			else
			{
				if (count < 0)
				{
					count = 15;
				}
				map[x][y] = inside[count];
				count--;
			}
		}
	}
}
void rand(int**map, int mapx, int mapy,Pos &posA)
{
	srand(time(NULL));
	for (int x = 1; x < 1000; x++)
	{
		int a = rand() % mapx + 1;
		int b = rand() % mapy + 1;
		int c = rand() % mapx + 1;
		int d = rand() % mapy + 1;
		if (a != c && b != d)
		{
			if (a == posA.x &&b == posA.y)
			{
			map[a][b] = posA.backup;
			map[a][b] = map[a][b] ^ map[c][d];
			map[c][d] = map[a][b] ^ map[c][d];
			map[a][b] = map[a][b] ^ map[c][d];
			posA.backup = map[a][b];
			map[a][b] = 11;
			}
			else if (c == posA.x && d == posA.y)
			{
				map[c][d] = posA.backup;
				map[a][b] = map[a][b] ^ map[c][d];
				map[c][d] = map[a][b] ^ map[c][d];
				map[a][b] = map[a][b] ^ map[c][d];
				posA.backup = map[c][d];
				map[c][d] = 11;
			}
			else
			{
				map[a][b] = map[a][b] ^ map[c][d];
				map[c][d] = map[a][b] ^ map[c][d];
				map[a][b] = map[a][b] ^ map[c][d];
			}
		}
	}


	//for (int x = 0; x < mapx + 1; x++)
	//{
	//	for (int y = 0; y < mapy + 1; y++)
	//	{
	//		cout << map[x][y] << " ";
	//	}
	//	cout << endl;
	//}
}
void drawmap(int **map, int mapx, int mapy, Pos &posA,Pos &space1)
{
	for (int x = 0; x < mapx + 1; x++)
	{
		cout << "  \t\t\t";
		for (int y = 0; y < mapy + 1; y++)
		{
			switch (map[x][y])
			{
			case 0:
				cout << "  ";
				break;
			case 1:
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
				cout << "※";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 2:
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "▲";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 3:
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
				cout << "●";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 4:
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | BACKGROUND_INTENSITY);
				cout << "▓";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 5:
				SetConsoleTextAttribute(h, FOREGROUND_RED | BACKGROUND_INTENSITY);
				cout << "★";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 6:
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
				cout << "㊣";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 7:
				cout << "ㄅ";
				break;
			case 8:
				cout << "ㄖ";
				break;
			case 9:
				cout << "  ";
				break;
			case 11:
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				switch (posA.backup)
				{
				case 1:
					cout << "※";
					break;
				case 2:
					cout << "▲";
					break;
				case 3:
					cout << "●";
					break;
				case 4:
					cout << "▓";
					break;
				case 5:
					cout << "★";
					break;
				case 6:
					cout << "㊣";
					break;
				case 7:
					cout << "ㄅ";
					break;
				case 8:
					cout << "ㄖ";
					break;
				case 9:
					cout << "  ";
					break;
				case 10087:
					cout << "  ";
					break;
				}
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;

			case 10086:
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				switch (space1.backup)
				{
				case 1:
					cout << "※";
					break;
				case 2:
					cout << "▲";
					break;
				case 3:
					cout << "●";
					break;
				case 4:
					cout << "▓";
					break;
				case 5:
					cout << "★";
					break;
				case 6:
					cout << "㊣";
					break;
				case 7:
					cout << "ㄅ";
					break;
				case 8:
					cout << "ㄖ";
					break;
				case 9:
					cout << "  ";
					break;
				}
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			}
		}
		cout << endl;
	}
}
void deleteone(int **map, int mapx, int mapy, Pos &posA, int posx, int posy, Pos &space1)
{
	//if (map[posx][posy] == 10086)
	//{
	//	map[posx][posy] = space1.backup;
	//}
	if (posx<1 || posy<1 || posx>mapx || posy>mapy)
	{
		return;
	}

	if (map[posx][posy] == 11)
	{
		if (space1.backup == posA.backup)
		{
			map[posA.x][posA.y] = 10087;
			space1.backup = 10087;
			//for (int x = 0; x < mapx + 1; x++)
			//{
			//	for (int y = 0; y < mapy + 1; y++)
			//	{
			//		cout << map[x][y] << "\t";
			//	}
			//	cout << endl;
			//}
			//_getch();
			posA.backup = 9;
		}
		else
		{
			map[space1.x][space1.y] = space1.backup;
		}
		return;
	}	
	if ((map[posx][posy] > 0 && map[posx][posy] < 9) || (map[posx][posy] == 10087))
	{
		return;
	}

	if (map[posx][posy] == 10086 || map[posx][posy] == 9)
	{
		if (map[posx][posy] == 9)
	{
		map[posx][posy] = 10087;
	}
		deleteone(map, mapx, mapy, posA, posx - 1, posy, space1);
		deleteone(map, mapx, mapy, posA, posx + 1, posy, space1);
		deleteone(map, mapx, mapy, posA, posx, posy - 1, space1);
		deleteone(map, mapx, mapy, posA, posx, posy + 1, space1);
	}	

}
void move(int **map, int mapx, int mapy, Pos &posA, Pos &space1,int &ischoosedone,int &backtomainUI)
{
	switch (_getch())
	{
	case 27:
		backtomainUI = 1;
		break;
	case 32:case '\r':
		if (posA.x == space1.x&&posA.y == space1.y)
		{
			break;
		}
		else
		{
			switch (ischoosedone)
			{
			case  0:
				map[posA.x][posA.y] = 10086;
				space1 = posA;
				ischoosedone = 1;
				break;
			case 1:
				int q = space1.x, w = space1.y;
				deleteone(map, mapx, mapy, posA, q, w, space1);
				map[space1.x][space1.y] = space1.backup;
				space1 = { 0, 0 };
				for (int e = 0; e < mapx+1; e++)
				{
					for (int r = 0; r < mapy+1; r++)
					{
						if (map[e][r] == 10087)
						{
							map[e][r] = 9;
						}
					}
				}
				ischoosedone = 0;
			}
			break;
		}
	break;
	case'r': case'R':
		ischoosedone = 0;
		for (int x = 0; x < mapx+1; x++)
		{
			for (int y = 0; y < mapy + 1; y++)
			{
				if (map[x][y] == 10086)
				{
					map[x][y] = space1.backup;
				}
			}
		}
		space1 = { 0, 0, 0 };
		rand(map, mapx, mapy, posA);
		break;
	case'w':case'W':
		if (map[posA.x - 1][posA.y] == 10086)
		{
			break;
		}
		if (map[posA.x - 1][posA.y] > 0)
		{
			if (space1.x == posA.x&&space1.y == posA.y)
			{
				map[posA.x][posA.y] = 10086;
				posA.backup = map[posA.x - 1][posA.y];
				map[--posA.x][posA.y] = 11;
			}
			else
			{
				map[posA.x][posA.y] = posA.backup;
				posA.backup = map[posA.x - 1][posA.y];
				map[--posA.x][posA.y] = 11;
			}
		}
		break;
	case's':case'S':
		if (map[posA.x + 1][posA.y] == 10086)
		{
			break;
		}
		if (map[posA.x + 1][posA.y] > 0)
		{
			if (space1.x == posA.x&&space1.y == posA.y)
			{
				map[posA.x][posA.y] = 10086;
				posA.backup = map[posA.x + 1][posA.y];
				map[++posA.x][posA.y] = 11;
			}
			else
			{
				map[posA.x][posA.y] = posA.backup;
				posA.backup = map[posA.x + 1][posA.y];
				map[++posA.x][posA.y] = 11;
			}
		}
		break;
	case'a':case'A':
		if (map[posA.x][posA.y - 1] == 10086)
		{
			break;
		}
		if (map[posA.x][posA.y - 1] > 0)
		{
			if (space1.x == posA.x&&space1.y == posA.y)
			{
				map[posA.x][posA.y] = 10086;
				posA.backup = map[posA.x][posA.y - 1];
				map[posA.x][--posA.y] = 11;
			}
			else
			{
				map[posA.x][posA.y] = posA.backup;
				posA.backup = map[posA.x][posA.y - 1];
				map[posA.x][--posA.y] = 11;
			}
		}
		break;
	case'd':case'D':
		if (map[posA.x][posA.y + 1] == 10086)
		{
			break;
		}
		if (map[posA.x][posA.y + 1] > 0)
		{
			if (space1.x == posA.x&&space1.y == posA.y)
			{
				map[posA.x][posA.y] = 10086;
				posA.backup = map[posA.x][posA.y + 1];
				map[posA.x][++posA.y] = 11;
			}
			else
			{
				map[posA.x][posA.y] = posA.backup;
				posA.backup = map[posA.x][posA.y+1];
				map[posA.x][++posA.y] = 11;
			}
		}
		break;
	}
}
