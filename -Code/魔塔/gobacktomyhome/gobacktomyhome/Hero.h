#pragma once
#include "Item.h"
#include "funcs.h"
struct Bag
{
	int num = 0;
	Item item[5];
};
struct Staff
{
	Item item[6];
};
class Hero
{
private:

		Pos heropos;
		char name[20];
		int lv;
		int hp;
		int mp;
		int exp;
		int atk;
		int def;
		int money;
		Bag bag;
		Staff staff;
		Keys keys;
		int bag_movechoose;
		int staff_movechoose;
public:
	Hero();
	Hero(Pos pos);

	//setget
	void setheropos(Pos pos)
	{
		this->heropos.x = pos.x;
		this->heropos.y = pos.y;
	}
	int getbag_movechoose()
	{
		return bag_movechoose;
	}
	void setbag_movechoose(bool choose)
	{
		bag_movechoose += choose;
	}
	int getstaff_movechoose()
	{
		return staff_movechoose;
	}
	void setstaff_movechoose(bool choose)
	{
		staff_movechoose += choose;
	}
	void setheromp(int qmp)
	{
		this->mp = qmp;
	}
	int getheromp()
	{
		return this->mp;
	}
	Pos getheropos()
	{
		return this->heropos;
	}
	void setherolv(int qlv)
	{
		this->lv = qlv;
	} 
	int getherolv()
	{
		return this->lv;
	}
	void setherohp(int qhp)
	{
		this->hp = qhp;
	}
	int getherohp()
	{
		return hp;
	}
	void setheroexp(int qexp)
	{
		this->exp = qexp;
	}
	int getheroexp()
	{
		return exp;
	}
	void setheroatk(int qatk)
	{
		this->atk = qatk;
	}
	int getheroatk()
	{
		return atk;
	}
	void setherodef(int qdef)
	{
		this->def = qdef;
	}
	int getherodef()
	{
		return def;
	}
	void setheromoney(int qmoney)
	{
		this->money = qmoney;
	}
	int getheromoney()
	{
		return money;
	}
	void setherokeys(Keys qkeys)
	{
		this->keys = qkeys;
	}
	Keys getherokeys()
	{
		return keys;
	}
	Bag getherobag()
	{
		return bag;
	}
	void setherobag(Bag qbag)
	{
		this->bag = qbag;
	}
	//英雄行动
		//升级
	void lvup(int qexp);
		//打架
	//void fight(Monster monster);
		//用道具
	void useitem(Item item);
		//丢道具
	void dropitemfrombag();
		//丢装备
	void dropitemfromstaff();
		//显示信息
	void showheromessage();
		//显示背包
	void showbag();
		//显示装备栏
	void showstaff();
};

