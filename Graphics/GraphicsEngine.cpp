// GraphicsEngine.cpp: implementation of the GraphicsEngine class.
//
//////////////////////////////////////////////////////////////////////

#include "GraphicsEngine.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GraphicsEngine::GraphicsEngine()
{
	this->m_hWnd		 = NULL;
	this->m_hDC			 = NULL;
	this->m_hRC			 = NULL;
}

GraphicsEngine::~GraphicsEngine()
{
}

LRESULT GraphicsEngine::InitGraphics(HWND hWnd)
{
	this->m_hWnd = hWnd;

	if (this->m_hWnd != NULL)
	{
		this->m_hDC = ::GetWindowDC(this->m_hWnd);

		if (this->m_hDC != NULL)
		{
			if(InitPixelFormat() == TRUE)
			{
				this->m_hRC = ::wglCreateContext(this->m_hDC);

				if (this->m_hRC != NULL)
				{
					if (::wglMakeCurrent(this->m_hDC, this->m_hRC) == TRUE)
					{
						return TRUE;
					}
				}
			}
		}
	}

	return FALSE;
}

LRESULT GraphicsEngine::CloseGraphics()
{
	::wglMakeCurrent(NULL, NULL);

	if (this->m_hRC != NULL)
	{
		::wglDeleteContext(this->m_hRC);
	}
	
	if (this->m_hWnd != NULL && this->m_hDC != NULL)
	{
		ReleaseDC(this->m_hWnd, this->m_hDC);
	}

	return FALSE;
}

LRESULT GraphicsEngine::InitPixelFormat()
{
	PIXELFORMATDESCRIPTOR pfd;
	LRESULT format;
	
	ZeroMemory( &pfd, sizeof( pfd ) );
	pfd.nSize = sizeof( pfd );
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;
	
	format = ::ChoosePixelFormat(this->m_hDC, &pfd);

	if (format != NULL)
	{
		if (::SetPixelFormat(this->m_hDC, format, &pfd) == TRUE)
		{
			return TRUE;
		}
	}

	return FALSE;
}

void GraphicsEngine::SelectEngine()
{
	::wglMakeCurrent(this->m_hDC, this->m_hRC);
}

void GraphicsEngine::Swap()
{
	::SwapBuffers(this->m_hDC);
}

void GraphicsEngine::BeginFrame()
{
	::glPushMatrix();

	::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	::glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void GraphicsEngine::EndFrame()
{
	::glPopMatrix();
}