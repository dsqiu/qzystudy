#include "ListNode.h"
/**
 * @brief 单向链表类
 *
 * 所有元素全部存入head所指向的链表内。
 *
 */

template<typename Type> class SingleList{
public:
	SingleList():head(new ListNode<Type>()){}
	~SingleList(){
		MakeEmpty();
		delete head;
	}
public:
	void MakeEmpty();
	int Length();
	ListNode<Type> *Find(Type value,int n);
	ListNode<Type> *Find(int n);
	bool Insert(Type item,int n = 0);
	Type Remove(int n = 0);
	bool RemoveAll(Type item);
	Type Get(int n);
	void Print();
private:
	ListNode<Type> *head;   ///< 单向链表头
};
/**
 * @brief 清空单向链表。
 */

template<typename Type>
void SingleList<Type>::MakeEmpty()
{
	ListNode<Type> *pdel;
	while(head->m_pnext != NULL) {
		pdel = head->m_pnext;
		head->m_pnext = pdel->m_pnext;
		delete pdel;
	}
}

/**
 * @brief 返回单向链表中节点个数。
 */

template<typename Type>
int SingleList<Type>::Length()
{
	ListNode<Type> *pmove = head->m_pnext;
	int count;
	while(pmove != NULL){
		pmove = pmove->m_pnext;
		count++;
	}
	return count;
}
/**
 * @brief 查找第n个节点。
 *
 * @param n 第n个节点。
 * @return 第n个节点。
 */

template<typename Type>
ListNode<Type>* SingleList<Type>::Find(int n)
{
	if(n < 0) {
		std::cout << "The n is out of boundary" << std::endl;
		return NULL;
	}
	ListNode<Type> *pmove = head->m_pnext;
	for(int i = 0;i < n && pmove;i++){
		pmove = pmove->m_pnext;
	}
	if(pmove == NULL) {
		std::cout << "The n is out of boundary" << std::endl;
		return NULL;
	}
	return pmove;
}
/**
 * @brief 查找第n个值为value的节点。
 *
 * @param value 第n个节点的值。
 * @param n     n个节点。
 * @return      符合要求的节点。
 */

template<typename Type>
ListNode<Type> *SingleList<Type>::Find(Type value,int n)
{
	if(n < 1) {
		std::cout << "The n is illegal" << std::endl;
		return NULL;
	}
	ListNode<Type> *pmove = head;
	int count = 0;
	while(count != n && pmove) {
		pmove = pmove->m_pnext;
		if(pmove->m_data == value) {
			count++;
		}
	}
	if(pmove == NULL) {
		std::cout << "can't find the element" << std::endl;
		return NULL;
	}
	return pmove;
}
/**
 * @brief 插入元素到第n个节点后链表中。
 *
 * @param item   要插入的元素。
 * @param n      第n个节点，若不传入任何值就为第一个节点相当于n = 0.
 * @return true: 表示成功，false： 表示不成功。
 */

template<typename Type>
bool SingleList<Type>::Insert(Type item,int n)
{
	if(n < 0) {
		std::cout << "The n is illegal" << std::endl;
		return false;
	}
	ListNode<Type> *pmove = head;
	ListNode<Type> *pnode = new ListNode<Type>(item);
	if(pnode == NULL) {
		std::cout << "Application error!" << std::endl;
		return false;
	}
	for(int i = 0;i < n && pmove;i++) {
		pmove = pmove->m_pnext;
	}
	if(pmove == NULL) {
		std::cout << "the n is illegal" << std::endl;
		delete pnode;
		return false;
	}
	pnode->m_pnext = pmove->m_pnext;
	pmove->m_pnext = pnode;
	return true;
}

/**
 * @brief 删除第n个节点。
 *
 * @param n 第n个节点。
 * @return 返回第n个节点，错误是后由错误输出。
 */

template<typename Type>
Type SingleList<Type>::Remove(int n)
{
	if(n < 0) {
		std::cout << "can't find the element" << std::endl;
		exit(1);
	}
	ListNode<Type> *pmove = head,*pdel;
	for(int i = 0;i < n && pmove->m_pnext;i++) {
		pmove = pmove->m_pnext;
	}
	if(pmove->m_pnext == NULL) {
		std::cout << "can't find the element" << std::endl;
		exit(1);
	}
	pdel = pmove->m_pnext;
	pmove->m_pnext = pdel->m_pnext;
	Type temp = pdel->m_data;
	delete pdel;
	return temp;
}

/**
 * @brief 删除所有等于Item的节点
 *
 * @param item 元素的值。
 */

template<typename Type>
bool SingleList<Type>::RemoveAll(Type item)
{
	ListNode<Type> *pmove = head;
	ListNode<Type> *pdel = head->m_pnext;
	while(pdel != NULL) {
		if(pdel->m_data == item) {
			pmove->m_pnext = pdel->m_pnext;
			delete pdel;
			pdel = pmove->m_pnext;
			continue;
		}
		pmove = pmove->m_pnext;
		pdel = pdel->m_pnext;
	}
	return true;
}

/**
 * @brief 获取第n个节点。
 *
 * @param n 第n个节点。
 * @return 返回第n个节点，错误是后由错误输出。
 */

template<typename Type>
Type SingleList<Type>::Get(int n)
{
	if(n < 0) {
		std::cout << "The n is out of boundary" << std::endl;
		exit(1);
	}
	ListNode<Type> *pmove = head->m_pnext;
	for (int i = 0; i < n; i++) {
		pmove = pmove->m_pnext;
		if(NULL == pmove) {
			std::cout << "The n is out of boundary" << std::endl;
			exit(1);
		}
	}
	return pmove->m_data;
}
/**
 * @brief 遍历各个节点并打印输出。
 *
 */

template<typename Type>
void SingleList<Type>::Print()
{
	ListNode<Type> *pmove = head->m_pnext;
	std::cout << "head";
	while(pmove){
		std::cout << "--->" << pmove->m_data;
		pmove = pmove->m_pnext;
	}
	std::cout << "--->over" << endl << endl << endl;
}
