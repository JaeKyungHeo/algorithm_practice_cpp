#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> city[1001];
vector<int>v[1001];
int INF = 100000001;// 전체길이가 1억까지는 가능하기 때문에 그것보다 커야함
int d[1001];
int N, M;
bool visit[1001];
int ans[1001];//경로 추적
vector<int> st;

void Dijkstra(int s, int e) {
	visit[s] = true;
	queue<pair<int, int>>q; // {index, distance}
	//인덱스 순으로 정렬해서 들어오기 때문에 큐를 사용
	for (int i = 1; i <= N; i++)
		d[i] = INF;
	q.push({ s, 0 });
	v[s].push_back(s);
	while (!q.empty()) {
		int cur = q.front().first;
		int distance = q.front().second;//그냥 큐로 구현해준다.
		q.pop();
		if (d[cur] < distance)continue;
		for (int i = 0; i < city[cur].size(); i++) {
			int next = city[cur][i].first;
			int nextDistance = distance + city[cur][i].second;
			if (nextDistance < d[next]) {
				//이렇게하하면 시간초과
				//v[next].clear();
				//for (int i = 0; i < v[cur].size(); i++)
				//	v[next].push_back(v[cur][i]);
				//v[next].push_back(next);
				ans[next] = cur;
				d[next] = nextDistance;
				q.push({ next,nextDistance });
			}
		}
	}
	int temp = e;
	st.push_back(e);
	while (temp != s) {//역추적
		temp = ans[temp];
		st.push_back(temp);
	}

	cout << d[e] << '\n';
	cout << st.size() << '\n';

	for (int i = st.size() - 1; i >= 0; i--)
		cout << st[i] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int a, b, d, s, e;
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> d;
		city[a].push_back({ b,d });
		//city[b].push_back({ a,d });
	}

	cin >> s >> e;

	Dijkstra(s, e);

	return 0;
}