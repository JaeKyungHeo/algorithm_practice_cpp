#include <iostream>
#include <vector>
#include <string>

using namespace std;

//조건
//10진법 N을 B진법으로 변화
//십진법으로 표현이 불가능 하다면 A:10, B:11 ... Z:35 이와 같이 문자로 표현
//입력: N(1~10^9) B(2~36)
//출력: 10진법 N을 B진법으로 출력

int main() {
	vector<int>list;
	int N, B;

	cin >> N >> B;

	int sub = N;
	//진수 변환을 위해 나머지 추출
	while (sub / B != 0) {
		list.push_back(sub % B);
		sub = sub / B;
	}

	list.push_back(sub);

	string ans = "";

	for (int i = list.size() - 1; i >= 0; i--) {
		if (list[i] < 10)
			ans += to_string(list[i]);
		else
			ans += (char)(list[i] + 55);// 아스키코드로 문자 변환
	}

	cout << ans;

	return 0;
}