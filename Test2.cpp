#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;
ofstream outfile("test.txt");

class circularQueue
{
private:
	int front;
	int rear;
	int data[1000];

public:
	circularQueue()
	{
		front = rear = 0;
	}
	bool IsEmpty()
	{
		if (front == rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool IsFull()
	{
		if ((rear + 1) % 1000 == front)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void frontqueue(int val)
	{
		if (IsFull())
		{
			cerr << "Queue is Full!" << endl;
		}
		else
		{
			rear = (rear + 1) % 1000;
			data[rear] = val;
		}
	}
	void rearqueue(int val)
	{
		if (IsEmpty())
		{
			cerr << "Queue is Empty!" << endl;
		}
		else
		{
			front = (front + 1) % 1000;
			data[front] = val;
		}
	}
	void print()
	{
		int size;
		if (front < rear)
		{
			size = rear;
		}
		else
		{
			size = rear + 1000;
		}
		for (int i = front + 1; i <= size; i++)
		{
			outfile << data[i % 1000] << " ";
		}
	}
};

int main()
{
	ifstream input("fortest.txt");

	int tCase;
	input >> tCase;

	for (int tc = 1; tc <= tCase; tc++) {
		
		circularQueue CQ;
		int n;
		input >> n;

		for (int i = 0; i < n; i++)
		{
			int val;
			input >> val;
			CQ.frontqueue(val);
		}

		outfile << "case " << tc << endl;
		CQ.print();
		outfile << endl;
	}
	return 0;
}
