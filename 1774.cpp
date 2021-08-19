#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class edge {
public:
	int node[2];
	double distance;

	edge(int a, int b, double c) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = c;
	}

	bool operator <(edge& edge) {
		return this->distance < edge.distance;
	}
};

int parent[1001];

int find(int index) {
	if (parent[index] == index) return index;
	return parent[index] = find(parent[index]);
}

void uni(int a, int b) {//����ó���� �������
	a = find(a);
	b = find(b);
	if (a < b)
		parent[b] = a;
	else if (a > b)
		parent[a] = b;

}

//����Ŭ ���� Ȯ��
bool isCycle(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return true;
	else
		return false;
}

double Distance(pair<int, int> a, pair<int, int>b) {
	return sqrt(pow(a.first - b.first,2)+pow(a.second - b.second,2));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<edge>v;
	vector<pair<int, int>>god;

	int N, M, a, b;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	god.push_back(make_pair(0, 0));
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		god.push_back(make_pair(a, b));
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		uni(a, b);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			v.push_back(edge(i, j, Distance(god[i], god[j])));
		}
	}

	//�Ÿ��� ����
	sort(v.begin(), v.end());

	double answer = 0;

	for (int i = 0; i < v.size(); i++) {
		if (isCycle(v[i].node[0], v[i].node[1]) == false) {
			answer += v[i].distance;
			uni(v[i].node[0], v[i].node[1]);
		}
	}

	//fixed�� ���� �Ҽ��� ��ȿ�ڸ� ���� ������Ŵ
	cout << fixed;
	cout.precision(2);
	cout << answer;

	return 0;
}