#include <iostream>
#include <queue>

using namespace std;

//����
//���忡 ���� ������ �Ķ� ������ �ϳ��� �־� ���� ������ �������� ������ ����
//N(��), M(��)
//�ɼ� -> ����, ������, ����, �Ʒ������� ����̱� ����(���ε��� ���̵�)
//���� ������ �Ķ� ������ ���ÿ� ���ۿ� ������ ����(-1)
//���� ������ �Ķ� ������ ���ÿ� ���� ��ġ�� ���� �� ����
//'.':�� ĭ, '#':��, 'O':����, 'R':���� ����, 'B':�Ķ� ����
//������ ��� �����ڸ����� #�� ���� -> valid �Լ� �ʿ�x
//�Է�:N, M(3~10)
//��ġ �� ����
//���:�ּ� �� �� ���� ���� ������ ������ ���� �������� �� �ִ���?
//���ٸ� -1���

char board[11][11];
int N, M;
bool c = false;
int idy[4] = { 1,-1,0,0 };
int idx[4] = { 0,0,-1,1 };

queue < pair<pair<pair<int, int>, pair<int,int>>, int>>q;//R(y, x), B(y, x), turn

void move(int ry, int rx,int by, int bx, int ny, int nx, int t) {
	//0�̸� R�� �ռ� �ְ�, 1�̸� B�� ����������� �ռ� �ִ�.
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
