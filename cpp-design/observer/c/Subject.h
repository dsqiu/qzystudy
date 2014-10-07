#ifndef SUBJECT__H
#define SUBJECT__H

#include "ConcreteObserverA.h"
#include "Observer.h"

/// class Subject - 
class Subject {
  // Associations
  // Attributes
public:
  list<Observer*> m_lst;
private:
  string m_state;
  // Operations
public:
  ~Subject ();
  void Notify ();
  void Attach (Observer* pObserver);
  void Detach (Observer* pObserver);
  void SetState (string state);
protected:
  Subject ();
};

#endif
