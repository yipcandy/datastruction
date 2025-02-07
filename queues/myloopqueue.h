#ifndef MY_LOOPQUEUE_H_
#define MY_LOOPQUEUE_H_

#include<iostream>

class CLoopQueue {
private:
	int* queue_;
	int capacity_;
	int head_;
	int tail_;
public:
	CLoopQueue(int size = 10)
		:capacity_(size+1), head_(0), tail_(0), queue_(nullptr) {
		queue_ = new int[capacity_];
	}
	//CQueue(){}	默认构造 default
	~CLoopQueue(){
		delete [] queue_;
	}
	bool IsFull() {
		return (tail_ + 1) % capacity_ == head_;
	}
	bool IsEmpty() {
		return tail_ == head_;
	}
	int GetSize() {
		return (tail_ - head_ + capacity_) % capacity_;
	}
	int GetBack() {
		if (IsEmpty())
			return false;
		return queue_[tail_];
	}
	bool PushBack(int data) {
		if (IsFull())
			return false;
		tail_ = ++tail_ % capacity_;
		queue_[tail_] = data;
		return true;
	}
	int GetFront() {
		if (IsEmpty())
			return false;
		return queue_[head_ + 1];
	}
	bool PopFront() {
		if (IsEmpty())
			return false;
		head_ = ++head_ % capacity_;
		return true;
	}
};

#endif