#pragma once
#include"Rectangles.h"
#define PI 3.14159265f
class Circle
{
public:
	Circle();
	HRESULT InitVB(LPDIRECT3DDEVICE9 g_pd3dDevice);
	VOID Render(LPDIRECT3DDEVICE9 g_pd3dDevice);
	~Circle();
private:
	LPDIRECT3DVERTEXBUFFER9 g_pVB;
};

