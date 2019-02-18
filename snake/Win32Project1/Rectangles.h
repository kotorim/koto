#pragma once
#include"D3D.h"
struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw; // 已经经过变换的顶点
	DWORD color;        // 顶点的颜色
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

