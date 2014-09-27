#include "Prototype.h"

/// class ConcretePrototype1 - 
class ConcretePrototype1 : public Prototype {
  // Operations
public:
  ConcretePrototype1 ();
  ~ConcretePrototype1 ();
  ConcretePrototype1 (const ConcretePrototype1& cp);
  static Prototype* Clone ();
};

