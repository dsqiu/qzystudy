#include <iostream>
using namespace std;

/// class Subject -
class Subject {
	// Operations
public:
	virtual ~Subject ();
	virtual void Request () = 0;
protected:
	Subject ();
};
/// class ConcreteSubject -
class ConcreteSubject : public Subject {
	// Operations
public:
	ConcreteSubject ();
	virtual ~ConcreteSubject ();
	virtual void Request ();
};

/// class Proxy -
class Proxy : public Subject {
	// Attributes
private:
	Subject *_subject;
	// Operations
public:
	Proxy ();
	virtual ~Proxy ();
	virtual void Request ();
private:
	void DoSomething1 ();
	void DoSomething2 ();
};

Subject::Subject()
{}
Subject::~Subject()
{}
ConcreteSubject::ConcreteSubject()
{}
ConcreteSubject::~ConcreteSubject()
{}
void ConcreteSubject::Request()
{
	cout << "ConcreteSubject::Request" << endl;
}

Proxy::Proxy():_subject(NULL)
{}
Proxy::~Proxy()
{
	if(NULL != _subject)
		delete _subject;
}
void Proxy::DoSomething1()
{
	cout << "Proxy::DoSomething1" << endl;
}
void Proxy::DoSomething2()
{
	cout << "Proxy::DoSomething2" << endl;
}

void Proxy::Request()
{
	if(NULL == _subject)
	{
		_subject = new ConcreteSubject();
	}
	DoSomething1();
	_subject->Request();
	DoSomething2();
}

/// class Client -
class Client {
};
int main(int argc, char *argv[])
{
	Proxy* proxy = new Proxy();
	proxy->Request();
    return 0;
}
