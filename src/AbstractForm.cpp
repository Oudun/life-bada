/*
 * AbstractForm.cpp
 *
 *  Created on: 23.05.2014
 *      Author: ddreval
 */

#include "AbstractForm.h"

AbstractForm::AbstractForm() {
	AppLog("AbstractForm::AbstractForm()");
}

AbstractForm::~AbstractForm() {
	// TODO Auto-generated destructor stub
}

void
AbstractForm::SetColorModel(ColorModel* colorModel) {
	AppLog("Setting color model");
	__colorModel = colorModel;
}


ColorModel*
AbstractForm::GetColorModel(void) {
	//AppLog("AbstractForm::GetColorModel(void)");
	return __colorModel;
}
