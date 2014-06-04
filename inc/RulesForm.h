/*
 * RulesForm.h
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#ifndef RULESFORM_H_
#define RULESFORM_H_

#include "AbstractForm.h"

class RulesForm :
	public AbstractForm,
	public Osp::Ui::IItemEventListener,
	public Osp::Ui::IActionEventListener {

public:
	RulesForm();
	virtual ~RulesForm();
	void PopulateList(void);
	virtual bool Initialize(void);
	virtual result OnInitializing(void);
	void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
	void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

private:
	Osp::Ui::Controls::CustomList* __list;


};

#endif /* RULESFORM_H_ */
