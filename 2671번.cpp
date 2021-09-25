#include <iostream>
#include <vector>

using namespace std;

//����
//(100~1~|01)~
//-> 100~1~�� 01�� ���Ƿ� ��� ���� �� �ִ� ��� ��Ʈ���� ����
//�տ��� ���� ���Ǻ��� ��������
//����Ǽ� 
//1. 100~1~ + 100~1~ (���ո��� 1100���� �̾���)
//2. 100~1~ + 01(101����)
//3. 01 + 100~1~
//4. 01 + 01
//5. 01 ��
//6. 100~1~ ��

void solution(string s) {
	vector<string>v;
	string t;
	int count, check;//count: ���ӵ� 1�� ��, check: �ش� ������ �����ϴµ� �պκ��� ���ŵǾ����� Ȯ��(������ ��ġ�� ������ ����� ���ٸ� ����ó��)
	bool conti1;
	while (s.size() != 0) {
		t = "";
		count = 0;
		conti1 = false;//check:1�� ���ӵǴ��� Ȯ�� & 1�� ���۵Ǿ����� Ȯ��
		if (s[0] == '0' && s[1] == '1')//���� �� 01���� ����(3, 4, 5�� ��� �ذ�)
			s.erase(0, 2);
		else if (s.size() < 4) {//01�� �ƴ� ����� 1~3�� ���ڿ��� ���ǿ� �ش�x(����ó��)
			cout << "NOISE";
			return;
		}
		else if (s.substr(0, 3) == "100") {
			t += s.substr(0, 3);
			check = s.size();
			for (int i = 3; i < s.size(); i++) {
				if (s[i] == '0' && count == 0);
				else {//s[i] = '1' ����
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
							if (s[i + 1] == '1') {//2�� �ذ�
								s.erase(0, i);
								break;
							}
							else if (s[i - 2] == '1' && s[i - 1] == '1' && s[i + 1] == '0') {//1�� �ذ�
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
			if (conti1 == true)//100...1..1�� ���� ���� (6�� �ذ�)
				s.clear();

			if (s.size() == check) {//(����ó��)
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