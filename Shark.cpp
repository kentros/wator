#include "StdAfx.h"
#include "shark.h"


int CShark::SharkCount = 0;

CShark::CShark(void)
: 
Stomach(0)
{
	SharkCount++;
}

CShark::CShark(int starvetime)
{
	Stomach = starvetime;
}

CShark::~CShark(void)
{
	SharkCount--;
}
