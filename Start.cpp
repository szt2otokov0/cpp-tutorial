// Start.cpp : Defines the entry point for the application.
//

#include "Start.h"

using namespace std;

template <typename T>
class stack
{
public:
	explicit stack(const int size)
	{
		arr_ = new T[size];
		size_ = size;
	}

	void push(T item)
	{
		T* new_arr = new T[size_+1];
		for(int i = 0;i < size_;i++)
		{
			new_arr[i] = arr_[i];
		}
		new_arr[size_] = item;
		delete[] arr_;
		arr_ = new_arr;
		size_++;
		print_all();
	}

	T pop()
	{
		if(is_empty()) return T();
		T* new_arr = new T[size_-1];
		T item = arr_[size_-1];
		for(int i = 1; i < size_-1;i++)
		{
			new_arr[i-1] = arr_[i];
		}
		delete[] arr_;
		arr_ = new_arr;
		size_--;
		print_all();
		return item;
	}

	T peek()
	{
		if(is_empty()) return def;
		T item = arr_[size_-1];
		return item;
	}

	bool is_empty() const
	{
		return size_ < 1;
	}

	void print_all()
	{
		cout << "--------------" << '\n';
		for(int i = 0; i< size_;i++)
		{
			cout << arr_[i] << '\n';
		}
		cout << "--------------" << '\n';
	}

	~stack()
	{
		delete[] arr_;
	}

private:
	T* arr_;
	int size_;
	static const T def = {};
};

int main()
{
	cout << "program works" << '\n';
	auto ints = stack<int>(1);
	cout << "creation works" << '\n';
	ints.push(34);
	ints.push(44);
	ints.push(69);
	cout << "push works" << '\n';
	cout << ints.pop() << '\n';
	cout << "pop works" << '\n';
	//cout << ints.peek() << '\n';
	//cout << "peek works" << '\n';
	cout << ints.pop() << '\n';
	cout << "Everything works?" << '\n';

	char b;

	(void)scanf_s(&b);

	return 0;
}
