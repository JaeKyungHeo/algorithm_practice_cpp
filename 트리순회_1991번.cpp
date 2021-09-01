#include <iostream>
#include <vector>

using namespace std;

struct tree
{
	char left;
	char right;
};


vector<tree>T(26);

//��� �Լ��� ���� Ʈ�� ���

void solve1(char root) {//���� ��ȸ
	cout << root;
	if (T[root - 'A'].left == '.');
	else
		solve1(T[root - 'A'].left);
	if (T[root - 'A'].right == '.');
	else
		solve1(T[root - 'A'].right);
}

void solve2(char root) {//���� ��ȸ
	if (T[root - 'A'].left == '.');
	else
		solve2(T[root - 'A'].left);
	cout << root;
	if (T[root - 'A'].right == '.');
	else
		solve2(T[root - 'A'].right);
}

void solve3(char root) {//���� ��ȸ
	if (T[root - 'A'].left == '.');
	else
		solve3(T[root - 'A'].left);
	if (T[root - 'A'].right == '.');
	else
		solve3(T[root - 'A'].right);
	cout << root;
}

int main() {
	int N;
	char root, L, R;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> root >> L >> R;
		T[root - 'A'] = { L,R };
	}
	
	solve1('A');
	cout << endl;
	solve2('A');
	cout << endl;
	solve3('A');

	return 0;
}