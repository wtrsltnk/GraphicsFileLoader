// StructureSceneManager.h: interface for the StructureSceneManager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef STRUCTURESCENEMANAGER_H
#define STRUCTURESCENEMANAGER_H

#include "StructureScene.h"
#include "SelectionGroups.h"
#include "Selector.h"

#include "ISceneLoader.h"
#include "ISelection.h"

class StructureSceneManager
{
private:
	StructureScene scene;
	SelectionGroups selectionGroup;

public:
	StructureSceneManager();
	virtual ~StructureSceneManager();

	IScene& GetScene();
	bool LoadScene(ISceneLoader& sceneloader, const char filename[256]);
	void NewScene();
	void Render();
	bool Select(ISelection** selection, int x, int y);

};

#endif
