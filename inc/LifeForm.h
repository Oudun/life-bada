#ifndef _FORM1_H_
#define _FORM1_H_

#include <FBase.h>
#include <FUi.h>
#include <FApp.h>

class LifeForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener
{

// Construction
public:
	LifeForm(void);
	virtual ~LifeForm(void);
	bool Initialize(void);
	void Update(void);

// Implementation
protected:
	static const int IDC_BUTTON_SEED = 1;
	static const int IDC_BUTTON_START = 2;
	Osp::Ui::Controls::Button *__pButtonOk;
	int __seedSize;

public:
	static const int START_BUTTON_PRESSED = 1;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

};

#endif	//_FORM1_H_
