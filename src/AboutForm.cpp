/*
 * AboutForm.cpp
 *
 *  Created on: 16.01.2014
 *      Author: ddreval
 */

#include "AboutForm.h"
#include "Constants.h"

using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

AboutForm::AboutForm() {
	// TODO Auto-generated constructor stub

}

AboutForm::~AboutForm() {
	// TODO Auto-generated destructor stub
}

bool
AboutForm::Initialize(void) {
	AppLog("Initializing about form");
	Construct(L"ABOUT_FORM");
	return true;
}

result
AboutForm::OnInitializing(void) {

	SetBackgroundColor(COLOR_FORM_BACKGROUND);

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* __bitmapConway = pAppResource->GetBitmapN(L"Conway.png");
	Bitmap* __bitmapButton = pAppResource->GetBitmapN(L"Button.png");

	Label* __textIntroLabel = static_cast<Label *>(GetControl("IDC_ABOUT_INTRO_LABEL"));
	__textIntroLabel -> SetEnabled(false);
	__textIntroLabel -> SetBackgroundColor(COLOR_FORM_BACKGROUND);
	__textIntroLabel -> SetTextColor(COLOR_TEXT);
	__textIntroLabel -> SetText(Constants::GetString(STRING_ABOUT_INTRO_TEXT));

	Label* __textLabel = static_cast<Label *>(GetControl("IDC_ABOUT_LABEL"));
	__textLabel -> SetEnabled(false);
	__textLabel -> SetBackgroundColor(COLOR_FORM_BACKGROUND);
	__textLabel -> SetTextColor(COLOR_TEXT);
	__textLabel -> SetText(Constants::GetString(STRING_ABOUT_TEXT));

	Button *pButton_about_back = static_cast<Button *>(GetControl("IDC_BUTTON_ABOUT_BACK"));
	if (pButton_about_back)
	{
		pButton_about_back -> SetActionId(1);
		pButton_about_back -> AddActionEventListener(*this);
		pButton_about_back -> SetNormalBackgroundBitmap(*__bitmapButton);
		pButton_about_back -> SetTextColor(COLOR_TEXT);
		pButton_about_back -> SetText(Constants::GetString(STRING_BACK));
	}

	Label *__labelConway = static_cast<Label *>(GetControl("IDC_LABEL_CONWAY"));
	if (__labelConway)
	{
		__labelConway -> SetBackgroundBitmap(*__bitmapConway);
		__labelConway -> SetBackgroundColor(COLOR_FORM_BACKGROUND);
	}

	return E_SUCCESS;

}

void
AboutForm::OnActionPerformed(const Osp::Ui::Control &source, int actionId)
{
	Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SETTINGS, null);
}
