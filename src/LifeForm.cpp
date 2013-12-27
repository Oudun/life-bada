#include "LifeForm.h"
#include "Generation.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

LifeForm::LifeForm(void)
{
	__seedSize = 20;

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

	// TODO: Add your initialization code here

	// Get a button via resource ID
	__pButtonOk = static_cast<Button *>(GetControl(L"IDC_BUTTON_SEED"));
	if (__pButtonOk != null)
	{
		__pButtonOk->SetActionId(IDC_BUTTON_SEED);
		__pButtonOk->AddActionEventListener(*this);
	}

	Button *pButton_seed = static_cast<Button *>(GetControl("IDC_BUTTON_SEED"));  
	if (pButton_seed)
	{
		pButton_seed->SetActionId(1);
		pButton_seed->AddActionEventListener(*this);
	}

	return r;
	Button *pButton1 = static_cast<Button *>(GetControl("IDC_BUTTON1"));  
	if (pButton1)
	{
		pButton1->SetActionId(2);
		pButton1->AddActionEventListener(*this);
	}
	Button *pButton_start = static_cast<Button *>(GetControl("IDC_BUTTON_START"));  
	if (pButton_start)
	{
		pButton_start->SetActionId(2);
		pButton_start->AddActionEventListener(*this);
	}

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

	AppLog("Button ID is %d\n", actionId);

	switch(actionId)
	{
	case IDC_BUTTON_SEED:
		{
			Generation::Initialize(
					GetBounds().width/__seedSize,
					GetBounds().height/__seedSize
					);
			Update();
		}
		break;
	case IDC_BUTTON_START:
		{
			AppLog("Start?");
			Osp::App::Application::GetInstance() -> SendUserEvent(START_BUTTON_PRESSED, null);
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

	AppLog("!!!Updating");

	Osp::Graphics::Canvas* canvas;
	Control* control = GetControl(L"IDF_FORM1");
	canvas = control -> GetCanvasN();
	canvas -> FillRectangle(Osp::Graphics::Color::COLOR_BLACK, GetBounds());

	for (int i=0; i < Generation::GetColumns(); i++) {
		for (int j=0; j < Generation::GetRows(); j++) {
			if(Generation::IsOccupied(i, j)) {
				canvas -> FillRectangle(Osp::Graphics::Color::COLOR_GREEN, Osp::Graphics::Rectangle(
						i*__seedSize,
						j*__seedSize,
						__seedSize,
						__seedSize
				));
			}
		}
	}

	AppLog("!!!Showing now");

	canvas -> Show();

}


