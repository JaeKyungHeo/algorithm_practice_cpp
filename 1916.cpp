#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> city[1001];
int INF = 100000001;// 전체길이가 1억까지는 가능하기 때문에 그것보다 커야함
int d[1001];
int N, M;
bool visit[1001];

void Dijkstra(int s, int e) {
	visit[s] = true;
	priority_queue<pair<int, int>>pq; // {index, distance}
	for (int i = 1; i <= N; i++)
		d[i] = INF;
	pq.push({ s, 0 });
	while (!pq.empty()) {
		int cur = pq.top().first;
		int distance = -pq.top().second;//거리가 작은 순으로 정렬하기 위해 음수화해줌
		pq.pop();

		if (d[cur] < distance)continue;
		for (int i = 0; i < city[cur].size(); i++) {
			//다이나믹 프로그래밍을 활용한 다익스트라 알고리즘
			int next = city[cur][i].first;
			int nextDistance = distance + city[cur][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push({ next,-nextDistance });
			}
		}
	}
	cout << d[e];
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int a, b, d, s, e;
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> d;
		city[a].push_back({ b,d });
		//city[b].push_back({ a,d });
	}

	cin >> s >> e;

	Dijkstra(s, e);

	return 0;
}