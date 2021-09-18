#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����
//��ȣ�� ���� ���� �� ������
//NxN ũ���� ������ M���� ĭ�� �� �� ������ �������
//1�ʸ��� ���� ������ �����¿� ĭ���� �̵���
//�̵��� ĭ�� ������ �Ѹ�(k�� �̵��ϸ� ������ �����)
//�̵��� ĭ�� �켱���� �ƹ� ������ ���� ĭ > �ڽ��� ������ �ִ� ĭ(������ ��� ĭ�� ��ĭ�̶� �켱���� ����))
//�ڽ��� ���� ĭ�� ��������� ���� �ο��Ǿ� �ִ� �켱������ ���� �̵�
//�� �����ִ� ���⿡ ���󼭵� �켱������ �ٸ�
//�̵� �� ���� �̵��� ������ ����
//���� ĭ�� ���� �� �����ϰ� �Ǹ� ���� ���� ��ȣ�� ���� �� �����ϰ� ������ ���� �����
//�Է�: N(2~20) M(2~N^2) k(1~1000)
//���: 1�� �� ���� �Ǳ���� �ɸ��� �ð� / 1000�ʰ� �Ѿ ������ �ʾҴٸ� -1 ���
//�� ��Ȳ�������� �� �̵��� ������ �����

struct state {
	int num_shark;//������ ���� ����ȣ
	int K;//������ ���� ��
	int exist_shark;//�� ������ �����ϴ��� ����� ��ȣ ���ٸ� 0
};

state board[22][22];//(1,1)~(N,N)
vector<pair<pair<int, int>, pair<int,int>>>list;//����� ��ǥ�� ����� ��ȣ, ���⸦ ����<y,x,n,d>
//�� ���͸� ���� �� �켱 �̵���Ű�� �ش� ���� ������ ��������
vector<vector<vector<int>>>pr(401);
//���� ���� ���� ��,�Ʒ�, ����, ���������� ���
//1:��, 2:�Ʒ�, 3:����, 4:������
int N, M, k;

int direct[401];

bool compare(pair<pair<int, int>, pair<int, int>>a, pair<pair<int, int>, pair<int, int>>b) {
	return a.second.first < b.second.first;
}

bool valid(int y, int x) { return (y > 0) && (y <= N) && (x > 0) && (x <= N); }

pair<int, int> dir(int n) {
	if (n == 1) return { -1,0 };//��
	else if (n == 2)return { 1,0 };//�Ʒ�
	else if (n == 3)return { 0,-1 };//����
	else return { 0,1 };//������
}

void move(pair<pair<int, int>, pair<int, int>> s) {
	//�켱 ������ ���� ��ĭ �̵��� �����ϴٸ� �̵�
	for (int i = 0; i < 4; i++) {
		pair<int, int> temp = dir(pr[s.second.first][s.second.second - 1][i]);
		int r = s.first.first + temp.first;
		int c = s.first.second + temp.second;
		if (valid(r, c) == true && board[r][c].K == 0) {
			direct[board[s.first.first][s.first.second].num_shark] = pr[s.second.first][s.second.second - 1][i];
			board[s.first.first][s.first.second].exist_shark = 0;
			board[r][c].exist_shark = board[s.first.first][s.first.second].num_shark;
			return;
		}
	}
	//��� ������ ä���� �ִٸ� �ٽ� �ڽ��� ���� �켱���� Ž��
	for (int i = 0; i < 4; i++) {
		pair<int, int> temp = dir(pr[s.second.first][s.second.second - 1][i]);
		int r = s.first.first + temp.first;
		int c = s.first.second + temp.second;
		if (valid(r, c) == true && board[r][c].num_shark == board[s.first.first][s.first.second].num_shark) {
			direct[board[s.first.first][s.first.second].num_shark] = pr[s.second.first][s.second.second - 1][i];
			board[s.first.first][s.first.second].exist_shark = 0;
			board[r][c].exist_shark = board[s.first.first][s.first.second].num_shark;
			return;
		}
	}
}

void solution() {
	for (int i = 1; i <= 1000; i++) {
		//�� �켱 �̵���Ŵ
		for (int j = list.size() - 1; j >= 0; j--)
			move(list[j]);

		list.clear();
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (board[r][c].exist_shark > 0)
					list.push_back({ {r,c},{board[r][c].exist_shark,direct[board[r][c].exist_shark]} });
			}
		}

		sort(list.begin(), list.end(), compare);

		//�� �� ���� ���Ҵٸ� ����
		if (list.size() == 1) {
			cout << i;
			return;
		}

		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (board[r][c].exist_shark == 0 && board[r][c].K > 0) {
					board[r][c].K--;
					if (board[r][c].K == 0)
						board[r][c].num_shark = 0;
				}
				else if (board[r][c].exist_shark > 0) {
					board[r][c].K = k;
					board[r][c].num_shark = board[r][c].exist_shark;
				}
			}
		}
	}
	cout << -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> k;

	//NxNĭ�� ������ ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j].exist_shark;
			if (board[i][j].exist_shark > 0) {
				list.push_back({ {i,j}, {board[i][j].exist_shark,0} });
				board[i][j].K = k;
				board[i][j].num_shark = board[i][j].exist_shark;
			}
			else {
				board[i][j].K = 0;
				board[i][j].num_shark = 0;
			}
		}
	}

	sort(list.begin(), list.end(), compare);

	//ó�� ������ ����
	int t;
	for (int i = 0; i < list.size(); i++) {
		cin >> t;
		list[i].second.second = t;
	}

	vector<int> sub;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> t;
				sub.push_back(t);
			}
			pr[i].push_back(sub);
			sub.clear();
		}
	}

	solution();

	return 0;
}