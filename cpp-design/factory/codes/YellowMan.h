#ifndef _YELLOWMAN_H_
#define _YELLOWMAN_H_
#include "Human.h"
/// class YellowMan -
class YellowMan : public Human {
public:
	YellowMan(){}
	~YellowMan(){}
	void run()
	{
		cout << "YellowMan::run()" << endl;
	}
	void sleep()
	{
		cout << "YellowMan::sleep()" << endl;
	}
};
#endif /* _YELLOWMAN_H_ */
