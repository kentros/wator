#pragma once

#include "creature.h"
#include "tuna.h"
#include "shark.h"

class CWaTor
{
public:
	CWaTor(void);
	~CWaTor(void);
	// Number of rows in the world (int) -- This is a const class variable with value 50
	static const int numRows = 50;
	// Number of columns in the world (int) -- This is a const class variable with value 70.
	static const int numCol = 70;
	// This will point to a dynamically allocated, 2-dimensional array of CCreature pointers
	CCreature*** Grid;
	// This will point to another dynamically allocated, 2-dimensional array of CCreature pointers.
	// Keeping a copy of the old array when you are creating the array for a new time unit can
	// make it easier to determine if a fish already has been moved
	CCreature*** OldGrid;

	// Initial number of tuna 
	int tunaInitNum;
	// Initial number of sharks
	int sharkInitNum;
	int tunaBreedTime;
	int sharkBreedTime;
	int sharkStarveTime;
	enum DIRECTION { NW, NE, E, SE, SW, W };

	bool GetEmptyNeighbor(int row, int col, int& newRow, int& newCol) const;
	bool GetTunaNeighbor(int row, int col, int& newRow, int& newCol) const;
	
	int NeighborStatus(DIRECTION dir, int r, int c) const;
	CCreature* getNeighbor(DIRECTION dir, int r, int c) const;
	void getNeighbor( DIRECTION dir, int r, int c, int& newRow, int& newCol) const;
	DIRECTION direct[6];
	
	void Create(void);
	void Update(void);
	const CCreature* GetGridCell(int row, int col) const;
};
