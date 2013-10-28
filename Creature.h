#pragma once

// An abstract class representing sea creatures

class CCreature
{
public:
	CCreature(void);
	virtual ~CCreature(void) =0;
	long Age;
	int IncreaseAge(void);
	void ResetAge(void);
};
