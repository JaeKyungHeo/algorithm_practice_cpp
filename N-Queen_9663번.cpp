#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool board[15][15];// false:위치할 수 있음, true:위치 불가능
int N, ans = 0;

// 퀸 성질:위, 아래, 대각선을 거리에 상관없이 자유롭게 이동가능
// 퀸 N개 놓을 수 있음.(N x N 체스판)

void check(int r, int c) {// 우치하면 가면 안되는 곳 체크
	for (int i = 0; i < N; i++) {
		board[i][c] = true;
		board[r][i] = true;
		if (r + i < N && c + i < N)
			board[r + i][c + i] = true;
		if (r - i >= 0 && c - i >= 0)
			board[r - i][c - i] = true;
	}
}

void solve(int L) {// L은 단계를 의미함
	if (L == N) {
		ans++;
		return;
	}
	queue<pair<int, int>>q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == false)
				q.push(make_pair(i, j));
		}
	}
	while (!q.empty()) {
		bool sub_board[15][15];
		copy(&board[0][0], &board[0][0] + N * N, &sub_board[0][0]);
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		check(r , c);
		solve(L + 1);
		copy(&sub_board[0][0], &sub_board[0][0] + N * N, &board[0][0]);
		solve(L);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(); cin.tie();
	cin >> N;

	solve(0);

	cout << ans;

	return 0;
}