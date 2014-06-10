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

	// Getting Color Model

	ColorModel* __colorModel = ColorModel::GetModel();

	// Creating forms

	lifeForm = new LifeForm();
	lifeForm -> SetColorModel(__colorModel);
	lifeForm -> Initialize();

	settingsForm = new SettingsForm();
	settingsForm -> SetColorModel(__colorModel);
	settingsForm -> Initialize();

	aboutForm = new AboutForm();
	aboutForm -> SetColorModel(__colorModel);
	aboutForm -> Initialize();

	AppLog("1");

	rulesForm = new RulesForm();
	AppLog("2");
	rulesForm -> SetColorModel(__colorModel);
	AppLog("3");
	rulesForm -> Initialize();
	AppLog("4");

	newColorForm = new NewColorForm();
	newColorForm -> SetColorModel(__colorModel);
	newColorForm -> Initialize();

	AppLog("5");

	newSurfaceForm = new NewSurfaceForm();
	newSurfaceForm -> SetColorModel(__colorModel);
	newSurfaceForm -> Initialize();

	AppLog("6");

	newCellSizeForm = new NewCellSizeForm();
	newCellSizeForm -> SetColorModel(__colorModel);
	newCellSizeForm -> Initialize();

	newSpeedForm = new NewSpeedForm();
	newSpeedForm -> SetColorModel(__colorModel);
	newSpeedForm -> Initialize();

	demoForm = new DemoForm();
	demoForm -> Initialize();

	// Add the form to the frame

	lifeFrame = GetAppFrame()->GetFrame();
	lifeFrame -> AddControl(*lifeForm);
	lifeFrame -> AddControl(*settingsForm);
	lifeFrame -> AddControl(*aboutForm);
	lifeFrame -> AddControl(*rulesForm);
	lifeFrame -> AddControl(*newColorForm);
	lifeFrame -> AddControl(*newSurfaceForm);
	lifeFrame -> AddControl(*newCellSizeForm);
	lifeFrame -> AddControl(*newSpeedForm);
	lifeFrame -> AddControl(*demoForm);

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
			AppLog("Seed button pressed");
			if (evolution -> IsStarted())
				AppLog("Evolution started");
			if (evolution -> IsSuspended())
				AppLog("Evolution suspended");
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
		case EVENT_SHOW_GAME_RULES: {
			AppLog("Showing rules");
			lifeFrame -> SetCurrentForm(*rulesForm);
			rulesForm -> Draw();
			rulesForm -> Show();
			AppLog("ended -> Showing rules form");
			break;
		}
		case EVENT_SHOW_WARNING: {
			AppLog("Showing warning");
			lifeFrame -> SetCurrentForm(*demoForm);
			demoForm -> Draw();
			demoForm -> Show();
			break;
		}

// "SHOW SETTINGS" CASES

		case EVENT_SHOW_COLOR_SCHEME: {
			AppLog("Showing newColorForm");
			lifeFrame -> SetCurrentForm(*newColorForm);
			newColorForm -> SetParam(newColorForm -> GetColorModel() -> id);
			newColorForm -> Draw();
			newColorForm -> Show();
			AppLog("ended -> Showing newColorForm form");
			break;
		}
		case EVENT_SHOW_CELL_SIZE: {
			AppLog("Showing newCellSizeForm");
			lifeFrame -> SetCurrentForm(*newCellSizeForm);
			newCellSizeForm -> SetParam(lifeForm -> GetCellSize());
			newCellSizeForm -> Draw();
			newCellSizeForm -> Show();
			AppLog("ended -> Showing newCellSizeForm");
			break;
		}
		case EVENT_SHOW_SPEED: {
			AppLog("Showing newSpeedForm");
			lifeFrame -> SetCurrentForm(*newSpeedForm);
			newSpeedForm -> SetParam(evolution->GetDelay());
			newSpeedForm -> Draw();
			newSpeedForm -> Show();
			AppLog("ended -> Showing speedForm");
			break;
		}
		case EVENT_SHOW_SURFACE: {
			AppLog("Showing newSurfaceForm");
			lifeFrame -> SetCurrentForm(*newSurfaceForm);
			AppLog("Surface number is %d", Generation::GetSurface());
			newSurfaceForm -> SetParam(Generation::GetSurface());
			newSurfaceForm -> Draw();
			newSurfaceForm -> Show();
			AppLog("ended -> Showing newSurfaceForm");
			break;

		}

// "APPLY SETTINGS" CASES

		case EVENT_APPLY_CELL_SIZE: {
			AppLog("Show Life Form with updated size");
			Integer* size = (Integer*)(pArgs -> GetAt(0));
			Constants::Store(STORED_SIZE, size -> ToInt());
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
		case EVENT_APPLY_SPEED: {
			AppLog("Show Life Form with updated speed");
			Integer* delay = (Integer*)(pArgs -> GetAt(0));
			Constants::Store(STORED_SPEED, delay->ToInt());
			evolution -> SetDelay(delay -> ToInt());
			lifeFrame -> SetCurrentForm(*lifeForm);
			lifeFrame -> Draw();
			lifeFrame -> Show();
			AppLog("ended -> Showing speedForm");
			break;
		}
		case EVENT_APPLY_COLOR: {

			AppLog("Show Life Form with updated color");
			Integer* colorSchemeId = (Integer*)(pArgs -> GetAt(0));
			AppLog("Color scheme id is %d", colorSchemeId -> ToInt());
			ColorModel* selectedModel = ColorModel::GetInstance(colorSchemeId -> ToInt());
			Constants::Store(STORED_COLOR, colorSchemeId -> ToInt());

			lifeForm -> SetColorModel(selectedModel);
			settingsForm -> SetColorModel(selectedModel);
			newSurfaceForm -> SetColorModel(selectedModel);
			newCellSizeForm -> SetColorModel(selectedModel);
			newSpeedForm -> SetColorModel(selectedModel);
			newColorForm -> SetColorModel(selectedModel);
			aboutForm -> SetColorModel(selectedModel);
			rulesForm -> SetColorModel(selectedModel);

			lifeForm -> RePaint();
			settingsForm -> RePaint();
			newSurfaceForm -> RePaint();
			newCellSizeForm -> RePaint();
			newSpeedForm -> RePaint();
			newColorForm -> RePaint();
			aboutForm -> RePaint();
			rulesForm -> RePaint();

			lifeFrame -> SetCurrentForm(*lifeForm);
			lifeForm -> Update();
			lifeFrame -> Draw();
			lifeFrame -> Show();
			AppLog("ended -> Showing speedForm");

			break;
		}
		case EVENT_APPLY_SURFACE: {
			AppLog("Show Life Form with updated surface");
			Integer* surfaceId = (Integer*)(pArgs -> GetAt(0));
			Constants::Store(STORED_SURFACE, surfaceId -> ToInt());
			lifeFrame -> SetCurrentForm(*lifeForm);
			lifeForm -> UpdateGenerationSurface(surfaceId -> ToInt());
			lifeFrame -> Draw();
			lifeFrame -> Show();
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
	// Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
	// Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
	// Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}
