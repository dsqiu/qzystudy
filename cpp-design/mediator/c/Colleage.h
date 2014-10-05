#ifndef COLLEAGE__H
#define COLLEAGE__H

#include "Mediator.h"

// Abstract
/// class Colleage - 
class Colleage {
  // Associations
  // Operations
public:
  ~Colleage ();
  void SetMediator (Mediator* pMediator);
  virtual void SendMsg (string msg) = 0;
  void GetMsg (string msg);
protected:
  Colleage ();
};

#endif
