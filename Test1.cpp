#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;
ofstream outflie("text2.txt");

class node {
private:
	friend class list;
	int data;
	node *next;
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
		}
		else {
			node *newNode = new node;
			newNode->data = val;

			newNode->next = first;
			first = newNode;
		}
	}

	void print() {
		node *pos = first;
		while (pos != NULL)
		{
			outflie << pos->data << " ";
			pos = pos->next;
		}
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
		list List;

		for (int i = 0; i < n; i++)
		{
			int val;
			input >> val;
			List.insert(val);
		}
		outflie << "case " << tc << endl;
		List.print();
		outflie << endl;
	}
	input.close();
	outflie.close();
	return 0;
}

