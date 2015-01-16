/*
 * Generation.cpp
 *
 *  Created on: 24.12.2013
 *      Author: ddreval
 */

#include "Generation.h"
#include "Constants.h"

int Generation::columns;
int Generation::rows;
bool** Generation::pastGeneration;
bool** Generation::currentGeneration;
bool** Generation::nextGeneration;
bool* Generation::top;
bool* Generation::right;
bool* Generation::bottom;
bool* Generation::left;
bool Generation::topLeft;
bool Generation::topRight;
bool Generation::bottomRight;
bool Generation::bottomLeft;
long Generation::counter;

int Generation::surface;

Generation::Generation() {

	if (IS_DEMO) {
		int rand = Constants::GetRandom();
		if (rand < 10000) {
			surface = SURFACE_THOR;
		} else if (rand <20000) {
			surface = SURFACE_KLEIN;
		} else {
			surface = SURFACE_PROJECTIVE;
		}
	} else {
		surface = SURFACE_THOR;
	}

}

Generation::~Generation() {
	// TODO Auto-generated destructor stub
}


void
Generation::Initialize(int aColumns, int aRows) {
	AppLog("Initializing Generation width %d height %d", aColumns, aRows);
	columns = aColumns;
	AppLog("Columns number set to %d", columns);
	rows = aRows;
	pastGeneration = new bool*[columns];
	currentGeneration = new bool*[columns];
	nextGeneration = new bool*[columns];
	top = new bool[columns];
	bottom = new bool[columns];
	left = new bool[rows];
	right = new bool[rows];
	for (int i=0; i<columns; i++) {
		pastGeneration[i]= new bool[rows];
		currentGeneration[i]= new bool[rows];
		nextGeneration[i]= new bool[rows];
	}
	AppLog("Initializing Generation - done");
}

void
Generation::Seed(void) {
	AppLog("Seed");
	for (int i=0; i<columns; i++) {
		for (int j=0; j<rows; j++) {
			currentGeneration[i][j] = Osp::Base::Utility::Math::Rand()
			< (Osp::Base::Utility::Math::RAND_VALUE_MAX / 2);
		}
	}
	ResetCounter();
}

//If the cell is alive, then it stays alive if it has either 2 or 3 live neighbors
//If the cell is dead, then it springs to life only in the case that it has 3 live neighbors
void
Generation::Calculate(void) {

	AppLog("Calculation started");

	int siblingNum = 0;

	for (int i=1; i<columns-1; i++) {
		for (int j=1; j<rows-1; j++) {

			siblingNum = 0;

			// INSIDE FIELD (>1 CELL FROM EDGE)

			siblingNum += (int)currentGeneration[(i-1)][(j-1)];
			siblingNum += (int)currentGeneration[(i-1)][j];
			siblingNum += (int)currentGeneration[(i-1)][(j+1)];
			siblingNum += (int)currentGeneration[i][(j-1)];
			siblingNum += (int)currentGeneration[i][(j+1)];
			siblingNum += (int)currentGeneration[(i+1)][(j-1)];
			siblingNum += (int)currentGeneration[(i+1)][j];
			siblingNum += (int)currentGeneration[(i+1)][(j+1)];

			nextGeneration[i][j] = MakeAlive(currentGeneration[i][j], siblingNum);

		}
	}


// START SETTING EDGE CELLS

	if (surface == SURFACE_THOR) {

		//	   _C|D____C|D_
		//		B|A    B|A
		//		 |      |
		//     _C|D____C|D_
		//		B|A    B|A

		for (int i = 0; i < columns-1; i++) {
			top[i] = currentGeneration[i][rows-1];
			bottom[i] = currentGeneration[i][0];
		}
		for (int j = 0; j < rows-1; j++) {
			left[j] = currentGeneration[columns-1][j];
			right[j] = currentGeneration[1][j];
		}
		topLeft = currentGeneration[columns-1][rows-1];
		topRight = currentGeneration[0][rows-1];
		bottomRight = currentGeneration[0][0];
		bottomLeft = currentGeneration[columns-1][0];

	} else if (surface == SURFACE_KLEIN) {

		//	   _D|C____D|C_
		//		B|A    B|A
		//		 |      |
		//     _C|D____C|D_
		//		A|B    A|B

		for (int i = 0; i < columns-1; i++) {
			top[i] = currentGeneration[columns-1-i][rows-1];
			bottom[i] = currentGeneration[columns-1-i][0];
		}
		for (int j = 0; j < rows-1; j++) {
			left[j] = currentGeneration[columns-1][j];
			right[j] = currentGeneration[1][j];
		}
		topLeft = currentGeneration[0][rows-1];
		topRight = currentGeneration[columns-1][rows-1];
		bottomRight = currentGeneration[columns-1][0];
		bottomLeft = currentGeneration[0][0];

	} else if (surface == SURFACE_PROJECTIVE) {

		//	   _B|C____D|A_
		//		D|A    B|C
		//		 |      |
		//     _A|D____C|B_
		//		C|B    A|D

		for (int i = 0; i < columns-1; i++) {
			top[i] = currentGeneration[columns-1-i][rows-1];
			bottom[i] = currentGeneration[columns-1-i][0];
		}
		for (int j = 0; j < rows-1; j++) {
			left[j] = currentGeneration[columns-1][rows-j-1];
			right[j] = currentGeneration[1][rows-j-1];
		}
		topLeft = currentGeneration[columns-1][0];
		topRight = currentGeneration[0][0];
		bottomRight = currentGeneration[0][rows-1];
		bottomLeft = currentGeneration[columns-1][rows-1];
	}

// END SETTING EDGE CELLS

	for (int i=1; i<columns-1; i++) {

		// FIRST ROW

		siblingNum = 0;

		siblingNum += (int) currentGeneration[i-1][1];
		siblingNum += (int) currentGeneration[i-1][0];
		siblingNum += (int) top[i-1];
		siblingNum += (int) currentGeneration[i][1];
		siblingNum += (int) top[i];
		siblingNum += (int) currentGeneration[i+1][1];
		siblingNum += (int) currentGeneration[i+1][0];
		siblingNum += (int) top[i+1];

		nextGeneration[i][0] = MakeAlive(currentGeneration[i][0], siblingNum);

		// LAST ROW

		siblingNum = 0;

		siblingNum += (int) currentGeneration[i-1][rows-2];
		siblingNum += (int) currentGeneration[i-1][rows-1];
		siblingNum += (int) bottom[i-1];
		siblingNum += (int) currentGeneration[i][rows-2];
		siblingNum += (int) bottom[i];
		siblingNum += (int) currentGeneration[i+1][rows-2];
		siblingNum += (int) currentGeneration[i+1][rows-1];
		siblingNum += (int) bottom[i+1];

		nextGeneration[i][rows-1] = MakeAlive(currentGeneration[i][rows-1], siblingNum);

	}

	for (int i=1; i< rows-1; i++) {

		// FIRST COLUMN

		siblingNum = 0;

		siblingNum += (int) left[i-1];
		siblingNum += (int) left[i];
		siblingNum += (int) left[i+1];
		siblingNum += (int) currentGeneration[0][i-1];
		siblingNum += (int) currentGeneration[0][i+1];
		siblingNum += (int) currentGeneration[1][i-1];
		siblingNum += (int) currentGeneration[1][i];
		siblingNum += (int) currentGeneration[1][i+1];

		nextGeneration[0][i] = MakeAlive(currentGeneration[0][i], siblingNum);

		// LAST COLUMN

		siblingNum = 0;

		siblingNum += (int) currentGeneration[columns-2][i-1];
		siblingNum += (int) currentGeneration[columns-2][i];
		siblingNum += (int) currentGeneration[columns-2][i+1];
		siblingNum += (int) currentGeneration[columns-1][i-1];
		siblingNum += (int) currentGeneration[columns-1][i+1];
		siblingNum += (int) right[i-1];
		siblingNum += (int) right[i];
		siblingNum += (int) right[i+1];

		nextGeneration[columns-1][i] = MakeAlive(currentGeneration[columns-1][i], siblingNum);

	}


	// TOP LEFT

	siblingNum = 0;

	siblingNum += (int) topLeft;
	siblingNum += (int) top[0];
	siblingNum += (int) top[1];
	siblingNum += (int) currentGeneration[0][1];
	siblingNum += (int) currentGeneration[1][1];
	siblingNum += (int) currentGeneration[1][0];
	siblingNum += (int) left[1];
	siblingNum += (int) left[0];

	nextGeneration[0][0] = MakeAlive(currentGeneration[0][0], siblingNum);

	// TOP RIGHT

	siblingNum = 0;

	siblingNum += (int) top[columns-2];
	siblingNum += (int) top[columns-1];
	siblingNum += (int) topRight;
	siblingNum += (int) right[0];
	siblingNum += (int) right[1];
	siblingNum += (int) currentGeneration[columns-1][1];
	siblingNum += (int) currentGeneration[columns-2][1];
	siblingNum += (int) currentGeneration[columns-2][0];

	nextGeneration[columns-1][0] = MakeAlive(currentGeneration[columns-1][0], siblingNum);

	// BOTTOM RIGHT

	siblingNum = 0;

	siblingNum += (int) currentGeneration[columns-2][rows-2];
	siblingNum += (int) currentGeneration[columns-1][rows-2];
	siblingNum += (int) right[rows-2];
	siblingNum += (int) right[rows-1];
	siblingNum += (int) bottomRight;
	siblingNum += (int) bottom[columns-1];
	siblingNum += (int) bottom[columns-2];
	siblingNum += (int) currentGeneration[columns-2][rows-1];

	nextGeneration[columns-1][rows-1] = MakeAlive(currentGeneration[columns-1][rows-1], siblingNum);

	// TOP LEFT

	siblingNum = 0;

	siblingNum += (int) left[rows-2];
	siblingNum += (int) currentGeneration[0][rows-2];
	siblingNum += (int) currentGeneration[1][rows-2];
	siblingNum += (int) currentGeneration[1][rows-1];
	siblingNum += (int) bottom[1];
	siblingNum += (int) bottom[0];
	siblingNum += (int) bottomLeft;
	siblingNum += (int) left[rows-1];

	nextGeneration[0][rows-1] = MakeAlive(currentGeneration[0][rows-1], siblingNum);

	for (int i=0; i<columns; i++) {
		for (int j=0; j<rows; j++) {
				pastGeneration[i][j] = currentGeneration[i][j];
		}
	}

	for (int i=0; i<columns; i++) {
		for (int j=0; j<rows; j++) {
				currentGeneration[i][j] = nextGeneration[i][j];
		}
	}

	IncreaseCounter();
	AppLog("Calculation ended");

}

bool
Generation::MakeAlive(bool isAlive, int siblingNum) {
	if (isAlive&&(siblingNum==2||siblingNum==3)) {
		return true;
	} else if (!isAlive&&siblingNum==3) {
		return true;
	} else {
		return false;
	}
}


int
Generation::GetColumns(void) {
	return columns;
}

int
Generation::GetRows(void) {
	return rows;
}

bool
Generation::IsOccupied(int column, int row) {
	return currentGeneration[column][row];
}

void
Generation::IncreaseCounter(void){
	counter += 1;
}

void
Generation::ResetCounter(void) {
	counter = 0;
}

int
Generation::GetCounter(void){
	return counter;
}

void
Generation::SetSurface(int id) {
	surface = id;
}

int
Generation::GetSurface(void) {
	return surface;
}
