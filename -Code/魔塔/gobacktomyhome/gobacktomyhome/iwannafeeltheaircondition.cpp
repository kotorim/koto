
//int imdead = 0;//判断死亡跳出操控循环
//int play = 0;
//Item null = { "空    ", 0, 0, 0, EQUIP };//道具栏为空
//void Thread1()
//{
//	/*while (1)
//	{*/
//		//system("title %time%");
//		//system("color F0");
//		//Sleep(1000);
//		//system("color 0F");
//	//}
//}
//int main()
//{	
//
//	system("title 魔塔v1.0");
//	while(1)
//	{
//		HANDLE hThread;
//		DWORD ThreadID;
//		system("mode con: cols=130 lines=40");//cmd大小
//		srand(time(NULL));
//		imdead = 0;
//		int map1[15][15];
//		int map2[15][15];
//		int map3[15][15];
//		int map4[15][15];
//		int map5[15][15];
//		int map6[15][15];
//		int(*map[6])[15] = { map1, map2, map3, map4, map5,map6 };//用以改变的地图
//		int red = 0, blue = 0,yellow = 0;//三种钥匙
//		Bag herosbag; //包
//		Item items[5] = { null, null, null, null, null };//是空的
//		for (int x = 0; x < 5; x++)
//		{
//			herosbag.item[x] = items[x];//是主角的包
//		}
//		Hero hero = { 14, 7, "亚索", 1, 10, 0, 5, 5,0, herosbag };//快乐孤儿
//		//doge();//顾名思义
//		//Sleep(20);
//		//head();//动画
//		
//		//char a = _getch();
//		//cout << dec<<(int)a << endl;
//		//_getch();
//		mainUI(map,hero,red,blue,yellow);//主菜单
//		play = 1;
//		if (play == 1)
//		{
//			hThread = CreateThread(NULL, 5, (LPTHREAD_START_ROUTINE)Thread1,NULL, 0, &ThreadID);
//		}
//		while (imdead == 0)//没挂就继续
//		{
//			
//			drawmap(map, hero, red, blue, yellow);//画
//			gotmove(map, hero, red ,blue,yellow);//动
//		}
//
//	}
//	return 0;
//}
#pragma once
#include<iostream>
#include<conio.h>
#include<windows.h>
#include <time.h>
#include "funcs.h"
#include "Hero.h"
using namespace std;

int main()
{
	system("color F0");
	Pos pos = { 1, 1 };
	Hero hero(pos);
	hero.showheromessage();
	hero.showbag();
	_getch();
	return 0;
}