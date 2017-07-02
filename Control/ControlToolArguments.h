// ControlToolArguments.h: interface for the ControlToolArguments class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CONTROLTOOLARGUMENTS_H
#define CONTROLTOOLARGUMENTS_H

#include "IToolArguments.h"
#include "GraphicsCamera.h"
#include "StructureScene.h"

class ControlToolArguments : public IToolArguments  
{
private:
	GraphicsCamera* camera;
	StructureScene* scene;

public:
	ControlToolArguments();
	virtual ~ControlToolArguments();

	ICamera* GetCamera();
	IScene* GetScene();
};

#endif
