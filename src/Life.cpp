/**
 * Name        : Life
 * Version     : 
 * Vendor      : 
 * Description : 
 */


#include "Life.h"
#include "Generation.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

Life::Life()
{
	AppLog("CONSTRUCTING");
//	FORM_BACKGROUND(0, 0, 0);
//	static Osp::Graphics::Color CONTROL_NORMAL_BACKGROUND;
//	static Osp::Graphics::Color CONTROL_PRESSED_BACKGROUND;
//	static Osp::Graphics::Color TEXT_COLOR;
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

	// Creating forms

	lifeForm = new LifeForm();
	lifeForm -> Initialize();

	settingsForm = new SettingsForm();
	settingsForm -> Initialize();

	// Add the form to the frame

	lifeFrame = GetAppFrame()->GetFrame();
	lifeFrame -> AddControl(*lifeForm);
	lifeFrame -> AddControl(*settingsForm);

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

		case LifeForm::SEED_BUTTON_PRESSED: {
			if (evolution -> IsStarted()&&!evolution -> IsSuspended()) {
				evolution -> Suspend();
				String resumeString(L"RESUME");
				lifeForm -> SetStartLabel(resumeString);
			}
			Generation::Seed();
			lifeForm -> Update();
			lifeForm -> UpdateGenerationNumber();
			break;
		}
		case LifeForm::START_BUTTON_PRESSED: {
			AppLog("Start button pressed");
			if (!evolution -> IsStarted()) {
				evolution -> Start();
				String suspendString(L"SUSPEND");
				lifeForm -> SetStartLabel(suspendString);
			} else if (evolution -> IsStarted() && evolution -> IsSuspended()) {
				evolution -> Resume();
				String suspendString(L"SUSPEND");
				lifeForm -> SetStartLabel(suspendString);
			} else {
				evolution -> Suspend();
				String resumeString(L"RESUME");
				lifeForm -> SetStartLabel(resumeString);
			}
			break;
		}
		case Evolution::NEXT_GENERATION_BORN: {
			AppLog("Next generation born");
			Generation::Calculate();
			lifeForm -> Update();
			lifeForm -> UpdateGenerationNumber();
			break;
		}
		case LifeForm::SETTINGS_BUTTON_PRESSED: {
			AppLog("Showing settings form");
			lifeFrame -> SetCurrentForm(*settingsForm);
			settingsForm -> RequestRedraw(true);
			AppLog("ended -> Showing settings form");
			break;
		}

		default: {
			AppLog("Something no% is happening", requestId);
		}
	}

}

bool
Life::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO:
	// Deallocate resources allocated by this application for termination.
	// The application's permanent data and context can be saved via appRegistry.
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
