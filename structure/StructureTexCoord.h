// StructureTexCoord.h: interface for the StructureTexCoord class.
//
//////////////////////////////////////////////////////////////////////

#ifndef STRUCTURETEXCOORD_H
#define STRUCTURETEXCOORD_H

#include "ITexCoord.h"

class StructureTexCoord : public ITexCoord
{
private:
	static IModifier *modifier;

	friend class StructureSceneManager;

private:
	float fU;
	float fV;
	float fColor[4];
	char cFlag;

public:
	StructureTexCoord();
	virtual ~StructureTexCoord();

	void Set(ITexCoord& texcoord);

	IModifier& GetModifier();
		
	void SetU(float u);
	void GetU(float& u);

	void SetV(float v);
	void GetV(float& v);

	void SetColor(float r, float g, float b, float w);
	void GetColor(float& r, float& g, float& b, float& w);

	void SetFlag(char flag);
	void GetFlag(char& flag);

};

#endif
