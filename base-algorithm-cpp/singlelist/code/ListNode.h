#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
using namespace std;

/**
 * @brief 单向链表的节点。
 *
 * 为单向链表提供数据即下一个节点指针的封装。
 *
 */

template <typename Type> class SingleList;
template <typename Type> class ListNode;
template <typename Type>
ostream& operator<<(ostream&, ListNode<Type>&);

template <typename Type>
class ListNode{
private:
	friend class SingleList<Type>;
//public:
        ListNode() :m_pnext(NULL)
	{
	}
        ListNode(const Type item,ListNode<Type> *next = NULL)
	:m_data(item),m_pnext(next){}

	~ListNode() {
		m_pnext = NULL;
	}
public:
	Type GetData();
	friend ostream& operator<< <Type>(ostream& os,ListNode<Type>& out);
private:
	Type m_data;   ///<  数据节点。
	ListNode *m_pnext;  ///< 指向下一节点的指针。

};

/**
 * @brief 取本节点的数据。
 *
 * @return 返回节点数据
 */

template<typename Type>
Type ListNode<Type>::GetData()
{
	return m_data;
}

/**
 * @brief 提供节点数据输出的功能
 */

template<typename Type>
ostream& operator<<(ostream& os,ListNode<Type>& out)
{
	os << out.m_data;
	return os;
}

#endif /* LISTNODE_H */
