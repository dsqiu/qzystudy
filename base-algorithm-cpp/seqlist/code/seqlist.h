#ifndef SEQLIST_H
#define SEQLIST_H
/**
 * @file 顺序链表访问。
 *
 * @code
   #include <iostream>
   #include <seqlist.h>
   using namespace std;
   SeqList<int> test(15);
 * @endcode
 *
 */

const int DefaultSize = 100; /// 缺省设置空间为 100个元素

/**
 * @brief 顺序链表类
 *
 * 采用数组结构安排，每个元素可以是任何一个类。
 *
 * @param Type 可以是任何一个类
 */

template<typename Type>
class SeqList
{
public:
        /**
	 * @brief 顺序链表类构造函数
	 *
	 * SeqList(int sz) 当传入参数时为链表的Size，若是不传参数则为Default=100。
	 *
	 * @param sz 链表Type的个数。若是不传参数则为100个。
	 *
	 */
	SeqList(int sz=DefaultSize):m_nmaxsize(sz),m_ncurrentsize(-1)
	{
		if(sz > 0) {
			m_elements = new Type[m_nmaxsize];
		}
	}
        /**
	 * @brief 顺序链表类虚造函数
	 *
	 * ~SeqList() 释放链表空间。
	 *
	 */
	virtual ~SeqList()
	{
		delete[] m_elements;
	}
        /**
	 * @bried 顺序链表的长度为当前位置加一。
	 *
	 * Length() 当前的长度。
	 *
	 * @return 返回当前所用空间的长度。
	 *
	 */
	int Length() const{
		return m_ncurrentsize + 1;
	}
	int Find(Type x) const;
	int IsElement(Type x) const;
	int Insert(Type x,int i);
	int Remove(Type x);
        /**
	 * @brief 链表是否有合法元素，当元素没有时当前位置为-1。
	 *
	 * IsEmpty()
	 *
	 * @return 空者返回True。
	 */
	int IsEmpty() {
		return m_ncurrentsize == -1;
	}
        /**
	 * @brief 链表中元素是满了。当满了是链表中的位置是链表空间的最多值。
	 *
	 * IsFull()
	 *
	 * @return 当满了返回True。
	 */
	int IsFull() {
		return m_ncurrentsize == m_nmaxsize - 1;
	}
	Type Get(int i);
	void Print();
private:
        Type *m_elements;  ///< 放置元素的空间，构造函数中分配，数组结构。
	const int m_nmaxsize;  ///< 链表存储元素的最大个数。
	int m_ncurrentsize;  ///< 链表放置元素当前个数。
};
/**
 * @brief 查找元素所在的位置。
 *
 * @param x 要查找的元素。
 * @return 若是元素不在链表中则返回-1，并打印输出，否则返回元素所在位置。
 */
template<typename Type>
int SeqList<Type>::Find(Type x) const
{
	for (int i = 0; i < m_ncurrentsize; i++) {
		if(m_elements[i] == x)
			return i;
	}
	cout << "can't find the element you want to find" << endl;
	return -1;
}

/**
 * @brief 判断元素是否在链表中，这个函数要遍历所有元素所以耗时比较大。
 *
 * @param x 要查找的元素。
 * @retrurn 在链表中返回True。
 */
template<typename Type>
int SeqList<Type>::IsElement(Type x) const
{
	if(Find(x) == -1)
		return 0;
	return -1;
}

/**
 * @brief 在第i个元素后面插入元素，若是元素已经满了就会插入失败。
 *
 * @param x 要插入的元素
 * @return 成功返回True，否则False
 */
template<typename Type>
int SeqList<Type>::Insert(Type x,int i)
{
	if(i < 0 || i > m_ncurrentsize+1 || m_ncurrentsize == m_nmaxsize - 1) {
		cout << "the operate is illegal" << endl;
		return 0;
	}
	m_ncurrentsize++;
	for(int j = m_ncurrentsize;j > i;j--){
		m_elements[j] = m_elements[j - 1];
	}
	m_elements[i] = x;
	return 1;
}

/**
 * @brief 输出指定的链表中的元素。
 *
 * Remove(Type x) 若是元素在链表中，删除这个元素并返回True。
 *
 * @parram x 要删除的元素。
 * @return 删除成功返回True，否则False。
 */
template<typename Type>
int SeqList<Type>::Remove(Type x)
{
	int size = m_ncurrentsize;
	for(int i = 0;i < m_ncurrentsize;) {
		if(m_elements[i] == x) {
			for(int j = i;j < m_ncurrentsize;j++) {
				m_elements[j] = m_elements[j+1];
			}
			m_ncurrentsize--;
			continue;
		}
		i++;
	}
	if (size == m_ncurrentsize){
		cout << "can't find the element you want to remove" << endl;
		return 0;
	}
	return -1;
}
/**
 * @brief 取链表中元素的值。
 *
 * Get(int i)
 *
 * @param i 链表中的第i个元素。
 * @return 若是 i 小于0，返回True，i 大于最大有打印输出，并返回0，正确返回当前元素。
 */
template<typename Type>
Type SeqList<Type>::Get(int i) {
	return (i < 0) || (i > m_ncurrentsize?(cout << "can't find the element" << endl,0):m_elements[i]);
}
/**
 * @brief 顺序打印输出中有效的元素。
 *
 */
template<typename Type>
void SeqList<Type>::Print() {
	for(int i = 0;i <= m_ncurrentsize;i++)
		cout << i + 1 << ":\t" << m_elements[i] << endl;
	cout << endl << endl;
}

#endif /* SEQLIST_H */
