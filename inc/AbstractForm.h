/*
 * AbstractForm.h
 *
 *  Created on: 23.05.2014
 *      Author: ddreval
 */

#ifndef ABSTRACTFORM_H_
#define ABSTRACTFORM_H_

#include <FUi.h>
#include "ColorModel.h"

class AbstractForm : public Osp::Ui::Controls::Form {
	public:
		AbstractForm();
		virtual ~AbstractForm();
		void SetColorModel(ColorModel* colorModel);
		ColorModel* GetColorModel(void);
		virtual void RePaint(void);
	public:
		ColorModel* __colorModel;
};

#endif /* ABSTRACTFORM_H_ */
