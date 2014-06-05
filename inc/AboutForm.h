/*
 * AboutForm.h
 *
 *  Created on: 16.01.2014
 *      Author: ddreval
 */

#ifndef ABOUTFORM_H_
#define ABOUTFORM_H_

#include <FApp.h>
#include "AbstractForm.h"

class AboutForm :
 	public AbstractForm {

	public:
		AboutForm();
		virtual ~AboutForm();
		virtual result OnInitializing(void);
		bool Initialize(void);
		virtual void OnActionPerformed(const Osp::Ui::Control &source, int actionId);
		void RePaint(void);

	private:
		Osp::Graphics::Bitmap* __bitmapButton;
		Osp::Ui::Controls::Label* __textIntroLabel;
		Osp::Ui::Controls::Label* __textLabel;
		Osp::Ui::Controls::Button *__buttonBack;
		Osp::Ui::Controls::Label *__labelConway;


};

#endif /* ABOUTFORM_H_ */
