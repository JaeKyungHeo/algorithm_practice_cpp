#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class edge {
public:
	int node[2];
	float distance;

	edge(int a, int b, float c) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = c;
	}

	bool operator <(edge& edge) {
		return this->distance < edge.distance;
	}
};

int parent[101];

int find(int index) {
	if (parent[index] == index) return index;
	return parent[index] = find(parent[index]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

//사이클 유무 확인
bool isCycle(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return true;
	else
		return false;
}

float Distance(pair<float, float> a, pair<float, float>b) {
	return sqrt(pow((a.first - b.first),2) + pow((a.second - b.second),2));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<edge>v;
	vector<pair<float, float>>star;

	int V;
	float a, b;
	cin >> V;

	for (int i = 0; i < V; i++)
		parent[i] = i;

	for (int i = 0; i < V; i++) {
		cin >> a >> b;
		star.push_back(make_pair(a, b));
	}

	for (int i = 0; i < V; i++) {
		for (int j = i; j < V; j++) {
			v.push_back(edge(i, j, Distance(star[i], star[j])));
		}
	}

	//거리순 정렬
	sort(v.begin(), v.end());

	float answer = 0;

	for (int i = 0; i < v.size(); i++) {
		if (isCycle(v[i].node[0], v[i].node[1]) == false) {
			answer += v[i].distance;
			uni(v[i].node[0], v[i].node[1]);
		}
	}

	//fixed를 통해 소수의 유효자리 수를 고정시킴
	cout << fixed;
	cout.precision(2);
	cout << answer;

	return 0;
}