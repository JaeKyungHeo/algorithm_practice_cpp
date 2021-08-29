#include <iostream>

using namespace std;
int dp[501][501];

int main() {
	int n, temp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cin >> temp;
			if (j == 0)
				dp[i][j] = temp + dp[i - 1][j];
			else if (j == i - 1)
				dp[i][j] = temp + dp[i - 1][j - 1];
			else {
				if(dp[i-1][j-1]>dp[i-1][j])
					dp[i][j] = temp + dp[i - 1][j - 1];
				else
					dp[i][j] = temp + dp[i - 1][j];
			}
		}
	}

	int max = 0;

	for (int i = 0; i < n; i++) {
		if (dp[n][i] > max)
			max = dp[n][i];
	}

	cout << max;
	
	return 0;
}