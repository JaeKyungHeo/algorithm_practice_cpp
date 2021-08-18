#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class edge {
public:
	int node[2];
	int distance;

	edge(int a, int b, int c) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = c;
	}

	bool operator <(edge& edge) {
		return this->distance < edge.distance;
	}
};

int parent[10001];

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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<edge>v;

	int V, E, a, b, c;
	cin >> V >> E;

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v.push_back(edge(a, b, c));
	}
	
	//거리순 정렬
	sort(v.begin(), v.end());

	int answer = 0;

	for (int i = 0; i < v.size(); i++) {
		if (isCycle(v[i].node[0], v[i].node[1]) == false) {
			answer += v[i].distance;
			uni(v[i].node[0], v[i].node[1]);
		}
	}

	cout << answer;

	return 0;
}