/*
 * Evolution.h
 *
 *  Created on: 24.12.2013
 *      Author: ddreval
 */

#ifndef EVOLUTION_H_
#define EVOLUTION_H_

#include <FBase.h>

class Evolution:public Osp::Base::Runtime::Thread
{

public:
	Evolution();
	virtual ~Evolution();

public:
	void Resume(void);
	void Suspend(void);
	virtual bool OnStart(void);
	virtual void OnStop(void);
	virtual void OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList *pArgs);

public:
	bool isResumed;
	int delay;


};

#endif /* EVOLUTION_H_ */
