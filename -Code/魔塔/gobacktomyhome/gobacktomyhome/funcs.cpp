#include <iostream>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include "funcs.h"
using namespace std;
int movechoose = 0;//ѡ�����
int uplevel = 0;//����
int drawtype = 0;//��ͼ�ӳ��ж�
int springwatertimes = 3;//Ȫˮ����
int weaponusetimes = rand()%7 + 3;
int shildusetimes = rand()%20 + 7;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hout;
COORD coord;
//��
//Monster elf = { "ELF   ", 999,1000,999,999};
//Monster Slime = { "ʷ��ķ", 14, 30, 20, 5,30 };
//Monster Gob = { "�¶���", 50, 100, 31, 8,85 };
//Monster Youmo = { "��ħ", 25, 47, 27, 14, 30};
//Monster Monstro = { "��ȴ�", 150, 152, 34,21, 200 };
//Monster Mino = { "��ŵ��", 35, 143,50, 170 };
//Monster Cinder = { "н������", 300, 200, 200, 700 };
//Monster Circle = { "��ӡ����ʿ", 50, 250, 20, 20, 500 };
//Monster Midir= { "���ɺڰ����׵϶�",400,300, 300,750};
//Monster Lastbooooss = { "���˹¶�", 539, 0, 400, 400, 800 };
//��Ʒ
//Item woodsword = { "ľ��", 0, 9, 0, EQUIP };
//Item woodshild = { "ľ��", 0, 0, 9, EQUIP };
//Item ironsword = { "����", 0, 20, 0, EQUIP };
//Item ironshild = { "����", 0, 0, 20, EQUIP };
//Item extrasword = { "����ն", 0, 20, 0, EQUIP };
//Item extrashild = { "���ֶ�", 0, 0, 20, EQUIP };
//Item axeshild = { "�����ܸ�", 0, 100, 100, EQUIP };
//Item EstusFlask = { "Ԫ��ƿ", 0, 0, 0, USE };

//��ʼ���õ�ͼ
int map1[15][15] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, -8, -8, -8, -8, -8, 0, 2, 0, -8, -8, -8, -8, -8, 1 },
	{ 1, -8, -8, -8, -8, -8, 0, 99, 0, -8, -8, -8, -8, -8, 1 },
	{ 1, -8, -8, -8, -8, -8, 0, 0, 0, -8, -8, -8, -8, -8, 1 },
	{ 1, -8, -8, -8, -8, -8, 0, 0, 0, -8, -8, -8, -8, -8, 1 },
	{ 1, -8, -8, -8, -8, -8, 0, 0, 0, -8, -8, -8, -8, -8, 1 },
	{ 1, -8, -8, -8, -8, -8, 0, 0, 0, -8, -8, -8, -8, -8, 1 },
	{ 1, 1, -8, -8, -8, -8, 0, 0, 0, -8, -8, -8, -8, 1, 1 },
	{ 1, 1, 1, -8, -8, -8, 0, 0, 0, -8, -8, -8, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, -7, 1, -7, 1, 0, -9, 0, 1, -7, 1, -7, 1, 1 },
	{ 1, -7, -7, -7, -7, -7, -7, 0, -7, -7, -7, -7, -7, -7, 1 },
	{ 1, -7, -7, -7, -7, -7, -7, 0, -7, -7, -7, -7, -7, -7, 1 },
	{ 1, -7, -7, -7, -7, -7, -7, 0, -7, -7, -7, -7, -7, -7, 1 },
	{ 1, -7, -7, -7, -7, -7, -7, 9, -7, -7, -7, -7, -7, -7, 1 },
};
int map2[15][15] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 3, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, -1, 0, -3, 0, 5, 4, 4, 0, 1, 0, 1 },
	{ 1, 1, -1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 91, 0, 1, 0,-1, 0, 91, 5, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 1, 0, 91, 0, 5, 0, 1, 0, 1 },
	{ 1, 0, 91, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 1,-2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 90, 0, 1, 1, 0, 1, 1, 1, 1, -3, 1, 1, 1 },
	{ 1, 91, 91, 91, 1, 0, 90, 0, 1, 0, 0, 91, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 99, 0, 1, 0, 4, 4, 4, 0, 1 },
	{ 1, 0, 6, 0, 1, 0, 2, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
int map3[15][15] =
{
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{ 1, 0, 0, 0, 0, 0, 1, 92, 0, 0, 0, 0, 9, 3, 1 },
{ 1, 0, 0, 2, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
{ 1, 0, 0, 99, 0, 0, 1, 0, 1, 0, 0, 92, 0, 4, 1 },
{ 1, 1, 1, 93, 1, 1, 1, 0, -1, 92, 92, 92, 0, 4, 1 },
{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 92, 0, 0, 1},
{ 1, 1, 1, -1, 1, 1, 1, 0, 1, 1, 1, -1, 1, 1, 1 },
{1, 0, 0, 92, 0, 0, 1, 0, 1, 0, 0, 92, 0, 0, 1},
{ 1, 0, 0, 4, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 92, 0, 0, 1, 0, 1, 0, 0, 0, 5, 0, 1 },
{ 1, 1, 1, -3, 1, 1, 1, 0, 1, 1, 1, -1, 1, 1, 1 },
{ 1, 0, 0, 93, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 11, 10, 12, 0, 1, 0, -2, 93, 0, 0, 6, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
int map4[15][15] = 
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 13, 2, 14, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 99, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 96, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 95, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 95, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 3, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};
int map5[15][15]
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 13, 2, 14, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0 ,99, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 96, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 95, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 95, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 3, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};
int map6[15][15] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, -8, -7, -7, 0, 0, 0, 98, 0, 0, 0, -7, -7, -8, 1 },
	{ 1, 1, -8, -7 , -7, 0, 0, 0, 0, 0, -7, -7, -8, 1, 1 },
	{ 1, 1, 1, -8, -7, -7, 0, 0, 0, -7, -7, -8, 1, 1, 1 },
	{ 1, 1, 1, 1, -8,-7 , -7, 0, -7, -7, -8, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, -8, -7, 0, -7, -8, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, -8, 0, -8, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1 },
};
int(*maps[6])[15] = { map1, map2, map3, map4, map5, map6 };

void speak(bool isspeak, char *a)
{
	coord.X = 1;
	coord.Y = 15;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	cout << "\t\t\t\t\t����" << endl;
	cout << "\t\t\t\t\t����ة��������������������������������������������������������������ة��������� " << endl;
	cout << "\t\t\t\t\t ��                                     �� " << endl;
	cout << a << endl;
	cout << "\t\t\t\t\t ��                                     ��" << endl;
	cout << "\t\t\t\t\t ��                                  �� ��" << endl;
	cout << "\t\t\t\t\t �����������������������������������������������������������������������������ੴ " << endl;
	cout << "\t\t\t\t\t                                       ����" << endl;
	if (isspeak == true)
	{
		char w = _getch();
		if (!isascii(w))
		{
			_getch();
		}
		coord.Y = 22;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);
		cout << "\t\t\t\t                                                                                "
			<< endl << "\t\t\t\t                                                                                "
			<< endl << "\t\t\t\t                                                                                ";
	}
}
//����ͼ��UI
void drawmap(int (**map)[15], Hero hero, int red, int blue, int yellow)
{
	HANDLE shout;
	COORD scoord;
	scoord.X = 1;
	scoord.Y = 1;
	shout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(shout, scoord);//���ָ���һ��
	//system("cls");
	cout << "                                                    \n                                                    \n";
	for (int x = -1; x < 18; x++)
	{
		if (drawtype == 1)
		{
			Sleep(50);
		}
		cout << "\t\t\t";
		switch (x)
		{
		case -1:
			cout << "����";
			break;
		case 0:
			cout << "���੤�������������������������������� ";
			break;
		case 1:
			if (strcmp(hero.name, "���ֹ¶�") == 0)
			{
				cout << " �� name:" << hero.name << "  �� ";
			}
			else
			{
				cout << " �� name:" << hero.name << "\t  �� ";
			}
			break;
		case 2:
			cout << " �� hp  :";
			if (hero.hp > (hero.lv * 50)/2 )
			{
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY |BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
			}
			else if (hero.hp <= (hero.lv * 50) / 2 && hero.hp > (hero.lv * 50) / 4)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			else if (hero.hp <= (hero.lv * 50) / 4)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			cout << hero.hp;
			SetConsoleTextAttribute(h,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
			cout<<"/"<<hero.lv*50 << "\t  �� ";
			break;
		case 3:
			cout << " �� lv  :"<<hero.lv<<" \t  �� ";
			break;
		case 4:
			cout << " �� exp :"<<hero.exp<<" \t  �� ";
			break;
		case 5:
			cout << " �� atk :"<<hero.atk<<" \t  �� ";
			break;
		case 6:
			cout << " �� def :"<<hero.def<<" \t  �� ";
			break;
		case 7:
			cout << " �� ���:"<<hero.money<<" \t  �� ";
			break;
		case 8:
			cout<<" ������������������������������������ ";
			break;
		case 9:
			cout << " ��      Կ��      �� ";
			break;
		case 10:
			cout << " ������������������������������������ ";
			break;
		case 11:
			cout << " �� ";
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			cout << "  ��";
			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
			cout << "  x    ";
			cout << red;
			cout <<"   �� ";
			break;
		case 12:
			cout << " ��                �� ";
			break;
		case 13:
			cout << " �� ";
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			cout << "  ��";
			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
			cout << "  x    ";
			cout << blue;
			cout << "   �� ";
			break;
		case 14:
			cout << " ��                �� ";
			break;
		case 15:
			cout << " �� ";
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			cout << "  ��";
			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
			cout << "  x    ";
			cout << yellow;
			cout << "   �� ";
			break;
		case 16:
			cout << "���੤�������������������������������� ";
			break;
		case 17:
			cout << "����                 ";
		}
		for (int y = 0; y < 15;y++)
		{
			if (x == 0)
			{
				cout << "����";
			}
			else if (x == 16)
			{
				cout << "����";
			}
			else if (x == 17||x==-1)
			{
				cout << "  ";
			}
			else
			{
				switch (map[uplevel][x-1][y])
				{
				case -7:
					SetConsoleTextAttribute(h, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";//ɫ��
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case -8:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";//ɫ��
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case -9:
					cout << "��";//��ͷ�ľ���
					break;
				case -10:
					cout << "��";//��ͷ�ľ���boom
					break;
				case -1:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";//��1
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case -2:
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";//��2
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case -3:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";//��3
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case 1:
					cout << "��";//ǽ
					break;
				case 2:
					cout << "��";//����¥��
					break;
				case 3:
					cout << "��";//����¥��
					break;
				case 4:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case 5:
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case 6:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case 0:
					cout << "  ";//null
					break;
				case 10:
					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";//Ȫ
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case 11:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case 12:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case 13:
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case 14:
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case 15:
					cout << "��";
					break;
				case 99:
					cout << "  ";//��¥��λ��
					break;
				case 9:
					cout << "��";//��
					break;
				case 90:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";//��1
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				case 91:
					cout << "��";//��2
					break;

				case 92:
					cout << "��";//��3
					break;
				case 93:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";//��4
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;

				case 94:
					cout << "��";//��5
					break;
				case 95:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";//��6
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;

				case 96:
					cout << "��";//��7
					break;
				case 97:					
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << "��";//��8
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;

				case 98:
					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY);
					cout << "��";//��9
					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
					break;
				}
			}
		}
		switch (x)
		{
		case -1:
			cout << "                                   ����";
			break;
		case 0:
			cout << "�����������������������������������੼ ";
			break;
		case 1:
			cout << "��      Tips      ��";
			break;
		case 2:
			cout << "������������������������������������ ";
			break;
		case 3:
			cout << "�� S :�浵 L:���� �� ";
			break;
		case 4:
			cout << "�� Q :�˳�        �� ";
			break;
		case 5:
			cout << "�� tab:����ѡ��   �� ";
			break;
		case 6:
			cout << "�� 1 :ʹ�õ���    �� ";
			break;
		case 7:
			cout << "�� 2 :��������    �� ";
			break;
		case 8:
			cout << "������������������������������������ ";
			break;
		case 9:
			cout << "��      ����      ��";
			break;
		case 10:
			cout << "������������������������������������ ";
			break;
		case 11:
			cout << "��";
			if (movechoose == 0)
			{
				cout << " ��";
			}
			else
			{
				cout << "    ";
			}
			if (hero.bag.item[0].itemtype == EQUIP)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			else if (hero.bag.item[0].itemtype == USE)
			{
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			cout << hero.bag.item[0].name;
			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
			if (strlen(hero.bag.item[2].name) == 8 && movechoose == 2)
			{
				cout << "  ��";
			}
			else if (strlen(hero.bag.item[2].name) == 8)
			{
				cout << "    ��";

			}
			else
			{
				cout << "\t   ��";
			}
			break;
		case 12:
			cout << "��";
			if (movechoose == 1)
			{
				cout << " ��";
			}
			else
			{
				cout << "    ";
			}
			if (hero.bag.item[1].itemtype == EQUIP)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			else if (hero.bag.item[1].itemtype == USE)
			{
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			cout << hero.bag.item[1].name;
			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
			if (strlen(hero.bag.item[2].name) == 8)
			{
				cout << "";
			}
			else
			{
				cout << "\t   ��";
			}
			break;
		case 13:
			cout << "��";
			if (movechoose == 2)
			{
				cout << " ��";
			}
			else
			{
				cout << "    ";
			}
			if (hero.bag.item[2].itemtype == EQUIP)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			else if (hero.bag.item[2].itemtype == USE)
			{
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			cout << hero.bag.item[2].name;
			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
			if (strlen(hero.bag.item[2].name) == 8 && movechoose == 2)
			{
				cout << "  ��";
			}
			else if (strlen(hero.bag.item[2].name) == 8)
			{
				cout << "    ��";

			}
			else
			{
				cout << "\t   ��";
			}
			break;
		case 14:
			cout << "��";
			if (movechoose == 3)
			{
				cout << " ��";
			}
			else
			{
				cout << "    ";
			}
			if (hero.bag.item[3].itemtype == EQUIP)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			else if (hero.bag.item[3].itemtype == USE)
			{
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			cout << hero.bag.item[3].name;
			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
			if (strlen(hero.bag.item[2].name) == 8 && movechoose == 2)
			{
				cout << "  ��";
			}
			else if (strlen(hero.bag.item[2].name) == 8)
			{
				cout << "    ��";

			}
			else
			{
				cout << "\t   ��";
			}
			break;
		case 15:
			cout << "��";
			if (movechoose == 4)
			{
				cout << " ��";
			}
			else
			{
				cout << "    ";
			}
			if (hero.bag.item[4].itemtype == EQUIP)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			else if (hero.bag.item[4].itemtype == USE)
			{
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			cout << hero.bag.item[4].name;
			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
			if (strlen(hero.bag.item[2].name) == 8 && movechoose == 2)
			{
				cout << "  ��";
			}
			else if (strlen(hero.bag.item[2].name) == 8)
			{
				cout << "    ��";

			}
			else
			{
				cout << "\t   ��";
			}
			break;
		case 16:
			cout << "�����������������������������������ੴ ";
			break;
		case 17:
			cout << "                  ���� ";
		}
		cout << endl;
	}
	drawtype = 0;
	return;
}
//U DIED
void youdied()
{
	char a[15][73] =
	{
		"                                                                        ",
		"                                                                        ",
		"                                                                        ",
		"                                                                        ",
		"                                                                        ",
		"                                                                        ",
		"                                                                        ",
		"                                                                        ",
		"                                                                        ",
		"��    ��    ����    ��    ��      ������    ������  ��������  ������    ",
		"��    ��  ��    ��  ��    ��      ��    ��    ��    ��        ��    ��",
		"��    ��  ��    ��  ��    ��      ��    ��    ��    ������    ��    ��",
		"  ������  ��    ��  ��    ��      ��    ��    ��    ��        ��    ��",
		"      ��  ��    ��  ��    ��      ��    ��    ��    ��        ��    ��",
		"  ����      ����      ����        ������    ������  ��������  ������"
	};
	coord.X = 1;
	coord.Y = 1;
	for (int x = 15; x >= 0; x--)
	{
		Sleep(50);
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);//���ָ���һ��
		for (int y = x; y <15; y++)
		{
			cout << "\t\t\t    ";
			cout << a[y] << endl;
		}
	}
	uplevel = 0;
	cout << "\n\n\n\t\t\t\t\t\t�����������";
	_getch();
}
//���ǵ�
void gamestart()
{
	char story[28][43] =
	{
		" ",
		" ",
		" ",
		" ",
		" ",
		" ",
		" ",
		" ",
		" ",
		" ",
		" ",
		" ",
		" ",
		" ",
		"14�����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"13�����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"12�����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"11�����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"10�����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"9 �����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"8 �����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"7 �����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"6 �����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"5 �����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"4 �����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"3 �����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"2 �����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
		"1 �����Ǿ��������Ǿ��������Ǿ��������Ǿ���",
	};
	for (int x = 28; x >= 0; x--)
	{
		Sleep(100);
		system("cls");
		for (int y = x; y <28; y++)
		{

			cout << "\t\t\t    ";
			cout << story[y] << endl;
		}
	}
}
//����
void head()
{
	/*char a[][78] =
	{
		"                                                                        ",
		"                                                                   ",
		"   ����                      ��                                ��            ",
		" ��    ��                    ��                                ��   ���� ",
		" ��    ��    ����  ������    ������      ����     ������          ��    ��   ",
		" ��    ��  ��      ��    ��  ��    ��  ��    ��   ��    ��        ��         ",
		" ��    ��  ��      ��    ��  ��    ��  ��    ��   ��    ��          ����     ",
		"   ����    ��      ������    ��    ��    ������   ��    ��              ��   ",
		"                   ��                                             ��    ��",
		"                   ��                                               ����",
		"                                                                       ",
		"  ��                                                                      ",
		"������    ����    ��  ��  ��    ����      ����",
		"  ��    ��    ��  ��  ��  ��  ��    ��  ��",
		"  ��    ��    ��  ��  ��  ��  ��  ��    ��",
		"    ��    ����      ��  ��      ������  ��",
	};*/

	char a[][101] =
	{
		/*"                          @8;                                     S8@K                              ",
		"         Lc;            .@8@                                      xbE.                              ",
		"        ;8@8s          ;@8@V                                                                        ",
		"        k@O@8.        V@KV@T                            .L;.                                        ",
		"        @8 S@c       @@c 2@L         J@8@O.           ;8@8@8x     :             p8J                 ",
		"       E@x .8@,    ;@@L  @8:       Z8@J;W@8          @@Z  V@k    @8;          Y@8@@J                ",
		"       8@   T8@   L8@    8@      ,@8c   ;8z        L@8,   88L   L8@          W@Y  @8        :       ",
		"      C@K    4@@ L8@    ;@8     ,@8.    9@        S@8     8@,   s@8        .8@i   :;      c@D       ",
		"      @8.     G8@8D     j@b     @8.    L@8      L8@8    .#@8    S80       k8@#          Y@@L        ",
		"     i8@       LE;      K@9    G8T    2@8@z  .x@8D@O  ;8@E8@    i@8    .K@@68T        z@@L          ",
		"     #@@,               O@@    D@: .Z8@;.b@8@8@; L@8@8@p  @8     8@G;i@8@J  @8    ;T#8@;            ",
		"     k8@;               T@8.   ,8@8@8L     ,.     VWK;   ;8G     :8@8@@Y    i@@@8@8@C.              ",
		"      ,.                .@@8.    ::                      4@:       .,         :;;,                  ",
		"                          ;.                   L4:       @8                                         ",
		"                                                K8@K;..L@8.                                         ",
		"                                                  i88@8@S                                           ",
		"                                                                                                    ",
		"                     LL                                                                             ",
		"                    L@8                                                                             ",
		"                    k@c                                                                             ",
		"                    88          .                                    J8@#,                          ",
		"                   L@,       :88@88.                        .      ;@8cs@8       ;#.     .:.        ",
		"              ..  .@88D@8@8@8@8T2@8@8@8@888@b     ;@#      S8@K,  ;@@  c8z       @8;  ;@8@8@c       ",
		"              @8@8@@@0OZViT8@4    L8E,CS2j@8b    .@8@     i@9j@8@8@8. #8r       L8@  8@8;           ",
		"                  r@s     9@i     .@c     ;@8    @@@8;    8@     ;8@k@V       .G8@L 8@:             ",
		"                  @8.    V@S     .@#       8@:  E8, @O   K@      L@8:       L8@;L8L@@               ",
		"                 :80     @8V   ;#@G        p82 :8G  E@,  @2      :8@     L4@@C  C@@@                ",
		"                 9@L     ,@8@8@88,          @8Y@@    8@;@8        L8@8@8@89;    D8@L                ",
		"                 @8j       ,;;,             s@8@,    ,8@@;          ,;;;        O@8                 ",
		"                 L@8:                        p@.       ;.                        ;                  "*/
		"       bWbWbWWWbWbWQWWWbWbWOWbWQWbWbWWWbWQWbWQWQWbWbWQWbWQWbWbWbWbWOxOWbWbWbWQWQWbWQWbWbWbWbW       ",
		"    bWQWWWbWbWbWbWbWQWbWWL   WWWWWQWbWbWbWbWbWbWbWbWbWQWbWQWbWbWbW    bWbWWWbWbWbWbWbWQWbWbWWWWQ    ",
		"   WWbWQW   WbWbWbWbWWWbL   LQWWWbWbWbWbWWWbWbWbWQWWWQWWWbWbWWWQWb   LWWWQWbWbWbWbWWWbWbWWWQWbWbW   ",
		"  bWQWbW     WWWWWbWbWb     bWbWbWbWbWbWQWbWbWbWbWbWbWbWbWbWbWbWbWbWWWbWbWbWbWbWbWbWbWbWbWbWbWbWbW  ",
		" bWbWQWb     LWbWbWbWd      WWWbWQWbWbWbWbWWWQWWWbWQWbWWL  LWbWWWbWbWbWbWbWQWbWbWQWQWbWbWbWQWWWWWbW ",
		" WQWbWbL  j   QWbWbWL   Q   bWQWbWbWL     LWbWbWbWbWbW       WbWbdLCbWWWWWbWbWbL   WbWbWbWbWQWbWQWb ",
		"QQWbWWW   WL  LbWbW    bW  LWQWQWbK    L   bWWWWWbWbc   xb   QWbi   WbWWWQWbWb      WWWbWbWbWWWbWWWd",
		"DWbWbWL  LbW   LbW   LbWL  LbWbWWL   WbWL  WWWbWQWW   LWbW   WbW   JbWbWbWbWx   bs  kWbWbWbQ bbWbWQQ",
		"QbWWWb   WWbW   r   sbWbL  RWbWbL  LWQWQ  LbWbWWWG   LWbWK  LbWb   QWbWbWbWL   bWb  WbWbWQ   kWbWbWD",
		"DWWWbi  LWbWbb     OQWQW   WbWWL  LWbWQ   WWbWbW    LWWWL   LWbW   WQWbWQL    QWbWbWbWQW    QWbWWWbQ",
		"bbWbW   xbWQWbW   WbWbWb   bWWW   WbWK     fWL      WQ      kbWQ   GWbWL      WbWQWbWY    WbWQWbWbWD",
		"DWbWp   LWbWWWbWWWbWQWWW   WbWW  LbL   LL       b       ij  bWWWL   L     QL  LWbD      bWbWWWbWWWQQ",
		"QbWbb   LbWbWWWbWQWQWbWQ   LWbWL      WbWbLLLTWQWK    pbWL  WbWbWL      VbWb         LWQWbWbWbWQWbWD",
		"dWbWbDLLbWbWWWQWWWbWbWbWL   LWbWcLLEbWWWbWbWWWbWbWbWbWbWb  LbWbWbWbLLLbWbWbWbELL LKWQWbWbWQWQWbWbWWQ",
		"QQWbWbWbWbWbWbWQWbWWWbWbWLLLWQWbWbWbWQWbWbWbWbW  LWQWWWbL  bWbWbWbWWWbWQWQWQWbWWWQWbWWWWWQWQWWWbWbWD",
		"dWbWbWbWbWbWbWbWbWbWQWbWbWWWWWbWbWbWbWQWbWbWbWbZ    LLL   LWbWbWbWbWbWWWbWQWbWbWbWbWbWbWbWbWbWbWbWbQ",
		"QbWWWbWQWQWQWbWbWbWbWbWbWbWWWWWQWbWbWbWbWbWbWbWbWS       CWbWbWbWQWbWbWbWQWbWbWWWbWbWbWWWQWbWbWbWbWD",
		"dWQWWWbWbWbWbWWWbWbWd  WbWbWbWQWbWWWbWbWbWbWWWbWbWbWbWbWQWbWWWbWbWbWbWbWbWbWbWQWbWWWbWbWbWbWbWbWbWbQ",
		"QbWbWbWbWbWbWbWbWQWb   cWbWbWbWWWbWWWbWWWWWbWQWbWbWQWWWbWWWbWbWbWWWbWbWQWbWWWbWQWbWbWWWbWbWbWWWQWWWd",
		"dWbWbWbWbWbWbWWWbWbW   WQWbWbWbWbWQWQWbWbWWWbWQWWWbWbWWWWWbWbWbWbWbWbWbWbWbWbWbWbWbWbWbWbWbWbWWWbWbQ",
		"QQWbWWWbWbWbWbWbWbWL  fWWbWbWbWrLLWbWbWbWWWbWWWbWQWQWQWbWbWbWbWQWbWbx    LWbWWWbWWWbWWWbWbWbWbWbWWWD",
		"DWbWbWWWbWQWbWQWQWW  LbWWWbOLL     LLWbWWWQLLWbWbWbcVWbWbWQWLrbWbWbL      fWQWbWb  LQWbWxLLLQWbWbWbQ",
		"QbWWWbWbWbWbWQLLLLL                          WWWWQ   bWQWbW    LLiL  sW   bbWQWbO   WQ       bWbWWWD",
		"DWbWbWbWbWbWbz                JWQWL  L       WWWbL   kbWQW          rJ   WbWbWbW   bK    cWbOWbWbWQQ",
		"QbWbWbWbWQWbWQdKddL  bWbWW   bWQWbL  bWbWQL  LWbK    LWWWi  WbWOWL     YWWWQWbL   LT  LQWQWWWbWbWbWD",
		" WbWbWQWbWWWQWQWbW  LWbWb   bWWWbL  SWQWQWL  LbW  LJ  bWb  LbWbWb   LWbWbWQW   LL L  iQWWWbWbWbWbWW ",
		" bWbWWWbWbWQWbWbWL  WWWbW   WbQ    QWbWbWbW   WL  Wb  LbL  bWQWWW   cQWbL     Gb    sbWbWbWbWbWbWbW ",
		"  QWQWbWWWbWbWQWb   bWbWbL       LbWbWbWWWbL     sQWL  L  rWbWbWbW          WWQd    QWQWWWWWbWbWbW  ",
		"   bWWWWWbWWWbWbk   RWWbWQWLL LQWbWQWbWbWQWb    LbWbWL    WQWQWQWbWWL   LbWbWQWb   OWbWbWbWbWWWbW   ",
		"    QWbWWWbWQWbWb    WbWWWQWWWQWbWQWbWbWWWbWz  LbWbWbWf LWbWQWbWbWbWWWbWWWQWWWbWL LWQWQWQWbWWWQW    ",
		"       WWbWWWbWbWbWbWbWQWWWbWbWbWQWbWbWbWbWbWbWQWbWQWQWQWWWQWbWbWQWbWbWbWQWQWQWbWbWQWbWbWbWbW       ",
	};
	coord.X = 0;
	coord.Y = 2;
	for (int x = 31; x >= 0; x--)
	{
		//Sleep(50);
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);//���ָ���һ��
		for (int y = x; y < 31; y++)
		{
			cout <<"\t\t"<< a[y] << endl;
		}
	}
	_getch();
	system("cls");
	system("color F0");//cmd��Ҫ��ɫ
}
//���˵�
void mainUI(int (**map)[15],Hero &hero ,int &red,int &blue,int &yellow)
{

	int choose = 1;//���˵��������
	int boom = 0;
	char a[][78] =
	{
		//"                                                                        ",
		//"                                                                   ",
		//"   ����                      ��                                ��            ",
		//" ��    ��                    ��                                ��   ���� ",
		//" ��    ��    ����  ������    ������      ����     ������          ��    ��",
		//" ��    ��  ��      ��    ��  ��    ��  ��    ��   ��    ��        ��",
		//" ��    ��  ��      ��    ��  ��    ��  ��    ��   ��    ��          ����",
		//"   ����    ��      ������    ��    ��    ������   ��    ��              ��",
		//"                   ��                                             ��    ��",
		//"                   ��                                               ����",
		//"",
		//"  ��",
		//"������    ����    ��  ��  ��    ����      ����",
		//"  ��    ��    ��  ��  ��  ��  ��    ��  ��",
		//"  ��    ��    ��  ��  ��  ��  ��  ��    ��",
		//"    ��    ����      ��  ��      ������  ��",
"                  ##                           ##                     ",
"      ###       ###                                                   ",
"      # ##     ## #       ###         ####              ##            ",
"     ##  #   ##   #     ##  ##       ##  ##   #        ####           ",
"     #   #####   ##    ##   ##     ##    #   ##      ##        ##     ",
"    ##     ##    ##   ##   ###   ###   ###   ##    ###       ##       ",
"    ##           ##   ## ##  ####  ####  #    #####  ##   ###         ",
"                 ###   ##               ##     ##      ##             ",
"                                  #     #                             ",
"                                   #####                              ",
"               #                                                      ",
"              ##                                                      ",
"              #       #                         ####                  ",
"              #################     #     ##   ## ##     #   ####     ",
"          #####   ###   ##   ###   ##    ## #### #      ## ###        ",
"             #    ##    #     ##  # ##  ##    ##      # ####          ",
"            ##    ## ###       # ##  #  #     ### ####  ###           ",
"            ##                 ###    ##                ##            ",
	};

	coord.X = 1;
	coord.Y = 1;
	while (10086)
	{
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);//���ָ���һ��
		for (int y = 0; y < 18; y++)
		{
			cout << "\t\t" << a[y] << endl;
		}	
		cout << endl<<endl<<endl;
		switch (choose)
		{
		case 1:
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			cout << "\t\t\t\t\t\t ��  ����Ϸ" << endl << endl;
			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
			cout << "\t\t\t\t\t\t    ������Ϸ" << endl << endl;
			//cout << "\t\t\t\t\t\t    ���ģʽ(������˼)" << endl << endl;
			cout << "\t\t\t\t\t\t      �˳�" << endl;
			break;
		case 2:
			cout << "\t\t\t\t\t\t     ����Ϸ" << endl << endl;
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			cout << "\t\t\t\t\t\t �� ������Ϸ" << endl << endl;
			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
			//cout << "\t\t\t\t\t\t    ���ģʽ(������˼)" << endl << endl;
			cout << "\t\t\t\t\t\t      �˳�" << endl;
			break;
		//case 3:
		//	cout << "\t\t\t\t\t\t     ����Ϸ" << endl << endl;
		//	cout << "\t\t\t\t\t\t    ������Ϸ" << endl << endl;
		//	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		//	cout << "\t\t\t\t\t\t �� ���ģʽ(��ı��) " << endl << endl;
		//	SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
		//	cout << "\t\t\t\t\t\t      �˳�" << endl;
		//	break;
		case 3:
			cout << "\t\t\t\t\t\t     ����Ϸ" << endl << endl;
			cout << "\t\t\t\t\t\t    ������Ϸ" << endl << endl;
			/*cout << "\t\t\t\t\t\t    ���ģʽ(������˼)" << endl << endl;*/
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			cout << "\t\t\t\t\t\t ��   �˳�" << endl;
			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
		}
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
				if (choose < 4)
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
				if (choose < 3)
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
		for (int x = 0; x < 6; x++)
		{
			for (int y = 0; y < 15; y++)
			{
				for (int z = 0; z < 15; z++)
				{
					map[x][y][z] = maps[x][y][z];
				}
			}
		}
		for (int x = 0; x < 15; x++)
		{
			for (int y = 0; y < 15; y++)
			{
				if (map[uplevel][x][y] == 9)
				{
					hero.posx = x;
					hero.posy = y;
				}
			}
		}
		break;
	case 2:
		void loaddata(int(**map)[15], Hero &hero, int &red, int &blue, int &yellow);
		loaddata(map, hero, red, blue, yellow);
		break;
	/*case 3:
		for (int x = 0; x < 6; x++)
		{
			for (int y = 0; y < 15; y++)
			{
				for (int z = 0; z < 15; z++)
				{
					map[x][y][z] = maps[x][y][z];
				}
			}
		}
		for (int x = 0; x < 15; x++)
		{
			for (int y = 0; y < 15; y++)
			{
				if (map[uplevel][x][y] == 9)
				{
					hero.posx = x;
					hero.posy = y;
				}
			}
		}
		play = 1;
		break;*/
	case 3:
		exit(0);
		break;
	}
	system("cls");
}
//������ֹ¶��͹ֵ���Ϣ
void printmessage(Hero a, Monster b)
{
	system("cls");
	cout << "\n\n\n";
	cout << "\t\t\t\t\t���� " << endl;
	cout << "\t\t\t\t\t���੤������������������������������������������������������������������������ " << endl;
	cout << "\t\t\t\t\t ��                                    ��" << endl;
	cout << "\t\t\t\t\t ��  " << a.name << "\t    ";
	if (strlen(b.name) <= 6)
	{
		cout << b.name << "\t      ��" << endl;
	}
	else if (strlen(b.name) == 16)
	{
		cout << b.name << "  ��" << endl;
	}
	else if (strlen(b.name) == 8||strlen(b.name) == 10)
	{
		cout << b.name << "\t      ��" << endl;
	}
	cout << "\t\t\t\t\t ��                                    ��" << endl;
	cout << "\t\t\t\t\t ��     " << "hp:";
	if (a.hp > (a.lv * 50) / 2)
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	}
	else if (a.hp <= (a.lv * 50) / 2 && a.hp > (a.lv * 50) / 4)
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	}
	else if (a.hp <= (a.lv * 50) / 4)
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	}
	cout << a.hp;
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
	cout<< "\t\t" << "hp:" << b.hp << "\t      ��" << endl;
	cout << "\t\t\t\t\t ��                                    ��" << endl;
	cout << "\t\t\t\t\t ��     " << "atk:" << a.atk << "\t\t" << "atk:" << b.atk <<"\t      ��"<< endl;
	cout << "\t\t\t\t\t ��                                    ��" << endl;
	cout << "\t\t\t\t\t ��     " << "def:" << a.def << "\t\t" << "def:" << b.def << "\t      ��"<< endl;
	cout << "\t\t\t\t\t ��                                    ��" << endl;
	cout << "\t\t\t\t\t ���������������������������������������������������������������������������ੴ " << endl;
	cout << "\t\t\t\t\t                                      ����" << endl;
	return;
}
//����
//�����Ʒ����
int randitemintobag(Hero &hero)
{
	void equipitem(Hero &hero, Item item);
	int num = rand() % 5;
	if (num == 0 && hero.bag.num < 4)
	{
		if (rand() % 10 == 0)
		{
			hero.bag.item[++hero.bag.num] = axeshild;
			equipitem(hero, axeshild);
			return 2;
		}
		else
		{
			hero.bag.item[++hero.bag.num] = EstusFlask;
			return 1;
		}
		
	}
	else
	{
		return 0;
	}
}
//������
//void dropitem(Hero &hero)
//{
//	switch (hero.bag.item[movechoose].itemtype)
//	{
//	case USE:
//		hero.bag.item[movechoose] = null;
//		break;
//	case EQUIP:
//		hero.atk -= hero.bag.item[movechoose].atkup;
//		hero.def -= hero.bag.item[movechoose].defup;
//		hero.bag.item[movechoose] = null;
//		break;
//	}
//
//	for (int x = movechoose; x < 4; x++)
//		{
//			if (strcmp(hero.bag.item[x].name, "null      "))
//			{
//				hero.bag.item[x] = hero.bag.item[x + 1];
//				hero.bag.item[x + 1] = null;
//			}
//		}
//	hero.bag.num--;
//	return;
//}
//�ö���
//void useitem(Hero &hero, Item item)
//{
//	switch (item.itemtype)
//	{
//	case USE:
//		hero.atk += item.atkup;
//		hero.def += item.defup;
//		hero.hp += item.hpup;
//		if (hero.hp > hero.lv * 50)
//		{
//			hero.hp = hero.lv * 50;
//		}
//		if (strcmp(hero.bag.item[movechoose].name,"Ԫ��ƿ")==0)
//		{
//			hero.hp += (hero.lv * 50)*0.5;
//			if (hero.hp > hero.lv * 50)
//			{
//				hero.hp = hero.lv * 50;
//			}
//		}
//		dropitem(hero);
//		break;
//	case EQUIP:
//		break;
//	}
//
//	return;
//}
//��װ��
void equipitem(Hero &hero, Item item)
{
	hero.atk += item.atkup;
	hero.def += item.defup;
}
//����˵��
void elfspeak(int num,int (**map)[15],Hero &hero,int red,int blue,int yellow)
{
	//char a;
	char elf1[] = "\t\t\t\t\t �� ELF:                                �� \n\t\t\t\t\t ��   ��֪��֪���������Ķ��ǹ¶�        �� ";
	char elf2[] = "\t\t\t\t\t �� ELF:                                �� \n\t\t\t\t\t ��   �����ͷ���ֻ��5,���ܵ�����������? �� ";
	char elf3[] = "\t\t\t\t\t �� ELF:                                �� \n\t\t\t\t\t ��   ��Щ��������,������̫����         �� ";
	char elf4[] = "\t\t\t\t\t �� ELF:                                �� \n\t\t\t\t\t ��   ��NM�ļ�                          �� ";
	char elf5[] = "\t\t\t\t\t �� ELF:                                �� \n\t\t\t\t\t ��   ���Ѿ�����                        �� ";
	switch (num)
	{
	case 1:
		speak(1,elf1);
		strcpy(hero.name, "���ֹ¶�");
		speak(1,elf2);
		hero.bag.item[0] = woodsword;
		hero.bag.item[1] = woodshild;
		hero.bag.item[2] = EstusFlask;
		hero.bag.item[3] = EstusFlask;
		equipitem(hero, woodsword);
		equipitem(hero, woodshild);
		hero.bag.num = 3;
		speak(1,elf3);
		speak(1,elf4);
		return;
		break;
	case 2:
		speak(1,elf5);
		return;
		break;
	}
}
//Ȫˮ
void springwater(int(**map)[15], Hero &hero, int red, int blue, int yellow)
{
	if (springwatertimes > 0)
	{
		char a;
		speak(1,"\t\t\t\t\t ��   ���ҵ���һ��Ԫ��Ȫ,Ҫ���в�����?  �� \n\t\t\t\t\t ��                                     �� ");
		int cs = 0;
		while (1)
		{
			switch (cs)
			{
			case 0:
				speak(0,"\t\t\t\t\t �� ������                              �� \n\t\t\t\t\t ��   ��ȥ                              �� ");
				break;
			case 1:
				speak(0,"\t\t\t\t\t ��   ����                              �� \n\t\t\t\t\t �� ����ȥ                              �� ");
				break;
			}
			a = _getch();
			if (!isascii(a))
			{
				switch (_getch())
				{
				case 72:
					cs = 0;
					break;
				case 80:
					cs = 1;
					break;
				}
			}
			else
			{
				if (a == '\r' || a == 32)
				{
					if (cs == 0)
					{
						hero.hp = hero.lv * 50;
						springwatertimes--;
					}
					coord.Y = 22;
					hout = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleCursorPosition(hout, coord);
					cout << "\t\t\t\t                                                                                "
						<< endl << "\t\t\t\t                                                                                "
						<< endl << "\t\t\t\t                                                                                ";
					return;
				}
			}
		}
	}
	else
	{
		speak(1,"\t\t\t\t   ��   �ƺ��Ѿ�û��Ч����                �� \n\t\t\t\t\t ��                                     �� ");
	}
}
//�浵
void savedata(int(**map)[15], Hero hero, int red, int blue, int yellow)
{
	FILE *savedata = fopen("savedata.dat", "wb+");
	for (int x = 0; x < 6; x++)
	{
		fwrite(map[x], 900, 1, savedata);
	}
	fwrite(&uplevel, sizeof(uplevel), 1, savedata);
	fwrite(&red, sizeof(red), 1, savedata);
	fwrite(&blue, sizeof(blue), 1, savedata);
	fwrite(&yellow, sizeof(yellow), 1, savedata);
	fwrite(&hero, sizeof(Hero), 1, savedata);
	fwrite(&springwatertimes, sizeof(springwatertimes), 1, savedata);
	fclose(savedata);
	speak(1, "\t\t\t\t\t ��                                     �� \n\t\t\t\t\t ��   �浵�ɹ�                          �� ");

	return;
}
//����
void loaddata(int(**map)[15], Hero &hero, int &red, int &blue, int &yellow)
{
	FILE *loaddata = fopen("savedata.dat", "rb+");
	for (int x = 0; x < 6; x++)
	{
		fread(map[x], 900, 1, loaddata);
	}
	fread(&uplevel, sizeof(uplevel), 1, loaddata);
	fread(&red, sizeof(red), 1, loaddata);
	fread(&blue, sizeof(blue), 1, loaddata);
	fread(&yellow, sizeof(yellow), 1, loaddata);
	fread(&hero, sizeof(Hero), 1, loaddata);
	fread(&springwatertimes, sizeof(springwatertimes), 1, loaddata);
	fclose(loaddata);
	return;
}
//�ƶ�
void updownlevel(int type,int(**map)[15], Hero &hero)
{
	drawtype = 1;
	if (type == 0)
	{
		++uplevel;
		for (int x = 0; x < 15; x++)
		{
			for (int y = 0; y < 15; y++)
			{
				if (map[uplevel][x][y] == 9)
				{
					hero.posx = x;
					hero.posy = y;
				}
			}
		}
	}
	else if (type == 1)
	{
		--uplevel;
		for (int x = 0; x < 15; x++)
		{
			for (int y = 0; y < 15; y++)
			{
				if (map[uplevel][x][y] == 9)
				{
					hero.posx = x;
					hero.posy = y;
				}
			}
		}
	}
	return;
}
bool fight(Hero &a, Monster b)
{
	void dropitem(Hero &hero);
	weaponusetimes--;
	shildusetimes--;
	printmessage(a, b);
	while (1)
	{
		if (a.atk > b.def)
		{
			b.hp = b.hp - (a.atk - b.def);
		}
		else
		{
			b.hp = b.hp - 1;
		}
		if (b.hp < 0)
		{
			b.hp = 0;
		}
		Sleep(500);
		printmessage(a, b);
		if (b.hp == 0)
		{
			system("cls");
			cout << "\n\n\t\t\t\t\t  ����" << endl;
			cout << "\t\t\t\t\t  ���੤�������������������������������������������������������������������������� " << endl;
			cout << "\t\t\t\t\t   ��                                     ��" << endl;
			cout << "\t\t\t\t\t   �� " << a.name << "�����Ӯ�����ⳡս����ʤ��" << "  ��" << endl;
			cout << "\t\t\t\t\t   ��                                     ��" << endl;
			cout << "\t\t\t\t\t   �����������������������������������������������������������������������������ੴ " << endl;
			cout << "\t\t\t\t\t                                         ����" << endl;
			_getch();
			system("cls");
			int money = rand() % 10;
			cout << "\n\n\t\t\t\t\t  ����" << endl;
			cout << "\t\t\t\t\t  ���੤�������������������������������������������������������������������������� " << endl;
			cout << "\t\t\t\t\t   ��                                     ��" << endl;
			cout << "\t\t\t\t\t   �� " << a.name << "�����" << b.expup << "�㾭��\t         ��" << endl;
			cout << "\t\t\t\t\t   ��         " << "�����" << b.moneyup + money << "�����\t         ��" << endl;
			cout << "\t\t\t\t\t   ��                                     ��" << endl;
			cout << "\t\t\t\t\t   �����������������������������������������������������������������������������ੴ " << endl;
			cout << "\t\t\t\t\t                                         ����" << endl;
			_getch();
			a.exp += b.expup;
			a.money += (b.moneyup + money);
			int lvup = 0;
			while (1)
			{
				if (a.exp >= a.lv * 111)
				{
					lvup++;
					a.exp = a.exp - (a.lv * 111);
					a.atk += a.lv * 4;
					a.def += a.lv * 4;
				}
				else if (a.exp < a.lv * 111)
				{
					break;
				}
			}
			if (lvup != 0)
			{
				system("cls");
				cout << "\n\n\t\t\t\t\t  ����" << endl;
				cout << "\t\t\t\t\t  ���੤�������������������������������������������������������������������������� " << endl;
				cout << "\t\t\t\t\t   ��                                     ��" << endl;
				cout << "\t\t\t\t\t   �� " << a.name << "�ȼ�������" << lvup << "��\t         ��" << endl;
				cout << "\t\t\t\t\t   ��                                     ��" << endl;
				cout << "\t\t\t\t\t   �����������������������������������������������������������������������������ੴ " << endl;
				cout << "\t\t\t\t\t                                         ����" << endl;
				a.lv = a.lv + lvup;
				a.hp = a.lv * 50;
				_getch();
			}
			int randitemintobag(Hero &hero);
			switch (randitemintobag(a))
			{
			case 1:
				system("cls");
				cout << "\n\n\t\t\t\t\t  ����" << endl;
				cout << "\t\t\t\t\t  ���੤�������������������������������������������������������������������������� " << endl;
				cout << "\t\t\t\t\t   ��                                     ��" << endl;
				cout << "\t\t\t\t\t   �� �õ���һ��Ԫ��ƿ                    ��" << endl;
				cout << "\t\t\t\t\t   ��                                     ��" << endl;
				cout << "\t\t\t\t\t   �����������������������������������������������������������������������������ੴ " << endl;
				cout << "\t\t\t\t\t                                         ����" << endl;
				_getch();
				break;
			case 2:
				system("cls");
				cout << "\n\n\t\t\t\t\t  ����" << endl;
				cout << "\t\t\t\t\t  ���੤�������������������������������������������������������������������������� " << endl;
				cout << "\t\t\t\t\t   ��                                     ��" << endl;
				cout << "\t\t\t\t\t   �� �õ��˱����ܸ�!!!!                  ��" << endl;
				cout << "\t\t\t\t\t   ��                                     ��" << endl;
				cout << "\t\t\t\t\t   �����������������������������������������������������������������������������ੴ " << endl;
				cout << "\t\t\t\t\t                                         ����" << endl;
				_getch();
				break;
			default:
				break;
			}

			if (weaponusetimes == 0)
			{
				for (int x = 0; x < 4; x++)
				{
					if (strcmp(a.bag.item[x].name, "ľ��") == 0 || strcmp(a.bag.item[x].name, "����") == 0)
					{
						system("cls");
						cout << "\n\n\t\t\t\t\t  ����" << endl;
						cout << "\t\t\t\t\t  ���੤�������������������������������������������������������������������������� " << endl;
						cout << "\t\t\t\t\t   ��                                     ��" << endl;
						cout << "\t\t\t\t\t   ��         " << a.bag.item[x].name << "������!                 ��" << endl;
						cout << "\t\t\t\t\t   ��                                     ��" << endl;
						cout << "\t\t\t\t\t   �����������������������������������������������������������������������������ੴ " << endl;
						cout << "\t\t\t\t\t                                         ����" << endl;
						_getch();
						movechoose = x;
						dropitem(a);
					}
				}
				weaponusetimes = rand() % 7 + 3;
			}

			if (shildusetimes == 0)
			{
				for (int x = 0; x < 4; x++)
				{
					if (strcmp(a.bag.item[x].name, "ľ��") == 0 || strcmp(a.bag.item[x].name, "����") == 0)
					{
						system("cls");
						cout << "\n\n\t\t\t\t\t  ����" << endl;
						cout << "\t\t\t\t\t  ���੤�������������������������������������������������������������������������� " << endl;
						cout << "\t\t\t\t\t   ��                                     ��" << endl;
						cout << "\t\t\t\t\t   ��         " << a.bag.item[x].name << "������!                 ��" << endl;
						cout << "\t\t\t\t\t   ��                                     ��" << endl;
						cout << "\t\t\t\t\t   �����������������������������������������������������������������������������ੴ " << endl;
						cout << "\t\t\t\t\t                                         ����" << endl;
						_getch();
						movechoose = x;
						dropitem(a);
					}
				}
				shildusetimes = rand() % 20 + 7;
			}
			drawtype = 1;
			return 1;
		}
		if (b.atk > a.def)
		{
			a.hp = a.hp - (b.atk - a.def);
		}
		else
		{
			a.hp = a.hp - 1;
		}
		if (a.hp < 0)
		{
			a.hp = 0;
		}
		Sleep(500);
		printmessage(a, b);
		if (a.hp == 0)
		{
			imdead = 1;
			youdied();
			return 0;
		}
	}
}
void gotmove(int(**map)[15], Hero &hero, int &red, int &blue, int &yellow)
{
	char move = _getch();
	if (!isascii(move))
	{
		move = _getch();
		switch (move)
		{
		case 72:
			switch (map[uplevel][hero.posx - 1][hero.posy])
			{
			case 90:
				if (fight(hero, Gob))
				{
					map[uplevel][hero.posx-1][hero.posy] = 0;
				}
				break;
			case 91:
				if (fight(hero, Slime))
				{
					map[uplevel][hero.posx - 1][hero.posy] = 0;
				}
				break;
			case 92:
				if (fight(hero, Youmo))
				{
					map[uplevel][hero.posx - 1][hero.posy] = 0;
				}
				break;
			case 93:
				if (fight(hero, Monstro))
				{
					map[uplevel][hero.posx - 1][hero.posy] = 0;
				}
				break;
			case 94:
				if (fight(hero, Mino))
				{
					map[uplevel][hero.posx - 1][hero.posy] = 0;
				}
				break;
			case 95:
				if (fight(hero, Cinder))
				{
					map[uplevel][hero.posx - 1][hero.posy] = 0;
				}
				break;
			case 96:
				if (fight(hero, Circle))
				{
					map[uplevel][hero.posx - 1][hero.posy] = 0;
				}
				break;
			case 97:
				if (fight(hero, Midir))
				{
					map[uplevel][hero.posx - 1][hero.posy] = 0;
				}
				break;
			case 98:
				if (fight(hero, Lastbooooss))
				{
					map[uplevel][hero.posx - 1][hero.posy] = 0;
				}
				break;
			case 0:case 99:
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][--hero.posx][hero.posy] = 9;
				break;
			case -9:
				elfspeak(1,map, hero, red, blue, yellow);
				map[uplevel][10][7] = 0;
				map[uplevel][10][6] = -10;
				break;
			case -1:
				if (red > 0)
				{
					red--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][--hero.posx][hero.posy] = 9;
				}
				break;
			case -2:
				if (blue > 0)
				{
					blue--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][--hero.posx][hero.posy] = 9;
				}
			case -3:
				if (yellow > 0)
				{
					yellow--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][--hero.posx][hero.posy] = 9;
				}
				break;
			case 4:
				red++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][--hero.posx][hero.posy] = 9;
				break;
			case 5:
				blue++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][--hero.posx][hero.posy] = 9;
				break;
			case 6:
				yellow++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][--hero.posx][hero.posy] = 9;
				break;
			case 10:
				springwater(map, hero, red, blue, yellow);
				break;
			case 2:
				updownlevel(0, map, hero);
				break;
			case 3:
				updownlevel(1, map, hero);
				break;
			}
			break;
		case 80:
			switch (map[uplevel][hero.posx + 1][hero.posy])
			{
			case 90:
				if (fight(hero, Gob))
				{
					map[uplevel][hero.posx+1][hero.posy] = 0;
				}
				break;
			case 91:
				if (fight(hero, Slime))
				{
					map[uplevel][hero.posx + 1][hero.posy] = 0;
				}
				break;
			case 92:
				if (fight(hero, Youmo))
				{
					map[uplevel][hero.posx + 1][hero.posy] = 0;
				}
				break;
			case 93:
				if (fight(hero, Monstro))
				{
					map[uplevel][hero.posx + 1][hero.posy] = 0;
				}
				break;
			case 94:
				if (fight(hero, Mino))
				{
					map[uplevel][hero.posx + 1][hero.posy] = 0;
				}
				break;
			case 95:
				if (fight(hero, Cinder))
				{
					map[uplevel][hero.posx + 1][hero.posy] = 0;
				}
				break;
			case 96:
				if (fight(hero, Circle))
				{
					map[uplevel][hero.posx + 1][hero.posy] = 0;
				}
				break;
			case 97:
				if (fight(hero, Midir))
				{
					map[uplevel][hero.posx + 1][hero.posy] = 0;
				}
				break;
			case 98:
				if (fight(hero, Lastbooooss))
				{
					map[uplevel][hero.posx + 1][hero.posy] = 0;
				}
				break;
			case 0:case 99:
				if (hero.posx + 1 < 15)
				{
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][++hero.posx][hero.posy] = 9;
				}
				break;
			case 2:
				updownlevel(0, map, hero);
				break;
			case 3:
				updownlevel(1, map, hero);
				break;
			case 10:
				springwater(map, hero, red, blue, yellow);
				break;
			case -1:
				if (red > 0)
				{
					red--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][++hero.posx][hero.posy] = 9;
				}
				break;
			case -2:
				if (blue > 0)
				{
					blue--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][++hero.posx][hero.posy] = 9;
				}
				break;
			case -3:
				if (yellow > 0)
				{
					yellow--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][++hero.posx][hero.posy] = 9;
				}
				break;
			case 4:
				red++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][++hero.posx][hero.posy] = 9;
				break;
			case 5:
				blue++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][++hero.posx][hero.posy] = 9;
				break;
			case 6:
				yellow++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][++hero.posx][hero.posy] = 9;
				break;
			}
			break;
		case 75:
			switch (map[uplevel][hero.posx][hero.posy - 1])
			{
			case 90:
				if (fight(hero, Gob))
				{
					map[uplevel][hero.posx][hero.posy-1] = 0;
				}
			case 91:
				if (fight(hero, Slime))
				{
					map[uplevel][hero.posx ][hero.posy- 1] = 0;
				}
				break;
			case 92:
				if (fight(hero, Youmo))
				{
					map[uplevel][hero.posx  ][hero.posy-1] = 0;
				}
				break;
			case 93:
				if (fight(hero, Monstro))
				{
					map[uplevel][hero.posx  ][hero.posy-1] = 0;
				}
				break;
			case 94:
				if (fight(hero, Mino))
				{
					map[uplevel][hero.posx  ][hero.posy-1] = 0;
				}
				break;
			case 95:
				if (fight(hero, Cinder))
				{
					map[uplevel][hero.posx  ][hero.posy-1] = 0;
				}
				break;
			case 96:
				if (fight(hero, Circle))
				{
					map[uplevel][hero.posx  ][hero.posy-1] = 0;
				}
				break;
			case 97:
				if (fight(hero, Midir))
				{
					map[uplevel][hero.posx  ][hero.posy-1] = 0;
				}
				break;
			case 98:
				if (fight(hero, Lastbooooss))
				{
					map[uplevel][hero.posx  ][hero.posy-1] = 0;
				}
				break;
			case 0:case 99:
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][hero.posx][--hero.posy] = 9;
				break;
			case  -1:
				if (red > 0)
				{
					red--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][hero.posx][--hero.posy] = 9;
				}
				break;
			case  -2:
				if (blue > 0)
				{
					blue--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][hero.posx][--hero.posy] = 9;
				}
				break;
			case  -3:
				if (yellow > 0)
				{
					yellow--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][hero.posx][--hero.posy] = 9;
				}
				break;
			case 4:
				red++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][hero.posx][--hero.posy] = 9;
				break;
			case 5:
				blue++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][hero.posx][--hero.posy] = 9;
				break;
			case 6:
				yellow++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][hero.posx][--hero.posy] = 9;
				break;
			case 2:
				updownlevel(0, map, hero);
				break;
			case -10:
				elfspeak(2, map, hero, red, blue, yellow);
				fight(hero, elf);
				break;
			case 3:
				updownlevel(1, map, hero);
				break;
			}
			break;
		case 77:
			switch (map[uplevel][hero.posx][hero.posy + 1])
			{
			case 90:
				if (fight(hero, Gob))
				{
					map[uplevel][hero.posx][hero.posy+1] = 0;
				}
				break;
			case 91:
				if (fight(hero, Slime))
				{
					map[uplevel][hero.posx][hero.posy+1] = 0;
				}
				break;
			case 92:
				if (fight(hero, Youmo))
				{
					map[uplevel][hero.posx][hero.posy + 1] = 0;
				}
				break;
			case 93:
				if (fight(hero, Monstro))
				{
					map[uplevel][hero.posx][hero.posy + 1] = 0;
				}
				break;
			case 94:
				if (fight(hero, Mino))
				{
					map[uplevel][hero.posx][hero.posy + 1] = 0;
				}
				break;
			case 95:
				if (fight(hero, Cinder))
				{
					map[uplevel][hero.posx][hero.posy + 1] = 0;
				}
				break;
			case 96:
				if (fight(hero, Circle))
				{
					map[uplevel][hero.posx][hero.posy + 1] = 0;
				}
				break;
			case 97:
				if (fight(hero, Midir))
				{
					map[uplevel][hero.posx][hero.posy + 1] = 0;
				}
				break;
			case 98:
				if (fight(hero, Lastbooooss))
				{
					map[uplevel][hero.posx][hero.posy + 1] = 0;
				}
				break;
			case 0:case 99:
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][hero.posx][++hero.posy] = 9;
				break;
			case -1:
				if (red > 0)
				{
					red--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][hero.posx][++hero.posy] = 9;
				}
				break;
			case -2:
				if (blue > 0)
				{
					blue--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][hero.posx][++hero.posy] = 9;
				}
				break;
			case -3:
				if (yellow > 0)
				{
					yellow--;
					map[uplevel][hero.posx][hero.posy] = 0;
					map[uplevel][hero.posx][++hero.posy] = 9;
				}
				break;
			case 4:
				red++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][hero.posx][++hero.posy] = 9;
				break;
			case 5:
				blue++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][hero.posx][++hero.posy] = 9;
				break;
			case 6:
				yellow++;
				map[uplevel][hero.posx][hero.posy] = 0;
				map[uplevel][hero.posx][++hero.posy] = 9;
				break;
			case 2:
				updownlevel(0, map, hero);
				break;
			case 3:
				updownlevel(1, map, hero);
				break;
			}
			break;
		default:
			break;
		}
	}
	else
	{
		switch (move)
		{
		case 9:
			movechoose++;
			if (movechoose > 4)
			{
				movechoose = 0;
			}
			break;
		case '1':
			useitem(hero, hero.bag.item[movechoose]);
			break;
		case '2':
			dropitem(hero);
			break;
		case 'l':case'L':
			loaddata(map, hero, red, blue, yellow);
			break;
		case 's':case 'S':
			savedata(map, hero, red, blue, yellow);
			break;
		case 'q':case'Q':
			imdead = 1;
			break;
		}
	}
}
//����˼��
void doge()
{	            
	char dogeeeee[34][92] =
	{
		"                                            ivrz.                                          ",
		"                                            iir2X                                 .,::     ",
		"                                            :iiLET                              iqCqS8r    ",
		"                                            :iixqSC                           ,rLLLCE9K.   ",
		"                                            :ii7CTCq.                       .i77ocvLCX8Z   ",
		"                                            iiizCX2Z2r.                   ,iJ2xzxT7J7CE8.  ",
		"                                            rTZxcccczxocii:,.           .rLCNqrJTTZCCJqNi  ",
		"                                            zLrii:iiiiiroxLxozzx7LJLoq7ooJXN7oCX2XEEXqqNr  ",
		"                                          .ii::iiiiicvzzzrrcciiiiiczrTNXZENqcLCEK$B9CLS9i  ",
		"                                      ,iiiii:::iiiicrL7ozrrvcccccicrcicZ8N2xzvvS$$KdxxCN.  ",
		"                                   ,iiiiiii:::::iirxTvcrvzzvczrcccccciiiCECxCK@@BNLirZc   ",
		"                                   :i::::ii::::::icoTzvrvicccccccvvciicciivJE@M@8SJir2E    ",
		"                                 :ii:::,.  :i::iirzJozziii::iiczzxrciiiiii:io7EEJzzLNXC    ",
		"                               :iii::iEKQB7i:iizoL77zi:::i:::iiroxzvciiciii::icL7xoqJCc   ",
		"                               :i,. .:o8KMMMT:cviirvcii:::::i:,.:ivzzrrvcciii:::ix7qdEd7c  ",
		"                              ,i.    izN@MMBiii:iii:iii::iX8K@WEv:icrcrviiiiiiiiiivxd8Nqx: ",
		"                              i,  .::iLNBEz.:i:ii::icoLZKMN:ZBMMMBCzvccciiccciiiiiiczSETLi ",
		"                             ., ...icii:. .:::::::iii7SBMM:CMMMMMWociiiiiiiiiicciiiccxLoJ: ",
		"                             ,.....,:.   ,,:::::iiiiizrvXK8EKKKXi.::::::::iiiiiiiicccvzrLv ",
		"                            ,,,..    .:::,,::::::iiiicci::iiii,,::i:::::::iii:::iiiiiircr7 ",
		"                           .:..:  C88B8NdNNZi:::::iiiiii:iiiiiiicii::::::iii::iii::iiiiccc:",
		"                           ::::  :MMMMMMMMM@@L.,::::iiii:::::i:iiiii::::,,:::::::i:iiiicii:",
		"                           ..::  i8@$W@MMMMM@L,,,:::::iii::::,,:::::::i:::::::iiiiiiiivziii",
		"                          .::::,:vKHW@H$Q@@KSiiiiiiiiii:i::::::::::i:::::iiiiiiiiiiiczLzcc:",
		"                          :::::icTSNB@W$BNZ7iiiiii:iiii:::iiiiii::::i:::iiiiiiiiiiiiroxzcc:",
		"                          ::,,:irXE2ZEX2EE27vciziciiiiiii:iiiiiiiiiiiiiiiccciiiiiicvzzJxizi",
		"                          ::,,:::vNBQM@WNNN2ziiiiii::iivviiiiiiicciiiiiciii:iiiiiiiczozcvLi",
		"                          ,:,:::.,EH$Q@@MMMMB2xicoJSENKNxrciiiciciiiiiiii:::::::iiivzrvczzi",
		"                           ,::,::::c289K8KHB@MM@$@@MQKNqciiiiiiiiiiiiii:::iiiiiiiirzozvoori",
		"                            :::,,:::iLXZCCqJ7SNdCCCLxzi:::iiciiiiiiiiiiiiiiiiiccivzrroooLLc",
		"                            ,:::::i:::izciiiiiiiiiii::iiiiiiiicciiiii::iiiiiiiccrzxzvczxTCv",
		"                             ::::::i::::::iiiiiiiiiiiiccvcciciiiiiii:::iiiiivccrozrvzzJqT7c",
		"                             .i::::::ii:iiiiiiiiiicccccvcciciii:i:iiiiiiiiiiiivrzzzxqCCq7Ji",
		"                             :iii:i::iiiiiiiiiiciicviiiiiciii:::::iiiiicicciiccvvzLqCqT7Lzi"
	};
	HANDLE hout;
	COORD coord;
	coord.X = 1;
	coord.Y = 1;
	for (int r = 92; r > 0; r--)
	{
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout,coord);//���ָ���һ��
		//system("cls");
		for (int y = 0; y < 34; y++)
		{
			for (int x = r; x < 92; x++)
			{
				printf("%c", dogeeeee[y][x]);
			}
			cout << endl;
		}
	}
	for (int w = 92; w > 0; w--)
	{
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);//���ָ���һ��
		for (int y = 0; y < 34; y++)
		{
			for (int t = 0; t < 92 - w; t++)
			{
				if (92 - w < 70)
				{
					cout << " ";
				}
				
			}
			for (int x = 0; x < w; x++)
			{
				
				printf("%c", dogeeeee[y][x]);
			}
			cout << endl;
		}
	}
		return;
}
//��������,�̵�
void market(Hero &hero, int(**map)[15],int red,int blue ,int yellow)
{
	int num = 0;
	system("cls");
	drawmap(map, hero, red, blue, yellow);
	cout << "\t\t\t\t  ����" << endl;
	cout << "\t\t\t\t  ���੤�������������������������������������������������������������������������� " << endl;
	cout << "\t\t\t\t   ��                                     ��" << endl;
	cout << "\t\t\t\t   ��   �ƺ��Ǹ��̵�                        ��" << endl;
	cout << "\t\t\t\t   �����������������������������������������������������������������������������ੴ " << endl;
	cout << "\t\t\t\t                                         ����" << endl;
	_getch();
	while (1)
	{ 
	system("cls");
	drawmap(map, hero, red, blue, yellow);
	cout << "\t\t\t\t  ����" << endl;
	cout << "\t\t\t\t  ���੤�������������������������������������������������������������������������� " << endl;
	cout << "\t\t\t\t   �� ����:                               ��" << endl;
	switch (num)
	{
	case 0:
		cout << "\t\t\t\t   �� ������   :500���                     ��" << endl;
		cout << "\t\t\t\t   ��  ����   :500���                     ��" << endl;
		cout << "\t\t\t\t   ��  Ԫ��ƿ :100���                     ��" << endl;
		cout << "\t\t\t\t   ��  �뿪                               ��" << endl;

		break;
	case 1:
		cout << "\t\t\t\t   ��  ����   :500���                     ��" << endl;
		cout << "\t\t\t\t   �� ������   :500���                     ��" << endl;
		cout << "\t\t\t\t   ��  Ԫ��ƿ :100���                     ��" << endl;
		cout << "\t\t\t\t   ��  �뿪                               ��" << endl;
		break;
	case 2:
		cout << "\t\t\t\t   ��  ����   :500���                     ��" << endl;
		cout << "\t\t\t\t   ��  ����   :500���                     ��" << endl;
		cout << "\t\t\t\t   �� ��Ԫ��ƿ :100���                     ��" << endl;
		cout << "\t\t\t\t   ��  �뿪                               ��" << endl;
		break;
	case 3:
		cout << "\t\t\t\t   ��  ����   :500���                     ��" << endl;
		cout << "\t\t\t\t   ��  ����   :500���                     ��" << endl;
		cout << "\t\t\t\t   ��  Ԫ��ƿ :100���                     ��" << endl;
		cout << "\t\t\t\t   �� ���뿪                               ��" << endl;
		break;
	}
	cout << "\t\t\t\t   �����������������������������������������������������������������������������ੴ " << endl;
	cout << "\t\t\t\t                                         ����" << endl;
	char choo = _getch();
	if (!isascii(choo))
	{
		switch (_getch())
		{
		case 72:
			if (num > 0)
			{
				num--;
			}
			break;
		case 80:
			if (num < 3)
			{
				num++;
			}
			break;
		}
	}
	else
	{
		if (choo == '\r')
		{
			switch (num)
			{
			case 0:
				if (hero.money >= 500)
				{
					hero.money -= 500;
					hero.bag.item[++hero.bag.num] = ironsword;
				}
				break;
			case 1:
				if (hero.money >= 500)
				{
					hero.money -= 300;
					hero.bag.item[++hero.bag.num] = ironshild;
				}
				break;
			case 3:
				if (hero.money >= 500)
				{
					hero.money -= 100;
					hero.bag.item[++hero.bag.num] = EstusFlask;
				}
				break;
			case 4:
				break;
			}
		}
	}
	}
}
