#ifndef _CONCRETECOMMAND_H_
#define _CONCRETECOMMAND_H_
#include "Command.h"
#include "Receiver.h"
/// class ConcreteCommand -
class ConcreteCommand : public Command {
public:
	ConcreteCommand(){}
	~ConcreteCommand(){}
  virtual void Execute ()
  {
	  _recv->Action();
  }
  ConcreteCommand (Receiver* pReceiver)
  {
	  _recv = pReceiver;
  }
private:
  Receiver* _recv;

};
#endif /* _CONCRETECOMMAND_H_ */
