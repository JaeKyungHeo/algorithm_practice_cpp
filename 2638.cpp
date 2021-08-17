#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>>q, p;//q:치즈 위치 저장, p:이번 턴에 녹을 치즈들
int N, M;
int page[101][101];
//탐색 방향 위, 아래, 왼쪽, 오른쪽
int idx[4] = { 0,0,-1,1 };
int idy[4] = { -1,1,0,0 };

void dfs_air(int n ,int m) {
	if (page[n][m] != 0)return;
	page[n][m] = 2;
	for (int i = 0; i < 4; i++) {
		int x = m + idx[i];
		int y = n + idy[i];
		if (x >= 0 && x < M && 0 <= y && y < N && page[y][x] == 0)
			dfs_air(y, x);
	}
}

void melt() {
	int count = q.size();
	for (int i = 0; i < count; i++) {
		int n = q.front().first;
		int m = q.front().second;
		q.pop();

		int count_edge = 0;
		for (int j = 0; j < 4; j++) {
			int x = m + idx[j];
			int y = n + idy[j];

			if (page[y][x] == 2)
				count_edge++;
		}
		if (count_edge >= 2) {
			p.push(make_pair(n, m));
		}
		else 
			q.push(make_pair(n, m));//이번 턴에 녹지 않는 치즈들
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> page[i][j];
			if (page[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	int answer = 0;

	dfs_air(0, 0);

	while (q.size() != 0) {
		melt();

		while (!p.empty()) {
			int y = p.front().first;
			int x = p.front().second;
			p.pop();
			page[y][x] = 0;
			dfs_air(y, x);
		}
		answer++;
	}

	cout << answer;

	return 0;
}