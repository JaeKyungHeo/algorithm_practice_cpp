#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size())
		return a < b;// ���ڿ��� ���������� ���� �񱳰���!!!
	else
		return a.size() < b.size();
}

int main() {
	vector<string>v;
	string k;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> k;
		v.push_back(k);
	}

	sort(v.begin(), v.end(), compare);

	string st = "";
	for (auto elem : v) {
		if (st != elem)
			cout << elem << '\n';
		st = elem;
	}

	return 0;
}