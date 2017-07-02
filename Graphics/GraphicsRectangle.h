// GraphicsRectangle.h: interface for the GraphicsRectangle class.
//
//////////////////////////////////////////////////////////////////////

#ifndef GRAPHICSRECTANGLE_H
#define GRAPHICSRECTANGLE_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

class GraphicsRectangle  
{
protected:
	int m_nX;
	int m_nY;
	int m_nWidth;
	int m_nHeight;
	float m_fColor[3];
	float m_fOpacity;

public:
	GraphicsRectangle();
	virtual ~GraphicsRectangle();

	void Init(int x, int y, int w, int h, float c[3], float o);
	void Draw();

};

#endif
