/*
 * CellSizeForm.h
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#ifndef COLORFORM_H_
#define COLORFORM_H_

#include <FUi.h>
#include "AbstractForm.h"

class ColorForm :
	public AbstractForm,
	public Osp::Ui::IItemEventListener,
	public Osp::Ui::IActionEventListener {

	public:
		ColorForm();
		virtual ~ColorForm();
		bool Initialize(void);

	public:
		virtual result OnInitializing(void);
		virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
		virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	private:
		static const int INDEX_GREEN = 1;
		static const int INDEX_AMBER = 2;
		static const int INDEX_XRAY = 3;
		static const int IDC_BUTTON_CANCEL = 1;
		static const int IDC_BUTTON_APPLY = 2;

	private:
		Osp::Ui::Controls::List* __listColor;
		Osp::Ui::Controls::Label* __labelColor;
		Osp::Ui::Controls::Button* __buttonApply;
		Osp::Ui::Controls::Button* __buttonCancel;

	public:
		static const int SELECTED_BACK = 51;

};

#endif /* CELLSIZEFORM_H_ */
