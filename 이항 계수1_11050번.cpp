#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int N, K, ans = 1;
	cin >> N >> K;

	for (int i = N; i > N - K; i--) ans *= i;
	for (int i = 1; i <= K; i++) ans /= i;

	cout << ans;

	return 0;
}