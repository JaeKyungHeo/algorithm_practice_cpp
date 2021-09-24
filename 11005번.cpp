#include <iostream>
#include <vector>
#include <string>

using namespace std;

//����
//10���� N�� B�������� ��ȭ
//���������� ǥ���� �Ұ��� �ϴٸ� A:10, B:11 ... Z:35 �̿� ���� ���ڷ� ǥ��
//�Է�: N(1~10^9) B(2~36)
//���: 10���� N�� B�������� ���

int main() {
	vector<int>list;
	int N, B;

	cin >> N >> B;

	int sub = N;
	//���� ��ȯ�� ���� ������ ����
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
			ans += (char)(list[i] + 55);// �ƽ�Ű�ڵ�� ���� ��ȯ
	}

	cout << ans;

	return 0;
}