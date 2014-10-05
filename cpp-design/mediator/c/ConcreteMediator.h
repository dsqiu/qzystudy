#ifndef CONCRETEMEDIATOR__H
#define CONCRETEMEDIATOR__H

#include "Mediator.h"

/// class ConcreteMediator - 
class ConcreteMediator : public Mediator {
  // Attributes
private:
  Colleage* m_ColleageA;
  Colleage* m_ColleageB;
  // Operations
public:
  ConcreteMediator ();
  virtual ~ConcreteMediator ();
  virtual void SendMsg (string s, Colleage* colleage) = 0;
  void SetColleageA (Colleage* p);
  void SetColleageB (Colleage* p);
};

#endif
