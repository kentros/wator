#include "StdAfx.h"
#include "wator.h"


CWaTor::CWaTor(void)
: Grid(NULL)
, OldGrid(NULL)
, tunaInitNum(500)
, sharkInitNum(200)
, tunaBreedTime(5)
, sharkBreedTime(5)
, sharkStarveTime(5)
{
	// Set the initial number of tuna, initial number of sharks, breeding times, and starvation time
	// to the default values given above. Allocate the two, 2-dimensional arrays and set the 
	// pointers to NULL

	direct[0] = E;
	direct[1] = NE;
	direct[2] = NW;
	direct[3] = SE;
	direct[4] = SW;
	direct[5] = W;

	Grid = new CCreature**[numRows];
	OldGrid = new CCreature**[numRows];

	for (int i = 0; i < numRows; i++)
	{
		Grid[i] = new CCreature*[numCol];
		OldGrid[i] = new CCreature*[numCol];

		for (int j = 0; j < numCol; j++)
		{
			Grid[i][j] = NULL;
			OldGrid[i][j] = NULL;
		}
	}

}

CWaTor::~CWaTor(void)
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCol; j++)
		{
			delete Grid[i][j];
			//delete OldGrid[i][j];
		}
		delete[] Grid[i];
		//delete[] OldGrid[i];
	}

	delete[] Grid;
	//delete[] OldGrid;
	
	Grid = NULL;
	OldGrid = NULL;
}

bool CWaTor::GetEmptyNeighbor(int row, int col, int& newRow, int& newCol) const
{
	// Randomly choose one of the empty neighbors (Northwest, Northeast, East, SouthEast, SouthWest,
	// or West) of grid[Row][Col], then return true and set the 3rd and fourth parameters to the 
	// row and column number of the empty neighbor. If there are no empty neighbors, return false. 

	bool retVal = false;
	bool hasEmptyNeighbor = false;

	newRow = row;
	newCol = col;

	int status[6];

	// Check if there are any empty neighbors
	for (int x = 0; x < 6; x++)
	{
		status[x] = NeighborStatus(direct[x],row,col);
		if (status[x] == 0)
			hasEmptyNeighbor = true;
	}

	//int nb = 0;
	if (hasEmptyNeighbor)
	{
		int neighbor = rand()%6;
		while (status[neighbor] != 0)
			neighbor = rand()%6;
	
		// Set newRow and newCol to empty neighbor coordinates
		getNeighbor(direct[neighbor],row,col,newRow,newCol);
		
	}
	
	//if (newCol - col == 2)
	//	int funtime = 0;

	retVal = hasEmptyNeighbor;

	return retVal;
}

bool CWaTor::GetTunaNeighbor(int row, int col, int& newRow, int& newCol) const
{
	// Randomly choose one of the neighbors (Northwest, Northeast, East, SouthEast, SouthWest, 
	// or West) of grid[Row][Col] that contains a tuna, then return true and set the 3rd and fourth
	// parameters to the row and column number of the neighbor chosen. If there are no neighbors 
	// contain a tuna, return false. (When determining whether a non-NULL grid cell contains the 
	// address of a CTuna, use run-time-type-information obtained by using dynamic_cast.) 

	bool retVal = false;
	bool hasTunaNeighbor = false;

	int status[6];

	newRow = row;
	newCol = col;

	// Check if there are any empty neighbors
	for (int x = 0; x < 6; x++)
	{
		status[x] = NeighborStatus(direct[x],row,col);
		if (status[x] == 1)
			hasTunaNeighbor = true;
	}

	if (hasTunaNeighbor)
	{
		int neighbor = rand()%6;
		while (status[neighbor] != 1)
			neighbor = rand()%6;
	
		// Set newRow and newCol to empty neighbor coordinates
		getNeighbor(direct[neighbor],row,col,newRow,newCol);
	}

	retVal = hasTunaNeighbor;
	return retVal;
}


int CWaTor::NeighborStatus(DIRECTION dir, int r, int c) const
{
	// This function returns 0 if the neighbor to the cell in [r,c] is empty
	// 1 if there is a tuna, and 2 if there is a shark

	int retVal = 0;
	
	CCreature *cre;
	cre = getNeighbor(dir,r,c);

	if (CTuna *t2 = dynamic_cast<CTuna*>(cre))
		retVal = 1;
	if (CShark *s2 = dynamic_cast<CShark*>(cre))
		retVal = 2;

	return retVal;
}

void CWaTor::getNeighbor(DIRECTION dir, int r, int c, int& newRow, int& newCol) const
{
	// set NewRow and newCol to neighbor coordinates

	bool isOddRow = false;
	if (r % 2 != 0)
		isOddRow = true;

	if (isOddRow)
	{
		switch (dir){
        case E:
			c++;			
			break;
		case NE:
			r--;
			c++;			
			break;
		case NW:
			r--;     
			break;
		case SE:
			r++;
			c++;			
			break;
		case SW:
			r++;
            break;
		case W:
			c--;			
			break;
		default:
			r = r;
			c = c;
	} // end switch

	} //end odd
	else
	{
		switch (dir){
        case E:
			c++	;		
			break;
		case NE:
			r--;
			break;
		case NW:
			r--;  
			c--;
			break;
		case SE:
			r++;
			break;
		case SW:
			r++;
			c--;
            break;
		case W:
			c--;			
			break;
		default:
			r = r;
			c = c;
	} // end switch


	} // end even;

	if (r == -1)
		r = numRows - 1;
	if (r == numRows)
		r = 0;
	if (c == -1)
		c = numCol - 1;
	if (c == numCol)
		c = 0;
	
	
	newRow = r;
	newCol = c;

}


CCreature* CWaTor::getNeighbor(DIRECTION dir, int r, int c) const
{
	// returns the pointer to the neighbor
	CCreature *retVal = NULL;
	bool isOddRow = false;
	bool fault = false;
	if (r % 2 != 0)
		isOddRow = true;

	if (isOddRow)
	{
	switch (dir){

        case E:
			c++;			
			break;
		case NE:
			r--;
			c++;			
			break;
		case NW:
			r--;     
			break;
		case SE:
			r++;
			c++;			
			break;
		case SW:
			r++;
            break;
		case W:
			c--;			
			break;
		default:
			fault = true;
	} // end switch

	} //end odd
	else
	{
		switch (dir){
        case E:
			c++	;		
			break;
		case NE:
			r--;
			break;
		case NW:
			r--;  
			c--;
			break;
		case SE:
			r++;
			break;
		case SW:
			r++;
			c--;
            break;
		case W:
			c--;			
			break;
		default:
			fault = true;
	} // end switch


	} // end even;

	if (r == -1)
		r = numRows - 1;
	if (r == numRows)
		r = 0;
	if (c == -1)
		c = numCol - 1;
	if (c == numCol)
		c = 0;
   
	
	if (!fault)
		retVal = Grid[r][c];
	return retVal;
}



void CWaTor::Create(void)
{
	// Delete creature instances (if any) already associated with the grid array.
	// Create the initial number of tuna and sharks, and store their addresses at random,
	// different locations in the grid. 
	// (NULL pointers in the grid represent the absence of creatures at that point.) 

	for (int i = 0; i < numRows; i++)
	{	for (int j = 0; j < numCol; j++)
	{
		CCreature *cre = Grid[i][j];
		if (CTuna *t2 = dynamic_cast<CTuna*>(cre) )
			delete Grid[i][j];
		if (CShark *s2 = dynamic_cast<CShark*>(cre) )
			delete Grid[i][j];
		Grid[i][j] = NULL;

	}
	}

	int randomArray[3500];
	for (int x = 0; x < 3500; x++)
		randomArray[x] = x;
	for (int y = 0; y < 3500; y++)
	{
		int randomNum = rand()%3500;
		int temp = randomArray[y];
		randomArray[y] = randomArray[randomNum];
		randomArray[randomNum] = temp;
	}

	int row = 0;
	int col = 0;

	// Take care of the sharks
	for (int s = 1; s <= sharkInitNum; s++)
	{
		row = (int)(randomArray[s]/numCol);
		col = randomArray[s]%numCol;

		Grid[row][col] = new CShark(sharkStarveTime);
	}

	// Take care of the tuna
	for (int t = sharkInitNum + 1 + 1; t <= tunaInitNum + sharkInitNum + 1; t++)
	{
		row = (int)(randomArray[t]/numCol);
		col = randomArray[t]%numCol;

		Grid[row][col] = new CTuna;
	}

	
}

void CWaTor::Update(void)
{
	// Copy the grid array to the old grid array, then update the grid array contents according 
	// to the rules of movement, eating, reproducing, and starving given above. 
	// (When determining whether a non-NULL grid cell contains the address of a CTuna or a CShark,
	// use run-time-type-information obtained by using dynamic_cast.) 

	for (int i = 0; i < numRows; i++)
	{	for (int j = 0; j < numCol; j++)
		{
			OldGrid[i][j] = Grid[i][j];
			
			//CCreature *cr = Grid[i][j];
			//if (CTuna *t2 = dynamic_cast<CTuna*>(cr))
			//{
			//	OldGrid[i][j] = new CTuna();
			//	OldGrid[i][j]->Age = Grid[i][j]->Age;
			//}
			//if (CShark *s2 = dynamic_cast<CShark*>(cr))
			//{
			//	OldGrid[i][j] = new CShark();
			//	OldGrid[i][j]->Age = Grid[i][j]->Age;
			//}
			
		}

	}

	// As each time unit begins, all grid cells of WaTor are processed in a random order:
	int randomArray[3500];
	for (int x = 0; x < 3500; x++)
		randomArray[x] = x;
	for (int y = 0; y < 3500; y++)
	{
		int randomNum = rand()%3500;
		int temp = randomArray[y];
		randomArray[y] = randomArray[randomNum];
		randomArray[randomNum] = temp;
	}

	int currRow = 0;
	int currCol = 0;
	CCreature *cre;
	CCreature *ocre;
	int newR = 0;
	int newC = 0;

	for (int z = 0; z < 3500; z++)
	{
		currRow = (int)(randomArray[z]/numCol);
		currCol = randomArray[z]%numCol;
		cre = Grid[currRow][currCol];
		ocre = OldGrid[currRow][currCol];

		// If the cell contains a tuna that has not moved already in this time unit
		if (CTuna *t2 = dynamic_cast<CTuna*>(cre))
			if (CTuna *t3 = dynamic_cast<CTuna*>(ocre))
			{
				// Increase the tuna's age by 1.
				t2->IncreaseAge();

				// If empty cells exist around the tuna (Northwest, Northeast, East, SouthEast, SouthWest, 
				// or West), randomly choose one of the empty cells and move the tuna to it. 

				if (GetEmptyNeighbor(currRow,currCol,newR,newC))
				{
					Grid[newR][newC] = Grid[currRow][currCol];
					Grid[currRow][currCol] = NULL;

					// If the tuna was moved and its age exactly matches the breeding age of a tuna, 
					// create a new tuna in its old location, and set the ages of both tuna to zero

					if (t2->Age == tunaBreedTime)
					{
						Grid[newR][newC]->ResetAge();
						Grid[currRow][currCol] = new CTuna();
					}

				} // end move tuna
           
			} // end is tuna

	// If the cell contains a shark that has not moved already in this time unit:
	if (CShark *s2 = dynamic_cast<CShark*>(cre))
		if (CShark *s3 = dynamic_cast<CShark*>(ocre))
		{
			// Increase the shark's age by 1
			s2->IncreaseAge();

			// Decrease the shark's stomach contents by 1
			s2->Stomach--;

			bool sharkMove = false;

			// If tuna exist around the shark (Northwest, Northeast, East, SouthEast, SouthWest,
			// or West), randomly choose one to be eaten; delete the chosen tuna, and move the 
			// shark to the cell formerly occupied by the tuna; set the shark's stomach to full

			if (GetTunaNeighbor(currRow,currCol,newR,newC))
			{
				delete Grid[newR][newC];
				OldGrid[newR][newC] = NULL;
				Grid[newR][newC] = s2;
				Grid[currRow][currCol] = NULL;				
				
				s2->Stomach = sharkStarveTime;

				if (s2->Age == sharkBreedTime)
				{
					Grid[newR][newC]->ResetAge();
					Grid[currRow][currCol] = new CShark(s2->Stomach);
					
				}
			
				sharkMove = true;
			}
			// If no tuna existed around the shark and its stomach is empty, the shark dies. 
			// Delete the shark.
			else
			{
				if (s2->Stomach == 0)
				{
					delete Grid[currRow][currCol];
					Grid[currRow][currCol] = NULL;
					OldGrid[currRow][currCol] = NULL;
				} // end if

			// If the shark did not move (i.e., it did not eat a tuna), it did not starve,
			// and empty cells exist around the shark (Northwest, Northeast, East, SouthEast, 
			// SouthWest, or West), randomly choose one of the empty cells and move the shark to it

				else
				{
					if (GetEmptyNeighbor(currRow,currCol,newR,newC))
					{
						Grid[newR][newC] = Grid[currRow][currCol];
						Grid[currRow][currCol] = NULL;

						if (s2->Age == sharkBreedTime)
						{
							Grid[newR][newC]->ResetAge();
							Grid[currRow][currCol] = new CShark(s2->Stomach);

						}

						sharkMove = true;

					} // end if
				}

					
			} // end else
			
			// If the shark moved (eating a tuna or not) and its age exactly matches the breeding 
			// age of a shark, create a new shark in its old location, and set the ages of both 
			// shark to zero, and set the stomach contents of both sharks to be the same as the
			// original shark. 
			
		} // end is-shark


		// If the cell contains only ocean, do nothing to it. 

	} // end loop through all grid cells

}

const CCreature* CWaTor::GetGridCell(int row, int col) const
{
	//  Return the pointer contained in grid[row][col]. 
	
	return Grid[row][col];
}
