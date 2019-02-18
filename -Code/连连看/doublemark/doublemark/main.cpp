#include<iostream>
#include<conio.h>
#include "funcs.h"
#include <time.h>
using namespace std;
int main()
{
	system("color 87");
	int inside[16] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8 };//双数的元素
	int **map = { 0 };//地图
	int mapx = 10;//行
	int mapy = 10;//列
	int choose = 1;//主菜单界面滚动
	int boom = 0;//判断离开主菜单
	while (1)
	{
		int backtomainUI = 0;
		mainUI(mapx,mapy,map);
		Pos posA = { 1, 1 };//光标
		Pos space1 = { 0, 0, 0 };//第一格
		int ischoosedone = 0;//已经选中一个了
		map = new int*[mapx + 2];//规划地图大小
		for (int x = 0; x < mapx + 2; x++)
		{
			map[x] = new int[mapy + 2];
		}
		buildemptymap(map, mapx, mapy, inside);
		posA.backup = map[1][1];
		map[1][1] = 11;
		rand(map, mapx, mapy, posA);
		while (1)
		{
			if (backtomainUI == 1)
			{
				break;
			}
			system("cls");
			int win = 1;
			for (int x = 1; x < mapx + 1; x++)
			{
				for (int y = 1; y < mapy + 1; y++)
				{
					if (map[x][y] != 9)
					{
						win = 0;
					}
				}
			}
			if (win == 1)
			{
				system("cls");
				cout << "win" << endl;
				_getch();
				break;
			}
			drawmap(map, mapx, mapy, posA, space1);
			cout << endl << "\t\twasd移动\n\t\t空格或回车选取\n\t\tR重新随机地图\n\t\tesc返回主菜单" << endl;
			move(map, mapx, mapy, posA, space1, ischoosedone,backtomainUI);
		}
	}
	_getch();
	return 0;
}