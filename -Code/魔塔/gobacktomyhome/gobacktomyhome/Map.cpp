#include "Map.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
Map::Map(int ***map)
{
	map = new int **[6];
	for (int x = 0; x < 6; x++)
	{
		map[x] = new int*[15];
		for (int y = 0; y < 15; y++)
		{
			map[x][y] = new int[15];
		}
	}
	return;
}

//void Map::updata(int drawtype,Hero hero)
//{
//	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD coord;
//	coord.X = 1;
//	coord.Y = 1;
//	SetConsoleCursorPosition(hout, coord);//���ָ���һ��
//	cout << "                                                    \n                                                    \n";
//	for (int x = -1; x < 18; x++)
//	{
//		if (drawtype == 1)
//		{
//			Sleep(50);
//		}
//		cout << "\t\t\t";
//		switch (x)
//		{
//		case -1:
//			cout << "����";
//			break;
//		case 0:
//			cout << "���੤�������������������������������� ";
//			break;
//		case 1:
//			if (strcmp(hero.name, "���ֹ¶�") == 0)
//			{
//				cout << " �� name:" << hero.name << "  �� ";
//			}
//			else
//			{
//				cout << " �� name:" << hero.name << "\t  �� ";
//			}
//			break;
//		case 2:
//			cout << " �� hp  :";
//			if (hero.hp > (hero.lv * 50) / 2)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			else if (hero.hp <= (hero.lv * 50) / 2 && hero.hp > (hero.lv * 50) / 4)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			else if (hero.hp <= (hero.lv * 50) / 4)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			cout << hero.hp;
//			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//			cout << "/" << hero.lv * 50 << "\t  �� ";
//			break;
//		case 3:
//			cout << " �� lv  :" << hero.lv << " \t  �� ";
//			break;
//		case 4:
//			cout << " �� exp :" << hero.exp << " \t  �� ";
//			break;
//		case 5:
//			cout << " �� atk :" << hero.atk << " \t  �� ";
//			break;
//		case 6:
//			cout << " �� def :" << hero.def << " \t  �� ";
//			break;
//		case 7:
//			cout << " �� coin:" << hero.money << " \t  �� ";
//			break;
//		case 8:
//			cout << " ������������������������������������ ";
//			break;
//		case 9:
//			cout << " ��      Կ��      �� ";
//			break;
//		case 10:
//			cout << " ������������������������������������ ";
//			break;
//		case 11:
//			cout << " �� ";
//			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			cout << "  ��";
//			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//			cout << "  x    ";
//			cout << keys.red;
//			cout << "   �� ";
//			break;
//		case 12:
//			cout << " ��                �� ";
//			break;
//		case 13:
//			cout << " �� ";
//			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			cout << "  ��";
//			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//			cout << "  x    ";
//			cout << keys.blue;
//			cout << "   �� ";
//			break;
//		case 14:
//			cout << " ��                �� ";
//			break;
//		case 15:
//			cout << " �� ";
//			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			cout << "  ��";
//			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//			cout << "  x    ";
//			cout << keys.yellow;
//			cout << "   �� ";
//			break;
//		case 16:
//			cout << "���੤�������������������������������� ";
//			break;
//		case 17:
//			cout << "����                 ";
//		}
//		for (int y = 0; y < 15; y++)
//		{
//			if (x == 0)
//			{
//				cout << "����";
//			}
//			else if (x == 16)
//			{
//				cout << "����";
//			}
//			else if (x == 17 || x == -1)
//			{
//				cout << "  ";
//			}
//			else
//			{
//				switch (map[uplevel][x - 1][y])
//				{
//				case -7:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";//ɫ��
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case -8:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";//ɫ��
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case -9:
//					cout << "��";//��ͷ�ľ���
//					break;
//				case -10:
//					cout << "��";//��ͷ�ľ���boom
//					break;
//				case -1:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";//��1
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case -2:
//					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";//��2
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case -3:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";//��3
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case 1:
//					cout << "��";//ǽ
//					break;
//				case 55:
//					cout << "��";
//					break;
//				case 22:
//					cout << "��";
//					break;
//				case 33:
//					cout << "��";
//					break;
//				case 44:
//					cout << "��";
//					break;
//				case 2:
//					cout << "��";//����¥��
//					break;
//				case 3:
//					cout << "��";//����¥��
//					break;
//				case 4:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case 5:
//					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case 6:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case 0:
//					cout << "  ";//null
//					break;
//				case 10:
//					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";//Ȫ
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case 11:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case 12:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case 13:
//					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case 14:
//					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case 15:
//					cout << "��";
//					break;
//				case 99:
//					cout << "  ";//��¥��λ��
//					break;
//				case 9:
//					cout << "��";//��
//					break;
//				case 90:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";//��1
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				case 91:
//					cout << "��";//��2
//					break;
//
//				case 92:
//					cout << "��";//��3
//					break;
//				case 93:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";//��4
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//
//				case 94:
//					cout << "��";//��5
//					break;
//				case 95:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";//��6
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//
//				case 96:
//					cout << "��";//��7
//					break;
//				case 97:
//					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//					cout << "��";//��8
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//
//				case 98:
//					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
//					cout << "��";//��9
//					SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//					break;
//				}
//			}
//		}
//		switch (x)
//		{
//		case -1:
//			cout << "                                   ����";
//			break;
//		case 0:
//			cout << "�����������������������������������੼ ";
//			break;
//		case 1:
//			cout << "��      Tips      ��";
//			break;
//		case 2:
//			cout << "������������������������������������ ";
//			break;
//		case 3:
//			cout << "�� S :�浵 L:���� �� ";
//			break;
//		case 4:
//			cout << "�� Q :�˳�        �� ";
//			break;
//		case 5:
//			cout << "�� tab:����ѡ��   �� ";
//			break;
//		case 6:
//			cout << "�� 1 :ʹ�õ���    �� ";
//			break;
//		case 7:
//			cout << "�� 2 :��������    �� ";
//			break;
//		case 8:
//			cout << "������������������������������������ ";
//			break;
//		case 9:
//			cout << "��      ����      ��";
//			break;
//		case 10:
//			cout << "������������������������������������ ";
//			break;
//		case 11:
//			cout << "��";
//			if (movechoose == 0)
//			{
//				cout << " ��";
//			}
//			else
//			{
//				cout << "    ";
//			}
//			if (hero.bag.item[0].itemtype == EQUIP)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			else if (hero.bag.item[0].itemtype == USE)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			cout << hero.bag.item[0].name;
//			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//			if (strlen(hero.bag.item[2].name) == 8 && movechoose == 2)
//			{
//				cout << "  ��";
//			}
//			else if (strlen(hero.bag.item[2].name) == 8)
//			{
//				cout << "    ��";
//
//			}
//			else
//			{
//				cout << "\t   ��";
//			}
//			break;
//		case 12:
//			cout << "��";
//			if (movechoose == 1)
//			{
//				cout << " ��";
//			}
//			else
//			{
//				cout << "    ";
//			}
//			if (hero.bag.item[1].itemtype == EQUIP)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			else if (hero.bag.item[1].itemtype == USE)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			cout << hero.bag.item[1].name;
//			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//			if (strlen(hero.bag.item[2].name) == 8)
//			{
//				cout << "";
//			}
//			else
//			{
//				cout << "\t   ��";
//			}
//			break;
//		case 13:
//			cout << "��";
//			if (movechoose == 2)
//			{
//				cout << " ��";
//			}
//			else
//			{
//				cout << "    ";
//			}
//			if (hero.bag.item[2].itemtype == EQUIP)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			else if (hero.bag.item[2].itemtype == USE)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			cout << hero.bag.item[2].name;
//			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//			if (strlen(hero.bag.item[2].name) == 8 && movechoose == 2)
//			{
//				cout << "  ��";
//			}
//			else if (strlen(hero.bag.item[2].name) == 8)
//			{
//				cout << "    ��";
//
//			}
//			else
//			{
//				cout << "\t   ��";
//			}
//			break;
//		case 14:
//			cout << "��";
//			if (movechoose == 3)
//			{
//				cout << " ��";
//			}
//			else
//			{
//				cout << "    ";
//			}
//			if (hero.bag.item[3].itemtype == EQUIP)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			else if (hero.bag.item[3].itemtype == USE)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			cout << hero.bag.item[3].name;
//			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//			if (strlen(hero.bag.item[2].name) == 8 && movechoose == 2)
//			{
//				cout << "  ��";
//			}
//			else if (strlen(hero.bag.item[2].name) == 8)
//			{
//				cout << "    ��";
//
//			}
//			else
//			{
//				cout << "\t   ��";
//			}
//			break;
//		case 15:
//			cout << "��";
//			if (movechoose == 4)
//			{
//				cout << " ��";
//			}
//			else
//			{
//				cout << "    ";
//			}
//			if (hero.bag.item[4].itemtype == EQUIP)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			else if (hero.bag.item[4].itemtype == USE)
//			{
//				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//			}
//			cout << hero.bag.item[4].name;
//			SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//��ɫ
//			if (strlen(hero.bag.item[2].name) == 8 && movechoose == 2)
//			{
//				cout << "  ��";
//			}
//			else if (strlen(hero.bag.item[2].name) == 8)
//			{
//				cout << "    ��";
//
//			}
//			else
//			{
//				cout << "\t   ��";
//			}
//			break;
//		case 16:
//			cout << "�����������������������������������ੴ ";
//			break;
//		case 17:
//			cout << "                  ���� ";
//		}
//		cout << endl;
//	}
//	drawtype = 0;
//	return;
//}
Map::~Map()
{
}
