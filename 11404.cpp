#include <iostream>
#include <cstring>

using namespace std;

int INF = 10000001;// ��尡 �ִ� 100, ������ ���� �ִ� 100,000�� �̱� ������ �ּ� 10000001���� ����
int node[101][101];
int dp[101][101];

void floydWarshall(int n) {

	//�׷��� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=n ; j++)
			dp[i][j] = node[i][j];
	}

	// k:���İ��� ���
	for (int k = 1; k <= n; k++) {
		// i:��� ���
		for (int i = 1; i <= n; i++) {
			// j:���� ���
			for (int j = 1; j <= n; j++) {
				if (i == j)
					dp[i][j] = 0;
				else if (dp[i][k] + dp[k][j] < dp[i][j])// ���İ��� ��� ���� �� �۴ٸ� ��������
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

	//��� ��� �ʱ�ȭ
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