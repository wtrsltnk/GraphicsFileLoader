// GraphicsRectangle.cpp: implementation of the GraphicsRectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "GraphicsRectangle.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GraphicsRectangle::GraphicsRectangle()
{
	this->m_nX = 0;
	this->m_nY = 0;
	this->m_nWidth = 100;
	this->m_nHeight = 10;
	this->m_fColor[0] = 1.0f;
	this->m_fColor[1] = 1.0f;
	this->m_fColor[2] = 1.0f;
	this->m_fOpacity = 1.0f;
}

GraphicsRectangle::~GraphicsRectangle()
{
}

void GraphicsRectangle::Init(int x, int y, int w, int h, float c[3], float o)
{
	this->m_nX = x;
	this->m_nY = y;
	this->m_nWidth = w;
	this->m_nHeight = h;
	this->m_fColor[0] = c[0];
	this->m_fColor[1] = c[1];
	this->m_fColor[2] = c[2];
	this->m_fOpacity = o;
}

void GraphicsRectangle::Draw()
{
	::glEnable (GL_BLEND);
	::glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	::glColor4f(this->m_fColor[0], this->m_fColor[1], this->m_fColor[2], this->m_fOpacity);
	::glRecti(this->m_nX, this->m_nY, this->m_nX + this->m_nWidth, this->m_nY + this->m_nHeight);
}