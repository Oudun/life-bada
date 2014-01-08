/*
 * Evolution.cpp
 *
 *  Created on: 24.12.2013
 *      Author: ddreval
 */

#include "Evolution.h"
#include "Generation.h"

Evolution::Evolution() {
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
	Thread::GetCurrentThread()->Sleep(100);
	if (!isSuspended) {
		Osp::App::Application::GetInstance() -> SendUserEvent(NEXT_GENERATION_BORN, null);
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
