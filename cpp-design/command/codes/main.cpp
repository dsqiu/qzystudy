#include "Command.h"
#include "ConcreteCommand.h"
#include "Receiver.h"
#include "Invoker.h"
int main(int argc, char *argv[])
{
	Receiver *pRev = new Receiver();
	Command *pCom = new ConcreteCommand(pRev);
	Invoker* pInv = new Invoker(pCom);
	pInv->Invoke();
    return 0;
}
