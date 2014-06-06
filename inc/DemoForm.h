
#ifndef _DEMOFORM_H_
#define _DEMOFORM_H_

#include <FBase.h>
#include <FUi.h>



class DemoForm :
	public Osp::Ui::Controls::Form,
 	public Osp::Ui::IActionEventListener
{

// Construction
public:
	DemoForm(void);
	virtual ~DemoForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:


	virtual void OnActionPerformed(const Osp::Ui::Control &source, int actionId);
};

#endif
