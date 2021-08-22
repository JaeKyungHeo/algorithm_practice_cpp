#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool compare(pair<int, int> a, pair<int, int>b) {
	if (a.first == b.first) return a.second < b.second;
	else
		return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie();
	cin.tie();

	int N, S, T, answer = 0;
	vector<pair<int, int>>v;
	priority_queue<int>pq;

	cin >> N;

	int s = 100000001, e = 0;

	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		if (s > S)
			s = S;
		if (T > e)
			e = T;
		v.push_back({ S,T });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		pq.push(-v[i].second);
		int temp = -pq.top();
		if (temp <= v[i].first) {
			pq.pop();
			while(!pq.empty()) {
				if (temp == -pq.top())
					pq.pop();
				else
					break;
			}
		}
		if (pq.size() > answer)
			answer = pq.size();
	}

	cout << answer;

	return 0;
}