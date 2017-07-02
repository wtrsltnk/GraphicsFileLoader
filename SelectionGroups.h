// SelectionGroups.h: interface for the SelectionGroups class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SELECTIONGROUPS_H
#define SELECTIONGROUPS_H

#include "ISelection.h"
#include "StructureGroup.h"

class SelectionGroups : public ISelection  
{
private:
	int nGroupCount;
	int nAllocCount;
	StructureGroupPtr* pGroups;

	bool CheckSize(int newsize);

public:
	SelectionGroups();
	virtual ~SelectionGroups();

	void SetCenter(float x, float y, float z);
	void Move(float x, float y, float z);
	void Rotate(float x, float y, float z);
	void Size(float x, float y, float z);

	void Cleanup();
	bool AddGroup(StructureGroup* group);

};

#endif
