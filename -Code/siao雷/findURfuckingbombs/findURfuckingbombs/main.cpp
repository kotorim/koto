#include <iostream>
#include <conio.h>
#include <time.h>
#include<Windows.h>
#include <cstring>
using namespace std;

#include "funcs.h"
int main()
{
	while (1)
	{
		system("color 87");
	int **map = { 0 };//��ʵը��λ��
	int **showmap = { 0 };//��ʾ������
	int mapx = 0;//��
	int mapy = 0;//��
	int posx = 1;//���X
	int posy = 1;//���y
	int bombcount = 0;//ը������
	int choose = 1;//���˵��������
	int boom = 0;//�ж��뿪���˵�
	MailUIshow();//��
	mainUI(bombcount, mapx, mapy,map,showmap);//���˵�
	//�ض���������ͼ
	map = new int*[mapx + 1];
	showmap = new int *[mapx + 1];
	for (int x = 0; x < mapx + 1; x++)
	{
		map[x] = new int[mapy + 1];
		showmap[x] = new int[mapy + 1];
	}
	//��Ϸ��
	show(mapx, mapy);
	int backup = 10;//���ݹ��λ����ʾ������
	showmap[1][1] = 11;//��λ�ñ�Ϊ���
	//fakemap(mapx, mapy, posx, posy, backup);
	basemap(map, showmap, mapx, mapy);
	move(map, showmap, posx, posy, backup, mapx, mapy, bombcount);//����ͼ,����ƶ�
	//ɾָ����ڴ�
	for (int x = 0; x < mapx; x++)
	{
		delete[] map[x];
		delete[] showmap[x];
	}
	delete[] map;
	delete[] showmap;
}
	return 0;
}