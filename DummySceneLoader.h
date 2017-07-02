// DummySceneLoader.h: interface for the DummySceneLoader class.
//
//////////////////////////////////////////////////////////////////////

#ifndef DUMMYSCENELOADER_H
#define DUMMYSCENELOADER_H

#include "ISceneLoader.h"

class DummySceneLoader : public ISceneLoader  
{
public:
	DummySceneLoader();
	virtual ~DummySceneLoader();

	bool LoadScene(IScene& scene, const char filename[256]);
	bool SaveScene(IScene& scene, const char filename[256]);

};

#endif
