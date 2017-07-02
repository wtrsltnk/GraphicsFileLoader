// HoofdScherm.cpp: implementation of the HoofdScherm class.
//
//////////////////////////////////////////////////////////////////////

#include "HoofdScherm.h"
#include "DummySceneLoader.h"
#include <time.h>

//////////////////////////////////////////////////////////////////////
// WinMain
//////////////////////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HoofdScherm hoofdscherm;

	if (hoofdscherm.Create(hInstance) == TRUE)
	{
		return hoofdscherm.RunToClose();
	}

	return FALSE;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HoofdScherm::HoofdScherm()
{
}

HoofdScherm::~HoofdScherm()
{
}

LRESULT HoofdScherm::SchermProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		{
			DummySceneLoader dummy;

			this->manager.LoadScene(dummy, "\0");

			engine.InitGraphics(this->m_hWnd);

			view3d.InitView(0, 0, 200, 200);
			view2d.InitView(0, 0, 200, 200);

			camera.Move(-11.0f, 0.0f, 0.0f);

			cameratool.Initialize(args);

			SetTimer(this->m_hWnd, 0, 10, NULL);
			break;
		}

	case WM_SIZE:
		{
			view3d.Resize(LOWORD(lParam), HIWORD(lParam));
			view2d.Resize(LOWORD(lParam), HIWORD(lParam));
			break;
		}

	case WM_PAINT:
		{
			break;
		}

	case WM_TIMER:
		{
			engine.SelectEngine();
			view3d.Setup3D();
			engine.BeginFrame();

			::glEnable(GL_CULL_FACE);
			cameratool.Update();
			cube.Render();
			manager.Render();

			engine.EndFrame();
			engine.Swap();
			break;
		}

	case WM_CLOSE:
		{
			engine.CloseGraphics();
			break;
		}

	case WM_LBUTTONDOWN:
		{
			this->cameratool.OnLButtonDown(LOWORD(lParam), HIWORD(lParam), wParam);
			break;
		}

	case WM_MBUTTONDOWN:
		{
			this->cameratool.OnMButtonDown(LOWORD(lParam), HIWORD(lParam), wParam);
			break;
		}

	case WM_RBUTTONDOWN:
		{
			this->cameratool.OnRButtonDown(LOWORD(lParam), HIWORD(lParam), wParam);
			break;
		}

	case WM_LBUTTONUP:
		{
			this->cameratool.OnLButtonUp(LOWORD(lParam), HIWORD(lParam), wParam);
			break;
		}

	case WM_MBUTTONUP:
		{
			this->cameratool.OnMButtonUp(LOWORD(lParam), HIWORD(lParam), wParam);
			break;
		}

	case WM_RBUTTONUP:
		{
			this->cameratool.OnRButtonUp(LOWORD(lParam), HIWORD(lParam), wParam);
			break;
		}

	case WM_MOUSEMOVE:
		{
			this->cameratool.OnMouseMove(LOWORD(lParam), HIWORD(lParam), wParam);
			break;
		}

	case WM_KEYDOWN:
		{
			this->cameratool.OnKeyDown(wParam);
			break;
		}

	case WM_KEYUP:
		{
			this->cameratool.OnKeyUp(wParam);
			break;
		}
	}
	return Scherm::SchermProc(uMsg, wParam, lParam);
}