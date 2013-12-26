#include "LifeForm.h"
#include "Generation.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

LifeForm::LifeForm(void)
{
}

LifeForm::~LifeForm(void)
{
}

bool
LifeForm::Initialize()
{
	// Construct an XML form
	Construct(L"IDF_FORM1");

	return true;
}

result
LifeForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Osp::Graphics::Rectangle rectangle = GetBounds();
	Generation::Initialize(10, 10);
	AppLog("Height is %d", rectangle.height);

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

	Update();

	return r;
}

result
LifeForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
LifeForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
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

void
LifeForm::Update(void) {

	Osp::Graphics::Canvas* canvas;
	Control* control = GetControl(L"IDF_FORM1");
	canvas = control -> GetCanvasN();
	canvas -> SetBackgroundColor(Osp::Graphics::Color::COLOR_RED);
	canvas -> Clear();
	canvas -> Show();
	Draw();
	Show();

	for (int i=0; i < columns; i++) {
		for (int j=0; j < rows; j++) {
			//currentGeneration[i][j]

		}
	}
}


