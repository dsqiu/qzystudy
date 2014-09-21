#ifndef _HUMANFACTORY_H_
#define _HUMANFACTORY_H_
#include "Human.h"
#include "WhiteMan.h"
#include "BlackMan.h"
#include "YellowMan.h"
enum HumanType
{
	white = 0,black,yellow,
};
/// class HumanFactory -
class HumanFactory {
public:
	HumanFactory(){}
	~HumanFactory(){}
	static Human* createHuman(HumanType htp)
	{
		Human* human;
		switch(htp)
		{
		case white:
			human = new WhiteMan();
			break;
		case black:
			human = new BlackMan();
			break;
		case yellow:
			human = new YellowMan();
			break;
		default:
			human = NULL;
		}
		return human;
	}
};
#endif /* _HUMANFACTORY_H_ */
