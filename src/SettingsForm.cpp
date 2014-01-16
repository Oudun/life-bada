/*
 * SettingsForm.cpp
 *
 *  Created on: 11.01.2014
 *      Author: Denis
 */

#include "SettingsForm.h"
#include "Constants.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

SettingsForm::SettingsForm() {
	AppLog("Constructing settings form");
}

SettingsForm::~SettingsForm() {
	// TODO Auto-generated destructor stub
}

bool
SettingsForm::Initialize(void) {
	AppLog("Initializing settings form");
	Construct(L"SETTINGS_FORM");
	return true;
}

result
SettingsForm::OnInitializing(void) {

	SetTitleText(Constants::GetString(STRING_EXTRA), ALIGNMENT_CENTER);

	__settingsList = new List();

	__settingsList -> Construct(
			Rectangle(0, 0, 240, 400),
			LIST_STYLE_NORMAL,
			LIST_ITEM_SINGLE_IMAGE_TEXT, 50, 50, 50, 190);

	String __stringOne("One");
	String __stringTwo("Two");

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* __bitmapSurface = pAppResource->GetBitmapN(L"Surface.png");
	Bitmap* __bitmapConway = pAppResource->GetBitmapN(L"Conway.png");

	__settingsList -> AddItem(&Constants::GetString(STRING_ABOUT_GAME), null, __bitmapConway, null, INDEX_ABOUT_GAME);
	__settingsList -> AddItem(&Constants::GetString(STRING_SURFACE), null, __bitmapSurface, null, INDEX_SURFACE);
	__settingsList -> AddItem(&Constants::GetString(STRING_CELL_SIZE), null, __bitmapConway, null, INDEX_CELL_SIZE);
	__settingsList -> AddItem(&Constants::GetString(STRING_COLOR_SCHEME), null, __bitmapConway, null, INDEX_COLOR_SCHEME);
	__settingsList -> AddItem(&Constants::GetString(STRING_GAME_RULES), null, __bitmapConway, null, INDEX_GAME_RULES);
	__settingsList -> AddItem(&Constants::GetString(STRING_SPEED), null, __bitmapConway, null, INDEX_SPEED);
	__settingsList -> AddItem(&Constants::GetString(STRING_BACK), null, __bitmapConway, null, INDEX_BACK);

//	static String STRING_SETTINGS("SETTINGS");
//	static String STRING_ABOUT_GAME("ABOUT_GAME");
//	static String STRING_COLOR_SCHEME("COLOR_SCHEME");
//	static String STRING_GAME_RULES("GAME_RULES");
//	static String STRING_CELL_SIZE("CELL_SIZE");
//	static String STRING_SPEED("SPEED");
//	static String STRING_DONE("DONE");

	__settingsList -> SetItemTextColor(LIST_ITEM_TEXT1, COLOR_TEXT);

	__settingsList -> SetBackgroundColor(COLOR_FORM_BACKGROUND);

	AddControl(*__settingsList);

	__settingsList -> RequestRedraw(true);

	return E_SUCCESS;
}

result
SettingsForm::OnTerminating(void) {
	return E_SUCCESS;
}

void
SettingsForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {

}
