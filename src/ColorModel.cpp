/*
 * ColorModel.cpp
 *
 *  Created on: 23.05.2014
 *      Author: ddreval
 */

#include "ColorModel.h"
#include "Constants.h"

using namespace Osp::App;

ColorModel::ColorModel() {
	AppLog("ColorModel::ColorModel()");
	ColorModel(1);
}

ColorModel::ColorModel(int pId) {

	AppLog("ColorModel::ColorModel(%d)", id);

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	if (pId == 1) { //GREEN
		id = 1;
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
		surfaceThorBitmap = pAppResource -> GetBitmapN(L"TorusGreen.png");
		surfaceKleinBitmap = pAppResource -> GetBitmapN(L"KleinGreen.png");
		surfaceProjectiveBitmap = pAppResource -> GetBitmapN(L"ProjPlaneGreen.png");
	} else if (pId ==2 ) { // AMBER
		id = 2;
		formBkgColor = Color(0, 0, 0);
		formTextColor = Color(255, 126, 0);
		controlNormalBkgColor = Color(130, 62, 0);
		controlPressedBkgColor = Color(255, 126, 0);
		textColor = Color(255, 175, 96);
		cellColor = Color(255, 126, 0);
		conwayBitmap = pAppResource -> GetBitmapN(L"ConwayAmber.png");
		sizeThreeBitmap = pAppResource -> GetBitmapN(L"3x3xAmber.png");
		sizeFiveBitmap = pAppResource -> GetBitmapN(L"5x5xAmber.png");
		sizeTenBitmap = pAppResource -> GetBitmapN(L"10x10xAmber.png");
		sizeTwentyBitmap = pAppResource -> GetBitmapN(L"20x20xAmber.png");
		surfaceThorBitmap = pAppResource -> GetBitmapN(L"TorusAmber.png");
		surfaceKleinBitmap = pAppResource -> GetBitmapN(L"KleinAmber.png");
		surfaceProjectiveBitmap = pAppResource -> GetBitmapN(L"ProjPlaneAmber.png");
	} else {
		id = 3;
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
		surfaceThorBitmap = pAppResource -> GetBitmapN(L"TorusXray.png");
		surfaceKleinBitmap = pAppResource -> GetBitmapN(L"KleinXray.png");
		surfaceProjectiveBitmap = pAppResource -> GetBitmapN(L"ProjPlaneXray.png");
	}


	Osp::Graphics::Canvas __buttonCanvas;
	Osp::Graphics::Rectangle __buttonRectangle(0,0,30,80);

	__buttonCanvas.Construct(__buttonRectangle);
	__buttonCanvas.FillRectangle(controlNormalBkgColor, __buttonRectangle);
	normalBackgroundBitmap.Construct(__buttonCanvas,__buttonRectangle);

	__buttonCanvas.FillRectangle(controlPressedBkgColor, __buttonRectangle);
	pressedBackgroundBitmap.Construct(__buttonCanvas,__buttonRectangle);

	colorXrayBitmap = pAppResource -> GetBitmapN(L"XrayScheme.png");
	colorAmberBitmap = pAppResource -> GetBitmapN(L"AmberScheme.png");
	colorGreenBitmap = pAppResource -> GetBitmapN(L"GreenScheme.png");


}

ColorModel::~ColorModel() {
	// TODO Auto-generated destructor stub
}

ColorModel*
ColorModel::GetInstance(int pId) {
	AppLog("ColorModel::GetInstance(%d)", pId);
	TryLog(__greenInstance != null, "The __greenInstance is null.");
	if (pId == 1) { //why if (id == COLOR_SCHEME_GREEN) { does not work?
		AppLog("1");
		if (__greenInstance == null) {
			AppLog("2");
			__greenInstance = new ColorModel(1);
			AppLog("3");
		}
		AppLog("4");
		return __greenInstance;
	} else  if (pId == 2) {
		AppLog("5");
		if (__amberInstance == null) {
			AppLog("6");
			__amberInstance = new ColorModel(2);
			AppLog("7");
		}
		AppLog("8");
		return __amberInstance;
	} else if (pId == 3) {
		AppLog("9");
		if (__xrayInstance == null) {
			AppLog("10");
			__xrayInstance = new ColorModel(3);
			AppLog("11");
		}
		return __xrayInstance;
	} else {
		AppLog("12");
		AppLog("There is no Color Scheme with ID = %d", pId);
		return null;
	}
}

ColorModel*
ColorModel::GetModel() {

	if (IS_DEMO) {

		int rand = Constants::GetRandom();

		if (rand < 10000) {
			return GetInstance(COLOR_SCHEME_GREEN);
		} else if (rand < 20000) {
			return GetInstance(COLOR_SCHEME_AMBER);
		} else {
			return GetInstance(COLOR_SCHEME_XRAY);
		}
	} else {

		return GetInstance(Constants::GetStored(STORED_COLOR));

	}

}
