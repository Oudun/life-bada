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
}

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
	COLOR_FORM_BACKGROUND = Color::COLOR_RED;
	COLOR_CONTROL_NORMAL_BACKGROUND = Color::COLOR_RED;
	COLOR_CONTROL_PRESSED_BACKGROUND = Color::COLOR_RED;
	COLOR_TEXT = Color::COLOR_RED;
	COLOR_CELL = Color::COLOR_RED;
}




