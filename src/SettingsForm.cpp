/*
 * SettingsForm.cpp
 *
 *  Created on: 11.01.2014
 *      Author: Denis
 */

#include "SettingsForm.h"
#include "Constants.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

SettingsForm::SettingsForm() {
	AppLog("Constructing settings form");
}

SettingsForm::~SettingsForm() {
	
}

bool
SettingsForm::Initialize(void) {
	AppLog("Initializing settings form");
	Construct(L"SETTINGS_FORM");
	return true;
}

result
SettingsForm::OnInitializing(void) {

	SetBackgroundColor(GetColorModel()->formBkgColor);
	__settingsList = new List();
	__settingsList = static_cast<List *>(GetControl("SETTINGS_LIST"));
	//AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	//Bitmap* __bgImage = pAppResource->GetBitmapN(L"Splash_type3.png");

	__settingsList -> AddItem(Constants::GetStringPointer(STRING_SURFACE), null, null, null, INDEX_SURFACE);
	__settingsList -> AddItem(Constants::GetStringPointer(STRING_CELL_SIZE), null, null, null, INDEX_CELL_SIZE);
	__settingsList -> AddItem(Constants::GetStringPointer(STRING_COLOR_SCHEME), null, null, null, INDEX_COLOR_SCHEME);
//	__settingsList -> AddItem(Constants::GetStringPointer(STRING_GAME_RULES), null, null, null, INDEX_GAME_RULES);
	__settingsList -> AddItem(Constants::GetStringPointer(STRING_SPEED), null, null, null, INDEX_SPEED);

	__settingsList -> SetItemTextColor(LIST_ITEM_TEXT1, GetColorModel()->formTextColor);
	__settingsList -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__settingsList -> AddItemEventListener(*this);

	__settingsLabel = static_cast<Label *>(GetControl("SETTINGS_LABEL"));
	__settingsLabel -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__settingsLabel -> SetTextColor(GetColorModel()->formTextColor);
	__settingsLabel -> SetText(Constants::GetString(STRING_SETTINGS));

	__backButton = static_cast<Button *>(GetControl("IDC_BUTTON_BACK"));
	if (__backButton)
	{
		__backButton -> SetActionId(IDC_BUTTON_BACK);
		__backButton -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
		__backButton -> SetText(Constants::GetString(STRING_BACK));
		__backButton -> SetTextColor(GetColorModel()->textColor);
		__backButton -> AddActionEventListener(*this);
	}

	__aboutButton = static_cast<Button *>(GetControl("IDC_BUTTON_ABOUT"));
	if (__aboutButton)
	{
		__aboutButton -> SetActionId(IDC_BUTTON_ABOUT);
		__aboutButton -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
		__aboutButton -> SetText(Constants::GetString(STRING_ABOUT_GAME));
		__aboutButton -> SetTextColor(GetColorModel()->textColor);
		__aboutButton -> AddActionEventListener(*this);
	}

	return E_SUCCESS;

}

result
SettingsForm::OnTerminating(void) {
	return E_SUCCESS;
}

void
SettingsForm::OnItemStateChanged(
		const Osp::Ui::Control& source,
		int index,
		int itemId,
		Osp::Ui::ItemStatus status)
{
	AppLog("Index is %d id is %d", index, itemId);
	switch(itemId) {
	case INDEX_BACK:
		{
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_BACK, null);
			break;
		}
	case INDEX_COLOR_SCHEME:
		{
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_COLOR_SCHEME, null);
			break;
		}
	case INDEX_CELL_SIZE:
		{
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_CELL_SIZE, null);
			break;
		}
	case INDEX_SURFACE:
		{
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SURFACE, null);
			break;
		}
	case INDEX_GAME_RULES:
		{
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_GAME_RULES, null);
			break;
		}
	case INDEX_SPEED:
		{
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SPEED, null);
			break;
		}
	default:
		{
			break;
		}
	}
}

void
SettingsForm::OnActionPerformed(const Osp::Ui::Control &source, int actionId) {
	switch(actionId) {
		case IDC_BUTTON_BACK: {
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_BACK, null);
			break;
		}
		case IDC_BUTTON_ABOUT: {
			Control* control = GetControl(L"SETTINGS_FORM");
			Canvas* __bgCanvas = control -> GetCanvasN(GetBounds());
			//__bgCanvas -> DrawBitmap(Rectangle(0, 0, 240, 400), *__bgImage);
			__bgCanvas -> Clear();
			__bgCanvas -> FillRectangle(Color::COLOR_RED, Rectangle(GetBounds()));
			RequestRedraw(true);
			//Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_ABOUT_GAME, null);
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_GAME_RULES, null);
			break;
		}
		default: {
			break;
		}
	}
}

void
SettingsForm::RePaint(void) {

	AppLog("Re-painting Settings form");

	SetBackgroundColor(GetColorModel()->formBkgColor);

	__settingsList -> SetBackgroundColor(GetColorModel() -> formBkgColor);
	__settingsList -> SetItemTextColor(LIST_ITEM_TEXT1, GetColorModel() -> formTextColor);
	__settingsList -> SetItemTextColor(LIST_ITEM_TEXT2, GetColorModel() -> formTextColor);

	__settingsLabel -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__settingsLabel -> SetTextColor(GetColorModel()->textColor);

	__backButton -> SetNormalBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
	__backButton -> SetTextColor(GetColorModel()->textColor);

	__aboutButton -> SetNormalBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
	__aboutButton -> SetTextColor(GetColorModel()->textColor);

}

