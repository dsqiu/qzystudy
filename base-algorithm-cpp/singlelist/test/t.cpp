#include <iostream>
using namespace std;


// Class delcarations - we need them to declare functions

template <typename T>
class List;
template <typename T>
class Stack;
template <typename T>
class Queue;


// operator<< function declaration informs compiler that there is function that can be befriended

template <typename T>
ostream& operator<<(ostream&, const List<T>&);
template <typename T>
ostream& operator<<(ostream&, const Stack<T>&);
template <typename T>
ostream& operator<<(ostream&, const Queue<T>&);


// Class definitions

template <typename T>
class Node{
private:
friend class List<T>;
friend class Stack<T>;
friend class Queue<T>;
};

template <typename T>
class List{
public:
friend ostream& operator<< <T>(ostream&, const List<T>&);
};

template <typename T>
class Stack{
public:
friend ostream& operator<< <T>(ostream&, const Stack<T>&);
};

template <typename T>
class Queue{
public:
friend ostream& operator<< <T>(ostream&, const Queue<T>&);
};


// Actual implemetations

template <typename T>
ostream& operator<<(ostream& out, const List<T>& toPrint) {
	out << "List";
	return cout;
}

template <typename T>
ostream& operator<<(ostream& out, const Stack<T>& toPrint) {
	out << "Stack";
	return out;
}

template <typename T>
ostream& operator<<(ostream& out, const Queue<T>& toPrint) {
	out << "Queue";
	return out;
}

// Template instantations test

int main() {
	List<int>  list;
	Stack<int> stack;
	Queue<int> queue;

	cout << list  << endl
	     << stack << endl
	     << queue << endl;

	return 0;
}
