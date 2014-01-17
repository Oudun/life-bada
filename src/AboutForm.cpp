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
using namespace Osp::App;

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

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* __bitmapConway = pAppResource->GetBitmapN(L"Conway.png");
	Bitmap* __bitmapButton = pAppResource->GetBitmapN(L"Button.png");

	EditArea* __textArea0 = static_cast<EditArea *>(GetControl("IDC_EDITAREA_ABOUT_0"));
	__textArea0 -> SetTextSize(12);
	__textArea0 -> SetEnabled(false);
	__textArea0 -> SetColor(EDIT_STATUS_DISABLED, COLOR_FORM_BACKGROUND);
	__textArea0 -> SetTextColor(EDIT_TEXT_COLOR_DISABLED, COLOR_TEXT);
	__textArea0 -> SetText(
			L"  The Game of Life, also known simply as Life, is a cellular automaton "
			"devised by the British mathematician John Horton Conway in 1970.\n "
			);

	EditArea* __textArea = static_cast<EditArea *>(GetControl("IDC_EDITAREA_ABOUT"));
	__textArea -> SetTextSize(12);
	__textArea -> SetEnabled(false);
	__textArea -> SetColor(EDIT_STATUS_DISABLED, COLOR_FORM_BACKGROUND);
	__textArea -> SetTextColor(EDIT_TEXT_COLOR_DISABLED, COLOR_TEXT);
	__textArea -> SetText(
			L"  The \"game\" is a zero-player game, meaning that its evolution is determined by its "
			"initial state, requiring no further input. One interacts with the Game of Life by "
			"creating an initial configuration and observing how it evolves.\n"
			"  Conway was interested in a problem presented in the 1940s by mathematician John von Neumann, "
			"who attempted to find a hypothetical machine that could build copies of itself and succeeded "
			"when he found a mathematical model for such a machine with very complicated rules "
			"on a rectangular grid.\n"
			"  The Game of Life emerged as Conway's successful attempt to drastically "
			"simplify von Neumann's ideas.");

	Button *pButton_about_back = static_cast<Button *>(GetControl("IDC_BUTTON_ABOUT_BACK"));  
	if (pButton_about_back)
	{
		pButton_about_back -> SetActionId(1);
		pButton_about_back -> AddActionEventListener(*this);
		pButton_about_back -> SetNormalBackgroundBitmap(*__bitmapButton);
		pButton_about_back -> SetTextColor(COLOR_TEXT);
		pButton_about_back -> SetText(Constants::GetString(STRING_BACK));
	}

	Label *__labelConway = static_cast<Label *>(GetControl("IDC_LABEL_CONWAY"));
	if (__labelConway)
	{
		__labelConway -> SetBackgroundBitmap(*__bitmapConway);
		__labelConway -> SetBackgroundColor(COLOR_FORM_BACKGROUND);
	}


	return E_SUCCESS;

}

void
AboutForm::OnActionPerformed(const Osp::Ui::Control &source, int actionId)
{

}
