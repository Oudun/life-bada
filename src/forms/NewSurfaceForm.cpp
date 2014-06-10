/*
 * NewSurfaceForm.cpp
 *
 *  Created on: 27.05.2014
 *      Author: ddreval
 */

#include "forms/NewSurfaceForm.h"

NewSurfaceForm::NewSurfaceForm() {
	FORM_EVENT_CODE = EVENT_APPLY_SURFACE;
	LABEL_TEXT = Constants::GetString(STRING_SURFACE);
}

NewSurfaceForm::~NewSurfaceForm() {
	// TODO Auto-generated destructor stub
}

void
NewSurfaceForm::PopulateList(void) {

	__list -> RemoveAllItems();
	__list -> AddItem(Constants::GetStringPointer(STRING_SURFACE_TORUS), null, GetColorModel()->surfaceThorBitmap, null, SURFACE_THOR);
	__list -> AddItem(Constants::GetStringPointer(STRING_SURFACE_KLEIN), null, GetColorModel()->surfaceKleinBitmap, null, SURFACE_KLEIN);
	__list -> AddItem(Constants::GetStringPointer(STRING_SURFACE_PROJECTIVE), null, GetColorModel()->surfaceProjectiveBitmap, null, SURFACE_PROJECTIVE);

}
