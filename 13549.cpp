#include <iostream>
#include <queue>

using namespace std;

bool check[150001];
int time[150001];

void bfs(int start,int end) {
	queue<int>q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == end) {
			cout << time[x];
			return;
		}

		if (2 * x < 150001 && (!check[2 * x] || time[2 * x] > time[x])) {
			check[2 * x] = true;
			time[2 * x] = time[x];
			q.push(2 * x);
		}
		if (x < 150001 && (!check[x + 1] || time[x + 1] > time[x] + 1)) {
			check[x + 1] = true;
			time[x + 1] = time[x] + 1;
			q.push(x + 1);
		}
		if (x - 1 >= 0 && (!check[x - 1] || time[x - 1] > time[x] + 1)) {
			check[x - 1] = true;
			time[x - 1] = time[x] + 1;
			q.push(x - 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, d;

	cin >> s >> d;

	bfs(s, d);

	return 0;
}