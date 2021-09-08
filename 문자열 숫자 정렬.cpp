#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num(char k) {
	if (k == '0') return 0;
	if (k == '1') return 1;
	if (k == '2') return 2;
	if (k == '3') return 3;
	if (k == '4') return 4;
	if (k == '5') return 5;
	if (k == '6') return 6;
	if (k == '7') return 7;
	if (k == '8') return 8;
	if (k == '9') return 9;
	else
		return 0;
}

bool compare(pair<int, string> a, pair<int, string> b) {
	if (a.second.size() == b.second.size()){
		if (a.first == b.first)
			return a.second < b.second;// 문자열은 사전식으로 직접 비교가능!!!
		else
			return a.first < b.first;
	}
	else
		return a.second.size() < b.second.size();
}

int main() {
	vector<pair<int, string>>v;
	string k;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> k;
		int sum = 0;
		for (int i = 0; i < k.size(); i++)
			sum += num(k[i]);
		v.push_back(make_pair(sum, k));
	}

	sort(v.begin(), v.end(), compare);

	string st = "";
	for (auto elem : v)
		cout << elem.second << '\n';

	return 0;
}