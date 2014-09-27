#include "State.h"

/// class Context - 
class Context {
  // Associations
  State* unnamed;
  // Operations
public:
  Context (State* pState);
  ~Context ();
  void Request ();
  ChangeState (State * pState);
};

