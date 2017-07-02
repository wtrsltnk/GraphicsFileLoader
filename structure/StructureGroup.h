// StructureGroup.h: interface for the StructureGroup class.
//
//////////////////////////////////////////////////////////////////////

#ifndef STRUCTUREGROUP_H
#define STRUCTUREGROUP_H

#include "IGroup.h"
#include "StructureTriangle.h"
#include "StructureVertex.h"
#include "StructureTexCoord.h"

class StructureGroup : public IGroup
{
private:
	static IModifier *modifier;

	friend class StructureSceneManager;

private:
	int nTriangleCount;
	StructureTriangle* pTriangles;
	int nVertexCount;
	StructureVertex* pVertices;
	int nTexCoordCount;
	StructureTexCoord* pTexCoords;
	int nMaterialIndex;
	char cFlag;

	void CleanUp();

public:
	StructureGroup();
	virtual ~StructureGroup();

	void Set(IGroup& group);

	IModifier& GetModifier();
		
	bool SetTriangle(ITriangle& triangle, int index);
	bool GetTriangle(ITriangle& triangle, int index);
		
	bool SetVertex(IVertex& vertex, int index);
	bool GetVertex(IVertex& vertex, int index);
		
	bool SetTexCoord(ITexCoord& texcoord, int index);
	bool GetTexCoord(ITexCoord& texcoord, int index);
		
	bool SetMaterial(int materialindex);
	bool GetMaterial(int& materialindex);

	void SetFlag(char flag);
	void GetFlag(char& flag);

	ITriangle* GetNewTriangle();
	IVertex* GetNewVertex();
	ITexCoord* GetNewTexCoord();

};

typedef StructureGroup* StructureGroupPtr;

#endif
