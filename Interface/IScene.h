#ifndef ISCENE_H
#define ISCENE_H

#include "flag.h"

#include "IGroup.h"
#include "IMaterial.h"
#include "IModifier.h"

class IScene
{
public: virtual void		Set(IScene& scene) = 0;

public: virtual IModifier&	GetModifier() = 0;
		
public: virtual bool		SetGroup(IGroup& group, int index) = 0;
public: virtual bool		GetGroup(IGroup& group, int index) = 0;
		
public: virtual bool		SetMaterial(IMaterial& material, int index) = 0;
public: virtual bool		GetMaterial(IMaterial& material, int index) = 0;

public: virtual void		SetFlag(char flag) = 0;
public: virtual void		GetFlag(char& flag) = 0;

public: virtual IGroup*		GetNewGroup() = 0;
public: virtual IMaterial*	GetNewMaterial() = 0;
};

#endif