// DummySceneLoader.cpp: implementation of the DummySceneLoader class.
//
//////////////////////////////////////////////////////////////////////

#include "DummySceneLoader.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DummySceneLoader::DummySceneLoader()
{
}

DummySceneLoader::~DummySceneLoader()
{
}

bool DummySceneLoader::LoadScene(IScene& scene, const char filename[256])
{
	IGroup* group = scene.GetNewGroup();
	if (group != 0)
	{
		ITriangle* triangle = group->GetNewTriangle();
		IVertex* vertex = group->GetNewVertex();
		ITexCoord* texcoord = group->GetNewTexCoord();

		if ((triangle != 0) && (vertex != 0) && (texcoord != 0))
		{
			texcoord->SetU(0.0f);
			texcoord->SetV(0.0f);
			texcoord->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			group->SetTexCoord(*texcoord, 0);

			texcoord->SetU(1.0f);
			texcoord->SetV(0.0f);
			texcoord->SetColor(2.0f, 0.0f, 0.0f, 1.0f);
			group->SetTexCoord(*texcoord, 1);

			texcoord->SetU(0.0f);
			texcoord->SetV(1.0f);
			texcoord->SetColor(0.5f, 0.5f, 1.0f, 1.0f);
			group->SetTexCoord(*texcoord, 2);

			texcoord->SetU(1.0f);
			texcoord->SetV(1.0f);
			texcoord->SetColor(1.0f, 0.5f, 0.0f, 1.0f);
			group->SetTexCoord(*texcoord, 3);

			vertex->SetPosition(0.0f, 0.0f, -1.0f);
			group->SetVertex(*vertex, 0);

			vertex->SetPosition(2.0f, 0.0f, -1.0f);
			group->SetVertex(*vertex, 1);

			vertex->SetPosition(2.0f, 2.0f, -1.0f);
			group->SetVertex(*vertex, 2);

			vertex->SetPosition(0.0f, 2.0f, -1.0f);
			group->SetVertex(*vertex, 3);

			triangle->SetVertexIndexes(0, 1, 2);
			triangle->SetTexCoords(0, 1, 2);
			group->SetTriangle(*triangle, 0);

			triangle->SetVertexIndexes(0, 2, 3);
			triangle->SetTexCoords(0, 2, 3);
			group->SetTriangle(*triangle, 1);

			group->SetFlag(NORMAL_FLAG);

			delete triangle;
			delete vertex;
			delete texcoord;
		}

		scene.SetGroup(*group, 0);

		delete group;
	}
	return true;
}

bool DummySceneLoader::SaveScene(IScene& scene, const char filename[256])
{
	return true;
}