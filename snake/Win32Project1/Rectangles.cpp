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
		0, D3DFVF_CUSTOMVERTEX,//�����ʽ
		D3DPOOL_DEFAULT, &g_pVB, NULL)))//���㻺��������ĵ�ַ
	{
		return E_FAIL;
	}

	//�ڴ濽���������е����ݿ��������㻺����
	VOID* pVertices;
	if (FAILED(g_pVB->Lock(0, sizeof(Vertices), (void**)&pVertices, 0)))
		return E_FAIL;
	memcpy(pVertices, Vertices, sizeof(Vertices));
	g_pVB->Unlock();

	return S_OK;
}

VOID Rectangles::Render(LPDIRECT3DDEVICE9 g_pd3dDevice)
{
	//������Դ��
	g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
	//���������ʽ
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	//���ƻ���ͼԪ
	g_pd3dDevice->DrawPrimitive(D3DPT_LINELIST, 0, 4);//ͼԪ�����ͣ��������У�����ʼ�Ķ��㣬��һ��ͼԪ
}
Rectangles::~Rectangles()
{
}
