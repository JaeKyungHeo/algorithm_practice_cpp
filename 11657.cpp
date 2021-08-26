#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 5000001

int N, M;
int A, B, C;
long long dist[501];//범위가 int 범위를 넘길 수 있기 때문에 long long형 사용
bool cycle;//음의 사이클을 갖는지 확인
vector<pair<int, int>> v[501];

void BellmanFord() {
	for (int i = 1; i <= N; i++)
		dist[i] = INF; // 모든 노드 INF 초기화

	dist[1] = 0; // 시작점 0으로 초기화

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < v[j].size(); k++) {//j노드를 기준으로 연결된 노드들 체크
				int next = v[j][k].first;
				int cost = v[j][k].second;

				if (dist[j] != INF && dist[next] > dist[j] + cost) {
					dist[next] = dist[j] + cost;
					if (i == N) cycle = true;//N-1까지 확인한 이후에도 갱신이 된다면 음의 사이클이 존재
				}

			}
		}
	}

	if (cycle) cout << -1 << '\n';
	else {
		for (int i = 2; i <= N; i++)
			cout << (dist[i] != INF ? dist[i] : -1) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++){
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
	}

	BellmanFord();

	return 0;
}