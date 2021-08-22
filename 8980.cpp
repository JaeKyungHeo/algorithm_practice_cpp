//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//struct info
//{
//	int start;
//	int end;
//	int num;
//};
//
//bool compare(info a, info b) {
//	if (a.start != b.start)
//		return a.start < b.start;
//	else if (a.end != b.end)
//		return a.end < b.end;
//	else
//		return a.num > b.num;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cout.tie(NULL); cin.tie(NULL);
//
//	int N, C, M;// N:마을 수, C:트럭의 용량, M:박스 정보의 개수
//	int s, e, c;// s:시작마을, e:도착마을, c:박스의 개수
//	int now = 0, answer = 0;
//	vector<info>v;
//	priority_queue<pair<int,int>>pq;// {start,박수 개수}
//	cin >> N >> C;
//	cin >> M;
//
//	for (int i = 0; i < M; i++) {
//		cin >> s >> e >> c;
//		v.push_back({ s,e,c });
//	}
//
//	sort(v.begin(), v.end(), compare);
//
//	for (int i = 0; i < v.size(); i++) {
//		if (pq.empty()) {
//			if (C - now > v[i].num) {
//				pq.push({ -v[i].end, v[i].num });
//				now += v[i].num;
//				answer += v[i].num;
//				cout << 1 << '\n';
//				cout << i << ' ' << v[i].num << ' ' << answer << '\n';
//			}
//			else{
//				pq.push({ -v[i].end, C - now });
//				answer += C - now;
//				cout << 2 << '\n';
//				cout << i << ' ' << C-now << ' ' << answer << '\n';
//				now += C - now;
//			}
//		}
//		else {
//			pair<int, int> temp = pq.top();
//			if (-temp.first <= v[i].start) {
//				now -= temp.second;
//				pq.pop();
//				if (!pq.empty()) {
//					while (-temp.first == -pq.top().first) {
//						temp = pq.top();
//						now -= temp.second;
//						pq.pop();
//					}
//				}
//				if (C - now > v[i].num) {
//					pq.push({ -v[i].end, v[i].num });
//					now += v[i].num;
//					answer += v[i].num;
//					cout << 3 << '\n';
//					cout << i << ' ' << v[i].num << ' ' << answer << '\n';
//				}
//				else {
//					pq.push({ -v[i].end, C - now });
//					answer += C - now;
//					cout << 4 << '\n';
//					cout << i << ' ' << C-now << ' ' << answer << '\n';
//					now += C - now;
//				}
//			}
//			else {
//				if (now < C && C - now > v[i].num) {
//					pq.push({ -v[i].end, v[i].num });
//					now += v[i].num;
//					answer += v[i].num;
//					cout << 5 << '\n';
//					cout << i << ' ' << v[i].num << ' ' << answer << '\n';
//				}
//				else if (now < C && C - now <= v[i].num) {
//					pq.push({ -v[i].end, C - now });
//					answer += C - now;
//					cout << 6 << '\n';
//					cout << i << ' ' << C-now << ' ' << answer << '\n';
//					now += C - now;
//				}
//			}
//		}
//	}
//
//	cout << answer;
//
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Truck[2001];

struct info
{
	int start;
	int end;
	int num;
};

bool compare(info a, info b) {
	if (a.end != b.end)
		return a.end < b.end;
	else if (a.start != b.start)
		return a.start > b.start;
	else
		return a.num > b.num;
}

int main() {
	int N, C, M;// N:마을 수, C:트럭의 용량, M:박스 정보의 개수
	int s, e, c;// s:시작마을, e:도착마을, c:박스의 개수
	int now = 0, answer = 0;
	vector<info>v;
	cin >> N >> C;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> s >> e >> c;
		v.push_back({ s,e,c });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		int max = 0;
		for (int j = v[i].start; j <= v[i].end; j++) {
			if (max < Truck[j])
				max = Truck[j];
		}
		if (max < C) {
			if (C - max > v[i].num) {
				for (int j = v[i].start; j < v[i].end; j++)
					Truck[j] += v[i].num;
				answer += v[i].num;
			}
			else {
				answer += C - max;
				for (int j = v[i].start; j < v[i].end; j++)
					Truck[j] += C - max;
			}
		}
	}

	cout << answer;

	return 0;
}