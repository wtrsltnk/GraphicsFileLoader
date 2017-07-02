#ifndef ISCENELOADER_H
#define ISCENELOADER_H

#include "IScene.h"

class ISceneLoader
{
public: virtual bool		LoadScene(IScene& scene, const char filename[256]) = 0;
public: virtual bool		SaveScene(IScene& scene, const char filename[256]) = 0;
};

#endif