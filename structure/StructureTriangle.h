// StructureTriangle.h: interface for the StructureTriangle class.
//
//////////////////////////////////////////////////////////////////////

#ifndef STRUCTURETRIANGLE_H
#define STRUCTURETRIANGLE_H

#include "ITriangle.h"

class StructureTriangle : public ITriangle  
{
private:
	static IModifier *modifier;

	friend class StructureSceneManager;

private:
	int nVertex[3];
	int nTexCoord[3];
	char cFlag;

public:
	StructureTriangle();
	virtual ~StructureTriangle();

	void Set(ITriangle& tirangle);

	IModifier& GetModifier();

	void SetVertexIndexes(int v1, int v2, int v3);
	void GetVertexIndexes(int& v1, int& v2, int& v3);

	void SetTexCoords(int t1, int t2, int t3);
	void GetTexCoords(int& t1, int& t2, int& t3);

	void SetFlag(char flag);
	void GetFlag(char& flag);

};

#endif
