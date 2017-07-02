#ifndef IVERTEX_H
#define IVERTEX_H

#include "flag.h"

#include "IModifier.h"

class IVertex
{
public: virtual void		Set(IVertex& vertex) = 0;

public: virtual IModifier&	GetModifier() = 0;

public: virtual void		SetPosition(float x, float y, float z) = 0;
public: virtual void		GetPosition(float& x, float& y, float& z) = 0;

public: virtual void		SetBoneIndex(int index) = 0;
public: virtual void		GetBoneIndex(int& index) = 0;

public: virtual void		SetFlag(char flag) = 0;
public: virtual void		GetFlag(char& flag) = 0;
};

#endif