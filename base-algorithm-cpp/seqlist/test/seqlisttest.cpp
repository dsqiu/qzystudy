#include <iostream>
using namespace std;
#include "seqlist.h"
int main(int argc, char *argv[])
{
	SeqList<int> *seqlist;
	int array[15] = {
		2,5,8,1,9,
		9,7,6,4,3,
		2,9,7,7,9
	};
	seqlist = new SeqList<int>(15);
	for(int i = 0;i < 15;i++)
		seqlist->Insert(array[i],0);
	seqlist->Insert(1,0);
	cout << (seqlist->Find(0) ? "can't be fond ":"Be found ") << 0 << endl << endl;
	seqlist->Remove(7);
	seqlist->Print();
	seqlist->Remove(9);
	seqlist->Print();
	seqlist->Remove(0);
	seqlist->Print();
	delete seqlist;
	return 0;
}
