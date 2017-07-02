// StructureTriangle.cpp: implementation of the StructureTriangle class.
//
//////////////////////////////////////////////////////////////////////

#include "StructureTriangle.h"
#include "DummyModifier.h"

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////

IModifier* StructureTriangle::modifier = new DummyModifier();

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StructureTriangle::StructureTriangle()
{
	SetVertexIndexes(-1, -1, -1);
	SetTexCoords(-1, -1, -1);
	SetFlag(EMPTY_FLAG);
}

StructureTriangle::~StructureTriangle()
{
}

void StructureTriangle::Set(ITriangle& triangle)
{
	triangle.GetVertexIndexes(this->nVertex[0], this->nVertex[1], this->nVertex[2]);
	triangle.GetTexCoords(this->nTexCoord[0], this->nTexCoord[1], this->nTexCoord[2]);
	triangle.GetFlag(this->cFlag);
}

IModifier& StructureTriangle::GetModifier()
{
	return *modifier;
}

void StructureTriangle::SetVertexIndexes(int v1, int v2, int v3)
{
	this->nVertex[0] = v1;
	this->nVertex[1] = v2;
	this->nVertex[2] = v3;
}

void StructureTriangle::GetVertexIndexes(int& v1, int& v2, int& v3)
{
	v1 = this->nVertex[0];
	v2 = this->nVertex[1];
	v3 = this->nVertex[2];
}

void StructureTriangle::SetTexCoords(int t1, int t2, int t3)
{
	this->nTexCoord[0] = t1;
	this->nTexCoord[1] = t2;
	this->nTexCoord[2] = t3;
}

void StructureTriangle::GetTexCoords(int& t1, int& t2, int& t3)
{
	t1 = this->nTexCoord[0];
	t2 = this->nTexCoord[1];
	t3 = this->nTexCoord[2];
}

void StructureTriangle::SetFlag(char flag)
{
	this->cFlag = flag;
}

void StructureTriangle::GetFlag(char& flag)
{
	flag = this->cFlag;
}
