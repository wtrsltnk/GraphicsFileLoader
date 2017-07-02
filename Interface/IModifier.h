#ifndef IMODIFIER_H
#define IMODIFIER_H

class IModifier
{
public: virtual void		SetCenter(float x, float y, float z) = 0;
public: virtual void		Move(float x, float y, float z) = 0;
public: virtual void		Rotate(float x, float y, float z) = 0;
public: virtual void		Size(float x, float y, float z) = 0;
};

#endif