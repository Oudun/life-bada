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
	
}

bool
AboutForm::Initialize(void) {
	AppLog("Initializing about form");
	Construct(L"ABOUT_FORM");
	return true;
}

result
AboutForm::OnInitializing(void) {

	SetBackgroundColor(GetColorModel()->formBkgColor);

	__textIntroLabel = static_cast<Label *>(GetControl("IDC_ABOUT_INTRO_LABEL"));
	__textIntroLabel -> SetEnabled(false);
	__textIntroLabel -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__textIntroLabel -> SetTextColor(GetColorModel()->formTextColor);
	__textIntroLabel -> SetText(Constants::GetString(STRING_ABOUT_INTRO_TEXT));

	__textLabel = static_cast<Label *>(GetControl("IDC_ABOUT_LABEL"));
	__textLabel -> SetEnabled(false);
	__textLabel -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__textLabel -> SetTextColor(GetColorModel()->formTextColor);
	__textLabel -> SetText(Constants::GetString(STRING_ABOUT_TEXT));

	__buttonBack = static_cast<Button *>(GetControl("IDC_BUTTON_ABOUT_BACK"));
	if (__buttonBack)
	{
		__buttonBack -> SetActionId(1);
		__buttonBack -> AddActionEventListener(*this);
		__buttonBack -> SetNormalBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
		__buttonBack -> SetTextColor(GetColorModel()->textColor);
		__buttonBack -> SetText(Constants::GetString(STRING_BACK));
	}

	__labelConway = static_cast<Label *>(GetControl("IDC_LABEL_CONWAY"));
	if (__labelConway)
	{
		__labelConway -> SetBackgroundBitmap(*(GetColorModel()->conwayBitmap));
		__labelConway -> SetBackgroundColor(GetColorModel()->formBkgColor);
	}

	return E_SUCCESS;

}

void
AboutForm::OnActionPerformed(const Osp::Ui::Control &source, int actionId)
{
	Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SETTINGS, null);
}

void
AboutForm::RePaint(void)
{
	SetBackgroundColor(GetColorModel()->formBkgColor);

	__textIntroLabel -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__textIntroLabel -> SetTextColor(GetColorModel()->formTextColor);

	__textLabel -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__textLabel -> SetTextColor(GetColorModel()->formTextColor);

	__buttonBack -> SetNormalBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
	__buttonBack -> SetTextColor(GetColorModel()->textColor);

	__labelConway -> SetBackgroundBitmap(*(GetColorModel()->conwayBitmap));
	__labelConway -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__labelConway -> SetTextColor(GetColorModel()->textColor);

}

