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


#endif
