#include <iostream>

using namespace std;

int card[100];

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int n, k, ans = 1, temp;
	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		card[temp]++;
	}

	for (int i = n; i > n - k; i--) ans *= i;
	for (int i = 1; i <= k; i++) ans /= i;

	for (int i = 1; i < 100; i++) {
		if (card[i] != 0)
			ans /= card[i];
	}

	cout << ans;

	return 0;
}