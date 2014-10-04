#include "Target.h"

/// class Adapter - 
class Adapter : public Target {
  // Attributes
private:
  Adaptee* _adaptee;
  // Operations
public:
  Adapter ();
  ~Adapter ();
  void Request ();
};

