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

void
Constants::Init() {
	AppLog("Initializing strings");
//	String S;
//	Osp::App::AppResource* appResource = Osp::App::Application::GetInstance()->GetAppResource();
//
//	result r = appResource -> GetString(L"SUSPEND", S);
//	AppLog("Getting SUSPEND sting, result is %S", GetErrorMessage(r));
//	AppLog("Stirng is %s and %S", S.GetPointer(), S.GetPointer());
//
//	r = appResource -> GetString(L"SUSPEND", STRING_SUSPEND);
//	AppLog("Getting SUSPEND sting, result is %S", GetErrorMessage(r));
	AppLog("Stirng is %s and %S", STRING_SUSPEND.GetPointer(), STRING_SUSPEND.GetPointer());

//	appResource -> GetString("GENERATION_ZERO", STRING_GENERATION_ZERO);
//	appResource -> GetString("RESUME", STRING_RESUME);
//	appResource -> GetString("SEED", STRING_SEED);
//	appResource -> GetString("GENERATION_NUM", STRING_GENERATION_NUM);
//	appResource -> GetString("START", STRING_START);
}





