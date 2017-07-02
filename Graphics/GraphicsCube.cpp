// GraphicsCube.cpp: implementation of the GraphicsCube class.
//
//////////////////////////////////////////////////////////////////////

#include "GraphicsCube.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GraphicsCube::GraphicsCube()
{
	this->m_fSize = 1.0f;
	this->m_fPositionX = 0.0f;
	this->m_fPositionY = 0.0f;
	this->m_fPositionZ = 0.0f;
}

GraphicsCube::GraphicsCube(float size)
{
	this->m_fSize = size;
	this->m_fPositionX = 0.0f;
	this->m_fPositionY = 0.0f;
	this->m_fPositionZ = 0.0f;
}

GraphicsCube::~GraphicsCube()
{
}

void GraphicsCube::Render()
{
	::glPushMatrix();

	::glBegin(GL_QUADS);
	// Front Face
	::glColor3f(1.0f, 0.0f, 0.0f);
	::glNormal3f( 0.0f, 0.0f, 1.0f);					// Normal Pointing Towards Viewer
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + -(m_fSize/2),	m_fPositionZ + m_fSize/2);
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + -(m_fSize/2),	m_fPositionZ + m_fSize/2);
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + m_fSize/2,		m_fPositionZ + m_fSize/2);
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + m_fSize/2,		m_fPositionZ + m_fSize/2);
// Back Face
	::glColor3f(1.0f, 1.0f, 0.0f);
	::glNormal3f( 0.0f, 0.0f,-1.0f);					// Normal Pointing Away From Viewer
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + -(m_fSize/2),	m_fPositionZ + -(m_fSize/2));
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + m_fSize/2,		m_fPositionZ + -(m_fSize/2));
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + m_fSize/2,		m_fPositionZ + -(m_fSize/2));
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + -(m_fSize/2),	m_fPositionZ + -(m_fSize/2));
	// Top Face
	::glColor3f(0.0f, 1.0f, 0.0f);
	::glNormal3f( 0.0f, 1.0f, 0.0f);					// Normal Pointing Up
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + m_fSize/2,		m_fPositionZ + -(m_fSize/2));
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + m_fSize/2,		m_fPositionZ + m_fSize/2);
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + m_fSize/2,		m_fPositionZ + m_fSize/2);
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + m_fSize/2,		m_fPositionZ + -(m_fSize/2));
	// Bottom Face
	::glColor3f(0.0f, 1.0f, 1.0f);
	::glNormal3f( 0.0f,-1.0f, 0.0f);					// Normal Pointing Down
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + -(m_fSize/2),	m_fPositionZ + -(m_fSize/2));
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + -(m_fSize/2),	m_fPositionZ + -(m_fSize/2));
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + -(m_fSize/2),	m_fPositionZ + m_fSize/2);
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + -(m_fSize/2),	m_fPositionZ + m_fSize/2);
	// Right face
	::glColor3f(0.0f, 0.0f, 1.0f);
	::glNormal3f( 1.0f, 0.0f, 0.0f);					// Normal Pointing Right
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + -(m_fSize/2),	m_fPositionZ + -(m_fSize/2));
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + m_fSize/2,		m_fPositionZ + -(m_fSize/2));
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + m_fSize/2,		m_fPositionZ + m_fSize/2);
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( m_fPositionX + m_fSize/2,		m_fPositionY + -(m_fSize/2),	m_fPositionZ + m_fSize/2);
	// Left Face
	::glColor3f(1.0f, 0.0f, 1.0f);
	::glNormal3f(-1.0f, 0.0f, 0.0f);					// Normal Pointing Left
	::glTexCoord2f(0.0f, 0.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + -(m_fSize/2),	m_fPositionZ + -(m_fSize/2));
	::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + -(m_fSize/2),	m_fPositionZ + m_fSize/2);
	::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + m_fSize/2,		m_fPositionZ + m_fSize/2);
	::glTexCoord2f(0.0f, 1.0f); ::glVertex3f( m_fPositionX + -(m_fSize/2),	m_fPositionY + m_fSize/2,		m_fPositionZ + -(m_fSize/2));

	::glEnd();

	::glPopMatrix();
}

void GraphicsCube::Move(float x, float y, float z)
{
	this->m_fPositionX += x;
	this->m_fPositionY += y;
	this->m_fPositionZ += z;
}

void GraphicsCube::SetSize(float size)
{
	this->m_fSize = size;
}
