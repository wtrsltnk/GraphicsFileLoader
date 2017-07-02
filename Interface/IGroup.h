#ifndef IGROUP_H
#define IGROUP_H

#include "flag.h"

#include "ITriangle.h"
#include "IVertex.h"
#include "ITexCoord.h"
#include "IModifier.h"

class IGroup
{
public: virtual void		Set(IGroup& group) = 0;

public: virtual IModifier&	GetModifier() = 0;
		
public: virtual bool		SetTriangle(ITriangle& triangle, int index) = 0;
public: virtual bool		GetTriangle(ITriangle& triangle, int index) = 0;
		
public: virtual bool		SetVertex(IVertex& vertex, int index) = 0;
public: virtual bool		GetVertex(IVertex& vertex, int index) = 0;
		
public: virtual bool		SetTexCoord(ITexCoord& texcoord, int index) = 0;
public: virtual bool		GetTexCoord(ITexCoord& texcoord, int index) = 0;
		
public: virtual bool		SetMaterial(int materialindex) = 0;
public: virtual bool		GetMaterial(int& materialindex) = 0;

public: virtual void		SetFlag(char flag) = 0;
public: virtual void		GetFlag(char& flag) = 0;

public: virtual ITriangle*	GetNewTriangle() = 0;
public: virtual IVertex*	GetNewVertex() = 0;
public: virtual ITexCoord*	GetNewTexCoord() = 0;
};

#endif