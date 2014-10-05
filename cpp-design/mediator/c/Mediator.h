#ifndef MEDIATOR__H
#define MEDIATOR__H

// Abstract
/// class Mediator - 
class Mediator {
  // Operations
public:
  ~Mediator ();
  void SendMsg (string s, Colleage* colleage);
protected:
  Mediator ();
};

#endif
