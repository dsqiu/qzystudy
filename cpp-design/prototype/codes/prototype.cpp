#include <iostream>
using namespace std;
/// class Prototype -
class Prototype {
  // Operations
public:
  virtual ~Prototype ();
  virtual Prototype* Clone () const = 0;
protected:
  Prototype ();
};

/// class ConcretePrototype1 -
class ConcretePrototype1 : public Prototype {
  // Operations
public:
  ConcretePrototype1 ();
  virtual ~ConcretePrototype1 ();
  ConcretePrototype1 (const ConcretePrototype1& cp);
  virtual Prototype* Clone () const;
};

/// class ConcretePrototype2 -
class ConcretePrototype2 : public Prototype {
  // Operations
public:
  ConcretePrototype2 ();
  virtual ~ConcretePrototype2 ();
  ConcretePrototype2 (const ConcretePrototype2& cp);
  virtual Prototype* Clone () const;
};

/// class client -
class client {
};

Prototype::Prototype()
{
	cout << "Prototype" << endl;
}
Prototype::~Prototype()
{
	cout << "~Prototype" << endl;
}
ConcretePrototype1::ConcretePrototype1()
{
	cout << "ConcretePrototype1" << endl;
}
ConcretePrototype1::~ConcretePrototype1()
{
	cout << "~ConcretePrototype1" << endl;
}
ConcretePrototype1::ConcretePrototype1(const ConcretePrototype1& cp)
{
	cout << "ConcretePrototype1 copy" << endl;
}
Prototype* ConcretePrototype1::Clone() const
{
	return new ConcretePrototype1(*this);
}

ConcretePrototype2::ConcretePrototype2()
{
	cout << "ConcretePrototype2" << endl;
}
ConcretePrototype2::~ConcretePrototype2()
{
	cout << "~ConcretePrototype2" << endl;
}
ConcretePrototype2::ConcretePrototype2(const ConcretePrototype2& cp)
{
	cout << "ConcretePrototype2 copy" << endl;
}
Prototype* ConcretePrototype2::Clone() const
{
	return new ConcretePrototype2(*this);
}
int main(int argc, char *argv[])
{
    Prototype *p1 = new ConcretePrototype1();
	Prototype *p2 = p1->Clone();
	cout << "----------------------------------------" << endl;
	Prototype *p3 = new ConcretePrototype2();
	Prototype *p4 = p3->Clone();
	cout << "----------------------------------------" << endl;
	delete p1;
	delete p2;
	cout << "----------------------------------------" << endl;
	delete p3;
	delete p4;
    return 0;
}
