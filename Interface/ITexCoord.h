#ifndef ITEXCOORD_H
#define ITEXCOORD_H

#include "flag.h"

#include "IModifier.h"

class ITexCoord
{
public: virtual void		Set(ITexCoord& texcoord) = 0;

public: virtual IModifier&	GetModifier() = 0;
		
public: virtual void		SetU(float u) = 0;
public: virtual void		GetU(float& u) = 0;

public: virtual void		SetV(float v) = 0;
public: virtual void		GetV(float& v) = 0;

public: virtual void		SetColor(float r, float g, float b, float w) = 0;
public: virtual void		GetColor(float& r, float& g, float& b, float& w) = 0;

public: virtual void		SetFlag(char flag) = 0;
public: virtual void		GetFlag(char& flag) = 0;
};
#endif