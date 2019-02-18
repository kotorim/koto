#pragma once
#include "stdafx.h"
#include "Rectangles.h"

Rectangles::Rectangles()
{
}


HRESULT Rectangles::InitVB(LPDIRECT3DDEVICE9 g_pd3dDevice)
{
	CUSTOMVERTEX Vertices[] =
	{
		{ 50.0f, 50.0f, 0.0f, 1.0f, 0xffff0000, }, 
		{ 650.0f, 50.0f, 0.0f, 1.0f, 0xffff0000, },

		{ 50.0f, 50.0f, 0.0f, 1.0f, 0xffff0000, },
		{ 50.0f, 600.0f, 0.0f, 1.0f, 0xffff0000, },

		{ 50.0f, 600.0f, 0.0f, 1.0f, 0xffff0000, },
		{ 650.0f, 600.0f, 0.0f, 1.0f, 0xffff0000, },

		{ 650.0f, 50.0f, 0.0f, 1.0f, 0xffff0000, },
		{ 650.0f, 600.0f, 0.0f, 1.0f, 0xffff0000, },

	};
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(sizeof(Vertices),
		0, D3DFVF_CUSTOMVERTEX,//灵活顶点格式
		D3DPOOL_DEFAULT, &g_pVB, NULL)))//顶点缓冲区顶点的地址
	{
		return E_FAIL;
	}

	//内存拷贝：数组中的数据拷贝到顶点缓冲区
	VOID* pVertices;
	if (FAILED(g_pVB->Lock(0, sizeof(Vertices), (void**)&pVertices, 0)))
		return E_FAIL;
	memcpy(pVertices, Vertices, sizeof(Vertices));
	g_pVB->Unlock();

	return S_OK;
}

VOID Rectangles::Render(LPDIRECT3DDEVICE9 g_pd3dDevice)
{
	//设置资源流
	g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
	//设置灵活顶点格式
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	//绘制基本图元
	g_pd3dDevice->DrawPrimitive(D3DPT_LINELIST, 0, 4);//图元的类型（三角形列），起始的顶点，画一个图元
}
Rectangles::~Rectangles()
{
}
