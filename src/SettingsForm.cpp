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

	__settingsList = new List();

	__settingsList -> Construct(
			Rectangle(0, 0, 240, 400),
			LIST_STYLE_NORMAL,
			LIST_ITEM_SINGLE_IMAGE_TEXT, 64, 64, 64, 176);

	String __stringOne("One");
	String __stringTwo("Two");

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* __bitmapSurface = pAppResource->GetBitmapN(L"Surface.png");
	Bitmap* __bitmapConway = pAppResource->GetBitmapN(L"Conway.png");

	__settingsList -> AddItem(&__stringOne, &__stringTwo, __bitmapConway, __bitmapConway, null);
	__settingsList -> AddItem(&__stringOne, &__stringTwo, __bitmapSurface, __bitmapSurface, null);

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
