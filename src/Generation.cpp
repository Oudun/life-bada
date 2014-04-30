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
}

void
Generation::Seed(void) {
	for (int i=0; i<columns; i++) {
		for (int j=0; j<rows; j++) {
			currentGeneration[i][j] = Osp::Base::Utility::Math::Rand()
			< (Osp::Base::Utility::Math::RAND_VALUE_MAX / 2);
		}
	}
	ResetCounter();
}


////If the cell is alive, then it stays alive if it has either 2 or 3 live neighbors
////If the cell is dead, then it springs to life only in the case that it has 3 live neighbors
//void
//Generation::Calculate(void) {
//	AppLog("Calculation started");
//	for (int i=0; i<columns; i++) {
//		for (int j=0; j<rows; j++) {
//			int siblingNum = 0;
//
////
////			PLANE
////
////			siblingNum += (int)currentGeneration[(columns+i-1)%columns][(rows+j-1)%rows];
////			siblingNum += (int)currentGeneration[(columns+i-1)%columns][j];
////			siblingNum += (int)currentGeneration[(columns+i-1)%columns][(rows+j+1)%rows];
////			siblingNum += (int)currentGeneration[i][(rows+j-1)%rows];
////			siblingNum += (int)currentGeneration[i][(rows+j+1)%rows];
////			siblingNum += (int)currentGeneration[(columns+i+1)%columns][(rows+j-1)%rows];
////			siblingNum += (int)currentGeneration[(columns+i+1)%columns][j];
////			siblingNum += (int)currentGeneration[(columns+i+1)%columns][(rows+j+1)%rows];
////
//
//
////			PLANE
//
//			siblingNum += (int)currentGeneration[(columns+i-1)%columns][(rows+j-1)%rows];
//			siblingNum += (int)currentGeneration[(columns+i-1)%columns][j];
//			siblingNum += (int)currentGeneration[(columns+i-1)%columns][(rows+j+1)%rows];
//			siblingNum += (int)currentGeneration[i][(rows+j-1)%rows];
//			siblingNum += (int)currentGeneration[i][(rows+j+1)%rows];
//			siblingNum += (int)currentGeneration[(columns+i+1)%columns][(rows+j-1)%rows];
//			siblingNum += (int)currentGeneration[(columns+i+1)%columns][j];
//			siblingNum += (int)currentGeneration[(columns+i+1)%columns][(rows+j+1)%rows];
//
//
//
//			if (currentGeneration[i][j]&&(siblingNum==2||siblingNum==3)) {
//				nextGeneration[i][j] = true;
//			} else if (!currentGeneration[i][j]&&siblingNum==3) {
//				nextGeneration[i][j] = true;
//			} else {
//				nextGeneration[i][j] = false;
//			}
//		}
//	}
//	for (int i=0; i<columns; i++) {
//		for (int j=0; j<rows; j++) {
//				currentGeneration[i][j] = nextGeneration[i][j];
//		}
//	}
//	IncreaseCounter();
//	AppLog("Calculation ended");
//}

//If the cell is alive, then it stays alive if it has either 2 or 3 live neighbors
//If the cell is dead, then it springs to life only in the case that it has 3 live neighbors
void
Generation::Calculate(void) {

	AppLog("Calculation started");

	int siblingNum = 0;

	for (int i=1; i<columns-1; i++) {
		for (int j=1; j<rows-1; j++) {

			siblingNum = 0;

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

	for (int i=1; i<columns-1; i++) {

		// FIRST ROW

		siblingNum = 0;

		siblingNum += (int) currentGeneration[i-1][1];
		siblingNum += (int) currentGeneration[i-1][0];
		siblingNum += (int) currentGeneration[i-1][rows-1];	// surface specific
		siblingNum += (int) currentGeneration[i][1];
		siblingNum += (int) currentGeneration[i][rows-1]; 	// surface specific
		siblingNum += (int) currentGeneration[i+1][1];
		siblingNum += (int) currentGeneration[i+1][0];
		siblingNum += (int) currentGeneration[i+1][rows-1]; // surface specific

		nextGeneration[i][0] = MakeAlive(currentGeneration[i][0], siblingNum);

		// LAST ROW

		siblingNum = 0;

		siblingNum += (int) currentGeneration[i-1][rows-2];
		siblingNum += (int) currentGeneration[i-1][rows-1];
		siblingNum += (int) currentGeneration[i-1][1];		// surface specific
		siblingNum += (int) currentGeneration[i][rows-2];
		siblingNum += (int) currentGeneration[i][1];		// surface specific
		siblingNum += (int) currentGeneration[i+1][rows-2];
		siblingNum += (int) currentGeneration[i+1][rows-1];
		siblingNum += (int) currentGeneration[i+1][1];		// surface specific

		nextGeneration[i][rows-1] = MakeAlive(currentGeneration[i][rows-1], siblingNum);

	}

	for (int i=1; i< rows-1; i++) {

		// FIRST COLUMN

		siblingNum = 0;

		siblingNum += (int) currentGeneration[columns-1][i-1];	// surface specific
		siblingNum += (int) currentGeneration[columns-1][i];	// surface specific
		siblingNum += (int) currentGeneration[columns-1][i+1];	// surface specific
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
		siblingNum += (int) currentGeneration[0][i-1];		// surface specific
		siblingNum += (int) currentGeneration[0][i];		// surface specific
		siblingNum += (int) currentGeneration[0][i+1];		// surface specific

		nextGeneration[columns-1][i] = MakeAlive(currentGeneration[columns-1][i], siblingNum);

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
