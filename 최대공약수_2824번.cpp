//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//int A_arr[31624],B_arr[31624];
//
//int gcd(int a, int b) {// 최대공약수 구하기(재귀, 유클리드 호제법)
//	if (b == 0) return a;
//	else return gcd(b, a % b);
//}
//
//int main() {
//	int N, M, k, A = 1, B = 1;
//	long long ans;
//	vector<int>vn, vm;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> k;
//		for (int j = 2; j < 31623; j++) {
//			if (k % j == 0) {
//				k /= j;
//				A_arr[j]++;
//				j = 1;
//			}
//			if (k == 0 || k == 1)
//				break;
//		}
//		if (k >= 31623)
//			vn.push_back(k);
//	}
//
//	cin >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> k;
//		for (int j = 2; j < 31623; j++) {
//			if (k % j == 0) {
//				k /= j;
//				B_arr[j]++;
//				j = 1;
//			}
//			if (k == 0 || k == 1)
//				break;
//		}
//		if (k >= 31623)
//			vm.push_back(k);
//	}
//	
//	k = 1;
//	bool check = false;
//	for (int i = 2; i < 31623; i++) {
//		if (A_arr[i] != 0 && B_arr[i] != 0) {
//			if (A_arr[i] > B_arr[i]) {
//				k = (k * abs(i * B_arr[i])) % 1000000000;
//				if (k * abs(i * B_arr[i]) > 1000000000)
//					check = true;
//			}
//			else {
//				k = (k * abs(i * A_arr[i])) % 1000000000;
//				if (k * abs(i * A_arr[i]) > 1000000000)
//					check = true;
//			}
//		}
//	}
//
//	if (check == false)
//		cout << k << endl;
//	else {
//		char ans[9];
//
//		itoa(k, ans, 10);//int, char, n진수
//
//		int id = 9;
//
//		for (int i = 0; i < 9; i++) {
//			if (ans[i] == '\0') {
//				id = i;
//				break;
//			}
//		}
//
//		for (int i = id; i < 9; i++)
//			cout << '0';
//
//		for (int i = 0; i < id; i++)
//			cout << ans[i];
//	}
//
//	return 0;
//}



#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {// 최대공약수 구하기(재귀, 유클리드 호제법)
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int N, M, k, GCD;
	long long ans = 1;
	vector<int>vn, vm;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> k;
		vn.push_back(k);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> k;
		vm.push_back(k);
	}

	bool check = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vm[j] == 1)continue;
			GCD = gcd(vn[i], vm[j]);
			vn[i] /= GCD;
			vm[j] /= GCD;
			ans *= GCD;
			if (ans >= 1000000000) {
				ans %= 1000000000;
				check = true;
			}
		}
	}

	if (check == false)
		cout << ans << endl;
	else {
		int id = 0;
		int temp = ans;
		for (int i = 0; i < 9; i++) {
			if (temp != 0) {
				id++;
				temp /= 10;
			}
			else
				break;
		}

		for (int i = 0; i < 9 - id; i++)
			cout << '0';

		cout << ans;

	}

	return 0;
}