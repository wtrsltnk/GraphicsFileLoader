// GraphicsObjects.cpp: implementation of the GraphicsObjects class.
//
//////////////////////////////////////////////////////////////////////

#include "GraphicsObjects.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GraphicsObjects::GraphicsObjects()
{
}

GraphicsObjects::~GraphicsObjects()
{
}

void GraphicsObjects::StartRotate(float x, float y, float z)
{
	::glPushMatrix();
}

void GraphicsObjects::StartTranslate(float x, float y, float z)
{
	::glPushMatrix();
}

void GraphicsObjects::EndRotate()
{
	::glPopMatrix();
}

void GraphicsObjects::EndTranslate()
{
	::glPopMatrix();
}

void GraphicsObjects::RenderCube(float size)
{
	RenderBox(size, size, size);
}

void GraphicsObjects::RenderBox(float sizex, float sizey, float sizez)
{
}

void GraphicsObjects::RenderCone(float size, float radius)
{
}

void GraphicsObjects::RenderCylinder(float size, float radius)
{
}