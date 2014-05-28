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

	__list -> RemoveAllItems();
	__list -> AddItem(&__greenScheme, null, GetColorModel()->colorGreenBitmap, null, COLOR_SCHEME_GREEN);
	__list -> AddItem(&__amberScheme, null, GetColorModel()->colorAmberBitmap, null, COLOR_SCHEME_AMBER);
	__list -> AddItem(&__xrayScheme, null, GetColorModel()->colorXrayBitmap, null, COLOR_SCHEME_XRAY);

}
