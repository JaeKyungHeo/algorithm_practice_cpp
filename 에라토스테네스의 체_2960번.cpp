#include <iostream>
#include <cstring>// memset 라이브러리
#include <cmath>

using namespace std;

bool Not_prime[1001];

void solve(int n, int k) {
	int num = 0;
	for (int i = 2; i <= n; i++) {//에라토스테네스의 체 정의 활용
		for (int j = 1; i * j <= n; j++) {//소수 역시 지워지는 것이기 때문에 1부터 시작한다.
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