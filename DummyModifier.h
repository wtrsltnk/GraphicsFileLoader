// DummyModifier.h: interface for the DummyModifier class.
//
//////////////////////////////////////////////////////////////////////

#ifndef DUMMYMODIFIER_H
#define DUMMYMODIFIER_H

#include "IModifier.h"

class DummyModifier : public IModifier  
{
public:
	DummyModifier();
	virtual ~DummyModifier();

	void SetCenter(float x, float y, float z);
	void Move(float x, float y, float z);
	void Rotate(float x, float y, float z);
	void Size(float x, float y, float z);

};

#endif
