#include <iostream>
#include <vector>

using namespace std;

//조건
//N:세로선 수, H:가로선 후보, M:가로선 개수(미리 놓려질 수)
//임의의 가로 선수가 주어졌을 때 
//가로선을 추가해서, 사다리 결고가 i출발해서 i로 가는 결과를 만들기
//그렇게하기 위해 추가해야할 최소 가로선 수
//입력
//N(2~10), M(0~(N-1)xH), H(1~30)
//가로선의 정보는 a b로 나타낸다(b번과 b+1번 세로선을 a번 점선 위치에서 연결)
//출력: 가로선 개수의 최솟값을 출력, 이 값이 3초과라면 -1출력 불가능한 경우에도 -1출력
//(1,1)~(N,H)까지 
//연속적으로 가로로 연결된 선은 없다.

//문제풀이: 연결되어 있지 않은 선들을 연결하고 이동을 진행 -> 이러한 방법을 백트래킹을 사용하여 완전탐색 진행

pair<bool,bool> node[32][12];// 현재 위치에서 왼쪽 또는 오른쪽으로 이동가능한지 판단
//true: 이동가능, false: 이동불가
int N, M, H;

//세로 기준 한열을 시작으로 잡고 가장 아래까지 내려가봄
bool move(int n) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int col = n;
	for (int i = 1; i <= H; i++) {
		if (node[i][col].first == true)
			col--;
		else if (node[i][col].second == true)
			col++;
	}
	if (col == n)
		return true;
	else
		return false;
}

//1행의 모든 점들에서 출발해서 모두 출발점과 같은 열에 있는지 확인
bool solve() {
	for (int i = 1; i <= N; i++) {
		if (move(i) == false)
			return false;
	}
	return true;
}


int main() {

	cin >> N >> M >> H;
	int a, b;
	bool check = false;
	vector<pair<int, int>>list;//아직 연결 안된 선 후보들(r,c), 연결되는 오른쪽 노드 표현

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		node[a][b].second = true;
		node[a][b+1].first = true;
	}

	for (int r = 1; r <= H; r++) {
		for (int c = 2; c <= N; c++) {
			if (node[r][c-1].first == false && node[r][c].second == false && node[r][c - 1].second == false && node[r][c].first == false)
				list.push_back({ r,c });
		}
	}

	if (solve() == true)
		cout << 0;
	else {
		//가로선을 한개 연결했을 때 되는지 확인
		for (int i = 0; i < list.size(); i++) {
			node[list[i].first][list[i].second].first = true;
			node[list[i].first][list[i].second - 1].second = true;
			if (solve() == true) {
				cout << 1;
				return 0;
			}
			node[list[i].first][list[i].second].first = false;
			node[list[i].first][list[i].second - 1].second = false;
		}
		//가로선 두개 연결했을 때 되는지 확인
		for (int i = 0; i < list.size(); i++) {
			for (int j = i + 1; j < list.size(); j++) {
				if (list[i].first == list[j].first && list[i].second + 1 == list[j].second) continue;//추가하는 두가로선이 연속된다면 pass
				node[list[i].first][list[i].second].first = true;
				node[list[i].first][list[i].second - 1].second = true;
				node[list[j].first][list[j].second].first = true;
				node[list[j].first][list[j].second - 1].second = true;
				if (solve() == true) {
					cout << 2;
					return 0;
				}
				node[list[i].first][list[i].second].first = false;
				node[list[i].first][list[i].second - 1].second = false;
				node[list[j].first][list[j].second].first = false;
				node[list[j].first][list[j].second - 1].second = false;
			}
		}
		for (int i = 0; i < list.size(); i++) {
			for (int j = i + 1; j < list.size(); j++) {
				for (int k = j + 1; k < list.size(); k++) {
					if ((list[i].first == list[j].first && list[i].second + 1 == list[j].second) || (list[j].first == list[k].first && list[j].second + 1 == list[k].second))continue;//추가하는 세가로선중 어떤 두선이라도 연속된다면 pass
					node[list[i].first][list[i].second].first = true;
					node[list[i].first][list[i].second - 1].second = true;
					node[list[j].first][list[j].second].first = true;
					node[list[j].first][list[j].second - 1].second = true;
					node[list[k].first][list[k].second].first = true;
					node[list[k].first][list[k].second - 1].second = true;
					if (solve() == true) {
						cout << 3;
						return 0;
					}
					node[list[i].first][list[i].second].first = false;
					node[list[i].first][list[i].second - 1].second = false;
					node[list[j].first][list[j].second].first = false;
					node[list[j].first][list[j].second - 1].second = false;
					node[list[k].first][list[k].second].first = false;
					node[list[k].first][list[k].second - 1].second = false;
				}
			}
		}
		cout << -1;
	}

	return 0;
}