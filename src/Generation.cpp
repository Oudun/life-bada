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
	for (int i=0; i<columns; i++) {
		for (int j=0; j<rows; j++) {
			currentGeneration[i][j] = Osp::Base::Utility::Math::Rand()
			< (Osp::Base::Utility::Math::RAND_VALUE_MAX / 2);
		}
	}
	counter = 1;
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

