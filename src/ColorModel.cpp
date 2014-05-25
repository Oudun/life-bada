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
		formBkgColor = Color(0, 0, 0);
		controlNormalBkgColor = Color(0, 128, 64);
		controlPressedBkgColor = Color(0, 128, 64);
		textColor = Color(0, 255, 0);
		cellColor = Color(0, 255, 0);
	} else if (id ==2 ) { // AMBER
		formBkgColor = Color(0, 0, 0);
		controlNormalBkgColor = Color(130, 62, 0);
		controlPressedBkgColor = Color(255, 126, 0);
		textColor = Color(255, 126, 0);
		cellColor = Color(255, 126, 0);
	} else {
		formBkgColor = Color(200, 200, 255);
		controlNormalBkgColor = Color(100, 100, 200);
		controlPressedBkgColor = Color(100, 100, 200);
		textColor = Color(255, 255, 255);
		cellColor = Color(100, 100, 200);
	}

	Osp::Graphics::Canvas __buttonCanvas;
	Osp::Graphics::Rectangle __buttonRectangle(0,0,30,80);

	__buttonCanvas.Construct(__buttonRectangle);
	__buttonCanvas.FillRectangle(controlNormalBkgColor, __buttonRectangle);
	normalBackgroundBitmap.Construct(__buttonCanvas,__buttonRectangle);

	__buttonCanvas.FillRectangle(controlPressedBkgColor, __buttonRectangle);
	pressedBackgroundBitmap.Construct(__buttonCanvas,__buttonRectangle);

}

ColorModel::~ColorModel() {
	// TODO Auto-generated destructor stub
}
