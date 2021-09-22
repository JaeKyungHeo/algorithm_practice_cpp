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

void solution(int n) {
	if (n == 0)
		return;

	int sub[21][21];
	vector<int>a;
	vector<int>b;
	
	//copy(��Ʈ��ŷ�� ���� ���)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			sub[i][j] = board[i][j];
	}

	//��
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
		for (int j = 0; j < a.size(); j++) {
			if (j == 0 && a.size() == 1)//1. a�� ũ�Ⱑ 1�� ���
				b.push_back(a[j]);
			else if (j == 0 && a.size() != 1)//2. ���� ������ 0�� �ƴ� �κп����� ������ ���� j=0 pass
				continue;
			else if (a[j - 1] == a[j]) {//3. ���� ������ ���ӵǸ� ��ġ�� ���ʿ� ��ġ
				b.push_back(2 * a[j - 1]);
				if (M < 2 * a[j - 1]) 
					M = 2 * a[j - 1];
				a[j] = 0;
			}
			else if(a[j - 1] != 0)//4. �� ���� ���� �����鼭 0�� �ƴ϶�� �տ� ���� b���Ϳ� ����
				b.push_back(a[j - 1]);
			//5. j�� 0�� �ƴϸ鼭 ������ �κ� ó��
			if (j != 0 && j == a.size() - 1 && a[j] > 0)
				b.push_back(a[j]);
		}

		//���� board ä���
		for (int j = 0; j < b.size(); j++)
			board[j][i] = b[j];
		for (int j = b.size(); j < N; j++)
			board[j][i] = 0;
		a.clear();
		b.clear();
	}

	solution(n - 1);

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
		for (int j = 0; j < a.size(); j++) {
			if (j == 0 && a.size() == 1)
				b.push_back(a[j]);
			else if (j == 0 && a.size() != 1)
				continue;
			else if (a[j - 1] == a[j]) {
				b.push_back(2 * a[j - 1]);
				if (M < 2 * a[j - 1])
					M = 2 * a[j - 1];
				a[j] = 0;
			}
			else if (a[j - 1] != 0)//������ ���� ���� ������ �� �ٽ��ѹ� 0�� �ƴ� ���� b���Ϳ� �����
				b.push_back(a[j - 1]);
			//������ �κб��� Ȯ��
			if (j != 0 && j == a.size() - 1 && a[j] > 0)
				b.push_back(a[j]);
		}

		for (int j = 0; j < b.size(); j++)
			board[N-1-j][i] = b[j];
		for (int j = b.size(); j < N; j++)
			board[N-1-j][i] = 0;
		a.clear();
		b.clear();
	}
	
	solution(n - 1);

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
		for (int j = 0; j < a.size(); j++) {
			if (j == 0 && a.size() == 1)
				b.push_back(a[j]);
			else if (j == 0 && a.size() != 1)
				continue;
			else if (a[j - 1] == a[j]) {
				b.push_back(2 * a[j - 1]);
				if (M < 2 * a[j - 1])
					M = 2 * a[j - 1];
				a[j] = 0;
			}
			else if (a[j - 1] != 0)
				b.push_back(a[j - 1]);
			//������ �κб��� Ȯ��
			if (j != 0 && j == a.size() - 1 && a[j] > 0)
				b.push_back(a[j]);
		}

		for (int j = 0; j < b.size(); j++)
			board[i][j] = b[j];
		for (int j = b.size(); j < N; j++)
			board[i][j] = 0;
		a.clear();
		b.clear();
	}

	solution(n - 1);
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
		for (int j = 0; j < a.size(); j++) {
			if (j == 0 && a.size() == 1)
				b.push_back(a[j]);
			else if (j == 0 && a.size() != 1)
				continue;
			else if (a[j - 1] == a[j]) {
				b.push_back(2 * a[j - 1]);
				if (M < 2 * a[j - 1])
					M = 2 * a[j - 1];
				a[j] = 0;
			}
			else if (a[j - 1] != 0)
				b.push_back(a[j - 1]);
			//������ �κб��� Ȯ��
			if (j != 0 && j == a.size() - 1 && a[j] > 0)
				b.push_back(a[j]);
		}

		for (int j = 0; j < b.size(); j++)
			board[i][N-1-j] = b[j];
		for (int j = b.size(); j < N; j++)
			board[i][N-1-j] = 0;
		a.clear();
		b.clear();
	}

	solution(n - 1);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (M < board[i][j])
				M = board[i][j];
		}
	}

	solution(5);

	cout << M;

	return 0;
}