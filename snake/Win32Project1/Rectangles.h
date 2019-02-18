#pragma once
#include"D3D.h"
struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw; // �Ѿ������任�Ķ���
	DWORD color;        // �������ɫ
};
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)
class Rectangles
{
public:
	Rectangles();
	HRESULT InitVB(LPDIRECT3DDEVICE9 g_pd3dDevice);
	VOID Render(LPDIRECT3DDEVICE9 g_pd3dDevice);
	~Rectangles();
	
private:
	LPDIRECT3DVERTEXBUFFER9 g_pVB;
};

