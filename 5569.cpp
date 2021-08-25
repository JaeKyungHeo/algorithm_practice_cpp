#include <iostream>
#define mod 100000
using namespace std;
int w, h;
int dp[2][2][101][101]; //dp[h][c][i][j] 에서
//i,j까지 왔을때
//h는 0 : 위, 1:왼쪽   
//c는 회전수 0:회전 x   1:회전0
//해서 온 경우의 수(경로의 수)
void goDP() {
	for (int r = 1; r <= h; r++) dp[0][0][r][1] = 1;
	for (int c = 1; c <= w; c++) dp[1][0][1][c] = 1;
	for (int i = 2; i <= h; i++) {
		for (int j = 2; j <= w; j++) {
			dp[0][0][i][j] += dp[0][0][i - 1][j] + dp[0][1][i - 1][j];
			dp[0][1][i][j] += dp[1][0][i - 1][j];

			dp[1][0][i][j] += dp[1][0][i][j - 1] + dp[1][1][i][j-1];//dp[1][0][i][j] += dp[0][1][i][j - 1] +  dp[0][0][i][j - 2]; 이렇게 해서 틀림
			//dp[1][0][i-][j-1]을 더해줘야함!
			dp[1][1][i][j] += dp[0][0][i][j-1];
			dp[0][0][i][j] %= mod;
			dp[0][1][i][j] %= mod;
			dp[1][0][i][j] %= mod;
			dp[1][1][i][j] %= mod;
		}
	}
}
int main() {
	scanf("%d %d", &w, &h); 
	goDP();
	printf("%d\n", (dp[0][0][h][w] + dp[1][0][h][w] + dp[0][1][h][w] + dp[1][1][h][w]) % mod);
	return 0;
}