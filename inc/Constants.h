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
	static String GetString(String& id);
	static String* GetStringPointer(String& id);
};

static Color COLOR_FORM_BACKGROUND(0,0,0);
static Color COLOR_CONTROL_NORMAL_BACKGROUND(0,128,64);
static Color COLOR_CONTROL_PRESSED_BACKGROUND(0,128,64);
static Color COLOR_TEXT(0,255,0);
static Color COLOR_CELL(0,255,0);

static String STRING_SUSPEND("SUSPEND");
static String STRING_GENERATION_ZERO("GENERATION_ZERO");
static String STRING_RESUME("RESUME");
static String STRING_SEED("SEED");
static String STRING_GENERATION_NUM("GENERATION_NUM");
static String STRING_START("START");

static String STRING_SETTINGS("SETTINGS");
static String STRING_EXTRA("EXTRA");
static String STRING_ABOUT_GAME("ABOUT_GAME");
static String STRING_SURFACE("SURFACE");
static String STRING_COLOR_SCHEME("COLOR_SCHEME");
static String STRING_GAME_RULES("GAME_RULES");
static String STRING_CELL_SIZE("CELL_SIZE");
static String STRING_SPEED("SPEED");
static String STRING_BACK("BACK");

static String STRING_ABOUT_INTRO_TEXT("ABOUT_INTRO_TEXT");
static String STRING_ABOUT_TEXT("ABOUT_TEXT");

#endif /* CONSTANTS_H_ */
