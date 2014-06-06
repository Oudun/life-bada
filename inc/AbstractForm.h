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
#include "Constants.h"

class AbstractForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IItemEventListener,
	public Osp::Ui::IActionEventListener
{
	public:
		AbstractForm();
		virtual ~AbstractForm();
		void SetColorModel(ColorModel* colorModel);
		ColorModel* GetColorModel(void);
		virtual void RePaint(void);
		virtual bool Initialize(void);
		virtual result OnInitializing(void);
		virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
		virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	public:
		ColorModel* __colorModel;

};

#endif /* ABSTRACTFORM_H_ */
