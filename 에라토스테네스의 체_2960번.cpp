#include <iostream>
#include <cstring>// memset ���̺귯��
#include <cmath>

using namespace std;

bool Not_prime[1001];

void solve(int n, int k) {
	int num = 0;
	for (int i = 2; i <= n; i++) {//�����佺�׳׽��� ü ���� Ȱ��
		for (int j = 1; i * j <= n; j++) {//�Ҽ� ���� �������� ���̱� ������ 1���� �����Ѵ�.
			if (Not_prime[i * j] == false) {
				Not_prime[i * j] = true;
				num++;
			}
			if (num == k) {
				cout << i * j;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int N, K;
	cin >> N >> K;
	
	memset(Not_prime, false, sizeof(Not_prime));

	solve(N, K);

	return 0;
}