#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//����
//N(��) x M(��) ���簢�� ���� 
//0:��ĭ, 1:��, 2:���̷���
//���̷����� �����¿�� ��������
//���� �� 3���� ���� �� ����
//�Է�:N M (2~8)
//��ĭ, ��, ���̷����� ��ġ
//���:���� �� �ִ� ���� ������ �ִ� ũ��

int N, M;
int map[9][9];
int submap[9][9];//���� ī�ǿ�
queue<pair<int, int>>q;
vector<pair<int, int>>subq;//���� ī�ǿ�
int idx[4] = { 0,0,-1,1 };
int idy[4] = { 1,-1,0,0 };

//�ε��� ��ȿ �� Ȯ��
bool valid(int y, int x) { return y >= 0 && y < N&& x >= 0 && x < M; }

//�� 3�� �����
void wall(pair<int,int>w1, pair<int, int>w2, pair<int, int>w3) {
	map[w1.first][w1.second] = 1;
	map[w2.first][w2.second] = 1;
	map[w3.first][w3.second] = 1;
}

//���̷����� ��������(BFS)
void virusSpread() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + idy[i];
			int nx = x + idx[i];

			if (valid(ny, nx) && map[ny][nx] == 0) {
				map[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}
}

//���� ������ ���·� ������
void copymap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = submap[i][j];
		}
	}
}

//���� ������ ���·� ������
void copyvirus() {
	for (int i = 0; i < subq.size(); i++)
		q.push(subq[i]);
}

//�������� �����ϴ� 0�� ��� ����(���� ����)
int count0() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				count++;
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<pair<int, int>>v;//0�� �ִ� ��ġ(���� ���� �� �ִ� ��)
	int max = 0, ans;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			submap[i][j] = map[i][j];
			if (map[i][j] == 2) {
				q.push({ i,j });
				subq.push_back({ i,j });
			}
			else if (map[i][j] == 0)
				v.push_back({ i,j });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				//���̽� ���� ��Ʈ��ŷ������ ����
				wall(v[i], v[j], v[k]);//�� 3�� ��ġ
				virusSpread();//���̷��� ����;
				int temp = count0();//���̷��� ���� �� �������� count
				if (temp > max)
					max = temp;
				copymap();//���� ����
				copyvirus();//���̷����� ����ִ� ť ����
			}
		}
	}

	ans = max;
	cout << ans;

	return 0;
}