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

}


void
Evolution::Suspend(void) {

}

bool
Evolution::OnStart(void) {
	AppLog("OnStart");
	SendUserEvent(1, null);
	return true;
}

void
Evolution::OnStop(void) {
	AppLog("OnStop");
}

void
Evolution::OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList *pArgs) {
	AppLog("Event received");
	Thread::GetCurrentThread()->Sleep(1000);
//	Generation::Seed();
	Osp::App::Application::GetInstance() -> SendUserEvent(NEXT_GENERATION_BORN, null);
	SendUserEvent(1, null);
}
