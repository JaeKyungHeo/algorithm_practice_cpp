#include <iostream>
#include <vector>

using namespace std;

//����
//N:���μ� ��, H:���μ� �ĺ�, M:���μ� ����(�̸� ������ ��)
//������ ���� ������ �־����� �� 
//���μ��� �߰��ؼ�, ��ٸ� ��� i����ؼ� i�� ���� ����� �����
//�׷����ϱ� ���� �߰��ؾ��� �ּ� ���μ� ��
//�Է�
//N(2~10), M(0~(N-1)xH), H(1~30)
//���μ��� ������ a b�� ��Ÿ����(b���� b+1�� ���μ��� a�� ���� ��ġ���� ����)
//���: ���μ� ������ �ּڰ��� ���, �� ���� 3�ʰ���� -1��� �Ұ����� ��쿡�� -1���
//(1,1)~(N,H)���� 
//���������� ���η� ����� ���� ����.

//����Ǯ��: ����Ǿ� ���� ���� ������ �����ϰ� �̵��� ���� -> �̷��� ����� ��Ʈ��ŷ�� ����Ͽ� ����Ž�� ����

pair<bool,bool> node[32][12];// ���� ��ġ���� ���� �Ǵ� ���������� �̵��������� �Ǵ�
//true: �̵�����, false: �̵��Ұ�
int N, M, H;

//���� ���� �ѿ��� �������� ��� ���� �Ʒ����� ��������
bool move(int n) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int col = n;
	for (int i = 1; i <= H; i++) {
		if (node[i][col].first == true)
			col--;
		else if (node[i][col].second == true)
			col++;
	}
	if (col == n)
		return true;
	else
		return false;
}

//1���� ��� ���鿡�� ����ؼ� ��� ������� ���� ���� �ִ��� Ȯ��
bool solve() {
	for (int i = 1; i <= N; i++) {
		if (move(i) == false)
			return false;
	}
	return true;
}


int main() {

	cin >> N >> M >> H;
	int a, b;
	bool check = false;
	vector<pair<int, int>>list;//���� ���� �ȵ� �� �ĺ���(r,c), ����Ǵ� ������ ��� ǥ��

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		node[a][b].second = true;
		node[a][b+1].first = true;
	}

	for (int r = 1; r <= H; r++) {
		for (int c = 2; c <= N; c++) {
			if (node[r][c-1].first == false && node[r][c].second == false && node[r][c - 1].second == false && node[r][c].first == false)
				list.push_back({ r,c });
		}
	}

	if (solve() == true)
		cout << 0;
	else {
		//���μ��� �Ѱ� �������� �� �Ǵ��� Ȯ��
		for (int i = 0; i < list.size(); i++) {
			node[list[i].first][list[i].second].first = true;
			node[list[i].first][list[i].second - 1].second = true;
			if (solve() == true) {
				cout << 1;
				return 0;
			}
			node[list[i].first][list[i].second].first = false;
			node[list[i].first][list[i].second - 1].second = false;
		}
		//���μ� �ΰ� �������� �� �Ǵ��� Ȯ��
		for (int i = 0; i < list.size(); i++) {
			for (int j = i + 1; j < list.size(); j++) {
				if (list[i].first == list[j].first && list[i].second + 1 == list[j].second) continue;//�߰��ϴ� �ΰ��μ��� ���ӵȴٸ� pass
				node[list[i].first][list[i].second].first = true;
				node[list[i].first][list[i].second - 1].second = true;
				node[list[j].first][list[j].second].first = true;
				node[list[j].first][list[j].second - 1].second = true;
				if (solve() == true) {
					cout << 2;
					return 0;
				}
				node[list[i].first][list[i].second].first = false;
				node[list[i].first][list[i].second - 1].second = false;
				node[list[j].first][list[j].second].first = false;
				node[list[j].first][list[j].second - 1].second = false;
			}
		}
		for (int i = 0; i < list.size(); i++) {
			for (int j = i + 1; j < list.size(); j++) {
				for (int k = j + 1; k < list.size(); k++) {
					if ((list[i].first == list[j].first && list[i].second + 1 == list[j].second) || (list[j].first == list[k].first && list[j].second + 1 == list[k].second))continue;//�߰��ϴ� �����μ��� � �μ��̶� ���ӵȴٸ� pass
					node[list[i].first][list[i].second].first = true;
					node[list[i].first][list[i].second - 1].second = true;
					node[list[j].first][list[j].second].first = true;
					node[list[j].first][list[j].second - 1].second = true;
					node[list[k].first][list[k].second].first = true;
					node[list[k].first][list[k].second - 1].second = true;
					if (solve() == true) {
						cout << 3;
						return 0;
					}
					node[list[i].first][list[i].second].first = false;
					node[list[i].first][list[i].second - 1].second = false;
					node[list[j].first][list[j].second].first = false;
					node[list[j].first][list[j].second - 1].second = false;
					node[list[k].first][list[k].second].first = false;
					node[list[k].first][list[k].second - 1].second = false;
				}
			}
		}
		cout << -1;
	}

	return 0;
}