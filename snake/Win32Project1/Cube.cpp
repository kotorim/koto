
#include "stdafx.h"
#include "Cube.h"


Cube::Cube()
{
}

HRESULT Cube::InitGeometry(LPDIRECT3DDEVICE9 g_pd3dDevice)
{
	CUSTOMVERTEX1 g_Vertices[] =
	{
		{ -2.5f, 2.5f, -2.5f, 0xFF0000FF },
		{ 2.5f, 2.5f, -2.5f, 0xFF0000FF },
		{ -2.5f, 2.5f, 2.5f, 0xFF0000FF },
		{ 2.5f, 2.5f, 2.5f, 0xFF0000FF },

		{ -2.5f, -2.5f, -2.5f, 0xFF0000FF },
		{ -2.5f, -2.5f, 2.5f, 0xFF0000FF },
		{ 2.5f, -2.5f, -2.5f, 0xFF0000FF },
		{ 2.5f, -2.5f, 2.5f, 0xFF0000FF },


		{ 2.5f, -2.5f, -2.5f, 0xFF0000FF },
		{ 2.5f, 2.5f, -2.5f, 0xFF0000FF },
		{ -2.5f, -2.5f, -2.5f, 0xFF0000FF },
		{ -2.5f, 2.5f, -2.5f, 0xFF0000FF },

		{ -2.5f, -2.5f, -2.5f, 0xFF0000FF },
		{ -2.5f, 2.5f, -2.5f, 0xFF0000FF },
		{ -2.5f, -2.5f, 2.5f, 0xFF0000FF },
		{ -2.5f, 2.5f, 2.5f, 0xFF0000FF },

		{ -2.5f, -2.5f, 2.5f, 0xfffffff },
		{ -2.5f, 2.5f, 2.5f, 0xfffffff },
		{ 2.5f, -2.5f, 2.5f, 0xfffffff },
		{ 2.5f, 2.5f, 2.5f, 0xfffffff },

		{ 2.5f, -2.5f, 2.5f, 0xFF0000FF },
		{ 2.5f, 2.5f, 2.5f, 0xFF0000FF },
		{ 2.5f, -2.5f, -2.5f, 0xFF0000FF },
		{ 2.5f, 2.5f, -2.5f, 0xFF0000FF },

	};

	// Create the vertex buffer.
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(sizeof(g_Vertices),
		0, D3DFVF_CUSTOMVERTEX1,D3DPOOL_DEFAULT, &g_pVB, NULL)))
	{
		return E_FAIL;
	}

	// Fill the vertex buffer.
	VOID* pVertices;
	if (FAILED(g_pVB->Lock(0, sizeof(g_Vertices), (void**)&pVertices, 0)))
		return E_FAIL;
	memcpy(pVertices, g_Vertices, sizeof(g_Vertices));
	g_pVB->Unlock();

	return S_OK;
}

VOID Cube::Render(LPDIRECT3DDEVICE9 g_pd3dDevice)
{
	g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX1));
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX1);
	g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 4, 2);
	g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 8, 2);
	g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 12, 2);
	g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 16, 2);
	g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 20, 2);
}
Cube::~Cube()
{
}
