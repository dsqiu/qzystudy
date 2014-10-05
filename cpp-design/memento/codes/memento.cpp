#include <iostream>
#include <string>
using namespace std;
/// class Memento -
class Memento {
  // Attributes
private:
  string _state;
  friend class Originator;
  // Operations
  Memento (const string& state);
  ~Memento ();
  string GetState ();
  void SetState (const string& state);
};

Memento::Memento(const string& state)
{
	_state = state;
}
Memento::~Memento()
{
}
void Memento::SetState(const string& state)
{
	_state = state;
}
string Memento::GetState()
{
	return _state;
}
/// class Originator -
class Originator {
  // Attributes
private:
  string _state;
  // Operations
public:
  Originator ();
  Originator (const string& state);
  ~Originator ();
  void RestoreToMemento (Memento* pMemento);
  Memento* CreateMemento ();
  string GetState ();
  void SetState (const string& state);
  void show ();
};
Originator::Originator()
{
}
Originator::Originator(const string& state)
{
	_state = state;
}
Originator::~Originator()
{
}
string Originator::GetState()
{
	return _state;
}
void Originator::show()
{
	cout << _state << endl;
}
void Originator::SetState(const string& state)
{
	_state = state;
}
Memento* Originator::CreateMemento()
{
	return new Memento(_state);
}
void Originator::RestoreToMemento(Memento* pMemento)
{
	_state = pMemento->GetState();
}
/// class Caretaker -
class Caretaker {
  // Associations
  // Attributes
private:
  Memento* _memento;
  // Operations
public:
  Caretaker ();
  ~Caretaker ();
  Memento* GetMemento();
  void SetMemento (Memento* pMemento);
};
Caretaker::Caretaker()
{
}
Caretaker::~Caretaker()
{
}
Memento* Caretaker::GetMemento()
{
	return _memento;
}
void Caretaker::SetMemento(Memento *pMemento)
{
	_memento = pMemento;
}
int main(int argc, char *argv[])
{
	Originator* o = new Originator("Old");
	Caretaker* pTaker = new Caretaker();
	pTaker->SetMemento(o->CreateMemento());
	o->SetState("New");
	o->show();
	o->RestoreToMemento(pTaker->GetMemento());
	o->show();
    return 0;
}
