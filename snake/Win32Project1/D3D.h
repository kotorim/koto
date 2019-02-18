#pragma once
#include <d3d9.h>
#include <strsafe.h>
#include"Cube.h"
class D3D
{
public:
	~D3D();
	static D3D* getpInstance()
	{
		if (nullptr == pInstance)
		{
			pInstance = new D3D;
		}
		return pInstance;
	}
	HRESULT InitD3D(HWND hWnd);
	VOID Cleanup();
	bool BeginRender();
	VOID EndRender();
	LPDIRECT3DDEVICE9 g_pd3dDevice;
private:
	D3D();
	static D3D* pInstance;
	LPDIRECT3D9 g_pD3D;
};

