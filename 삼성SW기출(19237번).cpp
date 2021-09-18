#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//조건
//번호가 작을 수록 상어가 강력함
//NxN 크기의 격자중 M개의 칸에 상어가 한 마리씩 들어있음
//1초마다 모든상어가 인접한 상하좌우 칸으로 이동함
//이동한 칸에 냄새를 뿌림(k번 이동하면 냄새가 사라짐)
//이동할 칸의 우선순위 아무 냄새가 없는 칸 > 자신의 냄새가 있는 칸(인접한 모든 칸이 빈칸이라도 우선순위 적용))
//자신의 냄새 칸이 여러개라면 상어마다 부여되어 있는 우선순위에 따라 이동
//상어가 보고있는 방향에 따라서도 우선순위가 다름
//이동 후 상어는 이동한 방향을 향함
//같은 칸에 여러 상어가 존재하게 되면 가장 장은 번호를 가진 상어를 제외하고 나머지 상어는 사라짐
//입력: N(2~20) M(2~N^2) k(1~1000)
//출력: 1번 상어만 남게 되기까지 걸리는 시간 / 1000초가 넘어도 끝나지 않았다면 -1 출력
//현 상황기준으로 상어가 이동후 냄새가 사라짐

struct state {
	int num_shark;//냄새를 남긴 상어번호
	int K;//냄새의 남은 턴
	int exist_shark;//현 공간에 존재하는지 상어의 번호 없다면 0
};

state board[22][22];//(1,1)~(N,N)
vector<pair<pair<int, int>, pair<int,int>>>list;//상어의 좌표와 상어의 번호, 방향를 담음<y,x,n,d>
//위 벡터를 통해 상어를 우선 이동시키고 해당 턴의 냄새를 지워나감
vector<vector<vector<int>>>pr(401);
//담기는 순서 역시 위,아래, 왼쪽, 오른쪽으로 담김
//1:위, 2:아래, 3:왼쪽, 4:오른쪽
int N, M, k;

int direct[401];

bool compare(pair<pair<int, int>, pair<int, int>>a, pair<pair<int, int>, pair<int, int>>b) {
	return a.second.first < b.second.first;
}

bool valid(int y, int x) { return (y > 0) && (y <= N) && (x > 0) && (x <= N); }

pair<int, int> dir(int n) {
	if (n == 1) return { -1,0 };//위
	else if (n == 2)return { 1,0 };//아래
	else if (n == 3)return { 0,-1 };//왼쪽
	else return { 0,1 };//오른쪽
}

void move(pair<pair<int, int>, pair<int, int>> s) {
	//우선 순위에 따라 빈칸 이동이 가능하다면 이동
	for (int i = 0; i < 4; i++) {
		pair<int, int> temp = dir(pr[s.second.first][s.second.second - 1][i]);
		int r = s.first.first + temp.first;
		int c = s.first.second + temp.second;
		if (valid(r, c) == true && board[r][c].K == 0) {
			direct[board[s.first.first][s.first.second].num_shark] = pr[s.second.first][s.second.second - 1][i];
			board[s.first.first][s.first.second].exist_shark = 0;
			board[r][c].exist_shark = board[s.first.first][s.first.second].num_shark;
			return;
		}
	}
	//모든 방향이 채워져 있다면 다시 자신의 냄새 우선순위 탐색
	for (int i = 0; i < 4; i++) {
		pair<int, int> temp = dir(pr[s.second.first][s.second.second - 1][i]);
		int r = s.first.first + temp.first;
		int c = s.first.second + temp.second;
		if (valid(r, c) == true && board[r][c].num_shark == board[s.first.first][s.first.second].num_shark) {
			direct[board[s.first.first][s.first.second].num_shark] = pr[s.second.first][s.second.second - 1][i];
			board[s.first.first][s.first.second].exist_shark = 0;
			board[r][c].exist_shark = board[s.first.first][s.first.second].num_shark;
			return;
		}
	}
}

void solution() {
	for (int i = 1; i <= 1000; i++) {
		//상어를 우선 이동시킴
		for (int j = list.size() - 1; j >= 0; j--)
			move(list[j]);

		list.clear();
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (board[r][c].exist_shark > 0)
					list.push_back({ {r,c},{board[r][c].exist_shark,direct[board[r][c].exist_shark]} });
			}
		}

		sort(list.begin(), list.end(), compare);

		//상어가 한 마리 남았다면 종료
		if (list.size() == 1) {
			cout << i;
			return;
		}

		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (board[r][c].exist_shark == 0 && board[r][c].K > 0) {
					board[r][c].K--;
					if (board[r][c].K == 0)
						board[r][c].num_shark = 0;
				}
				else if (board[r][c].exist_shark > 0) {
					board[r][c].K = k;
					board[r][c].num_shark = board[r][c].exist_shark;
				}
			}
		}
	}
	cout << -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> k;

	//NxN칸의 정보를 받음
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j].exist_shark;
			if (board[i][j].exist_shark > 0) {
				list.push_back({ {i,j}, {board[i][j].exist_shark,0} });
				board[i][j].K = k;
				board[i][j].num_shark = board[i][j].exist_shark;
			}
			else {
				board[i][j].K = 0;
				board[i][j].num_shark = 0;
			}
		}
	}

	sort(list.begin(), list.end(), compare);

	//처음 상어들의 방향
	int t;
	for (int i = 0; i < list.size(); i++) {
		cin >> t;
		list[i].second.second = t;
	}

	vector<int> sub;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> t;
				sub.push_back(t);
			}
			pr[i].push_back(sub);
			sub.clear();
		}
	}

	solution();

	return 0;
}