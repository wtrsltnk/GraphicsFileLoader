// StructureMaterial.cpp: implementation of the StructureMaterial class.
//
//////////////////////////////////////////////////////////////////////

#include "StructureMaterial.h"
#include "DummyModifier.h"

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////

IModifier* StructureMaterial::modifier = new DummyModifier();

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StructureMaterial::StructureMaterial()
{
	for (int i = 0; i < MAX_NAME; i++)
		this->strName[i] = '\0';

	for (int j = 0; j < MAX_TEXTURE_PATH; j++)
		this->strTexture[j] = '\0';

	SetAmbient(1.0f, 1.0f, 1.0f, 1.0f);
	SetDiffuse(1.0f, 1.0f, 1.0f, 1.0f);
	SetSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	SetEmissive(1.0f, 1.0f, 1.0f, 1.0f);
	SetShininess(0.0f);
	SetTransparency(0.0f);
	SetFlag(EMPTY_FLAG);
}

StructureMaterial::~StructureMaterial()
{
}

void StructureMaterial::Set(IMaterial& material)
{
	material.GetName(this->strName);
	material.GetTexture(this->strTexture);
	material.GetAmbient(this->fAmbient[0], this->fAmbient[1], this->fAmbient[2], this->fAmbient[3]);
	material.GetDiffuse(this->fDiffuse[0], this->fDiffuse[1], this->fDiffuse[2], this->fDiffuse[3]);
	material.GetSpecular(this->fSpecular[0], this->fSpecular[1], this->fSpecular[2], this->fSpecular[3]);
	material.GetEmissive(this->fEmissive[0], this->fEmissive[1], this->fEmissive[2], this->fEmissive[3]);
	material.GetShininess(this->fShininess);
	material.GetTransparency(this->fTransparency);
	material.GetFlag(this->cFlag);
}

IModifier& StructureMaterial::GetModifier()
{
	return *modifier;
}

void StructureMaterial::SetName(const char name[MAX_NAME])
{
	for (int i = 0; i < MAX_NAME; i++)
	{
		this->strName[i] = name[i];
		if (name[i] == '\0')
			break;
	}
}

void StructureMaterial::GetName(char name[MAX_NAME])
{
	for (int i = 0; i < MAX_NAME; i++)
	{
		name[i] = this->strName[i];
		if (this->strName[i] == '\0')
			break;
	}
}

void StructureMaterial::SetTexture(const char name[MAX_TEXTURE_PATH])
{
	for (int i = 0; i < MAX_NAME; i++)
	{
		this->strTexture[i] = name[i];
		if (name[i] == '\0')
			break;
	}
}

void StructureMaterial::GetTexture(char name[MAX_TEXTURE_PATH])
{
	for (int i = 0; i < MAX_NAME; i++)
	{
		name[i] = this->strTexture[i];
		if (this->strTexture[i] == '\0')
			break;
	}
}
	
void StructureMaterial::SetAmbient(float r, float g, float b, float w)
{
	this->fAmbient[0] = r;
	this->fAmbient[1] = g;
	this->fAmbient[2] = b;
	this->fAmbient[3] = w;
}

void StructureMaterial::GetAmbient(float& r, float& g, float& b, float& w)
{
	r = this->fAmbient[0];
	g = this->fAmbient[1];
	b = this->fAmbient[2];
	w = this->fAmbient[3];
}

void StructureMaterial::SetDiffuse(float r, float g, float b, float w)
{
	this->fDiffuse[0] = r;
	this->fDiffuse[1] = g;
	this->fDiffuse[2] = b;
	this->fDiffuse[3] = w;
}

void StructureMaterial::GetDiffuse(float& r, float& g, float& b, float& w)
{
	r = this->fDiffuse[0];
	g = this->fDiffuse[1];
	b = this->fDiffuse[2];
	w = this->fDiffuse[3];
}

void StructureMaterial::SetSpecular(float r, float g, float b, float w)
{
	this->fSpecular[0] = r;
	this->fSpecular[1] = g;
	this->fSpecular[2] = b;
	this->fSpecular[3] = w;
}

void StructureMaterial::GetSpecular(float& r, float& g, float& b, float& w)
{
	r = this->fSpecular[0];
	g = this->fSpecular[1];
	b = this->fSpecular[2];
	w = this->fSpecular[3];
}

void StructureMaterial::SetEmissive(float r, float g, float b, float w)
{
	this->fEmissive[0] = r;
	this->fEmissive[1] = g;
	this->fEmissive[2] = b;
	this->fEmissive[3] = w;
}

void StructureMaterial::GetEmissive(float& r, float& g, float& b, float& w)
{
	r = this->fEmissive[0];
	g = this->fEmissive[1];
	b = this->fEmissive[2];
	w = this->fEmissive[3];
}

void StructureMaterial::SetShininess(float shininess)
{
	this->fShininess = shininess;
}

void StructureMaterial::GetShininess(float& shininess)
{
	shininess = this->fShininess;
}

void StructureMaterial::SetTransparency(float transparency)
{
	this->fTransparency = transparency;
}

void StructureMaterial::GetTransparency(float& transparency)
{
	transparency = this->fTransparency;
}

void StructureMaterial::SetFlag(char flag)
{
	this->cFlag = flag;
}

void StructureMaterial::GetFlag(char& flag)
{
	flag = this->cFlag;
}
