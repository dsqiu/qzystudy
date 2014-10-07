#ifndef CONCRETEOBSERVERB__H
#define CONCRETEOBSERVERB__H

#include "Observer.h"

/// class ConcreteObserverB - 
class ConcreteObserverB : public Observer {
  // Operations
public:
  ConcreteObserverB ();
  ~ConcreteObserverB ();
  void Update (Subject* pSubject);
};

#endif
