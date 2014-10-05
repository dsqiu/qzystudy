#ifndef UNSHAREDCONCRETEFLYWEIGHT__H
#define UNSHAREDCONCRETEFLYWEIGHT__H

#include "Flyweight.h"
#include "Client.h"

/// class UnsharedConcreteFlyweight - 
class UnsharedConcreteFlyweight : public Flyweight {
  // Attributes
private:
  string _instrinsicStatic;
  // Operations
public:
  UnsharedConcreteFlyweight (string intrinsicState);
  ~UnsharedConcreteFlyweight ();
  virtual void Operation (const string& extrinsicState) = 0;
};

#endif
