#include <iostream>
#include <vector>
using namespace std;

// 다른 공약수문제에서 많이 사용되는 기초문제
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<int>v;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		if (N % i == 0) {
			N /= i;// 몫을 갱신해 주어야함
			v.push_back(i);
			i = 1;// 중복되는 인수가 있을 수 있기 때문에 인수발견 후 초기화 
		}
	}

	for (auto elem : v)
		cout << elem << '\n';

	return 0;
}

//강사님풀이
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//bool che[3200];
//vector<int> prime;
//int n;
//
//int main() {
//    for (int i = 2; i < 3200; i++) {
//        if (che[i]) continue;
//        for (int j = i + i; j < 3200; j += i) {
//            che[j] = true;
//        }
//    }
//    for (int i = 2; i < 3200; i++) {
//        if (!che[i]) {
//            prime.push_back(i);
//        }
//    }
//    scanf("%d", &n);
//    if (n == 1) {
//        return 0;
//    }
//    for (int i = 0; i < prime.size(); i++) {
//        while (n % prime[i] == 0) {
//            printf("%d\n", prime[i]);
//            n /= prime[i];
//        }
//    }
//    if (n > 1) {
//        printf("%d\n", n);
//    }
//}