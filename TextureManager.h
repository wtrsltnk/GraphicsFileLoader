// TextureManager.h: interface for the TextureManager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "IMaterial.h"

struct TextureIndex
{
	char texturename[MAX_TEXTURE_PATH];
	int textureindex;
};

class TextureManager  
{
private:
	static TextureManager* pManager;

public:
	static TextureManager* GetInstance();

private:
	int nTextureCount;
	int nAllocCount;
	TextureIndex* pTextures;

	TextureManager();
	virtual ~TextureManager();

	bool FittArray(int count);
	int Uploadtexture(const char texture[MAX_TEXTURE_PATH]);

public:
	bool LoadTexture(const char texture[MAX_TEXTURE_PATH]);
	int GetTextureIndex(const char texture[MAX_TEXTURE_PATH]);

};

#endif
