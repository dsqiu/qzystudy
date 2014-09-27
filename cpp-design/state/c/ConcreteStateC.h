#include "State.h"

/// class ConcreteStateC - 
class ConcreteStateC : public State {
  // Operations
public:
  ConcreteStateC ();
  ~ConcreteStateC ();
  void Handle (Context* pContext);
};

