/*
 * SpeedForm.cpp
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#include "SpeedForm.h"
#include "Constants.h"

using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

SpeedForm::SpeedForm() {
	delay = 100;
}

SpeedForm::~SpeedForm() {
	// TODO Auto-generated destructor stub
}

bool
SpeedForm::Initialize(void) {
	Construct(L"SPEED_FORM");
	return true;
}

result
SpeedForm::OnInitializing(void) {
	//SetBackgroundColor(COLOR_FORM_BACKGROUND);
	//Constants* c = new Constants();
	SetBackgroundColor(GetColorModel()->formBkgColor);
	//SetBackgroundColor(*(new Color(255,126,0)));


	__listSpeed = static_cast<List *>(GetControl("IDC_LIST_SPEED"));

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	__listSpeed -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__listSpeed -> SetItemTextColor(LIST_ITEM_TEXT1, GetColorModel()->textColor);
	__listSpeed -> AddItem(Constants::GetStringPointer(STRING_SPEED_FASTEST), null, null, null, INDEX_FASTEST);
	__listSpeed -> AddItem(Constants::GetStringPointer(STRING_SPEED_TEN_FPS), null, null, null, INDEX_TEN);
	__listSpeed -> AddItem(Constants::GetStringPointer(STRING_SPEED_FIVE_FPS), null, null, null, INDEX_FIVE);
	__listSpeed -> AddItem(Constants::GetStringPointer(STRING_SPEED_ONE_FPS), null, null, null, INDEX_ONE);

	int indexChecked = __listSpeed -> GetItemIndexFromItemId(delay);
	__listSpeed -> SetItemChecked(indexChecked, true);

	Button *__buttonCancel = static_cast<Button *>(GetControl("IDC_BUTTON_CANCEL"));
	if (__buttonCancel)
	{
		__buttonCancel -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
		__buttonCancel -> SetActionId(IDC_BUTTON_CANCEL);
		__buttonCancel -> SetTextColor(GetColorModel()->textColor);
		__buttonCancel -> SetText(Constants::GetString(STRING_CANCEL));
		__buttonCancel -> AddActionEventListener(*this);
	}

	Button *__buttonApply = static_cast<Button *>(GetControl("IDC_BUTTON_APPLY"));
	if (__buttonApply)
	{
		__buttonApply -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
		__buttonApply -> SetActionId(IDC_BUTTON_APPLY);
		__buttonApply -> SetTextColor(GetColorModel()->textColor);
		__buttonApply -> SetText(Constants::GetString(STRING_APPLY));
		__buttonApply -> AddActionEventListener(*this);
	}

	Label *__labelSpeed = static_cast<Label *>(GetControl("IDC_LABEL_SPEED_FORM"));
	if (__labelSpeed)
	{
		__labelSpeed -> SetBackgroundColor(GetColorModel()->formBkgColor);
		__labelSpeed -> SetTextColor(GetColorModel()->textColor);
		__labelSpeed -> SetText(Constants::GetString(STRING_SPEED_LABEL));
	}

	return E_SUCCESS;
}

void
SpeedForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
	switch (actionId) {
		case IDC_BUTTON_CANCEL: {
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SETTINGS, null);
			break;
		}
		case IDC_BUTTON_APPLY: {
			IList* args = new ArrayList();
			int checkedIndex = __listSpeed -> GetFirstCheckedItemIndex();
			int checkedItemId = __listSpeed -> GetItemIdAt(checkedIndex);
			delay = checkedItemId;
			args -> Add(*(new Integer(checkedItemId)));
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_APPLY_SPEED, args);
			break;
		}
	}
}

