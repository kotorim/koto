#include<iostream>
#include<conio.h>
#include "funcs.h"
#include <time.h>
using namespace std;
int main()
{
	system("color 87");
	int inside[16] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8 };//˫����Ԫ��
	int **map = { 0 };//��ͼ
	int mapx = 10;//��
	int mapy = 10;//��
	int choose = 1;//���˵��������
	int boom = 0;//�ж��뿪���˵�
	while (1)
	{
		int backtomainUI = 0;
		mainUI(mapx,mapy,map);
		Pos posA = { 1, 1 };//���
		Pos space1 = { 0, 0, 0 };//��һ��
		int ischoosedone = 0;//�Ѿ�ѡ��һ����
		map = new int*[mapx + 2];//�滮��ͼ��С
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
			cout << endl << "\t\twasd�ƶ�\n\t\t�ո��س�ѡȡ\n\t\tR���������ͼ\n\t\tesc�������˵�" << endl;
			move(map, mapx, mapy, posA, space1, ischoosedone,backtomainUI);
		}
	}
	_getch();
	return 0;
}