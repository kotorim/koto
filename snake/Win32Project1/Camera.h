#pragma once
#include"Cube.h"
class Camera
{
public:
	Camera();
	~Camera();
	VOID SetupView(LPDIRECT3DDEVICE9 g_pd3dDevice);
	VOID SetposA()
	{
		Pos.x = Pos.x - 1;
	}
	VOID SetposD()
	{
		Pos.x = Pos.x + 1;
	}
	VOID SetposW()
	{
		Pos.y = Pos.y + 1;
	}
	VOID SetposS()
	{
		Pos.y = Pos.y - 1;
	}
	VOID SetposQ()
	{
		Right.y -= 0.1;
	}
	VOID SetposE()
	{
		Right.y += 0.1;
	}
private:
	D3DXVECTOR3 Pos; 
	D3DXVECTOR3 Right;
	D3DXVECTOR3 Look;
	D3DXVECTOR3 Up;
};

