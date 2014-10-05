#ifndef ORIGINATOR__H
#define ORIGINATOR__H

/// class Originator - 
class Originator {
  // Attributes
private:
  string _state;
  // Operations
public:
  Originator ();
  Originator (const string& state);
  ~Originator ();
  void RestoreToMemento (Memento* pMemento);
  Memento* CreateMemento ();
  string SetState ();
  void show ();
};

#endif
