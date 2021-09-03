#include <iostream>
#include <vector>
using namespace std;

int check[4000001];
bool Not_prime[4000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	vector<int>prime;

	//소수가 아닌수 체크(에라토스테네스의 체)
	for (int i = 2; i < 2001; i++) {
		for (int j = 2; j * i <= 4000000; j++) {
			Not_prime[j * i] = true;
		}
	}

	//1-4,000,000까지 소수 prime
	for (int i = 2; i < 4000001; i++) {
		if (Not_prime[i] == false)
			prime.push_back(i);
	}

	//연속된 소수들의 합을 인덱스 별로 확인하여 누적
	for (int i = 0; i < prime.size(); i++) {
		int sum = prime[i];
		for (int j = 1; j + i < prime.size(); j++) {
			if (sum < 4000001) {
				check[sum]++;
				sum += prime[i + j];
			}
			else
				break;
		}
	}

	cin >> N;
	cout << check[N];

	return 0;
}