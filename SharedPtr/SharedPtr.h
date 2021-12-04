#pragma once

template <typename T> class SharedPtr {
	int* counter;
	T* ptr;
public:
	SharedPtr() : ptr(nullptr), counter(new int{ 1 }) {}

	SharedPtr(T* pointer) : ptr(pointer), counter(new int{ 1 }) {}

	SharedPtr(const SharedPtr& c_ptr) {
		ptr = c_ptr.ptr;
		counter = c_ptr.counter;
		(*counter)++;
	}

	SharedPtr& operator = (const SharedPtr& c_ptr) {
		(*counter)--;
		if (*counter == 0) {
			delete ptr;
			delete counter;
		}
		ptr = c_ptr.ptr;
		counter = c_ptr.counter;
		(*counter)++;
		return *this;
	}

	int get_count() {
		return *counter;
	}


	T* operator->(){
		return ptr;
	}

	T& operator*() {
		return *ptr;
	}


	~SharedPtr(){
		(*counter)--;
		if (*counter == 0) {
			delete ptr;
			delete counter;
		}
	}
};