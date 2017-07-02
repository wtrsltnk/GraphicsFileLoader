#ifndef ISELECTION_H
#define ISELECTION_H

class ISelection
{
public: virtual void		SetCenter(float x, float y, float z) = 0;
public: virtual void		Move(float x, float y, float z) = 0;
public: virtual void		Rotate(float x, float y, float z) = 0;
public: virtual void		Size(float x, float y, float z) = 0;
};

#endif