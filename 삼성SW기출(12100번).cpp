#include <iostream>
#include <vector>

using namespace std;

//조건
//번호가 써져있는 블록 이동시키기
//이동하는 방향 젤 앞에 있는 것부터 처리해줌
//NxN보드사이즈(1~20)
//한쪽 방향으로 이동했을 때 해당방향으로 인접해있으면서 같은 수를 가지고 있어야 합쳐짐
//입력: N(1~20) 보드 각 칸의 값(0은 빈칸)
//출력: 최대 5회 이동 후 최대값이 가장 큰 수

int N;
int board[21][21];
int M = 0;

void solution(int n) {
	if (n == 0)
		return;

	int sub[21][21];
	vector<int>a;
	vector<int>b;
	
	//copy(백트래킹을 위해 사용)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			sub[i][j] = board[i][j];
	}

	//위
	//1. 한쪽으로 밀기
	//2. 0이 아닌 숫자만 추출
	//3. 연속된 두 숫자를 비교하며 같은 수라면 앞쪽으로 합침(뒤에 수는 0으로 갱신) 
	//4. 그러고 다시 0을 빈칸 취급하여 한쪽을 밀기
	for (int i = 0; i < N; i++) {
		//한쪽 열을 잡고 0이 아닌 수를 벡터로 받는다.(접근에 비효율이 있음)
		for (int j = 0; j < N; j++) {
			if (board[j][i] > 0)
				a.push_back(board[j][i]);
		}
		for (int j = 0; j < a.size(); j++) {
			if (j == 0 && a.size() == 1)//1. a의 크기가 1인 경우
				b.push_back(a[j]);
			else if (j == 0 && a.size() != 1)//2. 이후 과정이 0이 아닌 부분에서의 진행을 위해 j=0 pass
				continue;
			else if (a[j - 1] == a[j]) {//3. 같은 수들의 연속되면 합치고 앞쪽에 배치
				b.push_back(2 * a[j - 1]);
				if (M < 2 * a[j - 1]) 
					M = 2 * a[j - 1];
				a[j] = 0;
			}
			else if(a[j - 1] != 0)//4. 앞 수와 같지 않으면서 0이 아니라면 앞에 수는 b벡터에 넣음
				b.push_back(a[j - 1]);
			//5. j가 0이 아니면서 마지막 부분 처리
			if (j != 0 && j == a.size() - 1 && a[j] > 0)
				b.push_back(a[j]);
		}

		//원래 board 채우기
		for (int j = 0; j < b.size(); j++)
			board[j][i] = b[j];
		for (int j = b.size(); j < N; j++)
			board[j][i] = 0;
		a.clear();
		b.clear();
	}

	solution(n - 1);

	//복원
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			board[i][j] = sub[i][j];
	}

	//아래
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j>=0; j--) {
			if (board[j][i] > 0)
				a.push_back(board[j][i]);//a벡터에는 0이 아닌 정수가 들어감
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
			else if (a[j - 1] != 0)//인접한 같은 수를 합쳐준 뒤 다시한번 0이 아닌 수를 b벡터에 담아줌
				b.push_back(a[j - 1]);
			//마지막 부분까지 확인
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

	//왼쪽
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
			//마지막 부분까지 확인
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

	//오른쪽
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
			//마지막 부분까지 확인
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