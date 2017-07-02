// StructureSceneManager.cpp: implementation of the StructureSceneManager class.
//
//////////////////////////////////////////////////////////////////////

#include "StructureSceneManager.h"
#include "TextureManager.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StructureSceneManager::StructureSceneManager()
{
}

StructureSceneManager::~StructureSceneManager()
{
}

IScene& StructureSceneManager::GetScene()
{
	return this->scene;
}

bool StructureSceneManager::LoadScene(ISceneLoader& sceneloader, const char filename[256])
{
	StructureScene newscene;

	if (sceneloader.LoadScene(newscene, filename) == true)
	{
		this->scene.Set(newscene);

		return true;
	}

	return false;
}

void StructureSceneManager::NewScene()
{
	StructureScene newscene;
	this->scene.Set(newscene);
}

void StructureSceneManager::Render()
{
	StructureGroup* groups = this->scene.pGroups;

	for (int i = 0; i < this->scene.nGroupCount; i++)
	{
		if (groups[i].cFlag != EMPTY_FLAG)
		{
			StructureMaterial material;
			this->scene.GetMaterial(material, groups[i].nMaterialIndex);

			int texture = 0;
			texture = TextureManager::GetInstance()->GetTextureIndex(material.strTexture);

			if (texture >= 0)
			{
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, texture);
			}

			glMaterialfv(GL_FRONT, GL_AMBIENT, material.fAmbient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, material.fDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, material.fSpecular);
			glMaterialfv(GL_FRONT, GL_EMISSION, material.fEmissive);

			glMaterialf(GL_FRONT, GL_SHININESS, material.fShininess);

			StructureTriangle* triangles = groups[i].pTriangles;
			
			::glBegin(GL_TRIANGLES);
			for (int j = 0; j < groups[i].nTriangleCount; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					StructureTexCoord texcoord;

					groups[i].GetTexCoord(texcoord, triangles[j].nTexCoord[k]);

					StructureVertex vertex;

					groups[i].GetVertex(vertex, triangles[j].nVertex[k]);

					// TODO : Normal per triangle of Vertex implementeren
					//::glNormal3f( 0.0f, 0.0f, 1.0f);

					::glTexCoord2f(texcoord.fU, texcoord.fV);
					if (groups[i].cFlag == SELECTION_FLAG)
					{
						::glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
					}
					else
					{
						::glColor4f(texcoord.fColor[0], texcoord.fColor[1], texcoord.fColor[2], texcoord.fColor[3]);
					}
					::glVertex3f(vertex.fPositionX, vertex.fPositionY, vertex.fPositionZ);
				}
			}
			::glEnd();
		}
	}
}

bool StructureSceneManager::Select(ISelection** selection, int x, int y)
{
	Selector selector;

	selector.SetupSelector((float)x, (float)y);

	StructureGroup* groups = this->scene.pGroups;

	for (int i = 0; i < this->scene.nGroupCount; i++)
	{
		if (groups[i].cFlag != EMPTY_FLAG)
		{
			StructureTriangle* triangles = groups[i].pTriangles;
			
			::glLoadName((LONG)&groups[i]);
			::glBegin(GL_TRIANGLES);
			for (int j = 0; j < groups[i].nTriangleCount; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					StructureVertex vertex;

					groups[i].GetVertex(vertex, triangles[j].nVertex[k]);

					// TODO : Normal per triangle of Vertex implementeren
					//::glNormal3f( 0.0f, 0.0f, 1.0f);

					::glVertex3f(vertex.fPositionX, vertex.fPositionY, vertex.fPositionZ);
				}
			}
			::glEnd();
		}
	}

	if (selector.GatherGroups(this->selectionGroup))
	{
		*selection = (ISelection*) &this->selectionGroup;
		return true;
	}

	return false;
}
