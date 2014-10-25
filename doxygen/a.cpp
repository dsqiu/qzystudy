/**
 * @file 本范例的程序代码档案。
 * 这个档案用来定义example这个class的
 * member function。
 * @author garylee@localhost
 */

#include <float.h>
#include "a.h"

/**
 * @brief ExFunc1的简易说明
 *
 * ExFunc1没有任何参数及传回值。
 *
 */

void Example::ExFunc1(void)
{
// empty funcion.
}

/**
 * @brief ExFunc2的简易说明
 *
 * ExFunc2()传回两个参数相加的值。
 *
 * @param a 用来相加的参数。
 * @param b 用来相加的参数。
 * @return 传回两个参数相加的结果。
 */
int Example::ExFunc2(int a,char b)
{
	return (a+b);
}

/**
 * @brief ExFunc3的简易说明
 *
 * ExFunc3()只传回参数输入的指标。
 *
 * @param c 传进的字符指针。
 * @retval NULL 空字符串。
 * @retval !NULL 非空字符串。
 */
char* Example::ExFunc3(char * c)
{
	return c;
}

int main(int argc, char *argv[])
{
	return 0;
}
