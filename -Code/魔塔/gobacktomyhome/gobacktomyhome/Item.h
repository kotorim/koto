#pragma once
enum Itemtype
{
	USE,
	EQUIP
};
class Item
{
public:
	Item();
	Item(char *n,int hu,int au,int du,Itemtype type);
	~Item();
	//void useitem(Hero &hero);
	//void dropitem(Hero &hero);
	char* getname()
	{
		return name;
	}
	int gethpup()
	{
		return hpup;
	}
	int getatkup()
	{
		return atkup;
	}
	int getdefup()
	{
		return defup;
	}
	Itemtype getitemtype()
	{
		return itemtype;
	}
private:
	char *name;
	int hpup;
	int atkup;
	int defup;
	Itemtype itemtype;
};

