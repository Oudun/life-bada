/*
 * ColorForm.cpp
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#include "CellSizeForm.h"
#include "Constants.h"

using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

CellSizeForm::CellSizeForm(int pCellSize) {
	cellSize = pCellSize;
}

CellSizeForm::~CellSizeForm() {
	// TODO Auto-generated destructor stub
}

bool
CellSizeForm::Initialize(void) {
	Construct(L"CELL_SIZE_FORM");
	return true;
}

result
CellSizeForm::OnInitializing(void) {

	SetBackgroundColor(*COLOR_FORM_BACKGROUND);

	__listCellSize = static_cast<List *>(GetControl("IDC_LIST_SIZE_FORM"));

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	Bitmap* __bitmapButton = pAppResource->GetBitmapN(L"Button.png");
	Bitmap* __bitmap3x3 = pAppResource->GetBitmapN(L"3x3.png");
	Bitmap* __bitmap5x5 = pAppResource->GetBitmapN(L"5x5.png");
	Bitmap* __bitmap10x10 = pAppResource->GetBitmapN(L"10x10.png");
	Bitmap* __bitmap20x20 = pAppResource->GetBitmapN(L"20x20.png");

	Osp::Base::String str3x3(L"3x3");
	Osp::Base::String str5x5(L"5x5");
	Osp::Base::String str10x10(L"10x10");
	Osp::Base::String str20x20(L"20x20");

	__listCellSize -> SetBackgroundColor(*COLOR_FORM_BACKGROUND);
	__listCellSize -> SetItemTextColor(LIST_ITEM_TEXT1, *COLOR_TEXT);
	__listCellSize -> AddItem(&str3x3, null, __bitmap3x3, null, INDEX_THREE);
	__listCellSize -> AddItem(&str5x5, null, __bitmap5x5, null, INDEX_FIVE);
	__listCellSize -> AddItem(&str10x10, null, __bitmap10x10, null, INDEX_TEN);
	__listCellSize -> AddItem(&str20x20, null, __bitmap20x20, null, INDEX_TWENTY);

	int indexChecked = __listCellSize -> GetItemIndexFromItemId(cellSize);
	__listCellSize -> SetItemChecked(indexChecked, true);

	Button *__buttonCancel = static_cast<Button *>(GetControl("IDC_BUTTON_CANCEL"));
	if (__buttonCancel)
	{
		__buttonCancel -> SetActionId(IDC_BUTTON_CANCEL);
		__buttonCancel -> SetNormalBackgroundBitmap(*__bitmapButton);
		__buttonCancel -> SetTextColor(*COLOR_TEXT);
		__buttonCancel -> SetText(Constants::GetString(STRING_CANCEL));
		__buttonCancel -> AddActionEventListener(*this);
	}

	Button *__buttonApply = static_cast<Button *>(GetControl("IDC_BUTTON_APPLY"));
	if (__buttonApply)
	{
		__buttonApply -> SetActionId(IDC_BUTTON_APPLY);
		__buttonApply -> SetNormalBackgroundBitmap(*__bitmapButton);
		__buttonApply -> SetTextColor(*COLOR_TEXT);
		__buttonApply -> SetText(Constants::GetString(STRING_APPLY));
		__buttonApply -> AddActionEventListener(*this);
	}

	Label *__labelCellSize = static_cast<Label *>(GetControl("IDC_LABEL_SIZE_FORM"));
	if (__labelCellSize)
	{
		__labelCellSize -> SetBackgroundColor(*COLOR_FORM_BACKGROUND);
		__labelCellSize -> SetTextColor(*COLOR_TEXT);
		__labelCellSize -> SetText(Constants::GetString(STRING_CELL_SIZE));
	}

	return E_SUCCESS;
}

void
CellSizeForm::OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status) {
//	switch (itemId) {
//		case INDEX_THREE: {
//			break;
//		}
//		case INDEX_FIVE: {
//			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_APPLY_CELL_SIZE, INDEX_FIVE);
//			break;
//		}
//		case INDEX_TEN: {
//			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_APPLY_CELL_SIZE, INDEX_TEN);
//			break;
//		}
//		case INDEX_TWENTY: {
//			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_APPLY_CELL_SIZE, INDEX_TWENTY);
//			break;
//		}
//	}
}

void
CellSizeForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
	switch (actionId) {
		case IDC_BUTTON_CANCEL: {
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SETTINGS, null);
			break;
		}
		case IDC_BUTTON_APPLY: {
			IList* args = new ArrayList();
			int checkedIndex = __listCellSize -> GetFirstCheckedItemIndex();
			int checkedItemId = __listCellSize -> GetItemIdAt(checkedIndex);
			cellSize = checkedItemId;
			args -> Add(*(new Integer(checkedItemId)));
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_APPLY_CELL_SIZE, args);
			break;
		}
	}

}
