/*
 * AboutForm.cpp
 *
 *  Created on: 16.01.2014
 *      Author: ddreval
 */

#include "AboutForm.h"
#include "Constants.h"

using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

AboutForm::AboutForm() {
	// TODO Auto-generated constructor stub

}

AboutForm::~AboutForm() {
	// TODO Auto-generated destructor stub
}

bool
AboutForm::Initialize(void) {

	AppLog("Initializing about form");
	Construct(L"ABOUT_FORM");
	return true;

}

result
AboutForm::OnInitializing(void) {

	SetBackgroundColor(COLOR_FORM_BACKGROUND);

	Osp::Ui::Controls::EditArea* __textArea = new EditArea();
	__textArea -> Construct(Rectangle(20, 60, 200, 300), INPUT_STYLE_OVERLAY);
	AddControl(*__textArea);

//	Osp::Ui::Controls::TextBox* __aboutText = new TextBox();
//	__aboutText -> Construct(Rectangle(20, 60, 200, 300), TEXT_BOX_BORDER_NONE);
//	AddControl(*__aboutText);

	__textArea -> SetTextSize(12);
	__textArea -> SetEnabled(false);
	__textArea -> SetColor(EDIT_STATUS_DISABLED, COLOR_FORM_BACKGROUND);
	__textArea -> SetTextColor(EDIT_TEXT_COLOR_DISABLED, COLOR_TEXT);
	__textArea -> SetText(L"The Game of Life, also known simply as Life, is a cellular automaton "
			"devised by the British mathematician John Horton Conway in 1970.\n "
			"The \"game\" is a zero-player game, meaning that its evolution is determined by its "
			"initial state, requiring no further input. One interacts with the Game of Life by "
			"creating an initial configuration and observing how it evolves.\n"
			"Conway was interested in a problem presented in the 1940s by mathematician John von Neumann, "
			"who attempted to find a hypothetical machine that could build copies of itself and succeeded "
			"when he found a mathematical model for such a machine with very complicated rules "
			"on a rectangular grid. The Game of Life emerged as Conway's successful attempt to drastically "
			"simplify von Neumann's ideas.");
//


	return E_SUCCESS;
	Button *pButton_about_back = static_cast<Button *>(GetControl("IDC_BUTTON_ABOUT_BACK"));  
	if (pButton_about_back)
	{
		pButton_about_back->SetActionId(1);
		pButton_about_back->AddActionEventListener(*this);
	}

}

void
AboutForm::OnActionPerformed(const Osp::Ui::Control &source, int actionId)
{
	// TODO: Add your implementation codes here

}
