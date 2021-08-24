#include <iostream>
#include <cstring>

using namespace std;

int INF = 200001;// 노드가 최대 100, 간선의 수가 최대 100,000개 이기 때문에 최소 10000001으로 설정
int node[101][101];
int dp[101][101];

void floydWarshall(int n) {

	//그래프 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dp[i][j] = node[i][j];
	}


	// k:사이 노드
	for (int k = 1; k <= n; k++) {
		// i:출발 노드
		for (int i = 1; i <= n; i++) {
			// j:도착 노드
			for (int j = 1; j <= n; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j])
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= n; j++){
			if (dp[i][j] < INF|| dp[j][i] < INF) // 서로 비교가능한 것들을 체크
				count++;
		}
		cout << n-count-1 << '\n';// 전체 - 비교가능 - (i = j)
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
		for (int j = 1; j <= n; j++) {
			node[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		node[a][b] = 1;//[a]>[b]
	}

	floydWarshall(n);

	return 0;
}