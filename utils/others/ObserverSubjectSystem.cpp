// Corresponding header
#include "utils/others/ObserverSubjectSystem.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

// ================================================================================
Observer::~Observer()
{
	
}

// ================================================================================
Subject::~Subject()
{
	Subject::DetachAll();
}

// ================================================================================
void Subject::Attach(Observer* obs)
{
	if (obs)
	{
		observers.insert(obs);
	}
}

// ================================================================================
void Subject::Detach(Observer* obs)
{
	if (obs)
	{
		observers.erase(obs);
	}
}

// ================================================================================
void Subject::DetachAll()
{
	for (auto& observer : observers)
	{
		Subject::Detach(observer);
	}
}

// ================================================================================
void Subject::Notify()
{
	for (auto& observer : observers)
	{
		observer->Update(this);
	}
}