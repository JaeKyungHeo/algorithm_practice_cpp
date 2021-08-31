#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int student[101] = { 0, };//��õ Ƚ�� ����
int check[101] = { 0, };//����Ʋ�� ��ġ ����(�����ϸ� 0, ���������� 1)
int old_check[101] = { 0, };//���� ����Ʋ���� �� �� ������ ���� �Ǵ�(���� ���� ������)
vector<int> recommend;//�������� ��õ

bool state_frame(int n, int m) {
	int total = 0;
	for (int i = 1; i <= m; i++)
		total += check[i];
	if (total == N && check[recommend[n]] != 1)
		return false;
	else
		return true;
}

void exchange(int n, int m) {
	int count = 0;
	int target = 0, min=1001;
	for (int i = 1; i <= m; i++) {
		//check�� 1�̸鼭(����Ʋ�� �������)  ��õ���� �ߺ��ȴٸ� old_check�� ���� ���� ���� ���� ���� �л��� ��ȯ
		if (check[i] == 1 && student[i] > 0) {
			if (min == student[i]) {
				if (old_check[target] > old_check[i])
					target = i;
			}
			else if (min > student[i]) {
				min = student[i];
				target = i;
			}
		}
	}
	check[target] = 0;
	student[target] = 0;
	check[n] = 1;
	student[n]++;
}

int main() {

	int max = 0, k;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &k);
		recommend.push_back(k);
		if (k > max)
			max = k;
	}
	
	for (int i = 0; i < M; i++) {
		if (state_frame(i, max) == true) {
			student[recommend[i]]++;
			if (check[recommend[i]] != 1)// ���� �ɷȴ� �κ� ����Ʋ�� �ö�� ������ �������� ������ ������ �ǹ���/�̹� �ִ� �л��� ��õ�� �޾Ҵٰ� �ؼ� ��õ ������ ���ϴ°� �ƴ�
				old_check[recommend[i]] = i;
			check[recommend[i]] = 1;
		}
		else {
			exchange(recommend[i], max);
			old_check[recommend[i]] = i;
		}
	}

	for (int j = 0; j <= max; j++) {
		if (check[j] == 1)
			printf("%d ", j);
	}

	return 0;
}