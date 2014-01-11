#include "LifeForm.h"
#include "Generation.h"
#include "Constants.h"

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

	Osp::Graphics::Canvas __buttonCanvas;
	Osp::Graphics::Rectangle __buttonRectangle(0,0,30,80);
	Osp::Graphics::Bitmap __buttonBitmap;

	__buttonCanvas.Construct(__buttonRectangle);
	__buttonCanvas.FillRectangle(CONTROL_NORMAL_BACKGROUND, __buttonRectangle);
	__buttonBitmap.Construct(__buttonCanvas,__buttonRectangle);

	// TODO: Add your initialization code here

	__seedButton = static_cast<Button *>(GetControl("IDC_BUTTON_SEED"));
	if (__seedButton)
	{
		__seedButton->SetActionId(IDC_BUTTON_SEED);
		__seedButton->AddActionEventListener(*this);
		__seedButton->SetNormalBackgroundBitmap(__buttonBitmap);
	}

	__startButton = static_cast<Button *>(GetControl("IDC_BUTTON_START"));
	if (__startButton)
	{
		__startButton->SetActionId(IDC_BUTTON_START);
		__startButton->AddActionEventListener(*this);
		__startButton->SetNormalBackgroundBitmap(__buttonBitmap);
	}

	__settingsButton = static_cast<Button *>(GetControl("IDC_BUTTON_SETTINGS"));
	if (__settingsButton)
	{
		__settingsButton->SetActionId(IDC_BUTTON_SETTINGS);
		__settingsButton->AddActionEventListener(*this);
		__settingsButton->SetNormalBackgroundBitmap(__buttonBitmap);
	}

	__counterLabel = static_cast<Label *>(GetControl("IDC_LABEL_GENERATION"));

	//this->SetBackgroundColor(Osp::Graphics::Color::COLOR_BLACK);
	SetBackgroundColor(FORM_BACKGROUND);

//	Label *_counterLabel

	Control* control = GetControl(L"LIFE_FORM");
	__lifeFieldCanvas = control -> GetCanvasN(0, 30, 240, 340);

	Generation::Initialize(
			__lifeFieldCanvas->GetBounds().width/__seedSize,
			__lifeFieldCanvas->GetBounds().height/__seedSize
			);

//	Generation::Initialize(
//			GetBounds().width/__seedSize,
//			GetBounds().height/__seedSize
//			);

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

//	Osp::Graphics::Canvas* canvas;
//	Control* control = GetControl(L"LIFE_FORM");
//	canvas = control -> GetCanvasN();

	result r = __lifeFieldCanvas -> FillRectangle(FORM_BACKGROUND, GetBounds());

	AppLog("Canvas filling result is %S", GetErrorMessage(r));

	for (int i=0; i < Generation::GetColumns(); i++) {
		for (int j=0; j < Generation::GetRows(); j++) {
			if(Generation::IsOccupied(i, j)) {
				__lifeFieldCanvas -> FillRectangle(CELL_COLOR, Osp::Graphics::Rectangle(
						i*__seedSize,
						j*__seedSize,
						__seedSize-1,
						__seedSize-1
				));
			}
		}
	}

	AppLog("!!!Showing now");

	__lifeFieldCanvas -> Show();
//	__lifeFieldCanvas -> ~Canvas();

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

