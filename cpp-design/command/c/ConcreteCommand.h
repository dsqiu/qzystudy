#include "Command.h"
#include "Receiver.h"

/// class ConcreteCommand - 
class ConcreteCommand : public Command {
  // Associations
  Receiver* unnamed;
  // Operations
public:
  void Excecute ();
  ConcreteCommand (Receiver * pReceiver);
};

