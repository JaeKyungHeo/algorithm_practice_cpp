//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <string.h>
//
//using namespace std;
//
//
//int edge_count(int n) {
//	int edge = 0;
//	bool dot[10001];
//	memset(dot, false, sizeof(dot));
//	vector<int>v;
//	for (int i = 2; i <= sqrt(n); i++) {//n의 약수를 모두 구함
//		if (n % i == 0)
//			v.push_back(i);
//	}
//
//	for (int j = 0; j < v.size(); j++) {// 1~n-1까지 수 중 n과 공약수가 있는 수 색출
//		for (int i = 1; i <= (n / 2)+1; i++) {
//			if (dot[v[j] * i] == false && v[j] * i < n)
//				dot[v[j] * i] = true;
//		}
//	}
//
//	for (int i = 1; i < n; i++) {
//		if (dot[i] == false)
//			edge++;
//	}
//	return edge;
//}
//
//void dot_count(int n) {
//	int total = 0;
//	for (int i = 1; i <= n; i++)
//		total += edge_count(i);
//	cout << total * 2 + 3 << endl;
//}
//
//
//int main() {
//	int C, N;
//	cin >> C;
//	for (int i = 0; i < C; i++) {
//		cin >> N;
//		dot_count(N);
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
	cin.tie(NULL);

	int C;
	vector<int>v;
	cin >> C;
	v.push_back(0);

	int ans = 0;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1)
				ans++;
		}
		v.push_back(ans);
	}

	while (C--) {
		int N;
		cin >> N;
		cout << v[N] * 2 + 3 << '\n';
	}

	return 0;
}