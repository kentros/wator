#include "StdAfx.h"
#include "creature.h"

CCreature::CCreature(void)
: Age(0)
{
}

CCreature::~CCreature(void)
{
}

int CCreature::IncreaseAge(void)
{
	// Increment the age and return its value
	
	return ++Age;
}

void CCreature::ResetAge(void)
{
	Age = 0;
}
