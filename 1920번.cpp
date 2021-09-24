#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;

void BS(int s, int e, int n) {
	int mid;
	while (e >= s) {
		mid = (s + e) / 2;
		if (v[mid] == n) {
			cout << 1 << '\n';
			return;
		}
		else if (v[mid] < n)
			s = mid + 1;
		else
			e = mid - 1;
	}
	cout << 0 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M, k;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> k;
		BS(0, v.size() - 1, k);
	}

	return 0;
}