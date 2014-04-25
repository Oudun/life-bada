/*
 * RulesForm.h
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#ifndef RULESFORM_H_
#define RULESFORM_H_

#include <FUi.h>

class RulesForm : public Osp::Ui::Controls::Form ,
	public Osp::Ui::IItemEventListener,
	public Osp::Ui::IActionEventListener {

public:
	RulesForm();
	virtual ~RulesForm();
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

private:
	const static int IDC_BUTTON_CANCEL = 1;
	const static int IDC_BUTTON_APPLY = 2;

};

#endif /* RULESFORM_H_ */
