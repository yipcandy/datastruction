#ifndef MY_STACK_H_
#define MY_STACK_H_

#include<iostream>
using namespace std;

template<class T>
class Stack {
private:
	T* stack_;
	int top_;
	int size_;
public:
	Stack(int size);
	Stack();
	~Stack();
	bool empty();
	bool full();
	bool push(int n);
	bool pop();
	T top();
};

template<class T>
Stack<T>::Stack(int size)
	:stack_(nullptr), top_(-1), size_(size) {
	stack_ = new int[size_];
}
template<class T>
Stack<T>::Stack() {}
template<class T>
Stack<T>::~Stack() {
	delete[] stack_;
}
template<class T>
bool Stack<T>::empty() {
	return top_ == -1;
}
template<class T>
bool Stack<T>::full() {
	return top_ == size_ - 1;
}
template<class T>
bool Stack<T>::push(int n) {
	if (full())
		return false;
	stack_[++top_] = n;
	return true;
}
template<class T>
bool Stack<T>::pop() {
	if (empty())
		return false;
	top_--;
	return true;
}
template<class T>
T Stack<T>::top() {
	return stack_[top_];
}
#endif
