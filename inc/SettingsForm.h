/*
 * SettingsForm.h
 *
 *  Created on: 11.01.2014
 *      Author: Denis
 */

#ifndef SETTINGSFORM_H_
#define SETTINGSFORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FApp.h>

class SettingsForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener
	{
public:
	SettingsForm();
	virtual ~SettingsForm();
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
private:
	Osp::Ui::Controls::List* __settingsList;

};

#endif /* SETTINGSFORM_H_ */
