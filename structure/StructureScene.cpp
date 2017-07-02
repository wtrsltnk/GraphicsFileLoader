// StructureScene.cpp: implementation of the StructureScene class.
//
//////////////////////////////////////////////////////////////////////

#include "StructureScene.h"
#include "DummyModifier.h"

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////

IModifier* StructureScene::modifier = new DummyModifier();

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StructureScene::StructureScene()
{
	this->nGroupCount = 0;
	this->pGroups = 0;
	this->nMaterialCount = 0;
	this->pMaterials = 0;
	SetFlag(EMPTY_FLAG);
}

StructureScene::~StructureScene()
{
	CleanUp();
}

void StructureScene::CleanUp()
{
	if (this->nGroupCount > 0)
	{
		delete [] this->pGroups;
		this->pGroups = 0;
		this->nGroupCount = 0;
	}

	if (this->nMaterialCount > 0)
	{
		delete [] this->pMaterials;
		this->pMaterials = 0;
		this->nMaterialCount = 0;
	}
}

void StructureScene::Set(IScene& scene)
{
	CleanUp();

	int i = 0;
	StructureGroup group;
	StructureMaterial material;

	while (scene.GetGroup(group, i))
	{
		this->SetGroup(group, i);
		i++;
	}
	
	i = 0;
	while (scene.GetMaterial(material, i))
	{
		this->SetMaterial(material, i);
		i++;
	}

	scene.GetFlag(this->cFlag);
}

IModifier& StructureScene::GetModifier()
{
	return *modifier;
}
	
bool StructureScene::SetGroup(IGroup& group, int index)
{
	if ((index >= 0) && (index < this->nGroupCount))
	{
		this->pGroups[index].Set(group);

		return true;
	}
	else if (index >= 0)
	{
		StructureGroup* tmp = new StructureGroup[index + 10];

		if (tmp != 0)
		{
			for (int i = 0; i < this->nGroupCount; i++)
				tmp[i].Set(this->pGroups[i]);

			tmp[index].Set(group);

			int dskhf = 0;

			group.GetMaterial(dskhf);

			if (this->pGroups != 0)
				delete this->pGroups;

			this->pGroups = tmp;
			this->nGroupCount = index + 10;

			return true;
		}
	}
	return false;
}

bool StructureScene::GetGroup(IGroup& group, int index)
{
	if ((index >= 0) && (index < this->nGroupCount))
	{
		group.Set(this->pGroups[index]);
		return true;
	}
	return false;
}

bool StructureScene::SetMaterial(IMaterial& material, int index)
{
	if ((index >= 0) && (index < this->nMaterialCount))
	{
		this->pMaterials[index].Set(material);

		return true;
	}
	else if (index >= 0)
	{
		StructureMaterial* tmp = new StructureMaterial[index + 10];

		if (tmp != 0)
		{
			for (int i = 0; i < this->nMaterialCount; i++)
				tmp[i].Set(this->pMaterials[i]);

			tmp[index].Set(material);

			delete this->pMaterials;

			this->pMaterials = tmp;
			this->nMaterialCount = index + 10;

			return true;
		}
	}
	return false;
}

bool StructureScene::GetMaterial(IMaterial& material, int index)
{
	if ((index >= 0) && (index < this->nMaterialCount))
	{
		material.Set(this->pMaterials[index]);
		return true;
	}
	return false;
}

void StructureScene::SetFlag(char flag)
{
	this->cFlag = flag;
}

void StructureScene::GetFlag(char& flag)
{
	flag = this->cFlag;
}

IGroup* StructureScene::GetNewGroup()
{
	return new StructureGroup();
}

IMaterial* StructureScene::GetNewMaterial()
{
	return new StructureMaterial();
}
