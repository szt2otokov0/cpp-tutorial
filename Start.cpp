// Start.cpp : Defines the entry point for the application.
//

#include "Start.h"

using namespace std;

template <typename T>
class stack
{
public:
	stack() = default;

	void push(T item)
	{
		T* new_arr = new T[size()+1];
		new_arr[size()] = item;
		delete[] arr_;
		arr_ = new_arr;
	}

	T pop()
	{
		if(is_empty()) return T();
		T* new_arr = new T[size()-1];
		T* item = &arr_[size()-1];
		for(int i = 1; i < size()-1;i++)
		{
			new_arr[i-1] = arr_[i];
		}
		delete[] arr_;
		arr_ = new_arr;
		return *item;
	}

	T peek()
	{
		if(is_empty()) return def_;
		T* item = &arr_[size()-1];
		return *item;
	}

	bool is_empty()
	{
		return size() == 0;
	}

	int size()
	{
		T arr = *arr_;
		return arr.size();
	}

	~stack()
	{
		delete[] arr_;
	}

private:
	T* arr_;
	static T def_;
};

int main()
{
	auto ints = stack<int>();
	ints.push(34);
	ints.push(44);
	cout << ints.pop() << '\n';
	cout << ints.peek() << '\n';
	return 0;
}
