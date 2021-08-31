#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, k;
vector<int> num;
queue<int> check;

int binary_s(int n){
	
	int L = 0, R = N-1;

	while (true) {
		int mid = (L + R) / 2;
		if (num[mid] == n)
			return 1;
		else if (num[mid] > n) {
			R = mid - 1;
		}
		else
			L = mid + 1;
		if (L > R) return 0;
	}
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &k);
		num.push_back(k);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &k);
		check.push(k);
	}

	sort(num.begin(), num.end());

	while (!check.empty()) {
		printf("%d\n", binary_s(check.front()));
		check.pop();
	}

	return 0;
}