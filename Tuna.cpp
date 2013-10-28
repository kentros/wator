#include "StdAfx.h"
#include "tuna.h"


int CTuna::TunaCount = 0;

CTuna::CTuna(void)
{
	TunaCount++;
}

CTuna::~CTuna(void)
{
	TunaCount--;
}
