/*
 * ColorForm.h
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#ifndef CELLSIZEFORM_H_
#define CELLSIZEFORM_H_

#include <FUi.h>

class CellSizeForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IItemEventListener,
	public Osp::Ui::IActionEventListener {

public:
	CellSizeForm(int cellSize);
	virtual ~CellSizeForm();
	bool Initialize(void);
	int cellSize;

public:
	virtual result OnInitializing(void);
	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

private:
	const static int IDC_BUTTON_CANCEL = 1;
	const static int IDC_BUTTON_APPLY = 2;
	const static int INDEX_THREE = 3;
	const static int INDEX_FIVE = 5;
	const static int INDEX_TEN = 10;
	const static int INDEX_TWENTY = 20;

private:
	Osp::Ui::Controls::List* __listCellSize;

};

#endif /* COLORFORM_H_ */
