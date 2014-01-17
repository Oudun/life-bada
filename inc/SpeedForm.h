/*
 * SpeedForm.h
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#ifndef SPEEDFORM_H_
#define SPEEDFORM_H_

#include <FUi.h>

class SpeedForm : public Osp::Ui::Controls::Form {

public:
	SpeedForm();
	virtual ~SpeedForm();
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
};

#endif /* SPEEDFORM_H_ */
