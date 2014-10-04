#include "Adstraction.h"

/// class RefineAdstractionB - 
class RefineAdstractionB : public Adstraction {
  // Attributes
public:
  AbstractionImplement* _imp;
  // Operations
public:
  ~RefineAdstractionB ();
  RefineAdstractionB (AbstractionImplement* imp);
  void Operation ();
};

