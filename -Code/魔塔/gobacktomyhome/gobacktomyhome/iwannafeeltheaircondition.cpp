
//int imdead = 0;//�ж����������ٿ�ѭ��
//int play = 0;
//Item null = { "��    ", 0, 0, 0, EQUIP };//������Ϊ��
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
//	system("title ħ��v1.0");
//	while(1)
//	{
//		HANDLE hThread;
//		DWORD ThreadID;
//		system("mode con: cols=130 lines=40");//cmd��С
//		srand(time(NULL));
//		imdead = 0;
//		int map1[15][15];
//		int map2[15][15];
//		int map3[15][15];
//		int map4[15][15];
//		int map5[15][15];
//		int map6[15][15];
//		int(*map[6])[15] = { map1, map2, map3, map4, map5,map6 };//���Ըı�ĵ�ͼ
//		int red = 0, blue = 0,yellow = 0;//����Կ��
//		Bag herosbag; //��
//		Item items[5] = { null, null, null, null, null };//�ǿյ�
//		for (int x = 0; x < 5; x++)
//		{
//			herosbag.item[x] = items[x];//�����ǵİ�
//		}
//		Hero hero = { 14, 7, "����", 1, 10, 0, 5, 5,0, herosbag };//���ֹ¶�
//		//doge();//����˼��
//		//Sleep(20);
//		//head();//����
//		
//		//char a = _getch();
//		//cout << dec<<(int)a << endl;
//		//_getch();
//		mainUI(map,hero,red,blue,yellow);//���˵�
//		play = 1;
//		if (play == 1)
//		{
//			hThread = CreateThread(NULL, 5, (LPTHREAD_START_ROUTINE)Thread1,NULL, 0, &ThreadID);
//		}
//		while (imdead == 0)//û�Ҿͼ���
//		{
//			
//			drawmap(map, hero, red, blue, yellow);//��
//			gotmove(map, hero, red ,blue,yellow);//��
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