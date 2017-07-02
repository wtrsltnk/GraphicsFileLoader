// GraphicsCamera.h: interface for the GraphicsCamera class.
//
//////////////////////////////////////////////////////////////////////

#ifndef GRAPHICSCAMERA_H
#define GRAPHICSCAMERA_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "MathLib.h"

#include "ICamera.h"

class GraphicsCamera : public ICamera
{
protected:
	Matrix viewMatrix;
	Vector position;

	float pitch;
	float roll;
	float yaw;

	float frameInterval;

	void BuildViewmatrix();
	void CalculateFrameInterval();
	float GetFrameInterval();

public:
	GraphicsCamera();
	virtual ~GraphicsCamera();

	void Setup();
	void Move(float front, float right, float up);
	void Rotate(float pitch, float roll, float yaw);
};

#endif
