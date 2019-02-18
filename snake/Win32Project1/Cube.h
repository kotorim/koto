#pragma once
#include <mmsystem.h>
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 ) 
struct CUSTOMVERTEX1
{
	FLOAT x, y, z;      // The untransformed, 3D position for the vertex
	DWORD color;        // The vertex color
};
#define D3DFVF_CUSTOMVERTEX1 (D3DFVF_XYZ|D3DFVF_DIFFUSE)
class Cube
{
public:
	Cube();
	HRESULT InitGeometry(LPDIRECT3DDEVICE9 g_pd3dDevice);
	VOID Render(LPDIRECT3DDEVICE9 g_pd3dDevice);
	VOID SetPos(CUSTOMVERTEX1 Pos1)
	{
		Pos = Pos1;
	}
	~Cube();
private:
	CUSTOMVERTEX1 Pos;
	LPDIRECT3DVERTEXBUFFER9 g_pVB;
};

