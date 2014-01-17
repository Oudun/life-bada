/*
 * SurfaceForm.h
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#ifndef SURFACEFORM_H_
#define SURFACEFORM_H_

#include <FUi.h>

class SurfaceForm : public Osp::Ui::Controls::Form {
public:
	SurfaceForm();
	virtual ~SurfaceForm();
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
};

#endif /* SURFACEFORM_H_ */
