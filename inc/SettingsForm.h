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

#include "AbstractForm.h"

class SettingsForm :
	public AbstractForm,
	public Osp::Ui::IItemEventListener,
 	public Osp::Ui::IActionEventListener
	{
public:
	SettingsForm();
	virtual ~SettingsForm();
	void RePaint(void);
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

public:
	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);

private:
	Osp::Ui::Controls::List* __settingsList;
	static const int INDEX_ABOUT_GAME = 1;
	static const int INDEX_SURFACE = 2;
	static const int INDEX_CELL_SIZE = 3;
	static const int INDEX_COLOR_SCHEME = 4;
	static const int INDEX_GAME_RULES = 5;
	static const int INDEX_SPEED = 6;
	static const int INDEX_BACK = 7;

protected:
	static const int IDC_BUTTON_BACK = 1;
	static const int IDC_BUTTON_ABOUT = 2;

	virtual void OnActionPerformed(const Osp::Ui::Control &source, int actionId);
};

#endif /* SETTINGSFORM_H_ */
