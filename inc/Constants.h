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

using Osp::Base::String;

class Constants {
public:
	Constants();
	virtual ~Constants();
	static String GetString(String& id);
	static String* GetStringPointer(String& id);

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
static const int EVENT_SHOW_WARNING = 38;

static const int EVENT_APPLY_CELL_SIZE = 41;
static const int EVENT_APPLY_SPEED = 51;
static const int EVENT_APPLY_COLOR = 61;
static const int EVENT_APPLY_RULES = 71;
static const int EVENT_APPLY_SURFACE = 81;

// Color schemes

static int COLOR_SCHEME_GREEN = 1;
static int COLOR_SCHEME_AMBER = 2;
static int COLOR_SCHEME_XRAY = 3;

// Generation update speed

static int SPEED_FASTEST = 0;
static int SPEED_TEN_FPS = 100;
static int SPEED_FIVE_FPS = 200;
static int SPEED_ONE_FPS = 1000;

// Cell Size

const static int SIZE_THREE = 3;
const static int SIZE_FIVE = 5;
const static int SIZE_TEN = 10;
const static int SIZE_TWENTY = 20;

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

static String STRING_SURFACE_TORUS("SURFACE_TORUS");
static String STRING_SURFACE_KLEIN("SURFACE_KLEIN");
static String STRING_SURFACE_PROJECTIVE("SURFACE_PROJECTIVE");

static String STRING_RULES("RULES");
static String STRING_HISTORY("HISTORY");

static String STRING_NOTAVALIABLE("NOT_AVAIALBLE");

static bool const IS_DEMO = 1;

#endif /* CONSTANTS_H_ */

