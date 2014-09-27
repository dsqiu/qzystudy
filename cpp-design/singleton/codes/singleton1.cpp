#include <iostream>
using namespace std;
/// class Singleton -
class Singleton {
  // Operations
private:
	static Singleton* pInstance;
public:
  static Singleton* Instance ();
  static void Destory ();
private:
  Singleton ();
};
Singleton* Singleton::pInstance = NULL;
Singleton::Singleton()
{
	cout << "Single..." << endl;
}
Singleton* Singleton::Instance()
{
	if(NULL == pInstance)
		pInstance = new Singleton();
	return pInstance;
}
void Singleton::Destory()
{
	delete pInstance;
	pInstance = NULL;
	cout << "Destory..." << endl;
}

int main(int argc, char *argv[])
{
    Singleton* ps = Singleton::Instance();
	Singleton* ps1 = Singleton::Instance();
	Singleton::Destory();
    return 0;
}
