#ifndef MEMENTO__H
#define MEMENTO__H

#include "Originator.h"

/// class Memento - 
class Memento {
  // Attributes
private:
  string _state;
  friend class Originator;
  // Operations
private:
  Memento ();
  ~Memento ();
  string GetState ();
  SetState (const string& state);
};

#endif
