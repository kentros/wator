#pragma once
#include "creature.h"

// Used to describe tuna

class CTuna :
	public CCreature
{
public:
	CTuna(void);
	~CTuna(void);
	// Count of tuna in the world (int) -- This is a class variable
	static int TunaCount;
};
