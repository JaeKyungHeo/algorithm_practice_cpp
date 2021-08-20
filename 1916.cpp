#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> city[1001];
int INF = 100000001;// ��ü���̰� 1������� �����ϱ� ������ �װͺ��� Ŀ����
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
		int distance = -pq.top().second;//�Ÿ��� ���� ������ �����ϱ� ���� ����ȭ����
		pq.pop();

		if (d[cur] < distance)continue;
		for (int i = 0; i < city[cur].size(); i++) {
			//���̳��� ���α׷����� Ȱ���� ���ͽ�Ʈ�� �˰���
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