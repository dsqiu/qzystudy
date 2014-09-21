#ifndef _BLACKMAN_H_
#define _BLACKMAN_H_
#include "Human.h"
/// class BlackMan -
class BlackMan : public Human {
public:
	BlackMan() {}
	~BlackMan(){}
	void run()
	{
		cout << "BlackMan::run()" << endl;
	}
	void sleep()
	{
		cout << "BlackMan:sleep()" << endl;
	}
};

#endif /* _BLACKMAN_H_ */
