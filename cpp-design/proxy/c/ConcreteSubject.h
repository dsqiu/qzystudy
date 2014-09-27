#include "Subject.h"
#include "Proxy.h"

/// class ConcreteSubject - 
class ConcreteSubject : public Subject {
  // Operations
public:
  ConcreteSubject ();
  ~ConcreteSubject ();
  void Request ();
};

