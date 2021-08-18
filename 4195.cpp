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

	if (a != b) {// ������ �������� ���̱� ������ ���� �ʿ�x
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
		for (int i = 0; i <= N * 2; i++)//�̸��� ��� �ٸ� ��츦 �����
			parent[i] = i, cnt[i] = 1;
		m.clear();

		for (int i = 0; i < N; i++) {
			string a, b;
			//cin >> a >> b;
			//cin�� cout�� �⺻������ ���� �־�, cin�� ������ ������ �ڵ����� cout�� flush��ŵ�ϴ�. 
			//cout�� printf�� �⺻������ ����ȭ�Ǿ��ִ� �����̹Ƿ� ���� ���������Դϴ�. 
			//�ݸ鿡 scanf�� �׷� ���� �����ϴ�.
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