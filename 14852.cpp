//#include <iostream>
//
//using namespace std;
//
//int dp[1000001];
//
//long long DP(int n) {
//	if (dp[n] > 0) return dp[n];
//
//	long long temp = 3 * dp[n - 2] + 2 * dp[n - 1];
//	
//	for (int i = 3; i <= n; i++)
//		temp += (2 * DP(n - 1)) % 10000007;
//	
//	return temp;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cout.tie(NULL); cin.tie(NULL);
//
//	int N;
//	long long answer;
//
//	dp[0] = 1;
//	dp[1] = 2;
//	dp[2] = 7;
//
//	cin >> N;
//
//	//��ȭ��
//	//dp[i]�� 3*dp[i-2](1*2 �ΰ�, 1*1 �ΰ� + 1*2�Ѱ� ��� 2�� ���� 3����) + 2*dp[i-1](1*1 �ΰ�, 2*1�Ѱ�)
//	//dp[i] = 3 * dp[i - 2] + 2 * dp[i - 1] + (2 * dp[i-3] + ... + 2 * dp[0])
//
//	cout<<DP(N);
//
//	return 0;
//}

//������ �ð��ʰ� O(N^2) �ð����⵵

#include <iostream>

using namespace std;

long long dp[1000001][2];


int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int N;

	dp[0][0] = 0;
	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[2][1] = 1;

	cin >> N;

	//��ȭ��
	//dp[i]�� 3*dp[i-2](1*2 �ΰ�, 1*1 �ΰ� + 1*2�Ѱ� ��� 2�� ���� 3����) + 2*dp[i-1](1*1 �ΰ�, 2*1�Ѱ�)
	//dp[i] = 3 * dp[i - 2] + 2 * dp[i - 1] + (2 * dp[i-3] + ... + 2 * dp[0])

	//O(N)�� �ð����⵵
	for (int i = 3; i <= N; i++) {
		dp[i][1] = (dp[i - 1][1] + dp[i - 3][0]) % 1000000007;
		dp[i][0] = (3 * dp[i - 2][0] + 2 * dp[i - 1][0] + 2 * dp[i][1]) % 1000000007;
	}

	cout<<dp[N][0];

	return 0;
}
