#include <iostream>

using namespace std;

int parent[500001];

int find(int index) {
	if (parent[index] == index)return index;
	return parent[index] = find(parent[index]);
}

bool uni(int a, int b) {
	a = find(a);
	b = find(b);

	if (parent[a] == parent[b]) {
		return true;
	}
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b, answer = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		parent[i] = i;
	bool check = true;//첫번째 사이클 턴을 출력하기 위함
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (uni(a, b) == true && check ==true) {
			answer = i;
			check = false;
		}
	}

	cout << answer;

	return 0;
}