// StructureVertex.cpp: implementation of the StructureVertex class.
//
//////////////////////////////////////////////////////////////////////

#include "StructureVertex.h"
#include "DummyModifier.h"

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////

IModifier* StructureVertex::modifier = new DummyModifier();

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StructureVertex::StructureVertex()
{
	SetPosition(0.0f, 0.0f, 0.0f);
	SetBoneIndex(-1);
	SetFlag(EMPTY_FLAG);
}

StructureVertex::~StructureVertex()
{
}

void StructureVertex::Set(IVertex& vertex)
{
	vertex.GetPosition(this->fPositionX, this->fPositionY, this->fPositionZ);
	vertex.GetBoneIndex(this->nBoneIndex);
	vertex.GetFlag(this->cFlag);
}

IModifier& StructureVertex::GetModifier()
{
	return *modifier;
}

void StructureVertex::SetPosition(float x, float y, float z)
{
	this->fPositionX = x;
	this->fPositionY = y;
	this->fPositionZ = z;
}

void StructureVertex::GetPosition(float& x, float& y, float& z)
{
	x = this->fPositionX;
	y = this->fPositionY;
	z = this->fPositionZ;
}

void StructureVertex::SetBoneIndex(int index)
{
	this->nBoneIndex = index;
}

void StructureVertex::GetBoneIndex(int& index)
{
	index = this->nBoneIndex;
}

void StructureVertex::SetFlag(char flag)
{
	this->cFlag = flag;
}

void StructureVertex::GetFlag(char& flag)
{
	flag = this->cFlag;
}