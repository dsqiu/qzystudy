#include <iostream>
using namespace std;
class SubSystem1
{
public:
	SubSystem1 ();
	~SubSystem1 ();
	void Operation ();
};
class SubSystem2
{
public:
	SubSystem2 ();
	~SubSystem2 ();
	void Operation ();
};

class Facade
{
public:
	Facade ();
	~Facade ();
	void OperationWrapper ();
private:
	SubSystem1*  _subsys1;
	SubSystem2* _subsys2;
};


class Client
{
};

SubSystem1::SubSystem1()
{
}
SubSystem1::~SubSystem1()
{
}
void SubSystem1::Operation()
{
	cout << "SubSystem1::Operation" << endl;
}

SubSystem2::SubSystem2()
{
}
SubSystem2::~SubSystem2()
{
}
void SubSystem2::Operation()
{
	cout << "SubSystem2::Operation" << endl;
}
Facade::Facade()
{
	_subsys1 = new SubSystem1();
	_subsys2 = new SubSystem2();
}
Facade::~Facade()
{
	delete _subsys1;
	delete _subsys2;
}
void Facade::OperationWrapper()
{
	_subsys1->Operation();
	_subsys2->Operation();
}
int main(int argc, char *argv[])
{
	Facade* pFacade = new Facade();
	pFacade->OperationWrapper();
	return 0;
}
