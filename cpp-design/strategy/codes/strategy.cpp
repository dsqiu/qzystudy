#include <iostream>
using namespace std;
/// class Strategy -
class Strategy {
	// Operations
public:
	Strategy ();
	virtual ~Strategy ();
	virtual void AlgrithmInterface () = 0;
};

/// class ConcreteStrategyA -
class ConcreteStrategyA : public Strategy {
	// Operations
public:
	ConcreteStrategyA ();
	virtual ~ConcreteStrategyA ();
	virtual void AlgrithmInterface ();
};


/// class ConcreteStrategyB -
class ConcreteStrategyB : public Strategy {
	// Operations
public:
	ConcreteStrategyB ();
	virtual ~ConcreteStrategyB ();
	virtual void AlgrithmInterface ();
};


/// class Context -
class Context {
	// Associations
private:
	Strategy* _strategy;
	// Operations
public:
	Context (Strategy* strategy);
	virtual ~Context ();
	virtual void DoAction ();
};
Strategy::Strategy()
{}
Strategy::~Strategy()
{}

ConcreteStrategyA::ConcreteStrategyA()
{}
ConcreteStrategyA::~ConcreteStrategyA()
{}
void ConcreteStrategyA::AlgrithmInterface()
{
	cout << "ConcreteStrategyA::AlgrithmInterface" << endl;
}
ConcreteStrategyB::ConcreteStrategyB()
{}
ConcreteStrategyB::~ConcreteStrategyB()
{}
void ConcreteStrategyB::AlgrithmInterface()
{
	cout << "ConcreteStrategyB::AlgrithmInterface" << endl;
}
Context::Context(Strategy *strategy)
{
	_strategy = strategy;

}
Context::~Context()
{
	delete _strategy;
}
void Context::DoAction()
{
	_strategy->AlgrithmInterface();
}
int main(int argc, char *argv[])
{
	Strategy *pStr = new ConcreteStrategyA();
	Context* pcon = new Context(pStr);
	pcon->DoAction();
	delete pcon;
	pStr = new ConcreteStrategyB();
	pcon = new Context(pStr);
	pcon->DoAction();
	delete pcon;
    return 0;
}
