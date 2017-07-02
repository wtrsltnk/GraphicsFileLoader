// HoofdScherm.h: interface for the HoofdScherm class.
//
//////////////////////////////////////////////////////////////////////

#ifndef HOOFDSCHERM_H
#define HOOFDSCHERM_H

#include "Scherm.h"
#include "ControlCameraTool.h"
#include "ControlToolArguments.h"
#include "GraphicsCamera.h"
#include "GraphicsCube.h"
#include "GraphicsEngine.h"
#include "GraphicsRectangle.h"
#include "GraphicsView.h"
#include "StructureSceneManager.h"

class HoofdScherm : public Scherm  
{
private:
	LRESULT SchermProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	ControlCameraTool cameratool;
	ControlToolArguments args;
	StructureSceneManager manager;

	GraphicsCamera camera;
	GraphicsCube cube;
	GraphicsEngine engine;
	GraphicsView view3d;
	GraphicsView view2d;

public:
	HoofdScherm();
	virtual ~HoofdScherm();

};

#endif
