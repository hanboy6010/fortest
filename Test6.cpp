#include<fstream>
#include<iostream>
using namespace std;
ofstream outfile("result.txt");

class chainnode
{
public:
	int data;
	chainnode* link;
};

class chain
{
	friend class chainnode;
public:
	chainnode * chainhead;
	chain();
	void printchain();
	void addchain(int data);
};

chain::chain()
{
	chainhead = NULL;
}

void chain::addchain(int data)
{
	chainnode* tempchain = new chainnode();
	tempchain->data = data;
	if (chainhead != NULL)
	{
		tempchain->link = chainhead;
		chainhead = tempchain;
	}
	else
	{
		chainhead = tempchain;
	}
}

void chain::printchain()
{

	chainnode* tempchain = new chainnode();
	tempchain = chainhead;
	while (tempchain)
	{
		outfile << tempchain->data << " ";
		tempchain = tempchain->link;
	}
	outfile << endl;
}

int main()
{
	ifstream input("test1.txt");
	if (input.is_open() == false)
	{
		cerr << "파일이 열리지 않았습니다" << endl;
	}
	int times;
	int chaintimes;
	input >> times;
	for (int i = 0; i<times; i++)
	{
		input >> chaintimes;
		chain* a = new chain();
		for (int j = 0; j<chaintimes; j++)
		{
			int data;
			input >> data;
			a->addchain(data);
		}
		outfile << "case " << i + 1 << endl;
		a->printchain();
	}
	input.close();
	outfile.close();
	return 0;
}