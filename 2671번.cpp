#include <iostream>
#include <vector>

using namespace std;

//조건
//(100~1~|01)~
//-> 100~1~과 01을 임의로 섞어서 만들 수 있는 모든 스트링의 집합

void solution(string s) {
	while (true) {
		if (s.find("01") == 0)
			s.erase(0, 2);
		else if (s.find("101") < 150) {
			s.erase(s.find("101") + 1, 2);
		}
		else
			break;
	}

	if (s.size() == 0) {
		cout << "SUBMARINE";
		return;
	}
	
	if (s[0] == '1');
	else {
		cout << "NOISE";
		return;
	}

	int count = 0;
	if (s.find("01") < 150) {
		if (s[s.find("01") - 1] == '0') {
			for (int i = s.find("01") + 1; i < s.size(); i++) {
				if (s[i] == '0') {
					cout << "NOISE";
					return;
				}
			}
			cout << "SUBMARINE";
		}
		else {
			cout << "NOISE";
			return;
		}
	}
	else {
		cout << "NOISE";
		return;
	}
}

int main() {
	string s;
	vector<int> v;
	


	cin >> s;

	solution(s);

	return 0;
}