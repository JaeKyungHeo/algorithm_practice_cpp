#include <iostream>

using namespace std;

int arr[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> k;
		arr[k]++;
	}

	int count = 0;
	for (int i = 0; count != N;i++) {
		if (arr[i] > 0) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i << '\n';
				count++;
			}
		}
	}

	return 0;
}