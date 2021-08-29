#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, M, k, count = 0;
	vector<int>v;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> k;
		v.push_back(k);
	}

	for (int i = 0; i < N; i++)	{
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += v[j];
			if (sum == M) {
				count++;
				break;
			}
			if (sum > M) break;
		}
	}

	cout << count;

	return 0;
}