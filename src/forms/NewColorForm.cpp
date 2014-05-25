/*
 * NewColorForm.cpp
 *
 *  Created on: 25.05.2014
 *      Author: Denis
 */

#include "forms/NewColorForm.h"

NewColorForm::NewColorForm() {
	FORM_EVENT_CODE = EVENT_APPLY_COLOR;
	LABEL_TEXT = Constants::GetString(STRING_COLOR_SCHEME);
}

NewColorForm::~NewColorForm() {
	// TODO Auto-generated destructor stub
}

void
NewColorForm::PopulateList(void) {

	String __greenScheme("Green");
	String __amberScheme("Amber");
	String __xrayScheme("X-Ray");
//
//	__listColor -> SetBackgroundColor(GetColorModel()->formBkgColor);
//	__listColor -> SetItemTextColor(LIST_ITEM_TEXT1, GetColorModel()->textColor);
//	__listColor -> AddItem(&__greenScheme, null, GetColorModel()->colorGreenBitmap, null, INDEX_GREEN);
//	__listColor -> AddItem(&__amberScheme, null, GetColorModel()->colorAmberBitmap, null, INDEX_AMBER);
//	__listColor -> AddItem(&__xrayScheme, null, GetColorModel()->colorXrayBitmap, null, INDEX_XRAY);

	__list -> AddItem(&__greenScheme, null, GetColorModel()->colorGreenBitmap, null, 1);
	__list -> AddItem(&__amberScheme, null, GetColorModel()->colorAmberBitmap, null, 1);
	__list -> AddItem(&__xrayScheme, null, GetColorModel()->colorXrayBitmap, null, 1);

}
