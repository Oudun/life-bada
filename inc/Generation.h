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

};

static int columns;
static int rows;
static bool** currentGeneration;
static bool** nextGeneration;
static long counter;

#endif /* GENERATION_H_ */
