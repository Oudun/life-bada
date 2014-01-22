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

	AppLog("Initializing Life Form");

	result r = E_SUCCESS;

	Osp::Graphics::Canvas __buttonCanvas;
	Osp::Graphics::Rectangle __buttonRectangle(0,0,30,80);
	Osp::Graphics::Bitmap __buttonBitmap;

	__buttonCanvas.Construct(__buttonRectangle);
	__buttonCanvas.FillRectangle(COLOR_CONTROL_NORMAL_BACKGROUND, __buttonRectangle);
	__buttonBitmap.Construct(__buttonCanvas,__buttonRectangle);

	// TODO: Add your initialization code here

	__seedButton = static_cast<Button *>(GetControl("IDC_BUTTON_SEED"));
	if (__seedButton)
	{
		__seedButton->SetActionId(IDC_BUTTON_SEED);
		__seedButton->AddActionEventListener(*this);
		__seedButton->SetNormalBackgroundBitmap(__buttonBitmap);
		__seedButton -> SetText(Constants::GetString(STRING_SEED));
	}

	__startButton = static_cast<Button *>(GetControl("IDC_BUTTON_START"));
	if (__startButton)
	{
		__startButton -> SetActionId(IDC_BUTTON_START);
		__startButton -> AddActionEventListener(*this);
		__startButton -> SetNormalBackgroundBitmap(__buttonBitmap);
		__startButton -> SetText(Constants::GetString(STRING_START));
	}

	__settingsButton = static_cast<Button *>(GetControl("IDC_BUTTON_SETTINGS"));
	if (__settingsButton)
	{
		__settingsButton->SetActionId(IDC_BUTTON_SETTINGS);
		__settingsButton->AddActionEventListener(*this);
		__settingsButton->SetNormalBackgroundBitmap(__buttonBitmap);
	}

	__counterLabel = static_cast<Label *>(GetControl("IDC_LABEL_GENERATION"));
	__counterLabel -> SetText(Constants::GetString(STRING_GENERATION_ZERO));

	//this->SetBackgroundColor(Osp::Graphics::Color::COLOR_BLACK);
	SetBackgroundColor(COLOR_FORM_BACKGROUND);

	Control* control = GetControl(L"LIFE_FORM");
	__lifeFieldCanvas = control -> GetCanvasN(0, 30, 240, 340);

	InitializeField();

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
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SEED, null);
			break;
		}
	case IDC_BUTTON_START:
		{
			AppLog("Start?");
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_START, null);
			break;
		}
	case IDC_BUTTON_SETTINGS:
		{
			AppLog("Start?");
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SETTINGS, null);
			break;
		}
	default:
		break;
	}

}

void
LifeForm::Update(void) {

	AppLog("!!!Updating");

//	Osp::Graphics::Canvas* canvas;
//	Control* control = GetControl(L"LIFE_FORM");
//	canvas = control -> GetCanvasN();

	result r = __lifeFieldCanvas -> FillRectangle(COLOR_FORM_BACKGROUND, GetBounds());

	if (__lifeFieldCanvas == null) {
		AppLog("Canvas is null");
	}
	AppLog("Canvas filling result is %s", GetErrorMessage(r));

	for (int i=0; i < Generation::GetColumns(); i++) {
		for (int j=0; j < Generation::GetRows(); j++) {
			if(Generation::IsOccupied(i, j)) {
				__lifeFieldCanvas -> FillRectangle(COLOR_CELL, Osp::Graphics::Rectangle(
						i*__seedSize,
						j*__seedSize,
						__seedSize-1,
						__seedSize-1
				));
			}
		}
	}

	AppLog("!!!Showing now");

	r = __lifeFieldCanvas -> Show();
	AppLog("Canvas show result is %s", GetErrorMessage(r));
	AppLog("Canvas is %d %d %d %d",
			__lifeFieldCanvas -> GetBounds().x,
			__lifeFieldCanvas -> GetBounds().y,
			__lifeFieldCanvas -> GetBounds().width,
			__lifeFieldCanvas -> GetBounds().height);

}

void
LifeForm::UpdateGenerationNumber(void) {
	if (Generation::GetCounter() > 0) {
		String __counterStr = Constants::GetString(STRING_GENERATION_NUM);
		__counterStr.Append(Generation::GetCounter());
		AppLog("Generation label is %S", __counterStr.GetPointer());
		__counterLabel -> SetText(__counterStr.GetPointer());
		__counterStr.~String();
	} else {
		__counterLabel -> SetText(Constants::GetString(STRING_GENERATION_ZERO).GetPointer());
	}
	__counterLabel -> RequestRedraw(true);
}

void
LifeForm::SetStartLabel(Osp::Base::String labelText) {
	__startButton -> SetText(labelText);
	__startButton -> RequestRedraw(true);
}

void
LifeForm::SetCellSize(int size) {
	__seedSize = size;
}

int
LifeForm::GetCellSize(void) {
	return __seedSize;
}

void
LifeForm::InitializeField(void) {
	Generation::Initialize(
		__lifeFieldCanvas->GetBounds().width/__seedSize,
		__lifeFieldCanvas->GetBounds().height/__seedSize
	);
}
