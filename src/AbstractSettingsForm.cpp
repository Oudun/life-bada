/*
 * AbstractSettingsForm.cpp
 *
 *  Created on: 25.05.2014
 *      Author: Denis
 */

#include "AbstractSettingsForm.h"

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
//			IList* args = new ArrayList();
//			int checkedIndex = __listCellSize -> GetFirstCheckedItemIndex();
//			int checkedItemId = __listCellSize -> GetItemIdAt(checkedIndex);
//			cellSize = checkedItemId;
//			args -> Add(*(new Integer(checkedItemId)));
//			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_APPLY_CELL_SIZE, args);
			AppLog("FORM_EVENT_CODE is %d", FORM_EVENT_CODE);
			Osp::App::Application::GetInstance() -> SendUserEvent(FORM_EVENT_CODE, null);
			break;
		}
	}
}

void
AbstractSettingsForm::PopulateList(void) {
	AppLog("AbstractSettingsForm::PopulateList");
}
