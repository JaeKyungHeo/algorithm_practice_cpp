#include <iostream>

using namespace std;

long long dp[1000001];

int main() {
    int n;
    cin >> n;
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
        dp[i] = ((i - 1) * (dp[i - 2] + dp[i - 1])) % 1000000000;
    cout << dp[n];
}