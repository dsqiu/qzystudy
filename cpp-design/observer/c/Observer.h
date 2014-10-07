#ifndef OBSERVER__H
#define OBSERVER__H

/// class Observer -
class Observer {
  // Operations
public:
  ~Observer ();
  void Update (Subject* pSubject) = 0;
protected:
  Observer ();
};

#endif
