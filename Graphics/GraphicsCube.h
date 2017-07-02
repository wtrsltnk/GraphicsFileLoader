// GraphicsCube.h: interface for the GraphicsCube class.
//
//////////////////////////////////////////////////////////////////////

#ifndef GRAPHICSCUBE_H
#define GRAPHICSCUBE_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

class GraphicsCube  
{
protected:
	float m_fSize;
	float m_fPositionX;
	float m_fPositionY;
	float m_fPositionZ;

public:
	GraphicsCube();
	GraphicsCube(float size);
	virtual ~GraphicsCube();

	void Render();

	void Move(float x, float y, float z);
	void SetSize(float size);

};

#endif
