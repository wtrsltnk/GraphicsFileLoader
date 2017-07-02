// ControlCameraTool.h: interface for the ControlCameraTool class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CONTROLCAMERATOOL_H
#define CONTROLCAMERATOOL_H

#include "ITool.h"

class ControlCameraTool : public ITool
{
protected:
	bool m_bInitialized;
	IToolArguments* m_Args;
	bool m_bKeyStatus[255];

	int m_iPrevX;
	int m_iPrevY;

public:
	ControlCameraTool();
	virtual ~ControlCameraTool();


// Implementation from 
//		IControlTool
public:
	void Initialize(IToolArguments& args);
	void Update();

	void OnLButtonDown(int x, int y, int key);
	void OnRButtonDown(int x, int y, int key);
	void OnMButtonDown(int x, int y, int key);

	void OnLButtonUp(int x, int y, int key);
	void OnRButtonUp(int x, int y, int key);
	void OnMButtonUp(int x, int y, int key);

	void OnMouseMove(int x, int y, int key);
	void OnKeyDown(int key);
	void OnKeyUp(int key);
};

#endif
