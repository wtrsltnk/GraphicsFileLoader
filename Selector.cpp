// Selector.cpp: implementation of the Selector class.
//
//////////////////////////////////////////////////////////////////////

#include "Selector.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Selector::Selector()
{
	memset(uiSelectionBuffer, 0, sizeof(uiSelectionBuffer));
}

Selector::~Selector()
{
}

bool Selector::SetupSelector(float x, float y)
{
	int viewport[4];

	::glGetIntegerv(GL_VIEWPORT, viewport);
	::glSelectBuffer(MAX_BUFFER, uiSelectionBuffer);
	
	::glRenderMode(GL_SELECT);
	::glInitNames();
	::glPushName(-1);

	::glMatrixMode(GL_PROJECTION);
	::glLoadIdentity();

	::gluPickMatrix((GLdouble)x, (GLdouble) (viewport[3] - y), 1, 1, viewport);

	return false;
}

bool Selector::GatherGroups(SelectionGroups& group)
{
	int iHits;

	group.Cleanup();

	::glFlush();
	iHits = ::glRenderMode(GL_RENDER);

	if (iHits >= 0)
	{
		int *ptr, names;
		ptr = (int*)uiSelectionBuffer;
		for (int i = 0; i < iHits; i++)
		{
			names = *ptr;
			ptr++;
	//		m_pSelection[i].fDepth[0] = (float) *ptr / 0x7fffffff;
			ptr++;
	//		m_pSelection[i].fDepth[1] = (float) *ptr / 0x7fffffff;
			ptr++;
			for (int j = 0; j < names; j++)
			{
	//			m_pSelection[i].iIndex = *ptr;
	//			m_pSelection[i].pObj = reinterpret_cast <ISelectObject*> (*ptr);

				StructureGroup* grp = reinterpret_cast <StructureGroup*> (*ptr);
				grp->SetFlag(SELECTION_FLAG);
				group.AddGroup(grp);
				ptr++;
			}
		}
		return true;
	}
	return false;
}