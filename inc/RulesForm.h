/*
 * RulesForm.h
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#ifndef RULESFORM_H_
#define RULESFORM_H_

#include <FUi.h>

class RulesForm : public Osp::Ui::Controls::Form {

public:
	RulesForm();
	virtual ~RulesForm();
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
};

#endif /* RULESFORM_H_ */
