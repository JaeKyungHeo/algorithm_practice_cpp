//#include <iostream>
//
//using namespace std;
//
//int main() {
//	long long P;// 입력받는 P값이 10^100이라 문자로 받아서 처리해야함...
//	int K, t;
//	cin >> P>>K;
//	bool check = true;
//
//
//	for (int i = 2; i < K; i++) {
//		if (P % i == 0) {
//			check = false;
//			t = i;
//			break;
//		}
//	}
//	if (check == false)
//		cout << "BAD " << t;
//	else
//		cout<<"GOOD";
//
//	return 0;
//}


#include <iostream>
#include <cmath>

using namespace std;

bool Not_prime[1000001];// K의 범위가 10^6이기 때문에 1000000까지의 수를 중 소수를 확인
int K;
string P;

// P를 K미만의 소수로 나누어 지는지 체크
bool check(int n) {
	int sum = 0;
	// 주어진 P를 가장 큰 자리 수부터 차례로 소수 n으로 나누어 지는지 확인
	for (int i = 0; P[i]; i++) {
		sum = (sum * 10 + (P[i] - '0')) % n;
	}
	if (sum == 0) {// 최종적으로 sum(나머지)가 0이라면 나누어진다.
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> P >> K;
	bool Is_good = true;
	int ans = 0;

	// P가 K 미만의 소수로 나누어 떨어지는지 확인.
	for (int i = 2; i < K; ++i) {// 1은 소수가 아니므로 시작을 2부터 잡아줌.
		if (Not_prime[i] == true)// i가 소수가 아니라면 다음 수로 넘어간다.
			continue;
		// 소수 i 로 P가 나누어 떨어지는지 여부 체크
		if (check(i) == true) {
			Is_good = false;
			ans = i;
			break;
		}
		// 소수아닌 수를 체크함(에라토스테네스의 체 - 2...sqrt(K) 전까지 배수를 확인해 주면 1부터 K까지의 모든 소수를 찾을 수 있다.)
		for (int j = 2 * i; j < sqrt(K); j += i)
			Not_prime[j] = true;
	}
	if (Is_good == true)
		cout << "GOOD" << endl;
	else
		cout << "BAD " << ans << endl;

	return 0;
}
