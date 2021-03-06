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
class Adapter : public Adaptee, public Target {
  // Operations
public:
  Adapter ();
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
Adapter::Adapter()
{}
Adapter::~Adapter()
{}
void Adapter::Request()
{
	cout << "Adapter::Request()" << endl;
	SpecificRequest();
	cout << "--------------------------------------" << endl;
}
int main(int argc, char *argv[])
{
    Target* pTarget = new Adapter();
	pTarget->Request();
    return 0;
}
