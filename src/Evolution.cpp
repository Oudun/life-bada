/*
 * Evolution.cpp
 *
 *  Created on: 24.12.2013
 *      Author: ddreval
 */

#include "Evolution.h"
#include "Generation.h"
#include "Constants.h"

Evolution::Evolution() {

	if (IS_DEMO) {
		int rand = Osp::Base::Utility::Math::Rand();
		if (rand < 8000) {
			delay = SPEED_FASTEST;
		} else if (rand <16000) {
			delay = SPEED_TEN_FPS;
		} else if (rand <24000) {
			delay = SPEED_FIVE_FPS;
		} else {
			delay = SPEED_ONE_FPS;
		}
	} else {
		delay = SPEED_FIVE_FPS;
	}

	result r = E_SUCCESS;
	r = Thread::Construct(Osp::Base::Runtime::THREAD_TYPE_EVENT_DRIVEN);
	AppLog("Created");
}

Evolution::~Evolution() {
	// TODO Auto-generated destructor stub
}

void
Evolution::Resume(void) {
	isSuspended = false;
}


void
Evolution::Suspend(void) {
	isSuspended = true;
}

bool
Evolution::OnStart(void) {
	AppLog("OnStart");
	isStarted = true;
	isSuspended = false;
	SendUserEvent(1, null);
	return true;
}

void
Evolution::OnStop(void) {
	AppLog("OnStop");
}

void
Evolution::OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList *pArgs) {
	Thread::GetCurrentThread()->Sleep(delay);
	if (!isSuspended) {
		Osp::App::Application::GetInstance() -> SendUserEvent(EVENT_NEXT_GENERATION, null);
	}
	SendUserEvent(1, null);
}

bool
Evolution::IsStarted(void) {
	return isStarted;
}

bool
Evolution::IsSuspended(void) {
	return isSuspended;
}


void
Evolution::SetDelay(int aDelay) {
	delay = aDelay;
}

int
Evolution::GetDelay(void) {
	return delay;
}
