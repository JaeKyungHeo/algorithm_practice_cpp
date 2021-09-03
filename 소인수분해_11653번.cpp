#include <iostream>
#include <vector>
using namespace std;

// �ٸ� ������������� ���� ���Ǵ� ���ʹ���
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<int>v;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		if (N % i == 0) {
			N /= i;// ���� ������ �־����
			v.push_back(i);
			i = 1;// �ߺ��Ǵ� �μ��� ���� �� �ֱ� ������ �μ��߰� �� �ʱ�ȭ 
		}
	}

	for (auto elem : v)
		cout << elem << '\n';

	return 0;
}

//�����Ǯ��
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