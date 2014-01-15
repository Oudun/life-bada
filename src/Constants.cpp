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
	if (id==null) {
		AppLog("Id is NULL");
	}
	String localResult;
	AppLog("Getting localized version of %S", id.GetPointer());
	Osp::App::AppResource* appResource = Osp::App::Application::GetInstance()->GetAppResource();
	result r = appResource -> GetString(id, localResult);
	AppLog("Getting resource %S result is %s string is %S", STRING_SUSPEND.GetPointer(), GetErrorMessage(r), localResult.GetPointer());
	return localResult;
}





