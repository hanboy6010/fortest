#include <iostream>
#include <cstdio>

using namespace std;

void prevTravel(int *tree, int node) {
	if (tree[node] == 0)
		return;

	cout << tree[node] << " ";
	prevTravel(tree, node * 2);
	prevTravel(tree, node * 2 + 1);
}

int main()
{
	int tCase;
	cin >> tCase;

	for (int tc = 1; tc <= tCase; tc++) {
		int node = 1;
		int arr[10002] = { 0, };
		int tree[10002] = { 0, };

		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		for (int i = 0; i < n; i++) {
			tree[node] = arr[i];
			node++;
		}
		cout << "case " << tc << endl;
		prevTravel(tree, 1);
		cout << endl;
	}
	return 0;
}
