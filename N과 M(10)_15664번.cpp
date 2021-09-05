#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int>v, ans;// v:수열을 받음, ans:출력하려는 수열
vector<vector<int>>check;// 이미 출력된 답 중복방지 비교

// 문제풀이:백트랙킹기법 사용
void solve(int id, int L) {
	if (L == M) {
		bool c1 = false;// 이전까지 출력된 답들과 중복되는 것이 있는지 false라면 아직 중복되는 것이 없음
		for (int i = 0; i < check.size(); i++) {
			bool c2 = false;// 부분적으로 지금까지 중복되는 것이 있는지 확인
			for (int j = 0; j < M; j++) {
				if (ans[j] != check[i][j]) {
					c2 = true;
					break;
				}
			}
			if (c2 == false) {// c2가 false라면 중복되는 답이 이미 나옴
				c1 = true;
				break;
			}
		}
		if (c1 == false) {// 아직 출력이 안된 답이라면 출력
			check.push_back(ans);
			for (int i = 0; i < M; i++) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	if (id >= N)return;// 확인할 인덱스가 전체 인덱스 범위를 넘겼다면 예외처리

	// 백트랙킹 진행 부분
	ans.push_back(v[id]);
	solve(id + 1, L + 1);
	ans.pop_back();
	solve(id + 1, L);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int k;
	vector<int>temp;// 최초 정렬하여 나오는 연속된 0 - M - 1까지는 바로 출력위해 받기용
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> k;
		v.push_back(k);
	}
	//정렬을 미리해주어야 순차적 출력과 중복확인에 유리
	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		cout << v[i] << " ";
		temp.push_back(v[i]);
	}
	//최초 출력된 답목록(check)에 넣어줌
	cout << endl;
	check.push_back(temp);

	solve(0, 0);

	return 0;
}