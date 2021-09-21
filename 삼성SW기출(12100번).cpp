#include <iostream>
#include <vector>

using namespace std;

//����
//��ȣ�� �����ִ� ��� �̵���Ű��
//�̵��ϴ� ���� �� �տ� �ִ� �ͺ��� ó������
//NxN���������(1~20)
//���� �������� �̵����� �� �ش�������� �����������鼭 ���� ���� ������ �־�� ������
//�Է�: N(1~20) ���� �� ĭ�� ��(0�� ��ĭ)
//���: �ִ� 5ȸ �̵� �� �ִ밪�� ���� ū ��

int N;
int board[21][21];
int M = 0;

void solution(int n, int m) {
	if (n == 0) {
		if (m > M)
			M = m;
		return;
	}
	int sub[21][21];
	vector<int>a;
	vector<int>b;
	//��
	//copy
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			sub[i][j] = board[i][j];
	}
	//1. �������� �б�
	//2. 0�� �ƴ� ���ڸ� ����
	//3. ���ӵ� �� ���ڸ� ���ϸ� ���� ����� �������� ��ħ(�ڿ� ���� 0���� ����) 
	//4. �׷��� �ٽ� 0�� ��ĭ ����Ͽ� ������ �б�
	for (int i = 0; i < N; i++) {
		//���� ���� ��� 0�� �ƴ� ���� ���ͷ� �޴´�.(���ٿ� ��ȿ���� ����)
		for (int j = 0; j < N; j++) {
			if (board[j][i] > 0)
				a.push_back(board[j][i]);
		}
		for (int j = 1; j < a.size(); j++) {
			if (a[j - 1] == a[j]) {
				b.push_back(2 * a[j - 1]);
				if (m < 2 * a[j - 1]) 
					m = 2 * a[j - 1];
				a[j] = 0;
			}
			else if(a[j-1] != 0)
				b.push_back(a[j - 1]);
			//������ �κб��� Ȯ��
			if (j == a.size() - 1 && a[j] > 0) {
				b.push_back(a[j]);
			}
		}

		for (int j = 0; j < b.size(); j++)
			board[j][i] = b[j];
		for (int j = b.size(); j < N; j++)
			board[j][i] = 0;
		a.clear();
		b.clear();
	}
	solution(n - 1, m);
	//����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			board[i][j] = sub[i][j];
	}



	//�Ʒ�
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j>=0; j--) {
			if (board[j][i] > 0)
				a.push_back(board[j][i]);//a���Ϳ��� 0�� �ƴ� ������ ��
		}
		for (int j = 1; j < a.size(); j++) {
			if (a[j - 1] == a[j]) {
				b.push_back(2 * a[j - 1]);
				if (m < 2 * a[j - 1])
					m = 2 * a[j - 1];
				a[j] = 0;
			}
			else if (a[j - 1] != 0)//������ ���� ���� ������ �� �ٽ��ѹ� 0�� �ƴ� ���� b���Ϳ� �����
				b.push_back(a[j - 1]);
			//������ �κб��� Ȯ��
			if (j == a.size() - 1 && a[j] > 0) {
				b.push_back(a[j]);
			}
		}

		for (int j = 0; j < b.size(); j++)
			board[N-1-j][i] = b[j];
		for (int j = b.size(); j < N; j++)
			board[N-1-j][i] = 0;
		a.clear();
		b.clear();
	}
	
	solution(n - 1,m);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			board[i][j] = sub[i][j];
	}

	//����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > 0)
				a.push_back(board[i][j]);
		}
		for (int j = 1; j < a.size(); j++) {
			if (a[j - 1] == a[j]) {
				b.push_back(2 * a[j - 1]);
				if (m < 2 * a[j - 1])
					m = 2 * a[j - 1];
				a[j] = 0;
			}
			else if (a[j - 1] != 0)
				b.push_back(a[j - 1]);
			//������ �κб��� Ȯ��
			if (j == a.size() - 1 && a[j] > 0) {
				b.push_back(a[j]);
			}
		}

		for (int j = 0; j < b.size(); j++)
			board[i][j] = b[j];
		for (int j = b.size(); j < N; j++)
			board[i][j] = 0;
		a.clear();
		b.clear();
	}

	solution(n - 1, m);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			board[i][j] = sub[i][j];
	}

	//������
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j>=0; j--) {
			if (board[i][j] > 0)
				a.push_back(board[i][j]);
		}
		for (int j = 1; j < a.size(); j++) {
			if (a[j - 1] == a[j]) {
				b.push_back(2 * a[j - 1]);
				if (m < 2 * a[j - 1])
					m = 2 * a[j - 1];
				a[j] = 0;
			}
			else if (a[j - 1] != 0)
				b.push_back(a[j - 1]);
			//������ �κб��� Ȯ��
			if (j == a.size() - 1 && a[j] > 0) {
				b.push_back(a[j]);
			}
		}

		for (int j = 0; j < b.size(); j++)
			board[i][N-1-j] = b[j];
		for (int j = b.size(); j < N; j++)
			board[i][N-1-j] = 0;
		a.clear();
		b.clear();
	}

	solution(n - 1,m);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int max = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (max < board[i][j])
				max = board[i][j];
		}
	}

	solution(5, max);
	cout << M;

	return 0;
}