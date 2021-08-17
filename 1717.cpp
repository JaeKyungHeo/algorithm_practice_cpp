#include <iostream>

using namespace std;

int parent[1000001];

//parent ã��
int getParent(int parent[], int x) {
	if (parent[x] == x)return x;
	return parent[x] = getParent(parent, parent[x]);
}

//�� ��带 ����
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

//�� ��尡 ���� �׷����� �����ϳ�?
void findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	while (m--) {
		int input, a, b;
		cin >> input >> a >> b;
		if (input == 0)
			unionParent(parent, a, b);
		else
			findParent(parent, a, b);
	}

	return 0;
}