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
	static const int INDEX_ABOUT_GAME = 1;
	static const int INDEX_SURFACE = 2;
	static const int INDEX_CELL_SIZE = 3;
	static const int INDEX_COLOR_SCHEME = 4;
	static const int INDEX_GAME_RULES = 5;
	static const int INDEX_SPEED = 6;
	static const int INDEX_BACK = 7;

};

#endif /* SETTINGSFORM_H_ */
