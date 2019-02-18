
#include "stdafx.h"
#include "Game.h"
#include <time.h>

Game* Game::pInstance = nullptr;
Game::Game					   ()
{
	srand(time(NULL));
	D3Der = D3D::getpInstance();
	Ca = new Camera;
	randcube.Pos1= { 0.0f, 20.0f, 0.0f };
	randcube.cube = new Cube;
	addnewcube();
	addnewcube();
	direct = U;
}
VOID Game::Init				   (HWND hWnd)
{
	if (SUCCEEDED(D3Der->InitD3D(hWnd)))
	{
		randcube.cube->InitGeometry(D3Der->g_pd3dDevice);
		line.InitVB(D3Der->g_pd3dDevice);
		return;
	}
}

void  Game::cubesmanage		   ()
{
	for (it = cubelist.begin(); it != cubelist.end(); it++)
	{
		(*it).cube->InitGeometry(D3Der->g_pd3dDevice);
	}
	list<Cubesss>::iterator temps = cubelist.begin();
	list<Cubesss>::iterator it2 = cubelist.end();
	it = cubelist.end();
	it2--;
	temps++;
	D3DXVECTOR3 TEMP;
	for (; it != temps;)
	{
		it2--;	
		if (it-- == temps)
		{
			break;
		}
		(*(it)).Pos1 = (*(it2)).Pos1;
		//switch ((*(it)).thisdir)
		//{
		//case U:
		//	if ((*(--it)).thisdir == U)
		//	{
		//		TEMP = (*(it2)).Pos1 + qUp;
		//		it++;
		//	}
		//	else
		//	{
		//		TEMP = (*(it2)).Pos1+qUp;
		//		(*(it)).thisdir = (*(it++)).thisdir;
		//	}
		//	(*(it)).Pos1 = TEMP;
		//	break;
		//case L:
		//	if ((*(--it)).thisdir == L)
		//	{
		//		TEMP = (*(it2)).Pos1+qLeft;
		//		it++;
		//	}
		//	else
		//	{
		//		TEMP = (*(it2)).Pos1+qLeft;
		//		(*(it)).thisdir = (*(it++)).thisdir;
		//	}
		//	(*(it)).Pos1 = TEMP;
		//	break;
		//case D:
		//	if ((*(--it)).thisdir == D)
		//	{
		//		TEMP = (*(it2)).Pos1+qDown;
		//		it++;
		//	}
		//	else
		//	{
		//		TEMP = (*(it2)).Pos1+qDown;
		//		(*(it)).thisdir = (*(it++)).thisdir;
		//	}
		//	(*(it)).Pos1 = TEMP;
		//	break;
		//case R:
		//	if ((*(--it)).thisdir == R)
		//	{
		//		TEMP = (*(it2)).Pos1+qRight;
		//		it++;
		//	}
		//	else
		//	{
		//		TEMP = (*(it2)).Pos1+qRight;
		//		(*(it)).thisdir = (*(it++)).thisdir;
		//	}
		//	(*(it)).Pos1 = TEMP;
		//	break;
		//}
	}
}
VOID  Game::SetupWorldMatrices ()
{
	if ((cubelist.front().thisdir == U&&direct == D) || (cubelist.front().thisdir == R&&direct == L) || (cubelist.front().thisdir == D&&direct == U) || (cubelist.front().thisdir == L&&direct == R))
	{
		direct = cubelist.front().thisdir;
	}
	else
	{
		cubelist.front().thisdir = direct;
	}
	D3DXMATRIXA16 matWorld;
	Sleep(100);
	switch (direct)
	{
	case U:
		D3DXMatrixTranslation(&matWorld, cubelist.front().Pos1.x, cubelist.front().Pos1.y -= 5.3, cubelist.front().Pos1.z);
		break;
	case D:
		D3DXMatrixTranslation(&matWorld, cubelist.front().Pos1.x, cubelist.front().Pos1.y += 5.3, cubelist.front().Pos1.z);
		break;
	case L:
		D3DXMatrixTranslation(&matWorld, cubelist.front().Pos1.x -= 5.3, cubelist.front().Pos1.y, cubelist.front().Pos1.z);
		break;
	case R:		
		D3DXMatrixTranslation(&matWorld, cubelist.front().Pos1.x += 5.3, cubelist.front().Pos1.y, cubelist.front().Pos1.z);
		break;
	}
	D3Der->g_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	D3Der->g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	
}
VOID  Game::SetupWorldMatrices1()
{
	
	D3DXMATRIXA16 matWorld;
	D3DXMatrixTranslation(&matWorld, (*it).Pos1.x, (*it).Pos1.y, (*it).Pos1.z);
	D3Der->g_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_FORCE_DWORD);

	D3Der->g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
}
VOID  Game::SetupWorldMatrices2()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixTranslation(&matWorld, randcube.Pos1.x, randcube.Pos1.y, randcube.Pos1.z);
	D3Der->g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

}
VOID Game::SetupProj		   ()
{
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 300.0f);
	//设置投影变换矩阵
	D3Der->g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}
VOID Game::Render			   ()
{

	this->cubesmanage();
	if (D3Der->BeginRender())
	{
		
		Ca->SetupView(D3Der->g_pd3dDevice);
		SetupProj();
		
		SetupWorldMatrices();	
		line.Render(D3Der->g_pd3dDevice);
		cubelist.front().cube->Render(D3Der->g_pd3dDevice);
	

		
		it = cubelist.begin();
		it++;
		for (; it != cubelist.end();it++ )
		{
			SetupWorldMatrices1();
			(*(it)).cube->Render(D3Der->g_pd3dDevice);
		}
		

		SetupWorldMatrices2();
		randcube.cube->Render(D3Der->g_pd3dDevice);

		hit(randcube,cubelist.front(),true);
		
		if (cubelist.size() >= 5)
		{
			it = cubelist.begin();
			it++;
			it++;
			it++;
			it++;
			for (; it != cubelist.end(); it++)
			{
				hit((*(it)), cubelist.front(), false);
			}
		}
	}
	D3Der->EndRender();
}
void Game::addnewcube		   ()
{
	Cubesss* pnew = new Cubesss;
	pnew->cube = new Cube;
	pnew->Pos1 = { 0.0f, 0.0f, 0.0f };
	pnew->thisdir = U;
	cubelist.push_back(*pnew);
}
Game::~Game					   ()
{
	delete D3Der;
	D3Der = nullptr;
}
void Game::hit(Cubesss &cube1,Cubesss cube2,bool add)
{
	if (add == true)
	{
		D3DXVECTOR3 v1min = { cube1.Pos1.x - 2.4f, cube1.Pos1.y - 2.4f, cube1.Pos1.z - 2.4f };
		D3DXVECTOR3 v1max = { cube1.Pos1.x + 2.4f, cube1.Pos1.y + 2.4f, cube1.Pos1.z + 2.4f };

		D3DXVECTOR3 v2min = { cube2.Pos1.x - 2.4f, cube2.Pos1.y - 2.4f, cube2.Pos1.z - 2.4f };
		D3DXVECTOR3 v2max = { cube2.Pos1.x + 2.4f, cube2.Pos1.y + 2.4f, cube2.Pos1.z + 2.4f };
		if (!(v1max.x < v2min.x || v1max.y < v2min.y || v1max.z < v2min.z ||
			v1min.x > v2max.x || v1min.y > v2max.y || v1min.z > v2max.z))
		{
			addnewcube();
			cube1.Pos1.x = rand() % 140 - 70;
			cube1.Pos1.y = rand() % 140 - 70;
		}

		D3DXVECTOR3 v3min = { -70.0f, -70.0f, 0.0f };
		D3DXVECTOR3 v3max = { 70.0f, 70.0f, 0.0f};
		if (v3max.x < v2min.x || v3max.y < v2min.y || v3max.z < v2min.z ||
			v3min.x > v2max.x || v3min.y > v2max.y || v3min.z > v2max.z)
		{
			MessageBox(0, L"die", L"you", 0);
			exit(0);
		}
	}
	else
	{
		D3DXVECTOR3 v1min = { cube1.Pos1.x - 2.4f, cube1.Pos1.y - 2.4f, cube1.Pos1.z - 2.4f };
		D3DXVECTOR3 v1max = { cube1.Pos1.x + 2.4f, cube1.Pos1.y + 2.4f, cube1.Pos1.z + 2.4f };

		D3DXVECTOR3 v2min = { cube2.Pos1.x - 2.4f, cube2.Pos1.y - 2.4f, cube2.Pos1.z - 2.4f };
		D3DXVECTOR3 v2max = { cube2.Pos1.x + 2.4f, cube2.Pos1.y + 2.4f, cube2.Pos1.z + 2.4f };
		if (!(v1max.x < v2min.x || v1max.y < v2min.y || v1max.z < v2min.z ||
			v1min.x > v2max.x || v1min.y > v2max.y || v1min.z > v2max.z))
		{
			MessageBox(0, L"die", L"you", 0);
			exit(0);
		}
	}
}