#ifndef _HUMAN_H_
#define _HUMAN_H_
#include <iostream>
#include <stdlib.h>
using namespace std;

/// class Human -
class Human {
public:
	virtual ~Human(){}
	virtual void run() = 0;
	virtual void sleep() = 0;
};
#endif /* _HUMAN_H_ */
