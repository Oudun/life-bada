/*
 * ColorModel.cpp
 *
 *  Created on: 23.05.2014
 *      Author: ddreval
 */

#include "ColorModel.h"

ColorModel::ColorModel() {
	AppLog("ColorModel::ColorModel()");
	ColorModel(1);
}

ColorModel::ColorModel(int id) {
	AppLog("ColorModel::ColorModel(%d)", id);
	if (id == 1) { //GREEN
		formBkgColor = new Color(0, 0, 0);
		controlNormalBkgColor = new Color(0, 128, 64);
		controlPressedBkgColor = new Color(0, 128, 64);
		textColor = new Color(0, 255, 0);
		cellColor = new Color(0, 255, 0);
	} else if (id ==2 ) { // AMBER
		formBkgColor = new Color(0, 0, 0);
		controlNormalBkgColor = new Color(130, 62, 0);
		controlPressedBkgColor = new Color(130, 62, 0);
		textColor = new Color(0, 0, 0);
		cellColor = new Color(0, 0, 0);
	} else {
		formBkgColor = new Color(200, 200, 255);
		controlNormalBkgColor = new Color(100, 100, 200);
		controlPressedBkgColor = new Color(100, 100, 200);
		textColor = new Color(200, 200, 255);
		cellColor = new Color(200, 200, 255);
	}

//	static Color COLOR_FORM_BACKGROUND_GREEN(0,0,0);
//	static Color COLOR_CONTROL_NORMAL_BACKGROUND_GREEN(0,128,64);
//	static Color COLOR_CONTROL_PRESSED_BACKGROUND_GREEN(0,128,64);
//	static Color COLOR_TEXT_GREEN(0,255,0);
//	static Color COLOR_CELL_GREEN(0,255,0);



//	static int COLOR_SCHEME_GREEN = 1;
//	static int COLOR_SCHEME_AMBER = 2;
//	static int COLOR_SCHEME_XRAY = 3;
//
//	static const int COLOR_FORM_BACKGROUND_ID = 1;
//	static const int COLOR_CONTROL_NORMAL_BACKGROUND_ID = 2;
//	static const int COLOR_CONTROL_PRESSED_BACKGROUND_ID = 3;
//	static const int COLOR_TEXT_ID = 4;
//	static const int COLOR_CELL_ID = 5;
//
//	// Colors
//
//	static Color COLOR_FORM_BACKGROUND_XRAY(200,200,255);
//	static Color COLOR_CONTROL_NORMAL_BACKGROUND_XRAY(100,100,200);
//	static Color COLOR_CONTROL_PRESSED_BACKGROUND_XRAY(100,100,200);
//	static Color COLOR_TEXT_XRAY(200,200,255);
//	static Color COLOR_CELL_XRAY(50,50,100);
//
//	//static Color COLOR_FORM_BACKGROUND_XRAY(255,0,0);
//	//static Color COLOR_CONTROL_NORMAL_BACKGROUND_XRAY(0,255,0);
//	//static Color COLOR_CONTROL_PRESSED_BACKGROUND_XRAY(0,0,255);
//	//static Color COLOR_TEXT_XRAY(255,255,0);
//	//static Color COLOR_CELL_XRAY(255,0,255);
//
//	static Color COLOR_FORM_BACKGROUND_AMBER(0,0,0);
//	static Color COLOR_CONTROL_NORMAL_BACKGROUND_AMBER(130,62,0);
//	static Color COLOR_CONTROL_PRESSED_BACKGROUND_AMBER(130,62,0);
//	static Color COLOR_TEXT_AMBER(0,0,0);
//	static Color COLOR_CELL_AMBER(0,0,0);
//
//	static Color COLOR_FORM_BACKGROUND_GREEN(0,0,0);
//	static Color COLOR_CONTROL_NORMAL_BACKGROUND_GREEN(0,128,64);
//	static Color COLOR_CONTROL_PRESSED_BACKGROUND_GREEN(0,128,64);
//	static Color COLOR_TEXT_GREEN(0,255,0);
//	static Color COLOR_CELL_GREEN(0,255,0);
//
//	static Color* COLOR_FORM_BACKGROUND = &COLOR_FORM_BACKGROUND_GREEN;
//	static Color* COLOR_CONTROL_NORMAL_BACKGROUND = &COLOR_CONTROL_NORMAL_BACKGROUND_GREEN;
//	static Color* COLOR_CONTROL_PRESSED_BACKGROUND = &COLOR_CONTROL_PRESSED_BACKGROUND_GREEN;
//	static Color* COLOR_TEXT = &COLOR_TEXT_GREEN;
//	static Color* COLOR_CELL = &COLOR_CELL_GREEN;
}

ColorModel::~ColorModel() {
	// TODO Auto-generated destructor stub
}
