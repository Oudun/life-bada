/**
 * Name        : Life
 * Version     : 
 * Vendor      : 
 * Description : 
 */


#include "Life.h"
#include "Generation.h"
#include "Constants.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

Life::Life()
{
	AppLog("CONSTRUCTING");

}

Life::~Life()
{
}

Application*
Life::CreateInstance(void)
{

	AppLog("CREATING");
	// Create the instance through the constructor.
	return new Life();
}

bool
Life::OnAppInitializing(AppRegistry& appRegistry) {

	AppLog("INITIALIZING");

	// Initializing constants

	AppLog("String is %s and %S address is %d", STRING_SUSPEND.GetPointer(), STRING_SUSPEND.GetPointer(), &STRING_SUSPEND);

	// Creating forms

	lifeForm = new LifeForm();
	lifeForm -> Initialize();

	settingsForm = new SettingsForm();
	settingsForm -> Initialize();

	aboutForm = new AboutForm();
	aboutForm -> Initialize();

	cellSizeForm = new CellSizeForm(lifeForm -> GetCellSize());
	cellSizeForm -> Initialize();

	colorForm = new ColorForm();
	colorForm -> Initialize();

//	surfaceForm = new SurfaceForm();
//	surfaceForm -> Initialize();
//
//	rulesForm = new RulesForm();
//	rulesForm -> Initialize();
//
//	speedForm = new SpeedForm();
//	speedForm -> Initialize();

	// Add the form to the frame

	lifeFrame = GetAppFrame()->GetFrame();
	lifeFrame -> AddControl(*lifeForm);
	lifeFrame -> AddControl(*settingsForm);
	lifeFrame -> AddControl(*aboutForm);
	lifeFrame -> AddControl(*colorForm);
	lifeFrame -> AddControl(*cellSizeForm);

	// Set the current form
	lifeFrame -> SetCurrentForm(*lifeForm);

	// Draw and Show the form
	lifeFrame -> Draw();
	lifeFrame -> Show();

	evolution = new Evolution();

	return true;



}


void
Life::OnUserEventReceivedN (RequestId requestId, Osp::Base::Collection::IList *pArgs) {

	switch (requestId) {

		case EVENT_SEED: {
			if (evolution -> IsStarted()&&!evolution -> IsSuspended()) {
				evolution -> Suspend();
				lifeForm -> SetStartLabel(Constants::GetString(STRING_RESUME));
			}
			Generation::Seed();
			lifeForm -> Update();
			lifeForm -> UpdateGenerationNumber();
			break;
		}
		case EVENT_START: {
			AppLog("Start button pressed");
			if (!evolution -> IsStarted()) {
				evolution -> Start();
				lifeForm -> SetStartLabel(Constants::GetString(STRING_SUSPEND));
			} else if (evolution -> IsStarted() && evolution -> IsSuspended()) {
				evolution -> Resume();
				lifeForm -> SetStartLabel(Constants::GetString(STRING_SUSPEND));
			} else {
				evolution -> Suspend();
				lifeForm -> SetStartLabel(Constants::GetString(STRING_RESUME));
			}
			break;
		}
		case EVENT_NEXT_GENERATION: {
			AppLog("Next generation born");
			Generation::Calculate();
			lifeForm -> Update();
			lifeForm -> UpdateGenerationNumber();
			break;
		}
		case EVENT_SHOW_SETTINGS: {
			AppLog("Showing settings form");
			lifeFrame -> SetCurrentForm(*settingsForm);
			//settingsForm -> RequestRedraw(true);
			settingsForm -> Draw();
			settingsForm -> Show();
			AppLog("ended -> Showing settings form");
			break;
		}
		case EVENT_SHOW_BACK: {
			AppLog("Showing main form");
			lifeFrame -> SetCurrentForm(*lifeForm);
			lifeForm -> Draw();
			lifeForm -> Show();
			lifeForm -> Update();
			AppLog("ended -> Showing life form");
			break;
		}
		case EVENT_SHOW_ABOUT_GAME: {
			AppLog("Showing about");
			lifeFrame -> SetCurrentForm(*aboutForm);
			aboutForm -> Draw();
			aboutForm -> Show();
			AppLog("ended -> Showing about form");
			break;
		}
//		case AboutForm::SELECTED_BACK: {
//			AppLog("Showing again settings form");
//			lifeFrame -> SetCurrentForm(*settingsForm);
//			settingsForm -> Draw();
//			settingsForm -> Show();
//			AppLog("ended -> Showing settings form");
//			break;
//		}
		case EVENT_SHOW_COLOR_SCHEME: {
			AppLog("Showing colorForm");
			lifeFrame -> SetCurrentForm(*colorForm);
			colorForm -> Draw();
			colorForm -> Show();
			AppLog("ended -> Showing colorForm form");
			break;
		}
		case EVENT_SHOW_CELL_SIZE: {
			AppLog("Showing cellSizeForm");
			lifeFrame -> SetCurrentForm(*cellSizeForm);
			cellSizeForm -> Draw();
			cellSizeForm -> Show();
			AppLog("ended -> Showing cellSizeForm");
			break;
		}
		case EVENT_APPLY_CELL_SIZE: {
			AppLog("Show Life Form with updated size");
			Integer* size = (Integer*)(pArgs -> GetAt(0));
			lifeForm -> SetCellSize(size -> ToInt());
			lifeForm -> InitializeField();
			Generation::Seed();
			lifeForm -> Update();
			lifeForm -> UpdateGenerationNumber();
			lifeFrame -> SetCurrentForm(*lifeForm);
			lifeFrame -> Draw();
			lifeFrame -> Show();
			AppLog("ended -> Showing cellSizeForm");
			break;
		}
		default: {
			AppLog("Something #%d is happening", requestId);
		}
	}

}

bool
Life::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	if(evolution -> IsStarted()) {
		evolution -> Stop();
	}
	return true;
}

void
Life::OnForeground(void)
{
	// TODO:
	// Start or resume drawing when the application is moved to the foreground.
}

void
Life::OnBackground(void)
{
	// TODO:
	// Stop drawing when the application is moved to the background.
}

void
Life::OnLowMemory(void)
{
	// TODO:
	// Free unused resources or close the application.
}

void
Life::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO:
	// Handle any changes in battery level here.
	// Stop using multimedia features(camera, mp3 etc.) if the battery level is CRITICAL.
}

void
Life::OnScreenOn (void)
{
	// TODO:
	// Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void
Life::OnScreenOff (void)
{
	// TODO:
	//  Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
	// Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
	// Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}
