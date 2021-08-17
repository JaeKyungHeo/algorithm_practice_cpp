#include <iostream>

using namespace std;

int parent[1000001];

//parent 찾기
int getParent(int parent[], int x) {
	if (parent[x] == x)return x;
	return parent[x] = getParent(parent, parent[x]);
}

//두 노드를 연결
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

//두 노드가 같은 그래프에 존재하나?
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