#include "Form1.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

Form1::Form1(void)
{
}

Form1::~Form1(void)
{
}

bool
Form1::Initialize()
{
	// Construct an XML form
	Construct(L"IDF_FORM1");

	return true;
}

result
Form1::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Get a button via resource ID
	__pButtonOk = static_cast<Button *>(GetControl(L"IDC_BUTTON_OK"));
	if (__pButtonOk != null)
	{
		__pButtonOk->SetActionId(ID_BUTTON_OK);
		__pButtonOk->AddActionEventListener(*this);
	}

	Button *pButton_seed = static_cast<Button *>(GetControl("IDC_BUTTON_SEED"));  
	if (pButton_seed)
	{
		pButton_seed->SetActionId(1);
		pButton_seed->AddActionEventListener(*this);
	}
	return r;
}

result
Form1::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
Form1::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_BUTTON_OK:
		{
			AppLog("OK Button is clicked! \n");
		}
		break;
	default:
		break;
	}

	/*
	 *
	 *
	 * */

}


