#include <iostream>
#include <vector>

using namespace std;

int S[100001];

void merge(int low, int mid, int high) {
	vector<int>u;
	int i = low;
	int j = mid + 1;
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
	for (int t = i; t <= mid; t++)
		u.push_back(S[t]);
	for (int t = j; t <= high; t++)
		u.push_back(S[t]);

	for (int t = 0; t < u.size(); t++)
		S[t + low] = u[t];
}

void mergeSort(int low, int high) {
	if (low < high) {
		//쪼게주기
		int mid = (low + high) / 2;
		mergeSort(low, mid);//앞부분
		mergeSort(mid + 1, high);//뒤부분
		
		merge(low, mid, high);//병합
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
	for (int i = 1; i <= N; i++)
		cin >> S[i];

	mergeSort(1, N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> k;
		BS(1, N, k);
	}

	return 0;
}