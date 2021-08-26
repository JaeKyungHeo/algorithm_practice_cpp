#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 5000001

int N, M;
int A, B, C;
long long dist[501];//������ int ������ �ѱ� �� �ֱ� ������ long long�� ���
bool cycle;//���� ����Ŭ�� ������ Ȯ��
vector<pair<int, int>> v[501];

void BellmanFord() {
	for (int i = 1; i <= N; i++)
		dist[i] = INF; // ��� ��� INF �ʱ�ȭ

	dist[1] = 0; // ������ 0���� �ʱ�ȭ

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < v[j].size(); k++) {//j��带 �������� ����� ���� üũ
				int next = v[j][k].first;
				int cost = v[j][k].second;

				if (dist[j] != INF && dist[next] > dist[j] + cost) {
					dist[next] = dist[j] + cost;
					if (i == N) cycle = true;//N-1���� Ȯ���� ���Ŀ��� ������ �ȴٸ� ���� ����Ŭ�� ����
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