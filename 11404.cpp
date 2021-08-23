#include <iostream>
#include <cstring>

using namespace std;

int INF = 10000001;// 노드가 최대 100, 간선의 수가 최대 100,000개 이기 때문에 최소 10000001으로 설정
int node[101][101];
int dp[101][101];

void floydWarshall(int n) {

	//그래프 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=n ; j++)
			dp[i][j] = node[i][j];
	}

	// k:거쳐가는 노드
	for (int k = 1; k <= n; k++) {
		// i:출발 노드
		for (int i = 1; i <= n; i++) {
			// j:도착 노드
			for (int j = 1; j <= n; j++) {
				if (i == j)
					dp[i][j] = 0;
				else if (dp[i][k] + dp[k][j] < dp[i][j])// 거쳐가는 경우 값이 더 작다면 갱신해줌
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(); cin.tie();

	int n, m, a, b, c;
	cin >> n;
	cin >> m;

	//모든 노드 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			node[i][j] = INF;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (node[a][b] > c)
			node[a][b] = c;
	}

	floydWarshall(n);

	return 0;
}