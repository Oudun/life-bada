/*
 * CellSizeForm.cpp
 *
 *  Created on: 17.01.2014
 *      Author: ddreval
 */

#include "CellSizeForm.h"
#include "Constants.h"

using namespace Osp::App;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

CellSizeForm::CellSizeForm() {
	// TODO Auto-generated constructor stub

}

CellSizeForm::~CellSizeForm() {
	// TODO Auto-generated destructor stub
}

bool
CellSizeForm::Initialize(void) {
	Construct(L"CELL_SIZE_FORM");
	return true;
}

result
CellSizeForm::OnInitializing(void) {

	SetBackgroundColor(COLOR_FORM_BACKGROUND);

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* __bitmapGreen = pAppResource->GetBitmapN(L"GreenScheme.png");
	Bitmap* __bitmapAmber = pAppResource->GetBitmapN(L"AmberScheme.png");
	Bitmap* __bitmapXray = pAppResource->GetBitmapN(L"XrayScheme.png");
	Bitmap* __bitmapButton = pAppResource->GetBitmapN(L"Button.png");

	List* __colorList =  static_cast<List *>(GetControl("IDC_LIST_COLOR"));

	String __greenScheme("Green");
	String __amberScheme("Amber");
	String __xrayScheme("X-Ray");

	__colorList -> SetBackgroundColor(COLOR_FORM_BACKGROUND);
	__colorList -> SetItemTextColor(LIST_ITEM_TEXT1, COLOR_TEXT);
	__colorList -> AddItem(&__greenScheme, null, __bitmapGreen, null, null);
	__colorList -> AddItem(&__amberScheme, null, __bitmapAmber, null, null);
	__colorList -> AddItem(&__xrayScheme, null, __bitmapXray, null, null);

	Button* __buttonBack =  static_cast<Button *>(GetControl("IDC_BUTTON_COLOR"));
	__buttonBack -> SetNormalBackgroundBitmap(*__bitmapButton);
	__buttonBack -> SetTextColor(COLOR_TEXT);

	Label* __labelColor =  static_cast<Label *>(GetControl("IDC_LABEL_COLOR"));
	__labelColor -> SetBackgroundColor(COLOR_CONTROL_NORMAL_BACKGROUND);
	__labelColor -> SetTextColor(COLOR_TEXT);

//	IDC_LIST_COLOR
//	IDC_LABEL_COLOR
//	IDC_BUTTON_COLOR

	return E_SUCCESS;


}


