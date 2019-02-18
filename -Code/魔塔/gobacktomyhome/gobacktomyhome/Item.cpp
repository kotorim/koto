#include "Item.h"
#include "Hero.h"
#include <iostream>
using namespace std;
char emptyname[10] = "Пе    ";
Item::Item()
	:name(emptyname),
	hpup(0),
	atkup(0),
	defup(0),
	itemtype(EQUIP)
{
}
Item::Item(char *n = emptyname, int hu = 0, int au = 0, int du = 0,Itemtype type = EQUIP)
	:name(n),
	hpup(hu),
	atkup(au),
	defup(du),
	itemtype(type)
{
	//FILE *pfile = fopen("items.data","rb+");
	//fread
}


Item::~Item()
{
}



