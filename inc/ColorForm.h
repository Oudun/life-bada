/*
 * ColorForm.h
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#ifndef COLORFORM_H_
#define COLORFORM_H_

#include <FUi.h>

class ColorForm : public Osp::Ui::Controls::Form {
public:
	ColorForm();
	virtual ~ColorForm();
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
};

#endif /* COLORFORM_H_ */
