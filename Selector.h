// Selector.h: interface for the Selector class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SELECTOR_H
#define SELECTOR_H

#include "SelectionGroups.h"

#define MAX_BUFFER 512

class Selector  
{
private:
	unsigned int uiSelectionBuffer[MAX_BUFFER];

public:
	Selector();
	virtual ~Selector();

	bool SetupSelector(float x, float y);
	bool GatherGroups(SelectionGroups& group);

};

#endif
