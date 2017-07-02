#ifndef ITRIANGLE_H
#define ITRIANGLE_H

#include "flag.h"

#include "IModifier.h"

class ITriangle
{
public: virtual void		Set(ITriangle& triangle) = 0;

public: virtual IModifier&	GetModifier() = 0;

public: virtual void		SetVertexIndexes(int v1, int v2, int v3) = 0;
public: virtual void		GetVertexIndexes(int& v1, int& v2, int& v3) = 0;

public: virtual void		SetTexCoords(int t1, int t2, int t3) = 0;
public: virtual void		GetTexCoords(int& t1, int& t2, int& t3) = 0;

public: virtual void		SetFlag(char flag) = 0;
public: virtual void		GetFlag(char& flag) = 0;
};

#endif