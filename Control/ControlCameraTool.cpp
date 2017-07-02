// ControlCameraTool.cpp: implementation of the ControlCameraTool class.
//
//////////////////////////////////////////////////////////////////////

#include <windows.h>
#include "ControlCameraTool.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ControlCameraTool::ControlCameraTool()
{
	this->m_Args = 0;
	this->m_bInitialized = false;

	this->m_iPrevX = 0;
	this->m_iPrevY = 0;
}

ControlCameraTool::~ControlCameraTool()
{
}

void ControlCameraTool::Initialize(IToolArguments& args)
{
	this->m_Args = &args;
	this->m_bInitialized = true;

	for (int i = 0; i < 255; i++)
		this->m_bKeyStatus[i] = false;

	if (this->m_Args->GetCamera() != 0)
	{
		this->m_Args->GetCamera()->Rotate(0.0f, 45.0f, 0.0f);
	}
}

void ControlCameraTool::Update()
{
	if (this->m_bInitialized && this->m_Args->GetCamera() != 0)
	{
		if (this->m_bKeyStatus['W'] == true)
			this->m_Args->GetCamera()->Move(1.0f, 0.0f, 0.0f);

		if (this->m_bKeyStatus['S'] == true)
			this->m_Args->GetCamera()->Move(-1.0f, 0.0f, 0.0f);
		
		if (this->m_bKeyStatus['A'] == true)
			this->m_Args->GetCamera()->Move(0.0f, 1.0f, 0.0f);

		if (this->m_bKeyStatus['D'] == true)
			this->m_Args->GetCamera()->Move(0.0f, -1.0f, 0.0f);

		this->m_Args->GetCamera()->Setup();
	}
}

void ControlCameraTool::OnLButtonDown(int x, int y, int key)
{
	if (this->m_bInitialized)
	{

		this->m_iPrevX = x;
		this->m_iPrevY = y;
	}
}

void ControlCameraTool::OnRButtonDown(int x, int y, int key)
{
	if (this->m_bInitialized)
	{

		this->m_iPrevX = x;
		this->m_iPrevY = y;
	}
}

void ControlCameraTool::OnMButtonDown(int x, int y, int key)
{
	if (this->m_bInitialized)
	{

		this->m_iPrevX = x;
		this->m_iPrevY = y;
	}
}

void ControlCameraTool::OnLButtonUp(int x, int y, int key)
{
	if (this->m_bInitialized)
	{

		this->m_iPrevX = x;
		this->m_iPrevY = y;
	}
}

void ControlCameraTool::OnRButtonUp(int x, int y, int key)
{
	if (this->m_bInitialized)
	{

		this->m_iPrevX = x;
		this->m_iPrevY = y;
	}
}

void ControlCameraTool::OnMButtonUp(int x, int y, int key)
{
	if (this->m_bInitialized)
	{

		this->m_iPrevX = x;
		this->m_iPrevY = y;
	}
}

void ControlCameraTool::OnMouseMove(int x, int y, int key)
{
	if (this->m_bInitialized)
	{
		if (key == MK_LBUTTON)
		{
			if (this->m_Args->GetCamera() != 0)
				this->m_Args->GetCamera()->Rotate((float)y - this->m_iPrevY, (float)x - this->m_iPrevX, 0.0f);
		}

		this->m_iPrevX = x;
		this->m_iPrevY = y;
	}
}
void ControlCameraTool::OnKeyDown(int key)
{
	if (this->m_bInitialized)
	{
		if (key > 0 && key < 256)
			this->m_bKeyStatus[key] = true;
	}
}

void ControlCameraTool::OnKeyUp(int key)
{
	if (this->m_bInitialized)
	{
		if (key > 0 && key < 256)
			this->m_bKeyStatus[key] = false;
	}
}