#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class MySingleton
{
public:
    ~MySingleton();

    static MySingleton* GetInstance();
private:
    MySingleton();

};

#endif /* _SINGLETON_H_ */
