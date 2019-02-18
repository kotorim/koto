#include <iostream>
#include <conio.h>
#include <time.h>
#include<Windows.h>
#include <cstring>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//返回坐标位置周围8格雷数量
int findbomb(int **map,int posx,int posy,int mapx,int mapy)
{
	int count = 0;
	if (map[posx][posy] == 9)
	{
		return 9;
	}
	if (map[posx - 1][posy - 1] == 9)
	{
		count++;
	}
	if (map[posx - 1][posy] == 9)
	{
		count++;
	}
	if (map[posx - 1][posy + 1] == 9)
	{
		count++;
	}
	if (map[posx][posy - 1] == 9)
	{
		count++;
	}
	if (map[posx][posy + 1] == 9)
	{
		count++;
	}
	if (map[posx +1][posy - 1] == 9)
	{
		count++;
	}
	if (map[posx + 1][posy] == 9)
	{
		count++;
	}
	if (map[posx + 1][posy + 1] == 9)
	{
		count++;
	}
	return count;
}
//界定地图
void basemap(int **map, int **showmap, int mapx, int mapy)
{
	//整体赋值(从第1位开始)(留边界)
	for (int x = 0; x < mapx + 1; x++)
	{
		for (int y = 0; y < mapy + 1; y++)
		{
			if (x == 0 || x == (mapx) || y == 0 || y == (mapy))
			{
				map[x][y] = 12;
				showmap[x][y] = 12;
			}
			else
			{
				map[x][y] = 0;
				showmap[x][y] = 10;
			}
		}
	}
}
//放置炸弹
void buildmap(int **map,int **showmap, int bombcount, int mapx, int mapy,int posx,int posy)
 {
	 srand(time(NULL));
	//放下设定数量的炸弹
	int count = 0;
	for (int x = 1; x < mapx; x++)
	{
		for (int y = 1; y < mapy; y++)
		{
			if (count == bombcount)
			{
				break;
			}
			else
			{
				map[x][y] = 9;
				count++;
			}
		}
	}
	//随机放置炸弹的位置
	count = 0;
	for (int x = 1; x < mapx; x++)
	{
		for (int y = 1; y < mapy; y++)
		{
			if (count == bombcount)
			{
				break;
			}
			else
			{
				int a = rand() % (mapx-1)+1;
				int b = rand() % (mapy-1)+1;
				if (a == posx&&b == posy)
				{
					a = rand() % (mapx - 1) + 1;
					b = rand() % (mapy - 1) + 1;
					int flag = 0;
					for (int x = mapx; x > 0; x--)
					{
						for (int y = mapy; y > 0; y--)
						{
							if (map[x][y] != 9)
							{
								a = x;
								b = y;
								flag = 1;
							}
						}
						if (flag == 1)
						{
							break;
						}
					}
				}
				map[x][y] = map[x][y] ^ map[a][b];
				map[a][b] = map[x][y] ^ map[a][b];
				map[x][y] = map[x][y] ^ map[a][b];
				count++;
			}
		}
	}
	//生成数字
	for (int x = 1; x < mapx; x++)
	{
		for (int y = 1; y < mapy; y++)
		{
			map[x][y] = findbomb(map, x, y,mapx,mapy);
		}
	}
}
//画地图
void drawmap(int **showmap,int mapx,int mapy,int &posx,int &posy,int backup,int &timescount)
{
	for (int x = 0; x < mapx; x++)
	{
		cout << "  \t\t\t";
		for (int y = 0; y < mapy; y++)
		{
			switch (showmap[x][y])
			{
			case 0:
				cout << "  ";
				break;
			case 1:
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
				cout << "１";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 2:
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "２";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 3:
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
				cout << "３";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 4:
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | BACKGROUND_INTENSITY);
				cout << "４";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 5:
				SetConsoleTextAttribute(h, FOREGROUND_RED | BACKGROUND_INTENSITY);
				cout << "５";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 6:
				cout << "６";
				break;
			case 7:
				cout << "７";
				break;
			case 8:
				cout << "８";
				break;
			case 9:
				SetConsoleTextAttribute(h, FOREGROUND_RED |FOREGROUND_INTENSITY| BACKGROUND_INTENSITY);
				cout << "▓";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 10:
				cout << "█";
					break;
			case 11:
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_INTENSITY);
				switch (backup)
				{
				case 0:
					cout << "□";
					break;
				case 1:
					cout << "①";
					break;
				case 2:
					cout << "②";
					break;
				case 3:
					cout << "③";
					break;
				case 4:
					cout << "④";
					break;
				case 5:
					cout << "⑤";
					break;
				case 6:
					cout << "⑥";
					break;
				case 7:
					cout << "⑦";
					break;
				case 8:
					cout << "⑧";
					break;
				case 9:
					cout << "Ⅹ";
					break;
				case 10:
					cout << "█";
					break;
				case 13:
					cout << "▲";
					break;
				}
				posx = x;
				posy = y;
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
					break;
			case 12:
				cout << "  ";
				break;
			case 13:
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
				cout << "▲";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 14:
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY|BACKGROUND_INTENSITY);
				cout << "×";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			case 15:
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
				cout << "√";
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
				break;
			}
		}
		cout << endl;
	}
	if (timescount <= 15&&timescount>=0)
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE|FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
		cout << "\t\twasd 或者 ↑↓←→ 移动光标" << endl << "\t\tSpace 或者 Enter 排雷" << endl << "\t\tTab插旗" << endl << "\t\t+ 号上天" << endl << "\t\tBackspace关闭提示" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
	}
	else if (timescount > 15 && timescount <= 50)
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
		cout << "\t\twasd 或者 ↑↓←→ 移动光标" << endl << "\t\tSpace 或者 Enter 排雷" << endl << "\t\tTab插旗" << endl << "\t\t+ 号上天" << endl << "\t\tBackspace关闭提示" << endl;
	}
	if (timescount > 70)
	{
		cout << "\t\tBackspace打开提示" << endl;
	}
	timescount++;
}
//递归回车位置光标周围
void  click(int **map,int **showmap, int posx, int posy, int &backup, int mapx, int mapy)
{
	//本身是边界
	if (posx<=0||posx>=mapx||posy<=0||posy>=mapy)
	{
		return;
	}	
	//本身是雷
	//本身是被翻开的
	if (showmap[posx][posy] >= 0 && showmap[posx][posy] <= 9)
	{
		return;
	}	
	if (showmap[posx][posy] == 13)
	{
		return;
	}
	showmap[posx][posy] = map[posx][posy];
	if (map[posx][posy] >= 1 && map[posx][posy] <= 9)
	{
		return;
	}
	//本身是被标记的
	//递归周围8格
		click(map, showmap, posx - 1, posy - 1, backup, mapx, mapy);
		click(map, showmap, posx - 1, posy, backup, mapx, mapy);
		click(map, showmap, posx - 1, posy + 1, backup, mapx, mapy);
		click(map, showmap, posx, posy - 1, backup, mapx, mapy);
		click(map, showmap, posx, posy + 1, backup, mapx, mapy);
		click(map, showmap, posx + 1, posy - 1, backup, mapx, mapy);
		click(map, showmap, posx +1, posy, backup, mapx, mapy);
		click(map, showmap, posx + 1, posy + 1, backup, mapx, mapy);
	return;
}
//光标移动
void move(int **map, int**showmap, int posx, int posy, int &backup, int mapx, int mapy, int bombcount)
{
	int check = 0;
	int isthefirsttimepress = 1;
	int cheat = 0;
	int timescount = 0;
	int nevermind = -1;
	while (1)
	{
		system("cls");
		drawmap(showmap, mapx, mapy, posx, posy, backup,timescount);//画地图
		if (cheat == 1)
		{
			drawmap(map, mapx, mapy, posx, posy, backup,nevermind);
		}
		int count=0;//计分
		for (int x = 0; x < mapx + 1; x++)
		{
			for (int y = 0; y < mapy + 1; y++)
			{
				if (showmap[x][y] ==13&&map[x][y]==9 )
				{
					count++;
				}
			}
		}
		if (count == bombcount)
		{   

			cout << "  \t\t\t\t你赢了" << endl;
			_getch();
			return;
		}
		if (check == 1)
		{
			cout << "  \t\t\t\t你踩到了雷" << endl;
			_getch();
			return;
		}
		char move = _getch();
		if (isascii(move))
		{
			switch (move)
			{
			case 8:
				if (timescount <= 70)
				{
					timescount = 100;
				}
				else
				{
					timescount = 0;
				}
				break;
			case '+':
				if (cheat == 0)
				{
					cheat = 1;
				}
				else
				{
					cheat = 0;
				}
				break;
			case 9:
				if (backup ==10)
				{
					showmap[posx][posy] = 13;
					backup = 13;
				}
				else if (backup == 13)
				{
					showmap[posx][posy] = 10;
					backup = 10;
				}
				break;
			case'w':case'W':
				if (posx - 1 > 0)
				{
					showmap[posx][posy] = backup;
					backup = showmap[posx - 1][posy];
					showmap[posx - 1][posy] = 11;
				}
				break;
			case's':case'S':
				if (posx + 1 < mapx)
				{
					showmap[posx][posy] = backup;
					backup = showmap[posx + 1][posy];
					showmap[posx + 1][posy] = 11;
				}
				break;
			case'a':case'A':
				if (posy - 1 > 0)
				{
					showmap[posx][posy] = backup;
					backup = showmap[posx][posy - 1];
					showmap[posx][posy - 1] = 11;
				}
				break;
			case'd':case'D':
				if (posy + 1 < mapy)
				{
					showmap[posx][posy] = backup;
					backup = showmap[posx][posy + 1];
					showmap[posx][posy + 1] = 11;
				}
				break;
			case '\r':case 32:
				if (isthefirsttimepress)
				{
					buildmap(map, showmap, bombcount, mapx, mapy, posx, posy);//map随机炸弹位置,写入数字
					isthefirsttimepress = 0;
				}
				if (map[posx][posy] == 9)
				{
					for (int x = 0; x < mapx + 1; x++)
					{
						for (int y = 0; y < mapy + 1; y++)
						{	
							if (showmap[x][y] ==13&&map[x][y]==9)
							{
								showmap[x][y] = 15;
							}
							if (map[x][y] == 9&&showmap[x][y]!=15)
							{
								showmap[x][y] = map[x][y];
							}
			
							if (showmap[x][y] == 13&&map[x][y]!=9)
							{
								showmap[x][y] = 14;
							}
	

						}
					}
					check = 1;
				}
				click(map, showmap, posx, posy, backup, mapx, mapy);
				backup = map[posx][posy];
			}
		}
		else
		{
			switch (_getch())
			{
			case 72:
				if (posx - 1 > 0)
				{
					showmap[posx][posy] = backup;
					backup = showmap[posx - 1][posy];
					showmap[posx - 1][posy] = 11;
				}
				break;
			case 80:
				if (posx + 1 < mapx)
				{
					showmap[posx][posy] = backup;
					backup = showmap[posx + 1][posy];
					showmap[posx + 1][posy] = 11;
				}
				break;
			case 75:
				if (posy - 1 > 0)
				{
					showmap[posx][posy] = backup;
					backup = showmap[posx][posy - 1];
					showmap[posx][posy - 1] = 11;
				}
				break;
			case 77:
				if (posy + 1 < mapy)
				{
					showmap[posx][posy] = backup;
					backup = showmap[posx][posy + 1];
					showmap[posx][posy + 1] = 11;
				}
				break;
			}
		}
	}
}
//戏法
void show(int mapx,int mapy)
{
	system("color 87");
	for (int x = 0; x < mapx; x++)
	{
		cout << "  \t\t\t";
		for (int y = 0; y < mapy; y++)
		{
			Sleep(10);
			if (x == 0 || x == mapx + 1 || y == 0 || y == mapy + 1)
			{
				cout << "  ";
			}
			else
			{
				cout << "█";
			}
		}
		cout << endl;
	}
	system("cls");
}
//戏法2
void MailUIshow()
{
	system("color 87");
	char a[23][23] = 
	{
	 "                      ",
	 "███████████" ,
	 "          █         " ,
	 "███████████",
	 "█        █        █",
	 "█  ██  █  ██  █",
	 "█        █        █",
	 "    ██  █  ██    ",
	 "                      ",
	 "  █████████  ",
	 "  █      █      █  ",
	 "  █      █      █  ",
	 "  █████████  ",
	 "  █      █      █  ",
	 "  █      █      █  ",
	 "  █████████  ",
	};

	for (int x = 16; x >= 0; x--)
	{
		Sleep(50);
		system("cls");
		for (int y = x; y <16; y++)
		{
			
			cout << "\t\t\t\t\t    ";
			cout << a[y] << endl;
		}
	}
	cout << endl << endl;
	cout << "\t\t\t\t\t      点按任意键开始游戏";
	_getch();
	system("cls");
}
//主菜单
void mainUI(int &bombcount,int &mapx,int &mapy,int **map,int **showmap)
{
	int choose = 1;//主菜单界面滚动
	int boom = 0;
	while (10086)
	{
		system("cls");
		cout << "\t\t\t\t\t\t   扫雷v1.0" << endl << endl << endl;
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
		cout <<endl<< "\t\t\t\t\tws或上下移动光标,空格或回车确定选择"<<endl;
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
		mapx =11 ;
		mapy = 11;
		bombcount = 10;
		break;
	case 2:
		mapx = 18;
		mapy = 18;
		bombcount = 40;
		break;
	case 3:
		mapx = 18;
		mapy = 32;
		bombcount = 99;
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
		system("cls");
		cout << endl << endl;
		cout << "请输入炸弹数量" << endl;
		while (1)
		{
			cin >> bombcount;
			if (bombcount <= mapx*mapy&&bombcount>0)
			{
				break;
			}
			else
			{
				cout << "炸弹数量超出地图总大小或小于一个,请重新输入" << endl;
			}
		}
		break;
	case 5:
		for (int x = 0; x < mapx; x++)
		{
			delete[] map[x];
			delete[] showmap[x];
		}
		delete[] map;
		delete[] showmap;
		exit(0);
		break;
	}
	system("cls");
}

