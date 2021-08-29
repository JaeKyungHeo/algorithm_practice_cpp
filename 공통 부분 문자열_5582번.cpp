#include <iostream>
#include <set>

using namespace std;

int main() {

	set<string>s, sub;

	string a, b;

	cin >> a;
	cin >> b;
	int max = 0;
	for (int i = 0; i < a.size(); i++) {
		string temp = "";
		for (int j = 0; j + i < a.size(); j++) {
			temp += a[j + i];
			s.insert(temp);
		}
	}

	int check = s.size();

	for (int i = 0; i < b.size(); i++) {
		string temp = "";
		for (int j = 0; j + i < b.size(); j++) {
			temp += b[j + i];
			sub = s;
			s.insert(temp);
			if (s.size() == check && max < temp.size())
				max = temp.size();
			s = sub;
		}
	}

	cout << max;

	return 0;
}