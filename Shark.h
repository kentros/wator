#pragma once
#include "creature.h"

class CShark :
	public CCreature
{
public:
	CShark(void);
	CShark(int starvetime);
	~CShark(void);
	// Count of sharks in the world (int) -- This is a class variable
	static int SharkCount;
	// Stomach -- Number of time units until the shark starves. 
	int Stomach;
};
