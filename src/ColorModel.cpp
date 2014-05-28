/*
 * ColorModel.cpp
 *
 *  Created on: 23.05.2014
 *      Author: ddreval
 */

#include "ColorModel.h"

using namespace Osp::App;

ColorModel::ColorModel() {
	AppLog("ColorModel::ColorModel()");
	ColorModel(1);
}

ColorModel::ColorModel(int id) {

	AppLog("ColorModel::ColorModel(%d)", id);

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	if (id == 1) { //GREEN
		formBkgColor = Color(0, 0, 0);
		formTextColor = Color(0, 255, 0);
		controlNormalBkgColor = Color(0, 128, 64);
		controlPressedBkgColor = Color(0, 128, 64);
		textColor = Color(0, 255, 0);
		cellColor = Color(0, 255, 0);
		conwayBitmap = pAppResource -> GetBitmapN(L"ConwayGreen.png");
		sizeThreeBitmap = pAppResource -> GetBitmapN(L"3x3xGreen.png");
		sizeFiveBitmap = pAppResource -> GetBitmapN(L"5x5xGreen.png");
		sizeTenBitmap = pAppResource -> GetBitmapN(L"10x10xGreen.png");
		sizeTwentyBitmap = pAppResource -> GetBitmapN(L"20x20xGreen.png");
	} else if (id ==2 ) { // AMBER
		formBkgColor = Color(0, 0, 0);
		formTextColor = Color(255, 126, 0);
		controlNormalBkgColor = Color(130, 62, 0);
		controlPressedBkgColor = Color(255, 126, 0);
		textColor = Color(255, 126, 0);
		cellColor = Color(255, 126, 0);
		conwayBitmap = pAppResource -> GetBitmapN(L"ConwayAmber.png");
		sizeThreeBitmap = pAppResource -> GetBitmapN(L"3x3xAmber.png");
		sizeFiveBitmap = pAppResource -> GetBitmapN(L"5x5xAmber.png");
		sizeTenBitmap = pAppResource -> GetBitmapN(L"10x10xAmber.png");
		sizeTwentyBitmap = pAppResource -> GetBitmapN(L"20x20xAmber.png");
	} else {
		formBkgColor = Color(200, 200, 255);
		formTextColor = Color(100, 100, 200);
		controlNormalBkgColor = Color(100, 100, 200);
		controlPressedBkgColor = Color(100, 100, 200);
		textColor = Color(255, 255, 255);
		cellColor = Color(100, 100, 200);
		conwayBitmap = pAppResource -> GetBitmapN(L"ConwayXray.png");
		sizeThreeBitmap = pAppResource -> GetBitmapN(L"3x3xXray.png");
		sizeFiveBitmap = pAppResource -> GetBitmapN(L"5x5xXray.png");
		sizeTenBitmap = pAppResource -> GetBitmapN(L"10x10xXray.png");
		sizeTwentyBitmap = pAppResource -> GetBitmapN(L"20x20xXray.png");
	}


	Osp::Graphics::Canvas __buttonCanvas;
	Osp::Graphics::Rectangle __buttonRectangle(0,0,30,80);

	__buttonCanvas.Construct(__buttonRectangle);
	__buttonCanvas.FillRectangle(controlNormalBkgColor, __buttonRectangle);
	normalBackgroundBitmap.Construct(__buttonCanvas,__buttonRectangle);

	__buttonCanvas.FillRectangle(controlPressedBkgColor, __buttonRectangle);
	pressedBackgroundBitmap.Construct(__buttonCanvas,__buttonRectangle);

	surfaceThorBitmap = pAppResource -> GetBitmapN(L"Torus.png");
	surfaceKleinBitmap = pAppResource -> GetBitmapN(L"Klein.png");
	surfaceProjectiveBitmap = pAppResource -> GetBitmapN(L"ProjPlane.png");

	colorXrayBitmap = pAppResource -> GetBitmapN(L"XrayScheme.png");
	colorAmberBitmap = pAppResource -> GetBitmapN(L"AmberScheme.png");
	colorGreenBitmap = pAppResource -> GetBitmapN(L"GreenScheme.png");


}

ColorModel::~ColorModel() {
	// TODO Auto-generated destructor stub
}

ColorModel*
ColorModel::GetInstance(int id) {
	AppLog("ColorModel::GetInstance(%d)", id);
	TryLog(__greenInstance != null, "The __greenInstance is null.");
	if (id == 1) { //why if (id == COLOR_SCHEME_GREEN) { does not work?
		AppLog("1");
		if (__greenInstance == null) {
			AppLog("2");
			__greenInstance = new ColorModel(1);
			AppLog("3");
		}
		AppLog("4");
		return __greenInstance;
	} else  if (id == 2) {
		AppLog("5");
		if (__amberInstance == null) {
			AppLog("6");
			__amberInstance = new ColorModel(2);
			AppLog("7");
		}
		AppLog("8");
		return __amberInstance;
	} else if (id == 3) {
		AppLog("9");
		if (__xrayInstance == null) {
			AppLog("10");
			__xrayInstance = new ColorModel(3);
			AppLog("11");
		}
		return __xrayInstance;
	} else {
		AppLog("12");
		AppLog("There is no Color Scheme with ID = %d", id);
		return null;
	}
}

