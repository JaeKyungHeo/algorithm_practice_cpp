#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int>v, ans;// v:������ ����, ans:����Ϸ��� ����
vector<vector<int>>check;// �̹� ��µ� �� �ߺ����� ��

// ����Ǯ��:��Ʈ��ŷ��� ���
void solve(int id, int L) {
	if (L == M) {
		bool c1 = false;// �������� ��µ� ���� �ߺ��Ǵ� ���� �ִ��� false��� ���� �ߺ��Ǵ� ���� ����
		for (int i = 0; i < check.size(); i++) {
			bool c2 = false;// �κ������� ���ݱ��� �ߺ��Ǵ� ���� �ִ��� Ȯ��
			for (int j = 0; j < M; j++) {
				if (ans[j] != check[i][j]) {
					c2 = true;
					break;
				}
			}
			if (c2 == false) {// c2�� false��� �ߺ��Ǵ� ���� �̹� ����
				c1 = true;
				break;
			}
		}
		if (c1 == false) {// ���� ����� �ȵ� ���̶�� ���
			check.push_back(ans);
			for (int i = 0; i < M; i++) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	if (id >= N)return;// Ȯ���� �ε����� ��ü �ε��� ������ �Ѱ�ٸ� ����ó��

	// ��Ʈ��ŷ ���� �κ�
	ans.push_back(v[id]);
	solve(id + 1, L + 1);
	ans.pop_back();
	solve(id + 1, L);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int k;
	vector<int>temp;// ���� �����Ͽ� ������ ���ӵ� 0 - M - 1������ �ٷ� ������� �ޱ��
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> k;
		v.push_back(k);
	}
	//������ �̸����־�� ������ ��°� �ߺ�Ȯ�ο� ����
	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		cout << v[i] << " ";
		temp.push_back(v[i]);
	}
	//���� ��µ� ����(check)�� �־���
	cout << endl;
	check.push_back(temp);

	solve(0, 0);

	return 0;
}