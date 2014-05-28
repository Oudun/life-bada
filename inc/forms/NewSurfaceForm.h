/*
 * NewSurfaceForm.h
 *
 *  Created on: 27.05.2014
 *      Author: ddreval
 */

#ifndef NEWSURFACEFORM_H_
#define NEWSURFACEFORM_H_

#include "AbstractSettingsForm.h"

class NewSurfaceForm : public AbstractSettingsForm {

	public:
		NewSurfaceForm();
		virtual ~NewSurfaceForm();
		virtual void PopulateList(void);

};

#endif /* NEWSURFACEFORM_H_ */
