#include "Adaptee.h"
#include "Target.h"

/// class Adapter - 
class Adapter : public Adaptee, public Target {
  // Operations
public:
  Adapter ();
  ~Adapter ();
  void Request ();
};

