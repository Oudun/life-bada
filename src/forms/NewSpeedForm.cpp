/*
 * NewSpeedForm.cpp
 *
 *  Created on: 28.05.2014
 *      Author: ddreval
 */

#include "forms/NewSpeedForm.h"

NewSpeedForm::NewSpeedForm() {
	FORM_EVENT_CODE = EVENT_APPLY_SPEED;
	LABEL_TEXT = Constants::GetString(STRING_SPEED_LABEL);
}

NewSpeedForm::~NewSpeedForm() {
	
}

void
NewSpeedForm::PopulateList(void) {

	//__list -> Set//LIST_ITEM_SINGLE_TEXT

	__list -> RemoveAllItems();
	__list -> SetColumn1Width(0);
	__list -> AddItem(Constants::GetStringPointer(STRING_SPEED_FASTEST), null, null, null, SPEED_FASTEST);
	__list -> AddItem(Constants::GetStringPointer(STRING_SPEED_TEN_FPS), null, null, null, SPEED_TEN_FPS);
	__list -> AddItem(Constants::GetStringPointer(STRING_SPEED_FIVE_FPS), null, null, null, SPEED_FIVE_FPS);
	__list -> AddItem(Constants::GetStringPointer(STRING_SPEED_ONE_FPS), null, null, null, SPEED_ONE_FPS);

}
