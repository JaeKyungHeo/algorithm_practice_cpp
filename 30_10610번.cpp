#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(string n) {
	vector<char>v;
	string ans = "";
	int total = 0;
	for (int i = 0; i < n.size(); i++) {
		v.push_back(n[i]);
		total += n[i] - '0';
	}

	sort(v.begin(), v.end());// ������������ ����
	
	//30���� �������� ���� ������ 1�� �ڸ��� 0�̸鼭 ��� �ڸ����� ���� ���� 3���� ���������Ѵ�.
	if (v[0] != '0' || total % 3 != 0) {// '-1'������� : 30���� �������� �ʴ� ��
		cout << -1;
	}
	else {
		for (int i = v.size()-1; i>=0; i--)
			ans += v[i];//�ڷ� �߰���
		cout << ans;
	}
}

int main() {

	string N;
	cin >> N;
	
	solve(N);

	return 0;
}

//�����Ǯ��
//#include <cstdio>
//
//char s[100001];
//int sum, count[128];
//
//int main() {
//	scanf("%s", s);
//	for (int i = 0; s[i]; i++) {
//		sum += s[i] - '0';
//		count[s[i]]++;
//	}
//	if (sum % 3 != 0 || count['0'] == 0) {
//		printf("-1");
//		return 0;
//	}
//	for (int i = '9'; i >= '0'; i--) {
//		for (int j = 0; j < count[i]; j++) {
//			printf("%c", i);
//		}
//	}
//}