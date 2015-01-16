/*
 * Generation.h
 *
 *  Created on: 24.12.2013
 *      Author: ddreval
 */

#ifndef GENERATION_H_
#define GENERATION_H_

#include <FBase.h>

class Generation {

public:
	Generation();
	virtual ~Generation();
	static void Initialize(int columns, int rows);
	static int GetColumns(void);
	static int GetRows(void);
	static bool IsOccupied(int column, int row);
	static void Seed(void);
	static void Calculate(void);
	static void IncreaseCounter(void);
	static void ResetCounter(void);
	static int GetCounter(void);
	static bool MakeAlive(bool isAlive, int siblingsNum);
	static void SetSurface(int id);
	static int GetSurface(void);

private:
	static int columns;
	static int rows;
	static bool** pastGeneration;
	static bool** currentGeneration;
	static bool** nextGeneration;
	static bool* top;
	static bool* right;
	static bool* bottom;
	static bool* left;
	static bool topLeft;
	static bool topRight;
	static bool bottomRight;
	static bool bottomLeft;
	static long counter;

	static int surface;

};

#endif /* GENERATION_H_ */

