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

	//�Ҽ��� �ƴѼ� üũ(�����佺�׳׽��� ü)
	for (int i = 2; i < 2001; i++) {
		for (int j = 2; j * i <= 4000000; j++) {
			Not_prime[j * i] = true;
		}
	}

	//1-4,000,000���� �Ҽ� prime
	for (int i = 2; i < 4000001; i++) {
		if (Not_prime[i] == false)
			prime.push_back(i);
	}

	//���ӵ� �Ҽ����� ���� �ε��� ���� Ȯ���Ͽ� ����
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