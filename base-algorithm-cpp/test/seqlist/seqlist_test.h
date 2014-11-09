#ifndef SEQLIST_TEST_H
#define SEQLIST_TEST_H
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
using namespace std;
#include <seqlist.h>
class SeqListTest: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( SeqListTest );
	CPPUNIT_TEST( test );
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp();
	void tearDown();

protected:
	void test();
private:
	SeqList<int> *seqlist;
};


#endif /* SEQLIST_TEST_H */
