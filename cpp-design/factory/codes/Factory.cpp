#include <sys/time.h>
#include "Human.h"
#include "HumanFactory.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
    int type = rand() % 3;
	cout << type << endl;
	Human *mhum;
	mhum = HumanFactory::createHuman((HumanType)type);
	if(mhum == NULL)
	{
		cout << "no human" << endl;
	}
	mhum->run();
	mhum->sleep();
    return 0;
}
