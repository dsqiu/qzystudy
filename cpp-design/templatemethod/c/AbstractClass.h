#ifndef ABSTRACTCLASS__H
#define ABSTRACTCLASS__H

#include "Client.h"

/// class AbstractClass - 
class AbstractClass {
  // Operations
public:
  ~AbstractClass ();
  void TemplateMethod ();
  void PrimitiveOperation1 ();
  void PrimitiveOperation2 ();
protected:
  AbstractClass ();
};

#endif
