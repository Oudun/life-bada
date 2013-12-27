/*
 * Evolution.cpp
 *
 *  Created on: 24.12.2013
 *      Author: ddreval
 */

#include "Evolution.h"

Evolution::Evolution() {
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
}
