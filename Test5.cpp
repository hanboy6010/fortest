#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
ofstream outfile("test.txt");

class node {
private:
	friend class list;
	int data;
	node *next;
	node *prev;
};
class list {
private:
	node * first;
	node *last;

public:
	list() {
		first = last = NULL;
	}
	~list() {} // 소멸자 구현은 따로 안했습니다.
	void insert(int val) {
		// 처음 리스트에 삽입될 때
		if (first == NULL) {
			node *newNode = new node;
			newNode->data = val;

			first = last = newNode;
			newNode->next = NULL;
			newNode->prev = NULL;
		}
		else {
			node *newNode = new node;
			newNode->data = val;

			newNode->prev = last;
			last->next = newNode;
			last = newNode;
		}
	}

	void print() {
		node *pos = last;
		while (pos != NULL)
		{
			outfile << pos->data << " ";
			pos = pos->prev;
		}
	}
};
int main()
{
	ifstream input("fortest.txt");
	int tCase;
	input >> tCase;

	for (int tc = 1; tc <= tCase; tc++) {
		list LIST;
		int n;
		input >> n;

		for (int i = 0; i < n; i++)
		{
			int val;
			input >> val;
			LIST.insert(val);
		}

		outfile << "case " << tc << endl;
		LIST.print();
		outfile << endl;
	}
	return 0;
}
