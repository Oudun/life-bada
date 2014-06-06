/*
 * NewColorForm.h
 *
 *  Created on: 25.05.2014
 *      Author: Denis
 */

#ifndef NEWCOLORFORM_H_
#define NEWCOLORFORM_H_

#include "AbstractSettingsForm.h"

class NewColorForm : public AbstractSettingsForm {

	public:
		NewColorForm();
		virtual ~NewColorForm();
		virtual void PopulateList(void);

};

#endif /* NEWCOLORFORM_H_ */
