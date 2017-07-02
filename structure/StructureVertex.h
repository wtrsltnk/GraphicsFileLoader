// StructureVertex.h: interface for the StructureVertex class.
//
//////////////////////////////////////////////////////////////////////

#ifndef STRUCTUREVERTEX_H
#define STRUCTUREVERTEX_H

#include "IVertex.h"

class StructureVertex : public IVertex  
{
private:
	static IModifier *modifier;

	friend class StructureSceneManager;

private:
	float fPositionX, fPositionY, fPositionZ;
	int nBoneIndex;
	char cFlag;

public:
	StructureVertex();
	virtual ~StructureVertex();

	void Set(IVertex& vertex);

	IModifier& GetModifier();

	void SetPosition(float x, float y, float z);
	void GetPosition(float& x, float& y, float& z);

	void SetBoneIndex(int index);
	void GetBoneIndex(int& index);

	void SetFlag(char flag);
	void GetFlag(char& flag);

};

#endif
