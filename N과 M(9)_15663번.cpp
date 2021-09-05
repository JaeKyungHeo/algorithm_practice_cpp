#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
vector<int>v, ans;// v:������ ����, ans:����Ϸ��� ����
int arr[10001];
set<vector<int>>s;

// ����Ǯ��:��Ʈ��ŷ��� ���
// 15664���� ���������� �� ����� �κ��� ����
// set�� Ȱ���ؾ� Ǯ�̰� ������.
void solve(int L) {
	if (L == M) {
		s.insert(ans);
		return;
	}

	// ��Ʈ��ŷ ���� �κ�
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
	//������ �̸����־�� ������ ��°� �ߺ�Ȯ�ο� ����
	sort(v.begin(), v.end());

	solve(0);

	//for(int i = 0; i<N;i++)
	//���� ���� �������� ����ϸ� ����� �������� ���� �ð��ʰ� ������ �߻���
	for (auto vector : s) {
		for (auto temp : vector)
			cout << temp << " ";
		cout << endl;
	}

	return 0;
}

//�����Ǯ��1
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