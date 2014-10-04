#include "Adstraction.h"

/// class RefineAdstractionA - 
class RefineAdstractionA : public Adstraction {
  // Attributes
public:
  AbstractionImplement* _imp;
  // Operations
public:
  ~RefineAdstractionA ();
  RefineAdstractionA (AbstractionImplement* imp);
  void Operation ();
};

