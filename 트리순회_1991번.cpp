#include <iostream>
#include <vector>

using namespace std;

struct tree
{
	char left;
	char right;
};


vector<tree>T(26);

//재귀 함수를 통한 트리 출력

void solve1(char root) {//전위 순회
	cout << root;
	if (T[root - 'A'].left == '.');
	else
		solve1(T[root - 'A'].left);
	if (T[root - 'A'].right == '.');
	else
		solve1(T[root - 'A'].right);
}

void solve2(char root) {//중위 순회
	if (T[root - 'A'].left == '.');
	else
		solve2(T[root - 'A'].left);
	cout << root;
	if (T[root - 'A'].right == '.');
	else
		solve2(T[root - 'A'].right);
}

void solve3(char root) {//후위 순회
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