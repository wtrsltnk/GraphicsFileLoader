#ifndef IMATERIAL_H
#define IMATERIAL_H

#define MAX_NAME 64
#define MAX_TEXTURE_PATH 256

#include "flag.h"

#include "IModifier.h"

class IMaterial
{
public: virtual void		Set(IMaterial& material) = 0;

public: virtual IModifier&	GetModifier() = 0;

public: virtual void		SetName(const char name[MAX_NAME]) = 0;
public: virtual void		GetName(char name[MAX_NAME]) = 0;

public: virtual void		SetTexture(const char name[MAX_TEXTURE_PATH]) = 0;
public: virtual void		GetTexture(char name[MAX_TEXTURE_PATH]) = 0;
		
public: virtual void		SetAmbient(float r, float g, float b, float w) = 0;
public: virtual void		GetAmbient(float& r, float& g, float& b, float& w) = 0;

public: virtual void		SetDiffuse(float r, float g, float b, float w) = 0;
public: virtual void		GetDiffuse(float& r, float& g, float& b, float& w) = 0;

public: virtual void		SetSpecular(float r, float g, float b, float w) = 0;
public: virtual void		GetSpecular(float& r, float& g, float& b, float& w) = 0;

public: virtual void		SetEmissive(float r, float g, float b, float w) = 0;
public: virtual void		GetEmissive(float& r, float& g, float& b, float& w) = 0;

public: virtual void		SetShininess(float shininess) = 0;
public: virtual void		GetShininess(float& shininess) = 0;

public: virtual void		SetTransparency(float transparency) = 0;
public: virtual void		GetTransparency(float& transparency) = 0;

public: virtual void		SetFlag(char flag) = 0;
public: virtual void		GetFlag(char& flag) = 0;
};

#endif