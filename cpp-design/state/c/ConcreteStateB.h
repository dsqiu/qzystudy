#include "State.h"

/// class ConcreteStateB - 
class ConcreteStateB : public State {
  // Operations
public:
  ConcreteStateB ();
  ~ConcreteStateB ();
  void Handle (Context* pContext);
};

