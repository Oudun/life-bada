/*
 * AbstractSettingsForm.cpp
 *
 *  Created on: 25.05.2014
 *      Author: Denis
 */

#include "AbstractSettingsForm.h"

using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Ui::Controls;

AbstractSettingsForm::AbstractSettingsForm() {
	// TODO Auto-generated constructor stub
}

AbstractSettingsForm::~AbstractSettingsForm() {
	// TODO Auto-generated destructor stub
}


bool
AbstractSettingsForm::Initialize(void) {
	Construct("ABSTRACT_SETTINGS_FORM");
	return true;
}

result
AbstractSettingsForm::OnInitializing(void) {

	SetBackgroundColor(GetColorModel()->formBkgColor);

	__list = static_cast<List *>(GetControl("IDC_LIST"));
	__list -> SetBackgroundColor(GetColorModel() -> formBkgColor);
	__list -> SetItemTextColor(LIST_ITEM_TEXT1, GetColorModel() -> formTextColor);
	__list -> SetItemTextColor(LIST_ITEM_TEXT2, GetColorModel() -> textColor);

	PopulateList();

	__buttonCancel = static_cast<Button *>(GetControl("IDC_BUTTON_CANCEL"));
	__buttonCancel -> SetActionId(IDC_BUTTON_CANCEL);
	__buttonCancel -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
	__buttonCancel -> SetTextColor(GetColorModel()->textColor);
	__buttonCancel -> SetText(Constants::GetString(STRING_CANCEL));
	__buttonCancel -> AddActionEventListener(*this);

	__buttonApply = static_cast<Button *>(GetControl("IDC_BUTTON_APPLY"));
	__buttonApply -> SetActionId(IDC_BUTTON_APPLY);
	__buttonApply -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
	__buttonApply -> SetTextColor(GetColorModel()->textColor);
	__buttonApply -> SetText(Constants::GetString(STRING_APPLY));
	__buttonApply -> AddActionEventListener(*this);

	__label = static_cast<Label *>(GetControl("IDC_LABEL"));
	__label -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__label -> SetTextColor(GetColorModel()->textColor);
	__label -> SetText(LABEL_TEXT);

	return E_SUCCESS;

}

void
AbstractSettingsForm::OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status) {

}

void
AbstractSettingsForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
	switch (actionId) {
		case IDC_BUTTON_CANCEL: {
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SETTINGS, null);
			break;
		}
		case IDC_BUTTON_APPLY: {
			IList* args = new ArrayList();
			int checkedIndex = __list -> GetFirstCheckedItemIndex();
			int checkedItemId = __list -> GetItemIdAt(checkedIndex);
			AppLog("Checked option id is %d", checkedItemId);
			args -> Add(*(new Integer(checkedItemId)));
			AppLog("FORM_EVENT_CODE is %d", FORM_EVENT_CODE);
			Osp::App::Application::GetInstance() -> SendUserEvent(FORM_EVENT_CODE, args);
			break;
		}
	}
}

void
AbstractSettingsForm::PopulateList(void) {
	AppLog("AbstractSettingsForm::PopulateList");
}

void
AbstractSettingsForm::RePaint(void) {

	AppLog("Repainting abstract settings form");

	PopulateList();

	this -> SetBackgroundColor(GetColorModel()->formBkgColor);

	__list -> SetBackgroundColor(GetColorModel() -> formBkgColor);
	__list -> SetItemTextColor(LIST_ITEM_TEXT1, GetColorModel() -> textColor);
	__list -> SetItemTextColor(LIST_ITEM_TEXT2, GetColorModel() -> textColor);

	__buttonCancel -> SetNormalBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
	__buttonCancel -> SetTextColor(GetColorModel()->textColor);

	__buttonApply -> SetNormalBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
	__buttonApply -> SetTextColor(GetColorModel()->textColor);

	__label -> SetBackgroundColor(GetColorModel()->formBkgColor);
	__label -> SetTextColor(GetColorModel()->textColor);

	AppLog("Done repainting abstract settings form");

}

void
AbstractSettingsForm::SetParam(int param) {
	__list -> SetItemChecked(__list -> GetItemIndexFromItemId(param), true);
}
