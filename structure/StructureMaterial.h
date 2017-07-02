// StructureMaterial.h: interface for the StructureMaterial class.
//
//////////////////////////////////////////////////////////////////////

#ifndef STRUCTUREMATERIAL_H
#define STRUCTUREMATERIAL_H

#include "IMaterial.h"

class StructureMaterial : public IMaterial  
{
private:
	static IModifier *modifier;

	friend class StructureSceneManager;

private:
	char strName[MAX_NAME];
	char strTexture[MAX_TEXTURE_PATH];
	float fAmbient[4];
	float fDiffuse[4];
	float fSpecular[4];
	float fEmissive[4];
	float fShininess;
	float fTransparency;
	char cFlag;

public:
	StructureMaterial();
	virtual ~StructureMaterial();

	void Set(IMaterial& material);

	IModifier& GetModifier();

	void SetName(const char name[MAX_NAME]);
	void GetName(char name[MAX_NAME]);

	void SetTexture(const char name[MAX_TEXTURE_PATH]);
	void GetTexture(char name[MAX_TEXTURE_PATH]);
		
	void SetAmbient(float r, float g, float b, float w);
	void GetAmbient(float& r, float& g, float& b, float& w);

	void SetDiffuse(float r, float g, float b, float w);
	void GetDiffuse(float& r, float& g, float& b, float& w);

	void SetSpecular(float r, float g, float b, float w);
	void GetSpecular(float& r, float& g, float& b, float& w);

	void SetEmissive(float r, float g, float b, float w);
	void GetEmissive(float& r, float& g, float& b, float& w);

	void SetShininess(float shininess);
	void GetShininess(float& shininess);

	void SetTransparency(float transparency);
	void GetTransparency(float& transparency);

	void SetFlag(char flag);
	void GetFlag(char& flag);
};

#endif
