#include "stdafx.h"
#include "Circle.h"
#include<math.h>

Circle::Circle()
{
}
HRESULT Circle::InitVB(LPDIRECT3DDEVICE9 g_pd3dDevice)
{
	CUSTOMVERTEX Circular[26];
	Circular[0] = { 500.0f, 150.0f, 0.5f, 1.0f, 0xff00ffff };
	float x = 500.0f;
	float y = 150.0f;
	float r = 100.0f;
	float angle = 15.0f / 180.0f * PI;

	for (int i = 1; i < 26; i++)
	{
		Circular[i] = { x + r*sin(angle), y - r*cos(angle), 0.5f, 1.0f, 0xff00ffff };
		if (angle <= 2.0 * PI)
		{
			angle += 15.0f / 180.0f * PI;
		}
		else
			break;
	}

	if (FAILED(g_pd3dDevice->CreateVertexBuffer(sizeof(Circular),
		0, D3DFVF_CUSTOMVERTEX,
		D3DPOOL_DEFAULT, &g_pVB, NULL)))
	{
		return E_FAIL;
	}

	VOID* pCircular;
	if (FAILED(g_pVB->Lock(0, sizeof(Circular), (void**)&pCircular, 0)))
		return E_FAIL;
	memcpy(pCircular, Circular, sizeof(Circular));
	g_pVB->Unlock();

	return S_OK;
}

VOID Circle::Render(LPDIRECT3DDEVICE9 g_pd3dDevice)
{
	g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, 0, 24);
}
Circle::~Circle()
{
}
