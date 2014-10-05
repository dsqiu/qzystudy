#ifndef CONCRETECOLLEAGEA__H
#define CONCRETECOLLEAGEA__H

#include "Colleage.h"
#include "ConcreteMediator.h"

/// class ConcreteColleageA - 
class ConcreteColleageA : public Colleage {
  // Operations
public:
  ConcreteColleageA ();
  ~ConcreteColleageA ();
  virtual void SendMsg (string msg) = 0;
  virtual void GetMsg (string msg) = 0;
};

#endif
