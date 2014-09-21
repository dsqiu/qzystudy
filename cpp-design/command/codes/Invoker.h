#ifndef _INVOKER_H_
#define _INVOKER_H_
#include "Command.h"

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
#endif /* _INVOKER_H_ */
