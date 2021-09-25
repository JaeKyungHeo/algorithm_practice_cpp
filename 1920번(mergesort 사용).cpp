#include <iostream>
#include <vector>

using namespace std;

int S[100001];
int i, j, k, t;

void merge(int low, int mid, int high) {
	vector<int>u;
	i = low;j = mid + 1;k = 0;
	while (i <= mid && j <= high) {
		if (S[i] < S[j]) {
			u.push_back(S[i]);
			i++;
		}
		else {
			u.push_back(S[j]);
			j++;
		}
	}
	for (t = j; t <= high; t++)
		u.push_back(S[t]);
	for (t = i; t <= mid; t++)
		u.push_back(S[t]);
	for (t = low; t <= high; t++)
		S[t] = u[t - low];
}

void mergeSort(int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(low, mid);
		mergeSort(mid + 1, high);
		merge(low, mid, high);
	}
}

void BS(int s, int e, int n) {
	int mid;
	while (e >= s) {
		mid = (s + e) / 2;
		if (S[mid] == n) {
			cout << 1 << '\n';
			return;
		}
		else if (S[mid] < n)
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
	for (i = 1; i <= N; i++)
		cin >> S[i];
	mergeSort(1, N);

	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> k;
		BS(1, N, k);
	}

	return 0;
}