/*
 * Constants.h
 *
 *  Created on: 10.01.2014
 *      Author: ddreval
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <FApp.h>

using Osp::Graphics::Color;
using Osp::Base::String;

class Constants {
public:
	Constants();
	virtual ~Constants();
	static void Init(void);
};

static Color COLOR_FORM_BACKGROUND(0,0,0);
static Color COLOR_CONTROL_NORMAL_BACKGROUND(0,128,64);
static Color COLOR_CONTROL_PRESSED_BACKGROUND(0,128,64);
static Color COLOR_TEXT(0,255,0);
static Color COLOR_CELL(0,255,0);

static String STRING_SUSPEND;
static String STRING_GENERATION_ZERO;
static String STRING_RESUME;
static String STRING_SEED;
static String STRING_GENERATION_NUM;
static String STRING_START;


#endif /* CONSTANTS_H_ */
