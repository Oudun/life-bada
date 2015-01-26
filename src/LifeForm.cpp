#include "LifeForm.h"
#include "Generation.h"
#include "Constants.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

LifeForm::LifeForm(void)
{
	//__seedSize = 10;

	if (IS_DEMO) {
		int rand = Constants::GetRandom();
		if (rand < 8000) {
			__seedSize = SIZE_THREE;
		} else if (rand <16000) {
			__seedSize = SIZE_FIVE;
		} else if (rand <24000) {
			__seedSize = SIZE_TEN;
		} else {
			__seedSize = SIZE_TWENTY;
		}
	} else {
		__seedSize = Constants::GetStored(STORED_SIZE);
	}

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

	SetOrientation(Osp::Ui::ORIENTATION_PORTRAIT);
	result r = E_SUCCESS;

	__seedButton = static_cast<Button *>(GetControl("IDC_BUTTON_SEED"));
	if (__seedButton)
	{
		__seedButton -> SetActionId(IDC_BUTTON_SEED);
		__seedButton -> AddActionEventListener(*this);
		__seedButton -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
		__seedButton -> SetText(Constants::GetString(STRING_SEED));
		__seedButton -> SetTextColor(GetColorModel()->textColor);
	}

	__startButton = static_cast<Button *>(GetControl("IDC_BUTTON_START"));
	if (__startButton)
	{
		__startButton -> SetActionId(IDC_BUTTON_START);
		__startButton -> AddActionEventListener(*this);
		__startButton -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
		__startButton -> SetText(Constants::GetString(STRING_START));
		__startButton -> SetTextColor(GetColorModel()->textColor);
	}

	__settingsButton = static_cast<Button *>(GetControl("IDC_BUTTON_SETTINGS"));
	if (__settingsButton)
	{
		__settingsButton -> SetActionId(IDC_BUTTON_SETTINGS);
		__settingsButton -> AddActionEventListener(*this);
		__settingsButton -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
		__settingsButton -> SetTextColor(GetColorModel()->textColor);
	}

	__counterLabel = static_cast<Label *>(GetControl("IDC_LABEL_GENERATION"));
	__counterLabel -> SetText(Constants::GetString(STRING_GENERATION_ZERO));
	__counterLabel -> SetTextColor(GetColorModel()->textColor);
	__counterLabel -> SetBackgroundColor(GetColorModel()->controlNormalBkgColor);

	SetBackgroundColor(GetColorModel()->formBkgColor);

	Control* control = GetControl(L"LIFE_FORM");
	__lifeFieldCanvas = control -> GetCanvasN(0,
			__counterLabel->GetBounds().height,
			GetBounds().width,
			GetBounds().height-(
					__counterLabel->GetBounds().height
					+ __startButton->GetBounds().height));

	InitializeField();

	AppLog("Initializing Life Form - done");

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

	result r = __lifeFieldCanvas -> FillRectangle(GetColorModel()->formBkgColor, GetBounds());

	if (__lifeFieldCanvas == null) {
		AppLog("Canvas is null");
	}

	AppLog("Canvas filling result is %s", GetErrorMessage(r));

	AppLog("Cell Color is (%d, %d, %d)",
			GetColorModel()->cellColor.GetRed(),
			GetColorModel()->cellColor.GetGreen(),
			GetColorModel()->cellColor.GetBlue());

	int c = 0;

	for (int i=0; i < Generation::GetColumns(); i++) {
		for (int j=0; j < Generation::GetRows(); j++) {
			if(Generation::IsOccupied(i, j)) {
				c++;
				__lifeFieldCanvas -> FillRectangle(GetColorModel()->cellColor,
					Osp::Graphics::Rectangle(
						i*__seedSize,
						j*__seedSize,
						__seedSize-1,
						__seedSize-1
					)
				);
			}
		}
	}

	AppLog("%d cells painted", c);
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
LifeForm::UpdateGenerationSurface(int id) {
	Generation::SetSurface(id);
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

void
LifeForm::RePaint(void) {

	AppLog("Repainting started");

	this -> SetBackgroundColor(GetColorModel()->formBkgColor);

	__seedButton -> SetNormalBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
	__seedButton -> SetTextColor(GetColorModel()->textColor);

	__startButton -> SetNormalBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
	__startButton -> SetTextColor(GetColorModel()->textColor);

	__settingsButton -> SetNormalBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
	__settingsButton -> SetTextColor(GetColorModel()->textColor);

	__counterLabel -> SetBackgroundColor(GetColorModel()->controlNormalBkgColor);
	__counterLabel -> SetTextColor(GetColorModel()->textColor);

	RequestRedraw(true);

	AppLog("Repainting ended");

}
