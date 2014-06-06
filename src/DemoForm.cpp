
#include "DemoForm.h"
#include "Constants.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


DemoForm::DemoForm(void)
{
}

DemoForm::~DemoForm(void)
{
}

bool
DemoForm::Initialize()
{
	Form::Construct(L"DEMO_FORM");

	return true;
}

result
DemoForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Label *label = static_cast<Label *>(GetControl("IDC_LABEL"));
	label -> SetText(Constants::GetString(STRING_NOTAVALIABLE));

	Button *pButton_back = static_cast<Button *>(GetControl("IDC_BUTTON_BACK"));  
	if (pButton_back)
	{
		pButton_back->SetActionId(0);
		pButton_back->SetText(Constants::GetString(STRING_BACK));
		pButton_back->AddActionEventListener(*this);
	}
	return r;
}

result
DemoForm::OnTerminating(void)
{
	result r = E_SUCCESS;
	return r;
}



void
DemoForm::OnActionPerformed(const Osp::Ui::Control &source, int actionId)
{
	Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SETTINGS, null);
}
