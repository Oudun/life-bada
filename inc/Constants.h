/*
 * Constants.h
 *
 *  Created on: 10.01.2014
 *      Author: ddreval
 */


#ifndef CONSTANTS_H_
#define CONSTANTS_H_



#include <FBase.h>
#include <FApp.h>
#include <FApp.h>

#include <FUi.h>

using Osp::Graphics::Color;
using Osp::Base::String;

class Constants {
public:
	Constants();
	virtual ~Constants();
	static String GetString(String& id);
	static String* GetStringPointer(String& id);
	static void SetColorScheme(int id);
	static Color* GetColor(int id);

};

// Events

const static int EVENT_START = 11;
const static int EVENT_SEED = 12;
const static int EVENT_SHOW_SETTINGS = 13;

const static int EVENT_NEXT_GENERATION = 21;

static const int EVENT_SHOW_ABOUT_GAME = 31;
static const int EVENT_SHOW_SURFACE = 32;
static const int EVENT_SHOW_CELL_SIZE = 33;
static const int EVENT_SHOW_COLOR_SCHEME = 34;
static const int EVENT_SHOW_GAME_RULES = 35;
static const int EVENT_SHOW_SPEED = 36;
static const int EVENT_SHOW_BACK = 37;

static const int EVENT_APPLY_CELL_SIZE = 41;
static const int EVENT_APPLY_SPEED = 51;
static const int EVENT_APPLY_COLOR = 61;


// Color schemes

static int COLOR_SCHEME_GREEN = 1;
static int COLOR_SCHEME_AMBER = 2;
static int COLOR_SCHEME_XRAY = 3;

static const int COLOR_FORM_BACKGROUND_ID = 1;
static const int COLOR_CONTROL_NORMAL_BACKGROUND_ID = 2;
static const int COLOR_CONTROL_PRESSED_BACKGROUND_ID = 3;
static const int COLOR_TEXT_ID = 4;
static const int COLOR_CELL_ID = 5;

// Colors

static Color COLOR_FORM_BACKGROUND_XRAY(0,0,0);
static Color COLOR_CONTROL_NORMAL_BACKGROUND_XRAY(0,0,0);
static Color COLOR_CONTROL_PRESSED_BACKGROUND_XRAY(0,0,0);
static Color COLOR_TEXT_XRAY(0,0,0);
static Color COLOR_CELL_XRAY(0,0,0);

static Color COLOR_FORM_BACKGROUND_AMBER(255,126,0);
static Color COLOR_CONTROL_NORMAL_BACKGROUND_AMBER(255,126,0);
static Color COLOR_CONTROL_PRESSED_BACKGROUND_AMBER(255,126,0);
static Color COLOR_TEXT_AMBER(255,126,0);
static Color COLOR_CELL_AMBER(255,126,0);

static Color COLOR_FORM_BACKGROUND_GREEN(0,0,0);
static Color COLOR_CONTROL_NORMAL_BACKGROUND_GREEN(0,128,64);
static Color COLOR_CONTROL_PRESSED_BACKGROUND_GREEN(0,128,64);
static Color COLOR_TEXT_GREEN(0,255,0);
static Color COLOR_CELL_GREEN(0,255,0);

static Color* COLOR_FORM_BACKGROUND = &COLOR_FORM_BACKGROUND_GREEN;
static Color* COLOR_CONTROL_NORMAL_BACKGROUND = &COLOR_CONTROL_NORMAL_BACKGROUND_GREEN;
static Color* COLOR_CONTROL_PRESSED_BACKGROUND = &COLOR_CONTROL_PRESSED_BACKGROUND_GREEN;
static Color* COLOR_TEXT = &COLOR_TEXT_GREEN;
static Color* COLOR_CELL = &COLOR_CELL_GREEN;


// Strings

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
static String STRING_APPLY("APPLY");
static String STRING_CANCEL("CANCEL");

static String STRING_SPEED_FASTEST("FASTEST");
static String STRING_SPEED_TEN_FPS("TEN");
static String STRING_SPEED_FIVE_FPS("FIVE");
static String STRING_SPEED_ONE_FPS("ONE");
static String STRING_SPEED_LABEL("SPEED_LABEL");

static String STRING_ABOUT_INTRO_TEXT("ABOUT_INTRO_TEXT");
static String STRING_ABOUT_TEXT("ABOUT_TEXT");

#endif /* CONSTANTS_H_ */
