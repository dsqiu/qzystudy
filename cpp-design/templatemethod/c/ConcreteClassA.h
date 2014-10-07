#ifndef CONCRETECLASSA__H
#define CONCRETECLASSA__H

#include "AbstractClass.h"

/// class ConcreteClassA - 
class ConcreteClassA : public AbstractClass {
  // Operations
public:
  ConcreteClassA ();
  ~ConcreteClassA ();
  void PrimitiveOperation1 ();
  void PrimitiveOperation2 ();
};

#endif
