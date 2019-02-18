#include "Hero.h"
#include <iostream>
Bag qqbag;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
Hero::Hero(Pos pos)
{
	strcpy(name, "yasuo");
	heropos = pos;
	hp = 10;
	lv = 1;
	exp = 0;
	atk = 5;
	def = 5;
	money = 0;
	bag = qqbag;
	keys = { 0, 0, 0 };
	bag_movechoose = 0;
	staff_movechoose = 0;
}
void Hero::dropitemfrombag()
{
	Item itemqqq;
	switch (bag.item[bag_movechoose].getitemtype())
	{
	case USE:
		bag.item[bag_movechoose] = itemqqq;
		break;
	case EQUIP:
		atk -=bag.item[bag_movechoose].getatkup();
		def -=bag.item[bag_movechoose].getdefup();
		bag.item[bag_movechoose] = itemqqq;
		break;
	}

	for (int x = bag_movechoose; x < 4; x++)
	{
		bag.item[x] = bag.item[x + 1];
	}
	bag.item[4] = itemqqq;
	bag.num--;
	return;
}

void Hero::dropitemfromstaff()
{
	Item itemqqq;
	switch (bag.item[movechoose].getitemtype())
	{
	case USE:
		bag.item[movechoose] = itemqqq;
		break;
	case EQUIP:
		atk -= bag.item[movechoose].getatkup();
		def -= bag.item[movechoose].getdefup();
		bag.item[movechoose] = itemqqq;
		break;
	}

	for (int x = movechoose; x < 4; x++)
	{
		bag.item[x] = bag.item[x + 1];
	}
	bag.item[4] = itemqqq;
	bag.num--;
	return;
}

void Hero::useitem(Item item)
{
	switch (item.getitemtype())
	{
	case USE:
		atk += item.getatkup();
		def += item.getdefup();
		hp += item.gethpup();
		if (hp >lv * 50)
		{
			hp = lv * 50;
		}
		if (strcmp(item.getname(), "元素瓶") == 0)
		{
			hp += (lv * 50)*0.5;
			if (hp > lv * 50)
			{
				hp = lv * 50;
			}
		}
		break;
	case EQUIP:
		atk += item.getatkup();
		def += item.getdefup();
		this->bag
		break;
	}

	return;
}


void Hero::lvup(int qexp)
{
	int qlv = this->lv;
	int qlvup = 0;
	while (1)
	{
		if (qexp >= qlv * 111)
		{
			qlvup++;
			this->exp = this->exp - (qlv * 111);
			this->atk += qlv * 4;
			this->def += qlv * 4;
			qlv++;
		}
		else if (qexp < qlv * 111)
		{
			break;
		}
	}
	if (qlvup != 0)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t  ┌┐" << endl;
		cout << "\t\t\t\t\t  └┼─────────────────────────────────────┐ " << endl;
		cout << "\t\t\t\t\t   │                                     │" << endl;
		//cout << "\t\t\t\t\t   │ " << this->name << "等级上升了" << lvup << "级\t         │" << endl;
		cout << "\t\t\t\t\t   │                                     │" << endl;
		cout << "\t\t\t\t\t   └─────────────────────────────────────┼┐ " << endl;
		cout << "\t\t\t\t\t                                         └┘" << endl;
		this->lv = qlv;
		this->hp = this->lv * 50;
		_getch();
	}
}


void Hero::showheromessage()
{
	cout << "┌─┐\n";
	cout << "└─┼─────────────────────┐ \n";
	cout << "  │      角色信息       │ \n";
	cout << "  ├─────────────────────┤ \n";
	if (strcmp(this->name, "快乐孤儿") == 0)
	{
		cout << "  │ name:" << this->name << "        │ \n";
	}
	else
	{
		cout << "  │ name:" << this->name << "\t        │ \n";
	}
	cout << "  │ hp  :";
	if (this->hp > (this->lv * 50) / 2)
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	}
	else if (this->hp <= (this->lv * 50) / 2 && this->hp > (this->lv * 50) / 4)
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	}
	else if (this->hp <= (this->lv * 50) / 4)
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	}
	cout << this->hp;
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//白色
	cout << "/" << this->lv * 50 << "\t        │ \n";
	cout << "  │ lv   :" << this->lv << " \t        │ \n";
	cout << "  │ exp  :" << this->exp << " \t        │ \n";
	cout << "  │ atk  :" << this->atk << " \t        │ \n";
	cout << "  │ def  :" << this->def << " \t        │ \n";
	cout << "  │ money:" << this->money << " \t        │ \n";
	cout << "  ├─────────────────────┤ \n";
	cout << "  │         钥匙        │ \n";
	cout << "  ├─────────────────────┤ \n";
	cout << "  │  ";
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << "  ㄟ";
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//白色
	cout << "  x     ";
	cout << keys.red;
	cout << "      │ \n";
	cout << "  │                     │ \n";
	cout << "  │  ";
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << "  ㄟ";
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//白色
	cout << "  x     ";
	cout << keys.blue;
	cout << "      │ \n";
	cout << "  │                     │ \n";
	cout << "  │  ";
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << "  ㄟ";
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);//白色
	cout << "  x     ";
	cout << keys.yellow;
	cout << "      │ \n";
	cout << "  └─────────────────────┼─┐ \n";
	cout << "                        └─┘\n";

}

void Hero::showbag()
{
	
	cout << "┌─┐\n";
	cout << "└─┼──────────────────────────────┐ \n";
	cout << "  │             背包             │ \n";
	cout << "  ├──────────────────────────────┤ \n";
	cout << "  │  ";
	if (bag_movechoose == 0)
	{cout << "→";}
	else{cout << "  ";}
	cout << this->bag.item[0].getname() <<"\t\t\t │ "<< endl;
	cout << "  ├┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┤ \n";
	cout << "  │  ";
	if (bag_movechoose == 1)
	{
		cout << "→";
	}
	else{ cout << "  "; }
	cout << this->bag.item[1].getname() << "\t\t\t │ " << endl;
	cout << "  ├┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┤ \n";
	cout << "  │  ";
	if (bag_movechoose == 2)
	{
		cout << "→";
	}
	else{ cout << "  "; }
	cout << this->bag.item[2].getname() << "\t\t\t │ " << endl;
	cout << "  ├┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┤ \n";
	cout << "  │  ";
	if (bag_movechoose == 3)
	{
		cout << "→";
	}
	else{ cout << "  "; }
	cout << this->bag.item[3].getname() << "\t\t\t │ " << endl;
	cout << "  ├┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┤ \n";	cout << "  │  ";
	if (bag_movechoose == 4)
	{
		cout << "→";
	}
	else{ cout << "  "; }
	cout << this->bag.item[4].getname() << "\t\t\t │ " << endl;
	cout << "  ├┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┤ \n";
	cout << "  │                              │ \n";
	cout << "  └──────────────────────────────┼─┐ \n";
	cout << "                                 └─┘ \n";
}

void Hero::showstaff()
{
	cout << "┌─┐\n";
	cout << "└─┼──────────────────────────────┐ \n";
	cout << "  │             背包             │ \n";
	cout << "  ├──────────────────────────────┤ \n";
	cout << "  │  ";
	if (staff_movechoose == 0)
	{
		cout << "→";
	}
	else{ cout << "  "; }
	cout << this->bag.item[0].getname() << "\t\t\t │ " << endl;
	cout << "  ├┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┤ \n";
	cout << "  │  ";
	if (staff_movechoose == 1)
	{
		cout << "→";
	}
	else{ cout << "  "; }
	cout << this->bag.item[1].getname() << "\t\t\t │ " << endl;
	cout << "  ├┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┤ \n";
	cout << "  │  ";
	if (staff_movechoose == 2)
	{
		cout << "→";
	}
	else{ cout << "  "; }
	cout << this->bag.item[2].getname() << "\t\t\t │ " << endl;
	cout << "  ├┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┤ \n";
	cout << "  │  ";
	if (staff_movechoose == 3)
	{
		cout << "→";
	}
	else{ cout << "  "; }
	cout << this->bag.item[3].getname() << "\t\t\t │ " << endl;
	cout << "  ├┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┤ \n";	cout << "  │  ";
	if (staff_movechoose == 4)
	{
		cout << "→";
	}
	else{ cout << "  "; }
	cout << this->bag.item[4].getname() << "\t\t\t │ " << endl;
	cout << "  ├┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┤ \n";
	cout << "  │                              │ \n";
	cout << "  └──────────────────────────────┼─┐ \n";
	cout << "                                 └─┘ \n";
}
