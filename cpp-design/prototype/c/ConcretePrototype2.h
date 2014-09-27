#include "Prototype.h"

/// class ConcretePrototype2 - 
class ConcretePrototype2 : public Prototype {
  // Operations
public:
  ConcretePrototype2 ();
  ~ConcretePrototype2 ();
  ConcretePrototype2 (const ConcretePrototype2& cp);
  static Prototype* Clone ();
};

