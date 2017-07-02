// GraphicsEngine.h: interface for the GraphicsEngine class.
//
//////////////////////////////////////////////////////////////////////

#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

class GraphicsEngine  
{
protected:
	HWND m_hWnd;
	HDC m_hDC;
	HGLRC m_hRC;

protected:
	LRESULT InitPixelFormat();

public:
	GraphicsEngine();
	virtual ~GraphicsEngine();

	LRESULT InitGraphics(HWND hWnd);
	LRESULT CloseGraphics();

	void SelectEngine();
	void Swap();

	void BeginFrame();
	void EndFrame();

};

#endif
