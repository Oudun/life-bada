/*
 * RulesForm.h
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#ifndef RULESFORM_H_
#define RULESFORM_H_

#include <FUi.h>
#include "AbstractSettingsForm.h"

class RulesForm : public AbstractSettingsForm {

public:
	RulesForm();
	virtual ~RulesForm();
	virtual void PopulateList(void);

};

#endif /* RULESFORM_H_ */
