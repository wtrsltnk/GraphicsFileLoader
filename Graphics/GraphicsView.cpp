// GraphicsView.cpp: implementation of the GraphicsView class.
//
//////////////////////////////////////////////////////////////////////

#include "GraphicsView.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GraphicsView::GraphicsView()
{
	this->m_nX				 = 0;
	this->m_nY				 = 0;
	this->m_nWidth			 = 100;
	this->m_nHeight			 = 100;
	this->m_fAspect			 = 1.0f;
	this->m_fFOV			 = 45.0f;
	this->m_fNear			 = 0.1f;
	this->m_fFar			 = 100.0f;
}

GraphicsView::~GraphicsView()
{
}

LRESULT GraphicsView::InitView(int x, int y, int width, int height)
{
	this->m_nX = x;
	this->m_nY = y;
	this->m_nWidth = width;
	if (height > 0)
	{
		this->m_nHeight = height;
	}
	this->m_fAspect = (float)this->m_nWidth / (float)this->m_nHeight;

	return TRUE;
}

LRESULT GraphicsView::Resize(int width, int height)
{
	this->m_nWidth = width;
	if (height > 0)
	{
		this->m_nHeight = height;
	}
	this->m_fAspect = (float)this->m_nWidth / (float)this->m_nHeight;

	return TRUE;
}

LRESULT GraphicsView::Move(int x, int y)
{
	this->m_nX = x;
	this->m_nY = y;

	return TRUE;
}

LRESULT GraphicsView::Setup3D()
{
	::glViewport(this->m_nX, this->m_nY, this->m_nWidth, this->m_nHeight);
	
	::glMatrixMode(GL_PROJECTION);			
	::glLoadIdentity();

	::gluPerspective(this->m_fFOV, this->m_fAspect, this->m_fNear, this->m_fFar);

	::glMatrixMode(GL_MODELVIEW);
	::glLoadIdentity();

	::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	::glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	return TRUE;
}

LRESULT GraphicsView::Setup2D()
{
	::glViewport(this->m_nX, this->m_nY, this->m_nWidth, this->m_nHeight);
	
	::glMatrixMode(GL_PROJECTION);			
	::glLoadIdentity();

    ::gluOrtho2D(0.0, (GLdouble)this->m_nWidth, 0.0, (GLdouble)this->m_nHeight);

	::glMatrixMode(GL_MODELVIEW);
	::glLoadIdentity();

	::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	::glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	return TRUE;
}
