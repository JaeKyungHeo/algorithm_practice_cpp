#include <iostream>
#include <stdlib.h>

using namespace std;

int gcd(int a, int b) {// 최대공약수 구하기(재귀, 유클리드 호제법)
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	while (N--) {
		string num, s1 = "0", s2 = "0";
		char n1[11], n2[11];
		cin >> num;
		int start = 0, end = 0;
		bool c = false;
		for (int i = 2; i < num.size(); i++) {
			if (num[i] == '(') {
				start = i;
				c = true;
			}
			else if (num[i] == ')')
				end = i;
			else
				s1 += num[i];
			if (c == false)
				s2 += num[i];
		}
		if (start != 0) {
			for (int i = 0; i < s1.size(); i++)
				n1[i] = s1[i];
			for (int i = 0; i < s2.size(); i++)
				n2[i] = s2[i];
			string temp = "";
			for (int i = 0; i < end - start - 1; i++)
				temp += '9';
			for (int i = 0; i < start - 2; i++)
				temp += '0';
			char temp1[11];
			for (int i = 0; i < temp.size(); i++)
				temp1[i] = temp[i];

			int m = atoi(temp1);

			int s = atoi(n1);
			int e = atoi(n2);

			int j = s - e;

			int p = gcd(j, m);

			cout << j / p << '/' << m / p << '\n';
		}
		else{
			int q = 1;
			for (int i = 0; i < num.size() - 2; i++)
				q *= 10;
			char t[11];
			for (int i = 2; i < num.size(); i++)
				t[i-2] = num[i];
			int a = atoi(t);

			int w = gcd(a, q);

			cout << a / w << '/' << q / w << '\n';

		}
	}

	return 0;
}