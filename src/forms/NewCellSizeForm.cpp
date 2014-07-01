/*
 * NewCellSizeForm.cpp
 *
 *  Created on: 28.05.2014
 *      Author: ddreval
 */

#include "forms/NewCellSizeForm.h"

NewCellSizeForm::NewCellSizeForm() {
	FORM_EVENT_CODE = EVENT_APPLY_CELL_SIZE;
	LABEL_TEXT = Constants::GetString(STRING_CELL_SIZE);
}

NewCellSizeForm::~NewCellSizeForm() {
	
}

void
NewCellSizeForm::PopulateList(void) {

	Osp::Base::String str3x3(L"3x3");
	Osp::Base::String str5x5(L"5x5");
	Osp::Base::String str10x10(L"10x10");
	Osp::Base::String str20x20(L"20x20");

	__list -> RemoveAllItems();
	__list -> AddItem(&str3x3, null, GetColorModel()->sizeThreeBitmap, null, SIZE_THREE);
	__list -> AddItem(&str5x5, null, GetColorModel()->sizeFiveBitmap, null, SIZE_FIVE);
	__list -> AddItem(&str10x10, null, GetColorModel()->sizeTenBitmap, null, SIZE_TEN);
	__list -> AddItem(&str20x20, null, GetColorModel()->sizeTwentyBitmap, null, SIZE_TWENTY);

}
