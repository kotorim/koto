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
	int **map = { 0 };//真实炸弹位置
	int **showmap = { 0 };//显示用数字
	int mapx = 0;//行
	int mapy = 0;//列
	int posx = 1;//光标X
	int posy = 1;//光标y
	int bombcount = 0;//炸弹数量
	int choose = 1;//主菜单界面滚动
	int boom = 0;//判断离开主菜单
	MailUIshow();//雷
	mainUI(bombcount, mapx, mapy,map,showmap);//主菜单
	//重定向两个地图
	map = new int*[mapx + 1];
	showmap = new int *[mapx + 1];
	for (int x = 0; x < mapx + 1; x++)
	{
		map[x] = new int[mapy + 1];
		showmap[x] = new int[mapy + 1];
	}
	//变戏法
	show(mapx, mapy);
	int backup = 10;//备份光标位置显示的内容
	showmap[1][1] = 11;//该位置变为光标
	//fakemap(mapx, mapy, posx, posy, backup);
	basemap(map, showmap, mapx, mapy);
	move(map, showmap, posx, posy, backup, mapx, mapy, bombcount);//画地图,光标移动
	//删指针和内存
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