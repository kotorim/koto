#include<iostream>
#include<conio.h>
#include<Windows.h>
#include <time.h>
using namespace std;
struct Item
{
	char name[10];
	int hpup;
	int mpup;
	int atkup;
	int defup;
};
struct Bag
{
	int num = 0;
	Item item[5];
};
struct Hero 
{
	char name[10];
	int lv;
	int hp;
	int exp;
	int atk;
	Bag bag;
};
struct Square
{
	int posx;
	int posy;
	int l;
	int h;
};
void sort(Hero a[],int num)
{
	cout << sizeof(a) << endl;
	cout << "选择排序" << endl << "1.血量,2.经验值,3.等级" << endl;
	switch (_getch())
	{
	case '1':
		for (int y = 0; y < num; y++)
		{
			for (int x = 0; x < num - y; x++)
			{
					if (a[x].hp < a[x + 1].hp)
					{
						Hero p = a[x];
						a[x] = a[x + 1];
						a[x + 1] = p;
					}
				}
			}
		break;
	case '2':
		for (int y = 0; y < num; y++)
		{
			for (int x = 0; x < num - y; x++)
			{
				if (a[x].exp < a[x + 1].exp)
				{
					Hero p = a[x];
					a[x] = a[x + 1];
					a[x + 1] = p;
				}
			}
		}
		break;
	case '3':
		for (int y = 0; y < num; y++)
		{
			for (int x = 0; x < num - y; x++)
			{
				if (a[x].hp < a[x + 1].hp)
				{
					Hero p = a[x];
					a[x] = a[x + 1];
					a[x + 1] = p;
				}
			}
		}
		break;
		}
	cout << a[0].name << "\t" << a[1].name << "\t" << a[2].name << endl;
	return;
}
void pk(Hero &a, Hero &b)
{
	while (1)
	{
		b.hp = (b.hp) - (a.atk);
		cout << a.name << "攻击" << b.name << "造成" << a.atk << "点伤害" << endl;
		Sleep(500);

		if (b.hp <= 0)
		{
			cout << b.name << "死亡" << endl;
			break;
		}
		cout << b.name << "还剩" << b.hp << "点血" << endl;
		Sleep(500);
		system("cls");
		a.hp = (a.hp) - (b.atk);
		cout << b.name << "攻击" << a.name << "造成" << b.atk << "点伤害" << endl;
		Sleep(500);

		if (a.hp <= 0)
		{
			cout << a.name << "死亡" << endl;
			break;
		}		
		cout << a.name << "还剩" << a.hp << "点血" << endl;
		Sleep(500);
		system("cls");
	}
	return;
}
bool isintersect(Square a, Square b)
{
	for (int x = (a.posx) - ((a.l) / 2); x < (a.posx) + ((a.l) / 2);x++)
	{
		for (int y = (a.posy) - ((a.h) / 2); y < (a.posy) + ((a.h) / 2); y++)
		{
			for (int q = (b.posx) - ((b.l) / 2); q < (b.posx) + ((b.l) / 2); q++)
			{
				for (int w = (b.posy) - ((b.h) / 2); w < (b.posy) + ((b.h) / 2); w++)
				{
					cout << x << "," << y << "\t" << q << " " << w << endl;
					Sleep(100);
					system("cls");
					if (x == q&&y == w)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
int area(Square a)
{
	return a.l*a.h;
}
int perimeter(Square a)
{
	return a.l * 2 + a.h * 2;
}
void randitemintobag(Item item[5], Bag &bag)
{
	
	bag.item[bag.num] = item[rand() % 5];
	(bag.num)++;
}
int main()
{	
	srand(time(NULL));
	Bag bag1;
	Bag bag2;
	Bag bag3;
	Hero hero1 = { "aimer", 999, 999, 5, 7, bag1 };
	Hero hero2 = { "koto", 50, 99,48, 8, bag2 };
	Hero hero3 = { "ara", 20, 30, 60, 1, bag3 };
	Hero a[3] = { hero1, hero2 ,hero3 };
	int num = sizeof(a) / sizeof(Hero)-1;
	sort(a,num);
	//pk(hero1, hero2);
	Square s = { 0, 0, 5, 5 };
	Square b = { 5, 5, 5, 5 };
	//cout << (int)isintersect(s, b) << endl;
	return 0;
}