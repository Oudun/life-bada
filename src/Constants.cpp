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

int
Constants::GetRandom(void) {
	Osp::Base::DateTime time;
	Osp::System::SystemTime::GetCurrentTime(time);
	Osp::Base::Utility::Math::Srand(time.GetSecond());
	int random = Osp::Base::Utility::Math::Rand();
	AppLog("Random is %d", random);
	return random;
	//Osp::Base::Utility::Math::Srand(Time);
}

int
Constants::GetStored(String& key) {

	AppLog("Getting %S", key.GetPointer());

	Osp::App::AppRegistry* appRegistry = Osp::App::Application::GetInstance()->GetAppRegistry();
	int value;
	int& v = value;
	result r = appRegistry -> Get(key, v);

	AppLog("Value is %d", v);

	if (r == E_KEY_NOT_FOUND) {
		AppLog("Key not found");
		if (key == STORED_SIZE) {
			v = SIZE_TEN;
		} else if (key == STORED_COLOR ){
			v = COLOR_SCHEME_GREEN;
		} else {
			v = 0;
		}
	} else {
		AppLog("Result is %S", GetErrorMessage(r));
	}

	return v;
}

void
Constants::Store(String& key, int value) {

	if (!IS_DEMO) {

		AppLog("Storing %d as %S", value, key.GetPointer());
		Osp::App::AppRegistry* appRegistry = Osp::App::Application::GetInstance()->GetAppRegistry();

		int value1;
		result r = appRegistry -> Get(key, value1);
		if (r == E_KEY_NOT_FOUND) {
			r = appRegistry -> Add(key, value);
			AppLog("Adding result is %S", GetErrorMessage(r));
		} else {
			r = appRegistry -> Set(key, value);
			AppLog("Storing result is %S", GetErrorMessage(r));
		}
		appRegistry -> Save();
		AppLog("Saving result is %S", GetErrorMessage(r));



		appRegistry -> Get(key, value1);
		AppLog("Stored value is %d", value1);

	}

}
