#include <iostream>

using namespace std;

long long arr[91];

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(); cin.tie();
	int n;
	cin >> n;
	
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n];

	return 0;
}