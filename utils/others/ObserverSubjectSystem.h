#ifndef OBSERVER_SUBJECT_SYSTEM_H_
#define OBSERVER_SUBJECT_SYSTEM_H_

// C/C++ system includes
#include <cstdint>
#include <set>

// Third-party includes

// Own includes

// Forward declarations
class Observer;
class Subject;

class Observer
{
public:
	virtual ~Observer();
	virtual void Update(Subject* changedSubject) = 0;

protected:
	Observer() = default;
};

class Subject
{
public:
	virtual ~Subject();

	virtual void Attach(Observer* obs);
	virtual void Detach(Observer* obs);
	virtual void DetachAll();

	virtual void Notify();

protected:
	Subject() = default;

private:
	std::set<Observer*> observers;
};

#endif // !OBSERVER_SUBJECT_SYSTEM_H_