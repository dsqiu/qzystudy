#include <iostream>
using namespace std;

/// class AbstractClass -
class AbstractClass {
  // Operations
public:
  ~AbstractClass ();
  void TemplateMethod ();
  virtual void PrimitiveOperation1 () = 0;
  virtual void PrimitiveOperation2 () = 0;
protected:
  AbstractClass ();
};

AbstractClass::AbstractClass()
{
}
AbstractClass::~AbstractClass()
{
}
void AbstractClass::TemplateMethod()
{
	PrimitiveOperation1();
	PrimitiveOperation2();
}

/// class ConcreteClassA -
class ConcreteClassA : public AbstractClass {
  // Operations
public:
  ConcreteClassA ();
  ~ConcreteClassA ();
  virtual void PrimitiveOperation1 ();
  virtual void PrimitiveOperation2 ();
};
ConcreteClassA::ConcreteClassA()
{
}
ConcreteClassA::~ConcreteClassA()
{
}
void ConcreteClassA::PrimitiveOperation1()
{
	cout << "ConcreteClassA PrimitiveOperation1" << endl;
}
void ConcreteClassA::PrimitiveOperation2()
{
	cout << "ConcreteClassA PrimitiveOperation2" << endl;
}

/// class ConcreteClassB -
class ConcreteClassB : public AbstractClass {
  // Operations
public:
  ConcreteClassB ();
  ~ConcreteClassB ();
  virtual void PrimitiveOperation1 ();
  virtual void PrimitiveOperation2 ();
};

ConcreteClassB::ConcreteClassB()
{
}
ConcreteClassB::~ConcreteClassB()
{
}
void ConcreteClassB::PrimitiveOperation1()
{
	cout << "ConcreteClassB PrimitiveOperation1" << endl;
}
void ConcreteClassB::PrimitiveOperation2()
{
	cout << "ConcreteClassB PrimitiveOperation2" << endl;
}
int main(int argc, char *argv[])
{
	AbstractClass* pAbstract = new ConcreteClassA();
	pAbstract->TemplateMethod();
	pAbstract = new ConcreteClassB();
	pAbstract->TemplateMethod();
	return 0;
}
