// StructureTexCoord.cpp: implementation of the StructureTexCoord class.
//
//////////////////////////////////////////////////////////////////////

#include "StructureTexCoord.h"
#include "DummyModifier.h"

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////

IModifier* StructureTexCoord::modifier = new DummyModifier();

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StructureTexCoord::StructureTexCoord()
{
	SetU(0.0f);
	SetV(0.0f);
	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	SetFlag(EMPTY_FLAG);
}

StructureTexCoord::~StructureTexCoord()
{
}

void StructureTexCoord::Set(ITexCoord& texcoord)
{
	texcoord.GetU(this->fU);
	texcoord.GetV(this->fV);
	texcoord.GetColor(this->fColor[0], this->fColor[1], this->fColor[2], this->fColor[3]);
	texcoord.GetFlag(this->cFlag);
}

IModifier& StructureTexCoord::GetModifier()
{
	return *modifier;
}
	
void StructureTexCoord::SetU(float u)
{
	this->fU = u;
}

void StructureTexCoord::GetU(float& u)
{
	u = this->fU;
}

void StructureTexCoord::SetV(float v)
{
	this->fV = v;
}

void StructureTexCoord::GetV(float& v)
{
	v = this->fV;
}

void StructureTexCoord::SetColor(float r, float g, float b, float w)
{
	this->fColor[0] = r;
	this->fColor[1] = g;
	this->fColor[2] = b;
	this->fColor[3] = w;
}

void StructureTexCoord::GetColor(float& r, float& g, float& b, float& w)
{
	r = this->fColor[0];
	g = this->fColor[1];
	b = this->fColor[2];
	w = this->fColor[3];
}

void StructureTexCoord::SetFlag(char flag)
{
	this->cFlag = flag;
}

void StructureTexCoord::GetFlag(char& flag)
{
	flag = this->cFlag;
}
