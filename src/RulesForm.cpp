/*
 * RulesForm.cpp
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#include "RulesForm.h"
#include "Constants.h"

using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

RulesForm::RulesForm() {
//	FORM_EVENT_CODE = EVENT_APPLY_RULES;
//	LABEL_TEXT = Constants::GetString(STRING_GAME_RULES);
}



RulesForm::~RulesForm() {
	// TODO Auto-generated destructor stub
}
//
bool
RulesForm::Initialize(void) {
	Construct("RULES_FORM");
	return true;
}
//
result
RulesForm::OnInitializing(void) {

	__list = new CustomList();
	__list -> Construct(Rectangle(0, 0, 480, 500), CUSTOM_LIST_STYLE_NORMAL);

	CustomListItemFormat* __format = new CustomListItemFormat();
	__format -> Construct();

	CustomListItem* __listItem = new CustomListItem();
	__listItem -> Construct(100);
	__listItem -> SetItemFormat(*__format);
	__listItem -> SetHighlightedItemBackgroundBitmap(GetColorModel()->normalBackgroundBitmap);
	__listItem -> SetCheckBox(1);

	__list -> AddItem(*__listItem, 1);

	this->AddControl(*__list);

	return E_SUCCESS;
}

void
RulesForm::PopulateList(void) {
	AppLog("RulesForm::PopulateList");
//
//	__list = static_cast<List *>(GetControl("IDC_LIST"));
//	__list -> AddItem();

}

void
RulesForm::OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status) {

}

void
RulesForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {

}



