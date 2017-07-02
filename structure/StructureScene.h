// StructureScene.h: interface for the StructureScene class.
//
//////////////////////////////////////////////////////////////////////

#ifndef STRUCTURESCENE_H
#define STRUCTURESCENE_H

#include "IScene.h"
#include "StructureGroup.h"
#include "StructureMaterial.h"

class StructureScene : public IScene  
{
private:
	static IModifier *modifier;

	friend class StructureSceneManager;

private:
	int nGroupCount;
	StructureGroup* pGroups;
	int nMaterialCount;
	StructureMaterial* pMaterials;
	char cFlag;
	
	void CleanUp();

public:
	StructureScene();
	virtual ~StructureScene();

	void Set(IScene& scene);

	IModifier& GetModifier();
		
	bool SetGroup(IGroup& group, int index);
	bool GetGroup(IGroup& group, int index);
		
	bool SetMaterial(IMaterial& material, int index);
	bool GetMaterial(IMaterial& material, int index);

	void SetFlag(char flag);
	void GetFlag(char& flag);

	IGroup* GetNewGroup();
	IMaterial* GetNewMaterial();

};

#endif
