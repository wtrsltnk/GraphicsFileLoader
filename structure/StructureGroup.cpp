// StructureGroup.cpp: implementation of the StructureGroup class.
//
//////////////////////////////////////////////////////////////////////

#include "StructureGroup.h"
#include "DummyModifier.h"

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////

IModifier* StructureGroup::modifier = new DummyModifier();

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StructureGroup::StructureGroup()
{
	this->nTriangleCount = 0;
	this->pTriangles = 0;
	this->nVertexCount = 0;
	this->pVertices = 0;
	this->nTexCoordCount = 0;
	this->pTexCoords = 0;
	this->nMaterialIndex = -1;
	SetFlag(EMPTY_FLAG);
}

StructureGroup::~StructureGroup()
{
	CleanUp();
}

void StructureGroup::CleanUp()
{
	if (this->nTriangleCount > 0)
	{
		delete [] this->pTriangles;
		this->pTriangles = 0;
		this->nTriangleCount = 0;
	}

	if (this->nVertexCount > 0)
	{
		delete [] this->pVertices;
		this->pVertices = 0;
		this->nVertexCount = 0;
	}

	if (this->nTexCoordCount > 0)
	{
		delete [] this->pTexCoords;
		this->pTexCoords = 0;
		this->nTexCoordCount = 0;
	}
}

void StructureGroup::Set(IGroup& group)
{
	CleanUp();

	int i = 0;
	StructureTriangle triangle;
	StructureVertex vertex;
	StructureTexCoord texcoord;

	while (group.GetTriangle(triangle, i))
	{
		this->SetTriangle(triangle, i);
		i++;
	}

	i = 0;
	while (group.GetVertex(vertex, i))
	{
		this->SetVertex(vertex, i);
		i++;
	}

	i = 0;
	while (group.GetTexCoord(texcoord, i))
	{
		this->SetTexCoord(texcoord, i);
		i++;
	}

	group.GetMaterial(this->nMaterialIndex);
	group.GetFlag(this->cFlag);
}

IModifier& StructureGroup::GetModifier()
{
	return *modifier;
}
	
bool StructureGroup::SetTriangle(ITriangle& triangle, int index)
{
	if ((index >= 0) && (index < this->nTriangleCount))
	{
		this->pTriangles[index].Set(triangle);

		return true;
	}
	else if (index >= 0)
	{
		StructureTriangle* tmp = new StructureTriangle[index + 10];

		if (tmp != 0)
		{
			for (int i = 0; i < this->nTriangleCount; i++)
				tmp[i].Set(this->pTriangles[i]);

			tmp[index].Set(triangle);

			delete this->pTriangles;

			this->pTriangles = tmp;
			this->nTriangleCount = index + 10;

			return true;
		}
	}
	return false;
}

bool StructureGroup::GetTriangle(ITriangle& triangle, int index)
{
	if ((index >= 0) && (index < this->nTriangleCount))
	{
		triangle.Set(this->pTriangles[index]);
		return true;
	}
	return false;
}
	
bool StructureGroup::SetVertex(IVertex& vertex, int index)
{
	if ((index >= 0) && (index < this->nVertexCount))
	{
		this->pVertices[index].Set(vertex);

		return true;
	}
	else if (index >= 0)
	{
		StructureVertex* tmp = new StructureVertex[index + 10];

		if (tmp != 0)
		{
			for (int i = 0; i < this->nVertexCount; i++)
				tmp[i].Set(this->pVertices[i]);

			tmp[index].Set(vertex);

			delete this->pVertices;

			this->pVertices = tmp;
			this->nVertexCount = index + 10;

			return true;
		}
	}
	return false;
}

bool StructureGroup::GetVertex(IVertex& vertex, int index)
{
	if ((index >= 0) && (index < this->nVertexCount))
	{
		vertex.Set(this->pVertices[index]);
		return true;
	}
	return false;
}
	
bool StructureGroup::SetTexCoord(ITexCoord& texcoord, int index)
{
	if ((index >= 0) && (index < this->nTexCoordCount))
	{
		this->pTexCoords[index].Set(texcoord);

		return true;
	}
	else if (index >= 0)
	{
		StructureTexCoord* tmp = new StructureTexCoord[index + 10];

		if (tmp != 0)
		{
			for (int i = 0; i < this->nTexCoordCount; i++)
				tmp[i].Set(this->pTexCoords[i]);

			tmp[index].Set(texcoord);

			delete this->pTexCoords;

			this->pTexCoords = tmp;
			this->nTexCoordCount = index + 10;

			return true;
		}
	}
	return false;
}

bool StructureGroup::GetTexCoord(ITexCoord& texcoord, int index)
{
	if ((index >= 0) && (index < this->nTexCoordCount))
	{
		texcoord.Set(this->pTexCoords[index]);
		return true;
	}
	return false;
}
	
bool StructureGroup::SetMaterial(int materialindex)
{
	this->nMaterialIndex = materialindex;
	return false;
}

bool StructureGroup::GetMaterial(int& materialindex)
{
	materialindex = this->nMaterialIndex;
	return false;
}

void StructureGroup::SetFlag(char flag)
{
	this->cFlag = flag;
}

void StructureGroup::GetFlag(char& flag)
{
	flag = this->cFlag;
}

ITriangle* StructureGroup::GetNewTriangle()
{
	return new StructureTriangle();
}

IVertex* StructureGroup::GetNewVertex()
{
	return new StructureVertex();
}

ITexCoord* StructureGroup::GetNewTexCoord()
{
	return new StructureTexCoord();
}