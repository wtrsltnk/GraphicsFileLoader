#ifndef ITOOLARGUMENTS_H
#define ITOOLARGUMENTS_H

#include "ICamera.h"
#include "IScene.h"

class IToolArguments
{
public: virtual ICamera*		GetCamera() = 0;
public: virtual IScene*			GetScene() = 0;
};

#endif