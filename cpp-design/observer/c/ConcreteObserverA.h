#ifndef CONCRETEOBSERVERA__H
#define CONCRETEOBSERVERA__H

#include "Observer.h"

/// class ConcreteObserverA - 
class ConcreteObserverA : public Observer {
  // Operations
public:
  ConcreteObserverA ();
  ~ConcreteObserverA ();
  void Update (Subject* pSubject);
};

#endif
