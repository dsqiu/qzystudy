#ifndef _COMMAND_H_
#define _COMMAND_H_
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

#endif /* _COMMAND_H_ */
