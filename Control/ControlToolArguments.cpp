// ControlToolArguments.cpp: implementation of the ControlToolArguments class.
//
//////////////////////////////////////////////////////////////////////

#include "ControlToolArguments.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ControlToolArguments::ControlToolArguments()
{
	this->camera = new GraphicsCamera();
	this->scene = 0;
}

ControlToolArguments::~ControlToolArguments()
{
	delete this->camera;
}

ICamera* ControlToolArguments::GetCamera()
{
	return this->camera;
}

IScene* ControlToolArguments::GetScene()
{
	return this->scene;
}
