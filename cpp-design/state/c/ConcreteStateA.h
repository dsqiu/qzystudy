#include "State.h"

/// class ConcreteStateA - 
class ConcreteStateA : public State {
  // Operations
public:
  ConcreteStateA ();
  ~ConcreteStateA ();
  void Handle (Context* pContext);
};

