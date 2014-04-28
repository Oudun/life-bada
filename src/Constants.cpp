/*
 * Constants.cpp
 *
 *  Created on: 24.12.2013
 *      Author: ddreval
 */

#include "Constants.h"

Constants::Constants() {
}

Constants::~Constants() {
	// TODO Auto-generated destructor stub
};

String
Constants::GetString(String& id) {
	String localResult;
	Osp::App::AppResource* appResource = Osp::App::Application::GetInstance()->GetAppResource();
	appResource -> GetString(id, localResult);
	return localResult;
}

String*
Constants::GetStringPointer(String& id) {
	String* localResult = new String();
	Osp::App::AppResource* appResource = Osp::App::Application::GetInstance()->GetAppResource();
	appResource -> GetString(id, *localResult);
	return localResult;
}

void
Constants::SetColorScheme(int id) {

	AppLog("Color Object reference is %d", &COLOR_FORM_BACKGROUND);
	AppLog("Current COLOR_FORM_BACKGROUND is (%d, %d, %d)", COLOR_FORM_BACKGROUND -> GetRed(), COLOR_FORM_BACKGROUND -> GetGreen(), COLOR_FORM_BACKGROUND -> GetBlue());

	if (id == COLOR_SCHEME_GREEN) {
		AppLog("Setting green scheme");
		COLOR_FORM_BACKGROUND = &COLOR_FORM_BACKGROUND_GREEN;
		COLOR_CONTROL_NORMAL_BACKGROUND = &COLOR_CONTROL_NORMAL_BACKGROUND_GREEN;
		COLOR_CONTROL_PRESSED_BACKGROUND = &COLOR_CONTROL_PRESSED_BACKGROUND_GREEN;
		COLOR_TEXT = &COLOR_TEXT_GREEN;
		COLOR_CELL = &COLOR_CELL_GREEN;
	} else if (id == COLOR_SCHEME_AMBER) {
		AppLog("Setting amber scheme");
		COLOR_FORM_BACKGROUND = &COLOR_FORM_BACKGROUND_AMBER;
		COLOR_CONTROL_NORMAL_BACKGROUND = &COLOR_CONTROL_NORMAL_BACKGROUND_AMBER;
		COLOR_CONTROL_PRESSED_BACKGROUND = &COLOR_CONTROL_PRESSED_BACKGROUND_AMBER;
		COLOR_TEXT = &COLOR_TEXT_AMBER;
		COLOR_CELL = &COLOR_CELL_AMBER;
	} else {
		AppLog("Setting xray scheme");
		COLOR_FORM_BACKGROUND = &COLOR_FORM_BACKGROUND_XRAY;
		COLOR_CONTROL_NORMAL_BACKGROUND = &COLOR_CONTROL_NORMAL_BACKGROUND_XRAY;
		COLOR_CONTROL_PRESSED_BACKGROUND = &COLOR_CONTROL_PRESSED_BACKGROUND_XRAY;
		COLOR_TEXT = &COLOR_TEXT_XRAY;
		COLOR_CELL = &COLOR_CELL_XRAY;
	}

	AppLog("Changed COLOR_FORM_BACKGROUND is (%d, %d, %d)", COLOR_FORM_BACKGROUND -> GetRed(), COLOR_FORM_BACKGROUND -> GetGreen(), COLOR_FORM_BACKGROUND -> GetBlue());

	//	COLOR_FORM_BACKGROUND = Color::COLOR_RED;
//	COLOR_CONTROL_NORMAL_BACKGROUND = Color::COLOR_RED;
//	COLOR_CONTROL_PRESSED_BACKGROUND = Color::COLOR_RED;
//	COLOR_TEXT = Color::COLOR_RED;
//	COLOR_CELL = Color::COLOR_RED;
}

Color*
Constants::GetColor(int id) {
	if (id == COLOR_FORM_BACKGROUND_ID) {
		return COLOR_FORM_BACKGROUND;
	} else if (id == COLOR_CONTROL_NORMAL_BACKGROUND_ID) {
		return COLOR_TEXT;
	} else if (id == COLOR_CONTROL_PRESSED_BACKGROUND_ID) {
		return COLOR_TEXT;
	} else if (id == COLOR_TEXT_ID) {
		return COLOR_TEXT;
	} else if (id == COLOR_CELL_ID) {
		return COLOR_CELL;
	}
}




