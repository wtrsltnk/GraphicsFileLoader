// GraphicsView.h: interface for the GraphicsView class.
//
//////////////////////////////////////////////////////////////////////

#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

class GraphicsView  
{
protected:
	int m_nX;
	int m_nY;
	int m_nWidth;
	int m_nHeight;
	float m_fAspect;
	float m_fFOV;
	float m_fNear;
	float m_fFar;

public:
	GraphicsView();
	virtual ~GraphicsView();

	LRESULT InitView(int x, int y, int width, int height);
	LRESULT Resize(int width, int height);
	LRESULT Move(int x, int y);

	LRESULT Setup3D();
	LRESULT Setup2D();

	int X() { return this->m_nX; };
	int Y() { return this->m_nY; };
	int Width() { return this->m_nWidth; };
	int Height() { return this->m_nHeight; };
	float Aspect() { return this->m_fAspect; };
	float FOV() { return this->m_fFOV; };
	float Near() { return this->m_fNear; };
	float Far() { return this->m_fFar; };
};

#endif
