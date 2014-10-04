#include <iostream>
using namespace std;
/// class Target -
class Target {
  // Operations
public:
  Target ();
  ~Target ();
   virtual void Request ();
};

/// class Adaptee -
class Adaptee {
  // Operations
public:
  Adaptee ();
  ~Adaptee ();
  void SpecificRequest ();
};

/// class Adapter -
class Adapter : public Target {
  // Attributes
private:
  Adaptee* _adaptee;
  // Operations
public:
  Adapter ();
  Adapter (Adaptee *adaptee);
  ~Adapter ();
  virtual void Request ();
};

/// class Client -
class Client {
};
Target::Target()
{}
Target::~Target()
{}
void Target::Request()
{
	cout << "Target::Request()" << endl;
}
Adaptee::Adaptee()
{}
Adaptee::~Adaptee()
{}
void Adaptee::SpecificRequest()
{
	cout << "Adaptee::SpecificRequest()" << endl;
}
Adapter::Adapter():_adaptee(new Adaptee)
{}
Adapter::Adapter(Adaptee *adaptee)
{
	_adaptee = adaptee;
}
Adapter::~Adapter()
{}
void Adapter::Request()
{
	cout << "Adapter::Request()" << endl;
	_adaptee->SpecificRequest();
	cout << "--------------------------------------" << endl;
}
int main(int argc, char *argv[])
{
	Adaptee *ade = new Adaptee();
    Target* pTarget1 = new Adapter(ade);
	pTarget1->Request();
	Target *pTarget2 = new Adapter();
	pTarget2->Request();
    return 0;
}
