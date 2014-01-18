/*
 * ColorForm.h
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#ifndef CELLSIZEFORM_H_
#define CELLSIZEFORM_H_

#include <FUi.h>

class CellSizeForm : public Osp::Ui::Controls::Form {
public:
	CellSizeForm();
	virtual ~CellSizeForm();
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
};

#endif /* COLORFORM_H_ */
