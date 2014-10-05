#ifndef CONCRETECOLLEAGEB__H
#define CONCRETECOLLEAGEB__H

#include "Colleage.h"
#include "ConcreteMediator.h"

/// class ConcreteColleageB - 
class ConcreteColleageB : public Colleage {
  // Operations
public:
  ConcreteColleageB ();
  ~ConcreteColleageB ();
  virtual void SendMsg (string msg) = 0;
  virtual void GetMsg (string msg) = 0;
};

#endif
