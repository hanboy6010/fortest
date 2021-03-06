#include <iostream>
#include <fstream>
using namespace std;
ofstream outfile("test5.txt");

template <class T>
class Stack 
{
private:
	T * stack;
	int top;
	int capacity;

public:
	Stack(int stackcapacity)
	{
		capacity = stackcapacity;
		if (capacity < 1)
		{
			cerr << "Stakc capacity must be > 0" << endl;
		}
		stack = new T[capacity];
		top = -1;
	}
	inline bool IsEmpty()const
	{
		return top == -1;
	}
	T& Top()const
	{
		if (IsEmpty())
		{
			cerr << "Stack is Empty" << endl;
		}
		return stack[top];
	}
	void Push(const T& item)
	{
		stack[++top] = item;
	}
	void Pop()
	{
		if (IsEmpty())
		{
			cerr << "Stack is Empty" << endl;
		}
		stack[top--].~T();
	}
};

int main()
{
	ifstream input("fortest.txt");
	if (!input.is_open())
	{
		cerr << "No Such File!" << endl;
	}
	int tCase;
	input >> tCase;

	for (int tc = 1; tc <= tCase; tc++)
	{
		int n;
		input >> n;
		Stack <int>stack(100);

		for (int i = 0; i < n; i++)
		{
			int val;
			input >> val;
			stack.Push(val);
		}
		outfile << "case " << tc << endl;
		while (!stack.IsEmpty())
		{
			outfile << stack.Top() << " ";
			stack.Pop();
		}
		outfile << endl;
	}
	input.close();
	outfile.close();
	return 0;
}