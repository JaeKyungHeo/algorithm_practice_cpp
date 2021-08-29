#include <iostream>

using namespace std;

int dp[1025][1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dp[i][j];
			dp[i][j] = dp[i-1][j]+dp[i][j-1] - dp[i-1][j-1] +dp[i][j];
		}
	}

	while (M--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << '\n';
	}

	return 0;
}



//int** Matrix = new int*[N];
//for (int i = 0; i < N; i++)
//	Matrix[i] = new int[N];


//if (Matrix) {
//	for (int i = 0; i < N; i++)
//		delete[] Matrix[i];
//	delete[] Matrix;
//}