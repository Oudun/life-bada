
#include "RulesForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


RulesForm::RulesForm(void)
{
}

RulesForm::~RulesForm(void)
{
}

bool
RulesForm::Initialize()
{
	Form::Construct(L"RULES_FORM");

	return true;
}

result
RulesForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	return r;
}

result
RulesForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


