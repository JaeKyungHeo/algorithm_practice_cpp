#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool prime[1000001];
//1,000,000이하의 수

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(prime, true, sizeof(prime));
	vector<int>prime_;
	int k = 1;

	for (int i = 2; i <= 1000; i++) {
		for (int j = 2; j * i <= 1000000; j++)
			prime[j * i] = false;
	}

	for (int i = 2; i < 1000000; i++) {
		if (prime[i])
			prime_.push_back(i);
	}

	while (1) {
		cin >> k;
		if (k == 0)break;
		for (int i = 0; i < prime_.size(); i++) {
			if (k > prime_[i] && prime[k - prime_[i]]) {
				cout << k << " = " << prime_[i] << " + " << k - prime_[i] << "\n";
				break;
			}
		}
	}

	return 0;
}