#include <iostream>

using namespace std;

int city[201];
int node[1001];

//보통 union find 알고리즘을 사용할 때 갱신을 작은 수쪽으로 수정해줍니다.

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
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	bool check = false;
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
		city[i] = i;

	int k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> k;
			if(k == 1)
				unionParent(city, i, j);
		}
	}
	
	cin >> node[0];
	for (int i = 1; i < m; i++) {
		cin >> node[i];
		if (findParent(city, node[i - 1], node[i]) != 1) {
			check = true;
			break;
		}
	}
	if (check == true)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}