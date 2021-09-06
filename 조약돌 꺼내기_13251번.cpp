#include <iostream>

using namespace std;

int color[51];

int com(int N, int K) {
	int ans = 1;

	for (int i = N; i > N - K; i--) ans *= i;
	for (int i = 1; i <= K; i++) ans /= i;

	return ans;
}


int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int M, K, N = 0, Case, Sub = 0;
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> color[i];
	cin >> K;

	for (int i = 0; i < M; i++)
		N += color[i];

	Case = com(N, K);

	for (int i = 0; i < M; i++) {
		if (color[i] > K)
			Sub += com(color[i], K);
	}

	if (1.0 * Sub / Case == 1)
		cout << "1.0";
	else {
		cout.precision(17);

		cout << 1.0 * Sub / Case;
	}

	return 0;
}