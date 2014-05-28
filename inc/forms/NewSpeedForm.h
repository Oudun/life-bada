/*
 * NewSpeedForm.h
 *
 *  Created on: 28.05.2014
 *      Author: ddreval
 */

#ifndef NEWSPEEDFORM_H_
#define NEWSPEEDFORM_H_

#include "AbstractSettingsForm.h"

class NewSpeedForm: public AbstractSettingsForm {
public:
	NewSpeedForm();
	virtual ~NewSpeedForm();
	virtual void PopulateList(void);
};

#endif /* NEWSPEEDFORM_H_ */
