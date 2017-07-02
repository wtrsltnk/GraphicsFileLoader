// ontrolSelectionTool.h: interface for the ControlSelectionTool class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CONTROLSELECTIONTOOL_H
#define CONTROLSELECTIONTOOL_H

#include "ITool.h"

class ControlSelectionTool : public ITool
{
private:
	bool m_bInitialized;
	IToolArguments* m_Args;

public:
	ControlSelectionTool();
	virtual ~ControlSelectionTool();

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
