#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//����
//���� �� ���� ��������� �ּҷ�
//N:���� ����, M:���� ����
//N(2~100,000), M(1~1,000,000)
//A B C -> A,B���� �����ϴ� ���� ������ C(1~1,000)
//�ּ� ���д� Ʈ���� ���ϰ� ���� ū ���ἱ ����

int N, M;
int road[100001];
int ta, tb;
vector<pair<pair<int, int>, int>>v;

bool compare(pair<pair<int, int>, int>a, pair<pair<int, int>, int>b) {
	if (a.second == b.second) {
		if (a.first.first == b.first.first)
			return a.first.second < b.first.second;
		else
			return a.first.first < b.first.first;
	}
	else
		return a.second < b.second;
}

int getparent(int n) {
	if (road[n] == n)
		return n;
	else
		return getparent(road[n]);
}

void uni(int a, int b) {
	ta = getparent(a);
	tb = getparent(b);

	if (ta<tb)
		road[tb] = ta;
	else
		road[ta] = tb;
}

bool find(int a, int b) {
	ta = getparent(a);
	tb = getparent(b);

	if (ta == tb)
		return false;//����Ǿ� ����
	else
		return true;//����x
}

void solution() {
	int total = 0, max;
	for (int i = 0; i < v.size(); i++) {
		if (find(v[i].first.first, v[i].first.second) == true) {
			uni(v[i].first.first, v[i].first.second);
			//cout << v[i].first.first << ' ' << v[i].first.second << ' ' << v[i].second << endl;
			total += v[i].second;
			max = v[i].second;
		}
	}
	cout << total - max;
}

int main() {
	cin >> N >> M;
	int a, b, c;

	for (int i = 1; i <= N; i++)
		road[i] = i;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}

	sort(v.begin(), v.end(), compare);

	solution();

	return 0;
}