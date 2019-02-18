
#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
	Pos = { 0.0f, -3.0f, -80.0f };
	Right = { 1.0f, 0.0f, 0.0f };
	Look = { 0.0f, 0.0f, 2.5f };
	Up = { 0.0f, -1.0f, 0.0f };
}

VOID Camera::SetupView(LPDIRECT3DDEVICE9 g_pd3dDevice)
{
	D3DXMATRIXA16 matView;
	matView._11 = Right.x;					 matView._12 = Up.x;				   matView._13 = Look.x;
	matView._21 = Right.y;					 matView._22 = Up.y;				   matView._23 = Look.y;
	matView._31 = Right.z;					 matView._32 = Up.z;				   matView._33 = Look.z;
	matView._41 = -D3DXVec3Dot(&Pos, &Right);matView._42 = -D3DXVec3Dot(&Pos, &Up);matView._43 = -D3DXVec3Dot(&Pos, &Look);		matView._44 = 1.0f;
	matView._14 =							 matView._24 =						   matView._34 = 0.0f;
	//ÉèÖÃÊÓÍ¼±ä»»
	g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);
}

Camera::~Camera()
{
}
