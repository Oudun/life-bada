
#ifndef _RULESFORM_H_
#define _RULESFORM_H_

#include <FBase.h>
#include <FUi.h>



class RulesForm :
	public Osp::Ui::Controls::Form
{

// Construction
public:
	RulesForm(void);
	virtual ~RulesForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:

};

#endif
