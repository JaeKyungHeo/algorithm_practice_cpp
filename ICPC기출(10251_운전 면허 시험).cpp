//#include <iostream>
//#include <vector>
//
//using namespace std;
//
////조건
////M행, N열 격자 그리드에서 운전 면허 시험을 치룸
////규칙 3가지
////1. s(0,0)지점에서 t(N-1, M-1)지점까지 도착(왼 위에서 오른 아래 == 왼 아래 오른 위)
////2. 시작점에서는 방향을 골라 출발가능(시간 사용x)
////3. 차를 아래로 모는 시간과 오른쪽으로 모는 시간은 격자 한 칸당 L로 동일
////4. 방향을 바꾸는 데 걸리는 시간은 항상 1
////5. 시험 시작 전 G만큼의 연료 주입(G이하의 연료를 사용여 t에 도착해야함)
////6. 각각의 그리드 면에는 소모되는 연료량이 주어져 있음
////7. 방향을 바꿀 때 연료는 사용되지 않음
//
////입력:그리드의 상태와 G,L
////M N L G (행 수, 열 수, 한 격자를 직선 주행 시 걸리는 시간, 연료량)
////M줄에 N-1개의 가로 경로 사용 연료량, M-1줄에 N개의 세로 경로 사용 연료량 
////출력:가장 빠르게 목적지 t에 도달하는 시간
//
////풀이
////정해진 연료량을 사용하여 안에 도착한 경로중 시간이 가장 적게 걸리는 경우 출력
//
//int Length[101][101];//세로 이동 연료량
//int Width[101][101];//가로 이동 연료량
//#define INF 1000000000;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	int T;//테스트 케이스 수
//	
//	cin >> T;
//
//	while (T--) {
//		vector<pair<pair<int, int>, char>> dp[101][101];//동적계획법 사용 각각의 값은 <<누적 시간, 누적 연료>, 이전 이동방향>
//		int M, N, L, G;//M:행 수(2-100), N:열 수(2-100), L:주행하는데 걸리는 시간(1-10), G:연료량(1-1,000,000)
//		cin >> M >> N >> L >> G;
//
//		//가로 이동 시 연료량
//		for (int i = 0; i < M; i++) {
//			for (int j = 1; j < N; j++) {
//				cin >> Width[i][j];
//			}
//		}
//
//		//세로 이동 시 연료량
//		for (int i = 1; i < M; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> Length[i][j];
//			}
//		}
//
//		for (int i = 1; i < N; i++)
//			dp[0][i].push_back({ { i * L, dp[0][i - 1][0].first.second + Width[0][i] }, 'w'});
//
//		for (int i = 1; i < N; i++)
//			dp[i][0].push_back({ { i * L, dp[i - 1][0][0].first.second + Length[i][0] },'l' });
//
//		for (int i = 1; i < M; i++) {
//			for (int j = 1; j < N; j++) {
//				int f = INF;
//				int s = INF;
//				for (int k = 0; k < dp[i - 1][j].size(); k++) {//위로 이동
//					if (dp[i - 1][j][k].first.second + Length[i][j] <= G) {//연료량 확인
//						if (dp[i - 1][j][k].second == 'w') {//방향 변경
//							if (f <= dp[i - 1][j][k].first.first + L + 1 && s <= dp[i - 1][j][k].first.second + Length[i][j]);
//							else {
//								f = dp[i - 1][j][k].first.first + L + 1;
//								s = dp[i - 1][j][k].first.second + Length[i][j];
//								dp[i][j].push_back({ { dp[i - 1][j][k].first.first + L + 1, dp[i - 1][j][k].first.second + Length[i][j]}, 'l' });
//							}
//						}
//						else {//동일 방향 이동
//							if (f <= dp[i - 1][j][k].first.first + L && s <= dp[i - 1][j][k].first.second + Length[i][j]);
//							else {
//								f = dp[i - 1][j][k].first.first + L;
//								s = dp[i - 1][j][k].first.second + Length[i][j];
//								dp[i][j].push_back({ { dp[i - 1][j][k].first.first + L, dp[i - 1][j][k].first.second + Length[i][j]}, 'l' });
//							}
//						}
//					}
//				}
//
//				for (int k = 0; k < dp[i][j - 1].size(); k++) {//오른쪽 이동
//					if (dp[i][j - 1][k].first.second + Width[i][j] <= G) {//연료량 확인
//						if (dp[i][j - 1][k].second == 'l') {//방향 변경
//							if (f <= dp[i][j - 1][k].first.first + L + 1 && s <= dp[i][j - 1][k].first.second + Width[i][j]);
//							else {
//								f = dp[i][j - 1][k].first.first + L + 1;
//								s = dp[i][j - 1][k].first.second + Width[i][j];
//								dp[i][j].push_back({ { dp[i][j - 1][k].first.first + L + 1, dp[i][j - 1][k].first.second + Width[i][j]}, 'w' });
//							}
//						}
//						else {//동일 방향 이동
//							if (f <= dp[i][j - 1][k].first.first + L && s <= dp[i][j - 1][k].first.second + Width[i][j]);
//							else {
//								f = dp[i][j - 1][k].first.first + L ;
//								s = dp[i][j - 1][k].first.second + Width[i][j];
//								dp[i][j].push_back({ { dp[i][j - 1][k].first.first + L , dp[i][j - 1][k].first.second + Width[i][j]}, 'w' });
//							}
//						}
//					}
//				}
//				//메모리 초과를 방지하기 위함(사용된 벡터를 비워줍니다.)
//				dp[i - 1][j].erase(dp[i - 1][j].begin(), dp[i - 1][j].end());
//			}
//		}
//
//		if (dp[M - 1][N - 1].size() == 0)
//			cout << -1 << '\n';
//		else {
//			int min = INF;//가장 빨리 도착하는 경우
//			for (int i = 0; i < dp[M - 1][N - 1].size(); i++) {
//				if (min > dp[M - 1][N - 1][i].first.first)
//					min = dp[M - 1][N - 1][i].first.first;
//			}
//			cout << min << '\n';
//		}
//	}
//
//	return 0;
//}

//위에 문제는 메모리 초과 발생


#include <iostream>

using namespace std;

//조건
//M행, N열 격자 그리드에서 운전 면허 시험을 치룸
//규칙 3가지
//1. s(0,0)지점에서 t(N-1, M-1)지점까지 도착(왼 위에서 오른 아래 == 왼 아래 오른 위)
//2. 시작점에서는 방향을 골라 출발가능(시간 사용x)
//3. 차를 아래로 모는 시간과 오른쪽으로 모는 시간은 격자 한 칸당 L로 동일
//4. 방향을 바꾸는 데 걸리는 시간은 항상 1
//5. 시험 시작 전 G만큼의 연료 주입(G이하의 연료를 사용여 t에 도착해야함)
//6. 각각의 그리드 면에는 소모되는 연료량이 주어져 있음
//7. 방향을 바꿀 때 연료는 사용되지 않음

//입력:그리드의 상태와 G,L
//M N L G (행 수, 열 수, 한 격자를 직선 주행 시 걸리는 시간, 연료량)
//M줄에 N-1개의 가로 경로 사용 연료량, M-1줄에 N개의 세로 경로 사용 연료량 
//출력:가장 빠르게 목적지 t에 도달하는 시간

//풀이
//정해진 연료량을 사용하여 안에 도착한 경로중 시간이 가장 적게 걸리는 경우 출력

int Length[101][101];//세로 이동 연료량
int Width[101][101];//가로 이동 연료량
int dp[101][101][200][2];//동적계획법 사용 각각의 값은 y축 위치, x축 위치, 방향 전환수,이전 방향(0-가로,1-세로) = 누적 연료량

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int INF = 2000000000;

	int T;//테스트 케이스 수
	
	cin >> T;

	while (T--) {
		int M, N, L, G;//M:행 수(2-100), N:열 수(2-100), L:주행하는데 걸리는 시간(1-10), G:연료량(1-1,000,000)
		cin >> M >> N >> L >> G;

		//오른쪽 이동 시 연료량
		for (int i = 0; i < M; i++) {
			for (int j = 1; j < N; j++) {
				cin >> Width[i][j];
			}
		}

		//위로 이동 시 연료량
		for (int i = 1; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Length[i][j];
			}
		}

		//dp배열 초기화(INF)
		for (int y = 0; y < 101; y++) {
			for (int x = 0; x < 101; x++) {
				for (int t = 0; t < 200; t++) {
					for (int d = 0; d < 2; d++)
						dp[y][x][t][d] = INF;
				}
			}
		}

		//시작점
		dp[0][0][0][0] = 0;
		dp[0][0][0][1] = 0;

		//바깥라인을 먼저 처리해줍니다.
		for (int i = 1; i < 101; i++) {
			dp[0][i][0][0] = dp[0][i - 1][0][0] + Width[0][i];
			dp[i][0][0][1] = dp[i - 1][0][0][1] + Length[i][0];
		}

		//이후 안쪽 라인 진행 현재 (x,y)기준으로 전 상황을 분석함.
		for (int y = 1; y < M; y++) {
			for (int x = 1; x < N; x++) {
				for (int t = 0; t <= 200; t++) {
					dp[y][x][t][0] = dp[y][x - 1][t][0] < dp[y][x - 1][t - 1][1] ? dp[y][x - 1][t][0] + Width[y][x] : dp[y][x - 1][t - 1][1] + Width[y][x];
					dp[y][x][t][1] = dp[y - 1][x][t - 1][0] < dp[y - 1][x][t][1] ? dp[y - 1][x][t - 1][0] + Length[y][x] : dp[y - 1][x][t][1] + Length[y][x];
				}
			}
		}


		int min = 201;

		for (int t = 1; t < 200; t++) {
			if (dp[M - 1][N - 1][t][0] <= G || dp[M - 1][N - 1][t][1] <= G)
				min = min > t ? t : min;
		}

		if (min == 201)
			cout << -1 << '\n';
		else
			cout << (M + N - 2) * L + min << '\n';
	}

	return 0;
}
