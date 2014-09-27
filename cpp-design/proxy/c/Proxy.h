#include "Subject.h"

/// class Proxy - 
class Proxy : public Subject {
  // Attributes
private:
  Subject _subject;
  // Operations
public:
  Proxy ();
  ~Proxy ();
  void Request ();
  void DoSomething1 ();
  void DoSomething2 ();
};

