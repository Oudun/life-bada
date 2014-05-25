/*
 * AbstractSettingsForm.h
 *
 *  Created on: 25.05.2014
 *      Author: Denis
 */

#ifndef ABSTRACTSETTINGSFORM_H_
#define ABSTRACTSETTINGSFORM_H_

#include <FUi.h>
#include "AbstractForm.h"
#include "Constants.h"

class AbstractSettingsForm :
	public AbstractForm,
	public Osp::Ui::IItemEventListener,
	public Osp::Ui::IActionEventListener {

	public:
		AbstractSettingsForm();
		virtual ~AbstractSettingsForm();

		virtual bool Initialize(void);
		virtual result OnInitializing(void);
		virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
		virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
		virtual void PopulateList(void);

	protected:
		Osp::Ui::Controls::List* __list;
		Osp::Ui::Controls::Label* __label;
		Osp::Ui::Controls::Button* __buttonApply;
		Osp::Ui::Controls::Button* __buttonCancel;

	protected:
		int FORM_EVENT_CODE;
		String LABEL_TEXT;

	private:
		const static int IDC_BUTTON_CANCEL = 0;
		const static int IDC_BUTTON_APPLY = 1;

	};

#endif /* ABSTRACTSETTINGSFORM_H_ */

