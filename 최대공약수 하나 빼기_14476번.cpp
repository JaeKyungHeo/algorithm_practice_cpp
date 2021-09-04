//#include <iostream>
//#include <vector>
//
//int arr[44722];
//
//using namespace std;
//// 1-2,000,000,000->44,722
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int N, k;
//	vector<int>v, ans;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> k;
//		v.push_back(k);
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 2; j < 44722; j++) {
//			if (v[i] < j) break;
//			if (v[i] % j == 0)
//				arr[j]++;
//		}
//	}
//
//	for (int i = 0; i < 44722; i++) {
//		if (arr[i] == N - 1)
//			ans.push_back(i);
//	}
//
//	if (ans.size() == 0) cout << -1;
//	else {
//		for (int i = 0; i < N; i++) {
//			if (v[i] % ans[ans.size() - 1] != 0) {
//				cout << ans[ans.size() - 1] << " " << v[i];
//				break;
//			}
//		}
//	}
//
//	return 0;
//}

#include <iostream>
using namespace std;
int L_gcd[1000001], R_gcd[1000001], arr[1000001];

int gcd(int a, int b) {// 최대공약수 구하기(재귀, 유클리드 호제법)
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	for (int i = 1; i <= n; i++)// 왼쪽에서부터 누적해서 공약수를 구함 
		L_gcd[i] = gcd(arr[i], L_gcd[i - 1]);
	for (int i = n; i >= 1; i--) // 오른쪽에서부터 누적해서 공약수를 구함
		R_gcd[i] = gcd(arr[i], R_gcd[i + 1]);

	int deletedNum = -1;
	int bigGCD = 0;
	for (int i = 1; i <= n; i++) {
		int gcdResult = gcd(L_gcd[i - 1], R_gcd[i + 1]);// i인덱스의 값을 빼고 나머지 수들 간의 최대 공약수를 구함
		if (gcdResult > bigGCD && (arr[i] % gcdResult)) {// 최대 공약수를 가장 큰 값으로 갱신/선택된 최대 공약수가 뺀 i인덱스 수의 약수이면 안되는 조건 추가
			bigGCD = gcdResult;
			deletedNum = arr[i];
		}
	}

	if (deletedNum == -1) cout << deletedNum;
	else cout << bigGCD << " " << deletedNum;

	return 0;
}