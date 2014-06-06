
#ifndef _RULESFORM_H_
#define _RULESFORM_H_

#include <FBase.h>
#include <FUi.h>
#include "AbstractForm.h"


class RulesForm :
	public AbstractForm
{

// Construction
public:
	RulesForm(void);
	virtual ~RulesForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);
	void RePaint(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

private:
	Osp::Ui::Controls::Label* __label;
	Osp::Ui::Controls::Button* __buttonBack;
	Osp::Ui::Controls::Button* __buttonAbout;

private:
	const static int IDC_BUTTON_BACK = 0;
	const static int IDC_BUTTON_ABOUT = 1;

};

#endif
