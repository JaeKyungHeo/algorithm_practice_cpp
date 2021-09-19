#include <iostream>
#include <queue>

using namespace std;

//조건
//보드에 빨간 구슬과 파란 구슬을 하나씩 넣어 빨간 구슬을 구멍으로 빼내는 게임
//N(행), M(열)
//옵션 -> 왼쪽, 오른쪽, 위쪽, 아래쪽으로 기울이기 가능(라인따라 쭉이동)
//빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패(-1)
//빨간 구슬과 파란 구슬이 동시에 같은 위치에 있을 수 없음
//'.':빈 칸, '#':벽, 'O':구멍, 'R':빨간 구슬, 'B':파란 구슬
//보드의 모든 가장자리에는 #이 있음 -> valid 함수 필요x
//입력:N, M(3~10)
//위치 별 상태
//출력:최소 몇 번 만에 빨간 구슬이 구멍을 통해 빠져나갈 수 있는지?
//없다면 -1출력

char board[11][11];
int N, M;
bool c = false;
int idy[4] = { 1,-1,0,0 };
int idx[4] = { 0,0,-1,1 };

queue < pair<pair<pair<int, int>, pair<int,int>>, int>>q;//R(y, x), B(y, x), turn

void move(int ry, int rx,int by, int bx, int ny, int nx, int t) {
	//0이면 R이 앞서 있고, 1이면 B가 진행방향으로 앞서 있다.
	int pre;
	if (ny == 0 && nx == 1) {
		if (rx - bx > 0) pre = 0;
		else pre = 1;
	}
	else if (ny == 0 && nx == -1) {
		if (rx - bx < 0) pre = 0;
		else pre = 1;
	}
	else if (ny == 1 && nx == 0) {
		if (ry - by > 0) pre = 0;
		else pre = 1;
	}
	else{
		if (ry - by < 0) pre = 0;
		else pre = 1;
	}

	int tRy = ry, tRx = rx, tBy = by, tBx = bx;
	bool cr = true;
	bool cb = true;

	for (int i = 1; i < 10; i++) {
		if (cr == true && board[ry][rx] == '#') {
			tRy = ry - ny;
			tRx = rx - nx;
			cr = false;
		}
		else if(cr == true){
			ry += ny;
			rx += nx;
		}
		if ( board[by][bx] == '#' && cb == true) {
			tBy = by - ny;
			tBx = bx - nx;
			cb = false;

		}
		else if(cb == true){
			by += ny;
			bx += nx;
		}
		
		if (board[ry][rx] == 'O') {
			c = true;
			return;
		}
		if (board[by][bx] == 'O')
			return;

		if (cr == false && cb == false) {
			if (tRx == tBx && tRy == tBy) {
				if (pre == 0) {
					q.push({ {{tRy,tRx}, {tBy - ny,tBx - nx}},t });
					break;
				}
				else {
					q.push({ {{tRy - ny,tRx - nx}, {tBy,tBx}},t });
					break;
				}
			}
			else {
				q.push({ {{tRy,tRx}, {tBy,tBx}},t });
				break;
			}
		}
	}
}

int goHole() {

	while (!q.empty()) {
		int Ry = q.front().first.first.first;
		int Rx = q.front().first.first.second;
		int By = q.front().first.second.first;
		int Bx = q.front().first.second.second;
		int t = q.front().second;
		q.pop();
		bool sim = false;
		if (t > 10) return -1;
		else {
			for (int i = 0; i < 4; i++) {
				move(Ry, Rx, By, Bx, idy[i], idx[i], t+1);
				if (c == true) {
					int y = By;
					int x = Bx;
					for (int j = 0; j < 9; j++) {
						y += idy[i];
						x += idx[i];
						if (board[y][x] == '#')break;
						if (y < 0 || y >= N || x < 0 || x >= M)break;
						if (board[y][x] == 'O') {
							sim = true;
							break;
						}
					}
					if (sim == false) {
						if (t + 1 < 11)
							return t + 1;
						else
							return -1;
					}
					c = false;
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	string t;
	pair<int, int>R;
	pair<int, int>B;

	for (int i = 0; i < N; i++) {
		cin >> t;
		for (int j = 0; j < M; j++) {
			board[i][j] = t[j];
			if (board[i][j] == 'R') {
				R.first = i;
				R.second = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				B.first = i;
				B.second = j;
				board[i][j] = '.';
			}
		}
	}

	q.push({ { { R.first ,R.second }, { B.first ,B.second } },0 });
	
	cout << goHole();

	return 0;
}
