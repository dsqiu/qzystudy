#include <stdio.h>
class MySingleton
{
public:
    ~MySingleton();

    static MySingleton* GetInstance();
private:
    MySingleton();

};

MySingleton::~MySingleton()
{

}

MySingleton::MySingleton()
{
	static int count = 0;
	printf("new MySingleton::MySingleton! %d\n",count++);
}

MySingleton* MySingleton::GetInstance()
{
    static MySingleton* pInstance = new MySingleton();

    return pInstance;
}
int main(int argc,char* argv[])
{
    MySingleton* pMySingleton = MySingleton::GetInstance();

    MySingleton* pMySingleton1 = MySingleton::GetInstance();
    return 0;
}
