/*
 * SurfaceForm.cpp
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#include "SurfaceForm.h"
#include "Constants.h"

using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

SurfaceForm::SurfaceForm() {
	// TODO Auto-generated constructor stub

}

SurfaceForm::~SurfaceForm() {
	// TODO Auto-generated destructor stub
}

bool
SurfaceForm::Initialize(void) {
	Construct(L"SURFACE_FORM");
	return true;
}

result
SurfaceForm::OnInitializing(void) {

	SetBackgroundColor(GetColorModel()->formBkgColor);

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	Button *__buttonCancel = static_cast<Button *>(GetControl("IDC_BUTTON_CANCEL"));
	if (__buttonCancel)
	{
		__buttonCancel -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
		__buttonCancel -> SetActionId(IDC_BUTTON_CANCEL);
		__buttonCancel -> SetTextColor(GetColorModel()->textColor);
		__buttonCancel -> SetText(Constants::GetString(STRING_CANCEL));
		__buttonCancel -> AddActionEventListener(*this);
	}

	Button *__buttonApply = static_cast<Button *>(GetControl("IDC_BUTTON_APPLY"));
	if (__buttonApply)
	{
		__buttonApply -> SetNormalBackgroundBitmap(GetColorModel()-> normalBackgroundBitmap);
		__buttonApply -> SetActionId(IDC_BUTTON_APPLY);
		__buttonApply -> SetTextColor(GetColorModel()->textColor);
		__buttonApply -> SetText(Constants::GetString(STRING_APPLY));
		__buttonApply -> AddActionEventListener(*this);
	}

//	Label *__labelSpeed = static_cast<Label *>(GetControl("IDC_LABEL_SPEED_FORM"));
//	if (__labelSpeed)
//	{
//		__labelSpeed -> SetBackgroundColor(COLOR_FORM_BACKGROUND);
//		__labelSpeed -> SetTextColor(COLOR_TEXT);
//		__labelSpeed -> SetText(Constants::GetString(STRING_SPEED_LABEL));
//	}

	return E_SUCCESS;
}

void
SurfaceForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
	switch (actionId) {
		case IDC_BUTTON_CANCEL: {
			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_SHOW_SETTINGS, null);
			break;
		}
//		case IDC_BUTTON_APPLY: {
//			IList* args = new ArrayList();
//			int checkedIndex = __listSpeed -> GetFirstCheckedItemIndex();
//			int checkedItemId = __listSpeed -> GetItemIdAt(checkedIndex);
//			delay = checkedItemId;
//			args -> Add(*(new Integer(checkedItemId)));
//			Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_APPLY_SPEED, args);
//			break;
//		}
	}
}
