
#include "RulesForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


RulesForm::RulesForm(void)
{
}

RulesForm::~RulesForm(void)
{
}

bool
RulesForm::Initialize()
{
	Form::Construct(L"RULES_FORM");
	return true;
}

result
RulesForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	SetBackgroundColor(GetColorModel()->formBkgColor);

	__label = static_cast<Label*>(GetControl("IDC_LABEL_RULES"));
	__label -> SetText(Constants::GetString(STRING_RULES));
	__label -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__label -> SetTextColor(GetColorModel()->formTextColor);

	__buttonBack = static_cast<Button*>(GetControl("IDC_BUTTON_BACK"));
	__buttonBack -> SetActionId(IDC_BUTTON_BACK);
	__buttonBack -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
	__buttonBack -> SetTextColor(GetColorModel()->textColor);
	__buttonBack -> SetText(Constants::GetString(STRING_BACK));
	__buttonBack -> AddActionEventListener(*this);

	__buttonAbout = static_cast<Button*>(GetControl("IDC_BUTTON_ABOUT"));
	__buttonAbout -> SetActionId(IDC_BUTTON_ABOUT);
	__buttonAbout -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
	__buttonAbout -> SetTextColor(GetColorModel()->textColor);
	__buttonAbout -> SetText(Constants::GetString(STRING_HISTORY));
	__buttonAbout -> AddActionEventListener(*this);

	return r;

}

result
RulesForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
RulesForm::RePaint(void) {

	this -> SetBackgroundColor(GetColorModel()->formBkgColor);

	__label -> SetBackgroundColor(GetColorModel() -> formBkgColor);
	__label -> SetTextColor(GetColorModel() -> formTextColor);

	__buttonBack -> SetNormalBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
	__buttonBack -> SetTextColor(GetColorModel()->textColor);

	__buttonAbout -> SetNormalBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
	__buttonAbout -> SetTextColor(GetColorModel()->textColor);

}

void
RulesForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {

	switch (actionId) {
		case IDC_BUTTON_BACK: {
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SETTINGS, null);
			break;
		}
		case IDC_BUTTON_ABOUT: {
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_ABOUT_GAME, null);
			break;
		}
	}

}


