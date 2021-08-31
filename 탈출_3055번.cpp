#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;// 이거 사용해야 자료형 라이브러리 적용가능

typedef pair<int, int>pii;	//좌표를 담을 예정임
int r, c;
char forest[51][51];

pii ddg;
vector<pii> water;
pii biber;
queue<pii> water_q, ddg_q;	//좌표를 저장하는 queue
int ans;
//	방문 배열....
int water_vt[51][51] = { 0, }, ddg_vt[51][51] = { 0, };
int dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 };// 4방향 위치얻기 위한 값

//길찾기
//	BFS 이론 -> 너비 우선 탐색 쓰이는 것 -> 갈수 o, 갈수 x
//	물의 이동 역시 생각해야함

bool check_rc(int param_r, int param_c) {//유효값 확인
	return 0 <= param_r && param_r < r && 0 <= param_c && param_c < c;
}

int main() {

	// 입력 받는 부분
	// 각자 자신만의 방법으로
	scanf("%d%d", &r, &c);//pass by ref로 가져옴
	//cin >> r >> c;
	for (int i = 0; i < r; i++) {
		scanf("%s", forest[i]);
	}

	// 할일
	// 두더지의 시작점이 어디인지 확인
	// 물 들은 어디에 있는지 확인
	// 비버의  굴
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (forest[i][j] == 'S') {
				ddg = pii(i, j);
				// 어짜피 S는 하나일테니까. 필요하면 중단하는것을 넣어도 됨 
			}
			if (forest[i][j] == '*') {
				water.push_back(pii(i, j));
			}
			if (forest[i][j] == 'D') {
				biber = pii(i, j);
			}
		}
	}

	//	할일
	//	두더지의 시작점이 어디인지 확인
	//	물들이 어디에 있는지 확인
	//	비버의 굴

	//debug
	//출력
	//printf("ddg : %d %d\n", ddg.first, ddg.second);
	
	//	탐색
		//	물 이동(물 먼저 이동시켜도 무방)
			//	주변에 한칸씩 이동
			//	물은 처음에 한개 이상임
			//	시작점이 여러 개...
		//	두더지를 이동시킴 : 주변에 한칸씩...-> BFS
			//	단, 돌멩이가 있으면 안됨
			//	다음번에  물이 찰 예정이면 안됨
			//	굴까지 이동을 끝냈으면 끝

	//물
	for (int i = 0; i < water.size(); i++) {
		pii cur_water = water[i];
		water_q.push(cur_water);
		water_vt[cur_water.first][cur_water.second] = 1;
	}

	//두더지
	ddg_q.push(ddg);
	ddg_vt[ddg.first][ddg.second] = 1;

	//물과 두더지를 탐색하면서 갈수 있는지 없는지 판단
	//두더지가 비버의 굴을 탐색하면 거리를 출력하고 끝
	//두더지가 더이상 탐색을 못하면 KAKTUS를 출력하고 끝
	while (!ddg_q.empty()) {
		//물 이동
		//q에서 하나를 꺼내고 상/하/좌/우로 이동
		//비버의 목적지는 가지말고
		//돌멩이도 가지말고
		//두더지?? 가도됨
		int water_qsz = water_q.size();
		//printf("%d\n", water_qsz);// -> 디버깅
		for (int i = 0; i < water_qsz; i++) {// 현재에 q에 있었던 만큼만 탐색을 할꺼다...
			pii cur_water = water_q.front();
			water_q.pop();
			for (int j = 0; j < 4; j++) {//싱/하/좌/우 순서대로 좌표를 얻는다
				int new_r, new_c;
				new_r = cur_water.first + dr[j];
				new_c = cur_water.second + dc[j];
				if (!check_rc(new_r, new_c))continue;
				if (forest[new_r][new_c] == 'D' || forest[new_r][new_c] == 'X' || water_vt[new_r][new_c] != 0) continue;
				water_vt[new_r][new_c] = water_vt[cur_water.first][cur_water.second] + 1;
				water_q.push(pii(new_r, new_c));

			}
		}

		//두더지 이동
		//queue에서 하나를 꺼내고 상/하/좌/우로 이동
		//물은 가지말고
		//돌멩이도 가지말고
		//목적지였으면?? 찾은것
		int ddg_qsz = ddg_q.size();
		for (int i = 0; i < ddg_qsz; i++) {
			pii cur_ddg = ddg_q.front();
			ddg_q.pop();
			for (int j = 0; j < 4; j++) {
				int new_r, new_c;
				new_r = cur_ddg.first + dr[j];
				new_c = cur_ddg.second + dc[j];
				if (!check_rc(new_r, new_c)) continue;
				if (forest[new_r][new_c] == 'X' || water_vt[new_r][new_c] != 0 || ddg_vt[new_r][new_c] != 0) continue; //두더지 역시 지나간 곳을 제외하고 진행하게 함
				if (forest[new_r][new_c] == 'D') {
					// 찾았다  
					ans = ddg_vt[cur_ddg.first][cur_ddg.second] + 1;
					ans--;
					printf("%d", ans);
					return 0;
				}
				else {
					ddg_vt[new_r][new_c] = ddg_vt[cur_ddg.first][cur_ddg.second] + 1;
					ddg_q.push(pii(new_r, new_c));
				}
			}
		}

	}
	//답을 출력

	//	고민할점
		//	두더지가 이동할 때 앞으로 물이 찰지 안찰지 어떻게 판단할지?

	printf("KAKTUS");

	return 0;
}