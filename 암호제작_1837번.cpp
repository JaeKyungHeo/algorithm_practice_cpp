//#include <iostream>
//
//using namespace std;
//
//int main() {
//	long long P;// �Է¹޴� P���� 10^100�̶� ���ڷ� �޾Ƽ� ó���ؾ���...
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

bool Not_prime[1000001];// K�� ������ 10^6�̱� ������ 1000000������ ���� �� �Ҽ��� Ȯ��
int K;
string P;

// P�� K�̸��� �Ҽ��� ������ ������ üũ
bool check(int n) {
	int sum = 0;
	// �־��� P�� ���� ū �ڸ� ������ ���ʷ� �Ҽ� n���� ������ ������ Ȯ��
	for (int i = 0; P[i]; i++) {
		sum = (sum * 10 + (P[i] - '0')) % n;
	}
	if (sum == 0) {// ���������� sum(������)�� 0�̶�� ����������.
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

	// P�� K �̸��� �Ҽ��� ������ ���������� Ȯ��.
	for (int i = 2; i < K; ++i) {// 1�� �Ҽ��� �ƴϹǷ� ������ 2���� �����.
		if (Not_prime[i] == true)// i�� �Ҽ��� �ƴ϶�� ���� ���� �Ѿ��.
			continue;
		// �Ҽ� i �� P�� ������ ���������� ���� üũ
		if (check(i) == true) {
			Is_good = false;
			ans = i;
			break;
		}
		// �Ҽ��ƴ� ���� üũ��(�����佺�׳׽��� ü - 2...sqrt(K) ������ ����� Ȯ���� �ָ� 1���� K������ ��� �Ҽ��� ã�� �� �ִ�.)
		for (int j = 2 * i; j < sqrt(K); j += i)
			Not_prime[j] = true;
	}
	if (Is_good == true)
		cout << "GOOD" << endl;
	else
		cout << "BAD " << ans << endl;

	return 0;
}
