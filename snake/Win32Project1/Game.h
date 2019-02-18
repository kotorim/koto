#pragma once
#include"D3D.h"
#include"Rectangles.h"
#include"Circle.h"
#include"Cube.h"
#include"Camera.h"
#include<math.h>
#include <list>
using namespace std;
enum dir
{
	R,
	L,
	U,
	D,
};

struct Cubesss
{
	Cube*					cube;
	dir						thisdir;
	D3DXVECTOR3				Pos1;
};

class Game
{
public:
	static Game* getpInstance()
	{
		if (nullptr == pInstance)
		{
			pInstance = new Game;
		}
		return pInstance;
	}
	void		 cubesmanage();
	VOID		 Init(HWND hWnd);
	VOID		 SetupWorldMatrices();
	VOID		 SetupWorldMatrices1();
	VOID		 SetupWorldMatrices2();
	VOID		 SetupProj();
	VOID		 Render();
	void		 addnewcube();
				 ~Game();
	VOID		 Setposx(float a)
	{
		cubelist.front().Pos1.x += a;
	}
	VOID		 Setposy(float b)
	{
		cubelist.front().Pos1.y += b;
	}
	VOID		 Setposz(float c)
	{
		cubelist.front().Pos1.z += c;
	}
	dir			 direct;
	Camera*		 Ca;
	
private:
	void		 hit(Cubesss &cube1, Cubesss cube2,bool add);
	D3D*		 D3Der;
	list<Cubesss> cubelist;
	list<Cubesss>::iterator it;
	Cubesss randcube;
	Rectangles line;
	Game();
	static Game* pInstance;
};

