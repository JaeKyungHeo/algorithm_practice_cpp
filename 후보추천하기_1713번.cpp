#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int student[101] = { 0, };//추천 횟수 누적
int check[101] = { 0, };//사진틀에 위치 여부(존재하면 0, 하지않으면 1)
int old_check[101] = { 0, };//꽉찬 사진틀에서 뺄 때 오래된 여부 판단(작을 수록 오래됨)
vector<int> recommend;//순차적인 추천

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
		//check가 1이면서(사진틀에 들어있음)  추천수가 중복된다면 old_check를 통해 가장 낮은 값을 가진 학생과 교환
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
			if (check[recommend[i]] != 1)// 오래 걸렸던 부분 사진틀에 올라온 순서를 기준으로 오래된 순서를 의미함/이미 있는 학생이 추천을 받았다고 해서 추천 순서가 변하는건 아님
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