/*
 * CellSizeForm.cpp
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#include "ColorForm.h"
#include "Constants.h"

using namespace Osp::App;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

ColorForm::ColorForm() {
	// TODO Auto-generated constructor stub

}

ColorForm::~ColorForm() {
	// TODO Auto-generated destructor stub
}

bool
ColorForm::Initialize(void) {
	Construct(L"COLOR_FORM");
	return true;
}

result
ColorForm::OnInitializing(void) {

	SetBackgroundColor(COLOR_FORM_BACKGROUND);

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* __bitmapGreen = pAppResource->GetBitmapN(L"GreenScheme.png");
	Bitmap* __bitmapAmber = pAppResource->GetBitmapN(L"AmberScheme.png");
	Bitmap* __bitmapXray = pAppResource->GetBitmapN(L"XrayScheme.png");
	Bitmap* __bitmapButton = pAppResource->GetBitmapN(L"Button.png");

	__listColor =  static_cast<List *>(GetControl("IDC_LIST_COLOR"));
//todo
	String __greenScheme("Green");
	String __amberScheme("Amber");
	String __xrayScheme("X-Ray");

	__listColor -> SetBackgroundColor(COLOR_FORM_BACKGROUND);
	__listColor -> SetItemTextColor(LIST_ITEM_TEXT1, COLOR_TEXT);
	__listColor -> AddItem(&__greenScheme, null, __bitmapGreen, null, INDEX_GREEN);
	__listColor -> AddItem(&__amberScheme, null, __bitmapAmber, null, INDEX_AMBER);
	__listColor -> AddItem(&__xrayScheme, null, __bitmapXray, null, INDEX_XRAY);

	__listColor -> AddItemEventListener(*this);

	__buttonApply =  static_cast<Button *>(GetControl("IDC_BUTTON_APPLY"));
	__buttonApply -> SetNormalBackgroundBitmap(*__bitmapButton);
	__buttonApply -> SetTextColor(COLOR_TEXT);
	__buttonApply -> SetText(Constants::GetString(STRING_APPLY));
	__buttonApply -> SetActionId(IDC_BUTTON_APPLY);
	__buttonApply -> AddActionEventListener(*this);

	__buttonCancel =  static_cast<Button *>(GetControl("IDC_BUTTON_CANCEL"));
	__buttonCancel -> SetNormalBackgroundBitmap(*__bitmapButton);
	__buttonCancel -> SetTextColor(COLOR_TEXT);
	__buttonCancel -> SetText(Constants::GetString(STRING_CANCEL));
	__buttonCancel -> SetActionId(IDC_BUTTON_CANCEL);
	__buttonCancel -> AddActionEventListener(*this);

	__labelColor =  static_cast<Label *>(GetControl("IDC_LABEL_COLOR"));
	__labelColor -> SetBackgroundColor(COLOR_FORM_BACKGROUND);
	__labelColor -> SetTextColor(COLOR_TEXT);
	__labelColor -> SetText(Constants::GetString(STRING_COLOR_SCHEME));

	return E_SUCCESS;
	Button *pButton_color = static_cast<Button *>(GetControl("IDC_BUTTON_COLOR"));  
	if (pButton_color)
	{
		pButton_color->SetActionId(1);
		pButton_color->AddActionEventListener(*this);
	}

}

void
ColorForm::OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status) {
	switch (itemId) {
		case INDEX_GREEN: {
			AppLog("Green");
//			Constants::SetColorScheme(COLOR_SCHEME_GREEN);
			break;
		}
		case INDEX_AMBER: {
			AppLog("Amber");
			Color assignedColor = __labelColor -> GetTextColor();
			Color storedColor = COLOR_TEXT;
			AppLog("Assigned color is %d", &assignedColor);
			AppLog("Stored color is %d", &storedColor);
			break;
		}
		case INDEX_XRAY: {
			AppLog("X-Ray");
//			Constants::SetColorScheme(COLOR_SCHEME_XRAY);
			break;
		}
	}
}

void
ColorForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
	switch(actionId)
	{
	case IDC_BUTTON_CANCEL:
		{
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SETTINGS, null);
			break;
		}
//todo re-implement
	case IDC_BUTTON_APPLY:
		{
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SETTINGS, null);
			break;
		}
	}
}




