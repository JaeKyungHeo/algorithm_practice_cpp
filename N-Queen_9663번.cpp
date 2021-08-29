#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool board[15][15];// false:��ġ�� �� ����, true:��ġ �Ұ���
int N, ans = 0;

// �� ����:��, �Ʒ�, �밢���� �Ÿ��� ������� �����Ӱ� �̵�����
// �� N�� ���� �� ����.(N x N ü����)

void check(int r, int c) {// ��ġ�ϸ� ���� �ȵǴ� �� üũ
	for (int i = 0; i < N; i++) {
		board[i][c] = true;
		board[r][i] = true;
		if (r + i < N && c + i < N)
			board[r + i][c + i] = true;
		if (r - i >= 0 && c - i >= 0)
			board[r - i][c - i] = true;
	}
}

void solve(int L) {// L�� �ܰ踦 �ǹ���
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