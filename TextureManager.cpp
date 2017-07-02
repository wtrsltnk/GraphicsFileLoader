// TextureManager.cpp: implementation of the TextureManager class.
//
//////////////////////////////////////////////////////////////////////

#include "TextureManager.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////

TextureManager* TextureManager::pManager = 0;

TextureManager* TextureManager::GetInstance()
{
	if (TextureManager::pManager == 0)
		TextureManager::pManager = new TextureManager();

	return TextureManager::pManager;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TextureManager::TextureManager()
{
	this->nTextureCount = 0;
	this->pTextures = 0;
}

TextureManager::~TextureManager()
{
	if (this->nTextureCount > 0)
	{
		delete this->pTextures;
		this->pTextures = 0;
		this->nTextureCount = 0;
	}
}

bool TextureManager::FittArray(int count)
{
	if (count < this->nAllocCount)
	{
		return true;
	}
	else if (count > 0)
	{
		TextureIndex* tmp = new TextureIndex[count + 10];

		if (tmp)
		{
			memcpy(tmp, this->pTextures, sizeof(TextureIndex) * this->nTextureCount);

			delete this->pTextures;
			this->pTextures = 0;
			this->nAllocCount = count + 10;
			
			return true;
		}
	}

	return false;
}

int TextureManager::Uploadtexture(const char texture[MAX_TEXTURE_PATH])
{
	return -1;
}

bool TextureManager::LoadTexture(const char texture[MAX_TEXTURE_PATH])
{
	if (FittArray(this->nTextureCount + 1))
	{
		this->pTextures[this->nTextureCount].textureindex = Uploadtexture(texture);
		strcpy(this->pTextures[this->nTextureCount].texturename, texture);
	}
	return false;
}

int TextureManager::GetTextureIndex(const char texture[MAX_TEXTURE_PATH])
{
	for (int i = 0; i < this->nTextureCount; i++)
	{
		if (strcmp(this->pTextures[i].texturename, texture) == 0)
			return this->pTextures[i].textureindex;
	}
	return -1;
}
