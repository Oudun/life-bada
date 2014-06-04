/*
 * NewCellSizeForm.h
 *
 *  Created on: 28.05.2014
 *      Author: ddreval
 */

#ifndef NEWCELLSIZEFORM_H_
#define NEWCELLSIZEFORM_H_

#include "AbstractSettingsForm.h"

class NewCellSizeForm: public AbstractSettingsForm {
public:
	NewCellSizeForm();
	virtual ~NewCellSizeForm();
	virtual void PopulateList(void);
};

#endif /* NEWCELLSIZEFORM_H_ */
