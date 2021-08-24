#include <iostream>
#include <cstring>

using namespace std;

int INF = 200001;// ��尡 �ִ� 100, ������ ���� �ִ� 100,000�� �̱� ������ �ּ� 10000001���� ����
int node[101][101];
int dp[101][101];

void floydWarshall(int n) {

	//�׷��� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dp[i][j] = node[i][j];
	}


	// k:���� ���
	for (int k = 1; k <= n; k++) {
		// i:��� ���
		for (int i = 1; i <= n; i++) {
			// j:���� ���
			for (int j = 1; j <= n; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j])
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= n; j++){
			if (dp[i][j] < INF|| dp[j][i] < INF) // ���� �񱳰����� �͵��� üũ
				count++;
		}
		cout << n-count-1 << '\n';// ��ü - �񱳰��� - (i = j)
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(); cin.tie();

	int n, m, a, b, c;
	cin >> n;
	cin >> m;

	//��� ��� �ʱ�ȭ
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