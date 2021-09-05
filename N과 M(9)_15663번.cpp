#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
vector<int>v, ans;// v:수열을 받음, ans:출력하려는 수열
int arr[10001];
set<vector<int>>s;

// 문제풀이:백트랙킹기법 사용
// 15664번과 유사하지만 더 어려운 부분이 있음
// set을 활용해야 풀이가 가능함.
void solve(int L) {
	if (L == M) {
		s.insert(ans);
		return;
	}

	// 백트랙킹 진행 부분
	for (int i = 0; i < N; i++) {
		if (arr[v[i]]>0) {
			ans.push_back(v[i]);
			arr[v[i]]--;
			solve(L + 1);
			arr[v[i]]++;
			ans.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int k;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> k;
		v.push_back(k);
		arr[k]++;
	}
	//정렬을 미리해주어야 순차적 출력과 중복확인에 유리
	sort(v.begin(), v.end());

	solve(0);

	//for(int i = 0; i<N;i++)
	//위와 같은 형식으로 출력하면 출력이 많아짐에 따라 시간초과 에러가 발생함
	for (auto vector : s) {
		for (auto temp : vector)
			cout << temp << " ";
		cout << endl;
	}

	return 0;
}

//강사님풀이1
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//int n, m, a[8], answer[8];
//bool used[8];
//
//void recur(int k) {
//	if (k == m) {
//		for (int i = 0; i < m; i++) {
//			printf("%d ", answer[i]);
//		}
//		printf("\n");
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		if (used[i]) continue;
//		used[i] = true;
//		// hint...
//		answer[k] = a[i];
//		recur(k + 1);
//		used[i] = false;
//	}
//}
//
//int main() {
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
//	sort(a, a + n);
//	recur(0);
//}