#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//조건
//N(행) x M(열) 직사각형 지도 
//0:빈칸, 1:벽, 2:바이러스
//바이러스는 상하좌우로 퍼져나감
//새로 벽 3개를 세울 수 있음
//입력:N M (2~8)
//빈칸, 벽, 바이러스의 위치
//출력:얻을 수 있는 안전 영역의 최대 크기

int N, M;
int map[9][9];
int submap[9][9];//나중 카피용
queue<pair<int, int>>q;
vector<pair<int, int>>subq;//나중 카피용
int idx[4] = { 0,0,-1,1 };
int idy[4] = { 1,-1,0,0 };

//인덱스 유효 값 확인
bool valid(int y, int x) { return y >= 0 && y < N&& x >= 0 && x < M; }

//벽 3개 세우기
void wall(pair<int,int>w1, pair<int, int>w2, pair<int, int>w3) {
	map[w1.first][w1.second] = 1;
	map[w2.first][w2.second] = 1;
	map[w3.first][w3.second] = 1;
}

//바이러스가 퍼져나감(BFS)
void virusSpread() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + idy[i];
			int nx = x + idx[i];

			if (valid(ny, nx) && map[ny][nx] == 0) {
				map[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}
}

//원래 지도의 형태로 돌려줌
void copymap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = submap[i][j];
		}
	}
}

//원래 지도의 형태로 돌려줌
void copyvirus() {
	for (int i = 0; i < subq.size(); i++)
		q.push(subq[i]);
}

//지도위에 존재하는 0을 모두 세줌(안전 영역)
int count0() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				count++;
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<pair<int, int>>v;//0이 있는 위치(벽을 세울 수 있는 곳)
	int max = 0, ans;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			submap[i][j] = map[i][j];
			if (map[i][j] == 2) {
				q.push({ i,j });
				subq.push_back({ i,j });
			}
			else if (map[i][j] == 0)
				v.push_back({ i,j });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				//케이스 별로 백트레킹형식을 취함
				wall(v[i], v[j], v[k]);//벽 3개 설치
				virusSpread();//바이러스 전파;
				int temp = count0();//바이러스 전파 뒤 안전영역 count
				if (temp > max)
					max = temp;
				copymap();//지도 복구
				copyvirus();//바이러스가 들어있는 큐 복구
			}
		}
	}

	ans = max;
	cout << ans;

	return 0;
}