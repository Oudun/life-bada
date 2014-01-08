/*
 * Generation.cpp
 *
 *  Created on: 24.12.2013
 *      Author: ddreval
 */

#include "Generation.h"

Generation::Generation() {

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
	currentGeneration = new bool*[columns];
	nextGeneration = new bool*[columns];
	for (int i=0; i<columns; i++) {
		currentGeneration[i]= new bool[rows];
		nextGeneration[i]= new bool[rows];
	}
	Seed();
	counter = 1;
}

void
Generation::Seed(void) {
	for (int i=0; i<columns; i++) {
		for (int j=0; j<rows; j++) {
			currentGeneration[i][j] = Osp::Base::Utility::Math::Rand()
			< (Osp::Base::Utility::Math::RAND_VALUE_MAX / 2);
			AppLog("%d", (int)currentGeneration[i][j]);
		}
	}
}


//If the cell is alive, then it stays alive if it has either 2 or 3 live neighbors
//If the cell is dead, then it springs to life only in the case that it has 3 live neighbors
void
Generation::Calculate(void) {
	AppLog("Calculation started");
	for (int i=0; i<columns; i++) {
		for (int j=0; j<rows; j++) {
			int siblingNum = 0;
			siblingNum += (int)currentGeneration[(columns+i-1)%columns][(rows+j-1)%rows];
			siblingNum += (int)currentGeneration[(columns+i-1)%columns][j];
			siblingNum += (int)currentGeneration[(columns+i-1)%columns][(rows+j+1)%rows];
			siblingNum += (int)currentGeneration[i][(rows+j-1)%rows];
			siblingNum += (int)currentGeneration[i][(rows+j+1)%rows];
			siblingNum += (int)currentGeneration[(columns+i+1)%columns][(rows+j-1)%rows];
			siblingNum += (int)currentGeneration[(columns+i+1)%columns][j];
			siblingNum += (int)currentGeneration[(columns+i+1)%columns][(rows+j+1)%rows];
			if (currentGeneration[i][j]&&(siblingNum==2||siblingNum==3)) {
				nextGeneration[i][j] = true;
			} else if (!currentGeneration[i][j]&&siblingNum==3) {
				nextGeneration[i][j] = true;
			} else {
				nextGeneration[i][j] = false;
			}
		}
	}
	for (int i=0; i<columns; i++) {
		for (int j=0; j<rows; j++) {
				currentGeneration[i][j] = nextGeneration[i][j];
		}
	}
	AppLog("Calculation ended");
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

