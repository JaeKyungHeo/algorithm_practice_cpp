#include<iostream>
#include<string>
#include<map>
using namespace std;

int N, M, parent[200001], cnt[200001];
map<string, int> m;

int find(int index) {
	if (parent[index] == index) return index;
	return parent[index] = find(parent[index]);
}

int uni(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {// 순서가 정해져서 쌓이기 때문에 갱신 필요x
		parent[a] = b;
		cnt[b] += cnt[a];
	}
	return cnt[b];
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;

	while(TC--) {
		int N, index = 1;
		cin >> N;
		for (int i = 0; i <= N * 2; i++)//이름이 모두 다를 경우를 대비함
			parent[i] = i, cnt[i] = 1;
		m.clear();

		for (int i = 0; i < N; i++) {
			string a, b;
			//cin >> a >> b;
			//cin은 cout에 기본적으로 묶여 있어, cin을 수행할 때마다 자동으로 cout을 flush시킵니다. 
			//cout과 printf는 기본적으로 동기화되어있는 상태이므로 역시 마찬가지입니다. 
			//반면에 scanf는 그런 것이 없습니다.
			//char a[21], b[21];
			//scanf("%s %s", &a, &b);
			cin >> a >> b;
			if (m.count(a) == 0) {
				m.insert({ a,index++ });
			}
			if (m.count(b) == 0) {
				m.insert({ b,index++ });
			}

			//printf("%d\n", uni(m[a], m[b]));
			cout << uni(m[a], m[b]) << '\n';
		}
	}

	return 0;
}