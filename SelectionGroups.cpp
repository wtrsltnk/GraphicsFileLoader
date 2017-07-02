// SelectionGroups.cpp: implementation of the SelectionGroups class.
//
//////////////////////////////////////////////////////////////////////

#include "SelectionGroups.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SelectionGroups::SelectionGroups()
{
	this->nGroupCount = 0;
	this->nAllocCount = 0;
	this->pGroups = 0;
}

SelectionGroups::~SelectionGroups()
{
	Cleanup();
}

bool SelectionGroups::CheckSize(int newsize)
{
	if (newsize > this->nAllocCount)
	{
		StructureGroupPtr* tmp = new StructureGroupPtr[newsize + 10];

		for (int i = 0; i < this->nGroupCount; i++)
		{
			tmp[i] = this->pGroups[i];
		}

		for (int j = i; j < newsize + 10; j++)
		{
			tmp[j] = 0;
		}

		this->nAllocCount = newsize + 10;

		return true;
	}
	else if (newsize > 0 && newsize <= this->nAllocCount)
	{
		return true;
	}

	return false;
}

void SelectionGroups::SetCenter(float x, float y, float z)
{
	if (this->nGroupCount > 0)
	{
	}
}

void SelectionGroups::Move(float x, float y, float z)
{
	if (this->nGroupCount > 0)
	{
	}
}

void SelectionGroups::Rotate(float x, float y, float z)
{
	if (this->nGroupCount > 0)
	{
	}
}

void SelectionGroups::Size(float x, float y, float z)
{
	if (this->nGroupCount > 0)
	{
	}
}

void SelectionGroups::Cleanup()
{
	if (this->nGroupCount > 0)
	{
		delete [] this->pGroups;
		this->pGroups = 0;
		this->nGroupCount = 0;
		this->nAllocCount = 0;
	}
}

bool SelectionGroups::AddGroup(StructureGroup* group)
{
	if (group != 0)
	{
		if (CheckSize(this->nGroupCount + 1))
		{
			this->pGroups[this->nGroupCount] = group;
		}
		return true;
	}
	return false;
}