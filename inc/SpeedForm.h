/*
 * SpeedForm.h
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#ifndef SPEEDFORM_H_
#define SPEEDFORM_H_

#include <FUi.h>

#include "AbstractForm.h"

class SpeedForm : public AbstractForm
{

public:
	SpeedForm();
	virtual ~SpeedForm();
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

private:
	int delay;
	Osp::Ui::Controls::List* __listSpeed;

private:
	const static int IDC_BUTTON_CANCEL = 1;
	const static int IDC_BUTTON_APPLY = 2;
	const static int INDEX_FASTEST = 0;
	const static int INDEX_FIVE = 200;
	const static int INDEX_TEN = 100;
	const static int INDEX_ONE = 1000;

};

#endif /* SPEEDFORM_H_ */
