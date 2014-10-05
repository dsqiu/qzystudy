#ifndef CARETAKER__H
#define CARETAKER__H

#include "Memento.h"

/// class Caretaker - 
class Caretaker {
  // Associations
  // Attributes
private:
  Memento* _memento;
  // Operations
public:
  Caretaker ();
  ~Caretaker ();
  void SetMemento (Memento pMemento);
};

#endif
