#include "LifeForm.h"
#include "Generation.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

LifeForm::LifeForm(void)
{
	__seedSize = 10;

}

LifeForm::~LifeForm(void)
{
}

bool
LifeForm::Initialize()
{
	// Construct an XML form
	Construct(L"LIFE_FORM");

	return true;
}

result
LifeForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	__seedButton = static_cast<Button *>(GetControl("IDC_BUTTON_SEED"));
	if (__seedButton)
	{
		__seedButton->SetActionId(IDC_BUTTON_SEED);
		__seedButton->AddActionEventListener(*this);
	}

	__startButton = static_cast<Button *>(GetControl("IDC_BUTTON_START"));
	if (__startButton)
	{
		__startButton->SetActionId(IDC_BUTTON_START);
		__startButton->AddActionEventListener(*this);
	}

	__settingsButton = static_cast<Button *>(GetControl("IDC_BUTTON_SETTINGS"));
	if (__settingsButton)
	{
		__settingsButton->SetActionId(IDC_BUTTON_SETTINGS);
		__settingsButton->AddActionEventListener(*this);
	}

	__counterLabel = static_cast<Label *>(GetControl("IDC_LABEL_GENERATION"));

//	Label *_counterLabel

	Generation::Initialize(
			GetBounds().width/__seedSize,
			GetBounds().height/__seedSize
			);

	return r;
	Button *pButton1 = static_cast<Button *>(GetControl("IDC_BUTTON1"));  
	if (pButton1)
	{
		pButton1->SetActionId(3);
		pButton1->AddActionEventListener(*this);
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
			Osp::App::Application::GetInstance() -> SendUserEvent(SEED_BUTTON_PRESSED, null);
			break;
		}
	case IDC_BUTTON_START:
		{
			AppLog("Start?");
			Osp::App::Application::GetInstance() -> SendUserEvent(START_BUTTON_PRESSED, null);
			break;
		}
	case IDC_BUTTON_SETTINGS:
		{
			AppLog("Start?");
			Osp::App::Application::GetInstance() -> SendUserEvent(SETTINGS_BUTTON_PRESSED, null);
			break;
		}
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

void
LifeForm::UpdateGenerationNumber(void) {
	if (Generation::GetCounter() > 0) {
		String counterStr;
		counterStr.Format(40, L"Generation number %d", Generation::GetCounter());
		__counterLabel -> SetText(counterStr.GetPointer());
	} else {
		String defaultStr("Evolution is not started yet.");
		__counterLabel -> SetText(defaultStr.GetPointer());
	}
	__counterLabel -> RequestRedraw(true);
}

void
LifeForm::SetStartLabel(Osp::Base::String &labelText) {
	__startButton -> SetText(labelText);
	__startButton -> RequestRedraw(true);
}

