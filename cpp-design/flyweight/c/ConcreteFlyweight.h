#ifndef CONCRETEFLYWEIGHT__H
#define CONCRETEFLYWEIGHT__H

#include "Flyweight.h"
#include "Client.h"

/// class ConcreteFlyweight - 
class ConcreteFlyweight : public Flyweight {
  // Attributes
private:
  string _instrinsicStatic;
  // Operations
public:
  ConcreteFlyweight (string intrinsicState);
  ~ConcreteFlyweight ();
  virtual void Operation (const string& extrinsicState) = 0;
};

#endif
