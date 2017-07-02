#ifndef ITOOL_H
#define ITOOL_H

#include "IToolArguments.h"

class ITool
{
public: virtual void		Initialize(IToolArguments& args) = 0;
public: virtual void		Update() = 0;

public: virtual void		OnLButtonDown(int x, int y, int key) = 0;
public: virtual void		OnRButtonDown(int x, int y, int key) = 0;
public: virtual void		OnMButtonDown(int x, int y, int key) = 0;

public: virtual void		OnLButtonUp(int x, int y, int key) = 0;
public: virtual void		OnRButtonUp(int x, int y, int key) = 0;
public: virtual void		OnMButtonUp(int x, int y, int key) = 0;

public: virtual void		OnMouseMove(int x, int y, int key) = 0;
public: virtual void		OnKeyDown(int key) = 0;
public: virtual void		OnKeyUp(int key) = 0;
};

#endif