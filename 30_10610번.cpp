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

	sort(v.begin(), v.end());// 오름차순으로 정렬
	
	//30으로 나눠지는 수의 조건은 1의 자리가 0이면서 모든 자리수를 더한 값이 3으로 나눠져야한다.
	if (v[0] != '0' || total % 3 != 0) {// '-1'출력조건 : 30으로 나눠지지 않는 수
		cout << -1;
	}
	else {
		for (int i = v.size()-1; i>=0; i--)
			ans += v[i];//뒤로 추가됨
		cout << ans;
	}
}

int main() {

	string N;
	cin >> N;
	
	solve(N);

	return 0;
}

//강사님풀이
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