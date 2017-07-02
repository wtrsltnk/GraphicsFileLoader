#ifndef IPOINT_H
#define IPOINT_H

class IPoint
{
public: virtual void		SetPosition(int x, int y, int z) = 0;
public: virtual void		GetPosition(int& x, int& y, int& z) = 0;
public: virtual void		SetNormal(int x, int y, int z) = 0;
public: virtual void		GetNormal(int& x, int& y, int& z) = 0;
};

#endif