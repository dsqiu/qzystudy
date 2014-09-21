#ifndef _WHITEMAN_H_
#define _WHITEMAN_H_
#include "Human.h"

/// class WhiteMan -
class WhiteMan : public Human {
public:
	WhiteMan(){}
	~WhiteMan(){}
	void run()
	{
		cout << "WriteMan:run()" << endl;
	}
	void sleep()
	{
		cout << "WriteMan:sleep()" << endl;
	}
};
#endif /* _WHITEMAN_H_ */
