#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
//좋은 문제 : 여러가지 알고리즘 혼합
int land[11][11];
int N, M;
vector<vector<pair<int, int>>>v;//0,1,2,3,4,5 (x,y) - 각각의 섬 위치 표시
int idx[4] = { 0,0,-1,1 };
int idy[4] = { -1,1,0,0 };

struct edge
{
	int index1;
	int index2;
	int distance;
};

vector<edge>island;

bool compare(edge a, edge b) {
	return a.distance < b.distance;
}

bool bfs(int x, int y, int index) {
	if (land[y][x] != 1) return false;
	queue<pair<int,int>>q;
	vector<pair<int, int>>temp;
	bool check = false;
	q.push({ x,y });
	temp.push_back({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		land[y][x] = index;
		check = true;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + idx[i];
			int ny = y + idy[i];
			if ((nx >= 0 && nx < M && ny >= 0 && ny < N) && land[ny][nx] == 1) {
				q.push({ nx,ny });
				temp.push_back({ nx,ny });
			}
		}

	}
	v.push_back(temp);
	return check;
}

int parent[8];

int find(int id) {
	if (parent[id] == id) return id;
	return parent[id] = find(parent[id]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool isCycle(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return true;
	else
		return false;
}

void distance(int now, int x, int y) {
	int move = 1;
	bool e = false, w = false, s = false, n = false;
	while (true) {
		if (n == false && y + move < N && land[y + move][x] == now) {
			n = true;
		}
		else if (n == false && y + move < N && land[y + move][x] != now && land[y + move][x] != 0) {
			if (move <= 2)
				n = true;
			else {
				island.push_back({ now, land[y + move][x], move - 1 });
				n = true;
			}
		}
		if (s == false && y - move < N && land[y - move][x] == now) {
			s = true;
		}
		else if (s == false && y - move >= 0 && land[y - move][x] != now && land[y - move][x] != 0) {
			if (move <= 2)
				s = true;
			else {
				island.push_back({ now, land[y - move][x], move - 1 });
				s = true;
			}
		}
		if (e == false && x + move < M && land[y][x + move] == now) {
			e = true;
		}
		else if (e == false && x + move < M && land[y][x + move] != now && land[y][x + move] != 0) {
			if (move <= 2)
				e = true;
			else {
				island.push_back({ now, land[y][x + move], move - 1 });
				e = true;
			}
		}
		if (w == false && x - move >= 0 && land[y][x - move] == now) {
			w = true;
		}
		else if (w == false && x - move >= 0 && land[y][x - move] != now && land[y][x - move] != 0) {
			if (move <= 2)
				w = true;
			else {
				island.push_back({ now, land[y][x - move], move - 1 });
				w = true;
			}
		}
		move++;
		if (move > 10)
			break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> land[i][j];
		}
	}

	int id = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (bfs(j, i, id) == true) {
				id++;
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {//2,3,4... v.size : 섬의 갯수
		for (int j = 0; j < v[i].size(); j++) {
			int x = v[i][j].first;
			int y = v[i][j].second;
			distance(i + 2, x, y);
		}
	}

	for(int i = 0; i < v.size() + 2; i++)
		parent[i] = i;

	sort(island.begin(), island.end(), compare);

	int ans = 0;

	for (int i = 0; i < island.size(); i++) {
		if (isCycle(island[i].index1, island[i].index2) == false) {
			ans += island[i].distance;
			uni(island[i].index1, island[i].index2);
		}
	}

	bool c = false;
	for (int i = 3; i < v.size() + 2; i++) {
		if (isCycle(i, i - 1) == false)//사이클 생성여부에 따라 모두 연결된 그래프인지 판단가능
			c = true;
	}

	if (c == true)
		cout << -1;
	else
		cout << ans;

	return 0;
}