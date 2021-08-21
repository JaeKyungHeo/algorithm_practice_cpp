//문제
//작업의 수 N(1~100,000), 제한시간 D(1~10,000,000)
//작업을 다수의 컴퓨터로 수행할 시 작업을 최소의 컴퓨터로 수행하는 컴퓨터의 수를 구하시오.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); 
	cout.tie(); cin.tie();
	
	int TC, N, D, input;
	int computer[100001];

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		priority_queue<int>pq;
		vector<int>work;
		memset(computer, 0, sizeof(computer));
		int slot = 1, min, total = 0;
		cin >> N >> D;
		for (int i = 0; i < N; i++) {
			cin >> input;
			work.push_back(input);
			total += input;
		}
		slot = total / D;
		bool check = false, end = false;
		int w = 0;
		for (int time = 0; time <= D; time++) {
			for (int i = 0; i < slot; i++) {
				if (computer[i] - time == 0) {
					computer[i] += work[w];
					if (computer[i] > D) {
						check = true;
						cout << '\n';
						break;
					}
					else if(i != slot-1) {
						pq.push(-computer[i]);
						cout << slot << ' ' << i << ' ' << computer[i] << ' ' << w << ' ' << work[w] << ' ' << time << '\n';
						w++;
						time--;
					}
					else {
						pq.push(-computer[i]);
						cout << slot << ' ' << i << ' ' << computer[i] << ' ' << w << ' ' << work[w] << ' ' << time << '\n';
						w++;
						min = -pq.top();
						pq.pop();
						time = min - 1;
					}
					if (w == N) {
						end = true;
					}
				}
			}
			
			if (check == true) {
				slot++;
				time = -1;
				w = 0;
				check = false;
				memset(computer, 0, sizeof(computer));
			}
			if (end == true) {
				break;
			}
		}

		cout <<'#'<<t<<' '<< slot << '\n';

	}


	return 0;
}