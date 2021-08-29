#include <iostream>

using namespace std;

int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int N, M, k;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> k;
		dp[i] = dp[i - 1] + k;
	}

	while (M--) {
		int i, j;
		cin >> i >> j;

		cout << dp[j] - dp[i - 1] << '\n';

	}

	return 0;
}