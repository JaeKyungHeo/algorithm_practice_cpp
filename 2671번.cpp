#include <iostream>
#include <vector>

using namespace std;

//조건
//(100~1~|01)~
//-> 100~1~과 01을 임의로 섞어서 만들 수 있는 모든 스트링의 집합
//앞에서 부터 조건별로 제거해줌
//경우의수 
//1. 100~1~ + 100~1~ (접합마디가 1100으로 이어짐)
//2. 100~1~ + 01(101존재)
//3. 01 + 100~1~
//4. 01 + 01
//5. 01 끝
//6. 100~1~ 끝

void solution(string s) {
	vector<string>v;
	string t;
	int count, check;//count: 연속된 1을 셈, check: 해당 과정을 수행하는데 앞부분이 제거되었는지 확인(과정을 거치고 이전과 사이즈가 같다면 예외처리)
	bool conti1;
	while (s.size() != 0) {
		t = "";
		count = 0;
		conti1 = false;//check:1이 연속되는지 확인 & 1이 시작되었는지 확인
		if (s[0] == '0' && s[1] == '1')//제일 앞 01패턴 추출(3, 4, 5번 경우 해결)
			s.erase(0, 2);
		else if (s.size() < 4) {//01이 아닌 사이즈가 1~3인 문자열은 조건에 해당x(예외처리)
			cout << "NOISE";
			return;
		}
		else if (s.substr(0, 3) == "100") {
			t += s.substr(0, 3);
			check = s.size();
			for (int i = 3; i < s.size(); i++) {
				if (s[i] == '0' && count == 0);
				else {//s[i] = '1' 시작
					conti1 = true;
					if (count == 0)
						count++;
					else if (s[i] == '0') {//c>0
						conti1 = false;
						if (i == s.size() - 1) {
							cout << "NOISE";
							return;
						}
						else {
							if (s[i + 1] == '1') {//2번 해결
								s.erase(0, i);
								break;
							}
							else if (s[i - 2] == '1' && s[i - 1] == '1' && s[i + 1] == '0') {//1번 해결
								s.erase(0, i - 1);
								break;
							}
							else {
								cout << "NOISE";
								return;
							}
						}
					}
					else if (s[i - 1] == '1')
						count++;
				}
			}
			if (conti1 == true)//100...1..1의 형태 제거 (6번 해결)
				s.clear();

			if (s.size() == check) {//(예외처리)
				cout << "NOISE";
				return;
			}
		}
		else {
			cout << "NOISE";
			return;
		}
	}
	cout << "SUBMARINE";
}

int main() {
	string s;

	cin >> s;

	solution(s);

	return 0;
}