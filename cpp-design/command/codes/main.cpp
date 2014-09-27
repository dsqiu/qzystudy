#include <iostream>
using namespace std;
/// class Command -
class Command {
public:
	virtual ~Command(){}
	// Operations

	virtual void Execute () = 0;
protected:
	Command(){}
};

/// class Receiver -
class Receiver{
  // Operations
public:
	Receiver(){}
	~Receiver(){}
  void Action ()
  {
	  cout << "Receiver::Action" << endl;
  }
};

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
/// class Invoker -
class Invoker {
  // Attributes
public:
  // Operations
  Invoker (Command* pCommand)
  {
	  _cmd = pCommand;
  }
  void Invoke ()
  {
	  _cmd->Execute();
  }
  ~Invoker();
private:
  Command* _cmd;
};
int main(int argc, char *argv[])
{
	Receiver *pRev = new Receiver();
	Command *pCom = new ConcreteCommand(pRev);
	Invoker* pInv = new Invoker(pCom);
	pInv->Invoke();
    return 0;
}
