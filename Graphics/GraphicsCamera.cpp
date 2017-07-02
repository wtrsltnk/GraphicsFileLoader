// GraphicsCamera.cpp: implementation of the GraphicsCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "GraphicsCamera.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GraphicsCamera::GraphicsCamera()
{
	this->viewMatrix.FillIndenity();
	this->position.Fill(0.0f, 0.0f, 0.0f);

	this->pitch = 0.0f;
	this->roll = 0.0f;
	this->yaw = 0.0f;
}

GraphicsCamera::~GraphicsCamera()
{
}

void GraphicsCamera::BuildViewmatrix()
{
	Matrix p, r, y, pos;

	p.MatrixRotateXDeg(this->pitch);
	r.MatrixRotateYDeg(this->roll);
	y.MatrixRotateZDeg(this->yaw);

	pos.MatrixTranslate(this->position);

	this->viewMatrix = p * r * y * pos;
}

void GraphicsCamera::Setup()
{
	BuildViewmatrix();
	this->viewMatrix.MatrixTranspose();

	::glLoadMatrixf(this->viewMatrix.Get());
}

void GraphicsCamera::CalculateFrameInterval()
{
	static float frameTime = 0;
    float currentTime;

	currentTime = (float)GetTickCount() / 100;	

 	this->frameInterval = currentTime - frameTime;

	frameTime = currentTime;
}

float GraphicsCamera::GetFrameInterval()
{
	return this->frameInterval;
}

void GraphicsCamera::Move(float front, float right, float up)
{
	if (front != 0)
	{
		this->position.X += this->viewMatrix.At(0, 2) * front;
		this->position.Y += this->viewMatrix.At(1, 2) * front;
		this->position.Z += this->viewMatrix.At(2, 2) * front;
	}
	if (right != 0)
	{
		this->position.X += this->viewMatrix.At(0, 0) * right;
		this->position.Y += this->viewMatrix.At(1, 0) * right;
		this->position.Z += this->viewMatrix.At(2, 0) * right;
	}
	if (up != 0)
	{
		this->position.X += this->viewMatrix.At(0, 1) * up;
		this->position.Y += this->viewMatrix.At(1, 1) * up;
		this->position.Z += this->viewMatrix.At(2, 1) * up;
	}
}

void GraphicsCamera::Rotate(float pitch, float roll, float yaw)
{
	if (pitch != 0)
	{
		this->pitch += pitch;
		if (this->pitch > 90)
			this->pitch = 90;
		else if (this->pitch < -90)
			this->pitch = -90;
	}
	if (roll != 0)
	{
		this->roll += roll;
	}
	if (yaw != 0)
	{
		this->yaw += yaw;
	}

	BuildViewmatrix();
}