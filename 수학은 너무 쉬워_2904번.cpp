//�����Ǯ��1
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//bool che[1000001];
//int n, a[100];
//vector<int> prime;
//int count[100][80000];  // �뷫 100�� ���� �Ҽ��� 7xxxx�� �ִµ�..... 
//int totalCount[80000];  // ��ü ���ڿ��� �Ҽ��� ��Ÿ�� Ƚ�� 
//int gcdCount[80000];    // gcd�� �� �� ���� Ƚ�� 
//int answer1, answer2;   // ���� ū ����, �ּ� Ƚ��  
//
//int main() {
//    for (int i = 2; i <= 1000000; i++) {
//        if (che[i]) continue;
//        // i is prime 
//        for (int j = i + i; j <= 1000000; j += i) {
//            che[j] = true;
//        }
//    }
//    for (int i = 2; i <= 1000000; i++) {
//        if (!che[i]) {
//            prime.push_back(i);
//        }
//    }
//
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);
//    }
//
//    // �� ���ں��� �Ҽ��� ��� ������????? ==> ���μ����� 
//    for (int i = 0; i < n; i++) {
//        int num = a[i];
//        for (int j = 0; j < prime.size(); j++) {
//            while (num % prime[j] == 0) {
//                count[i][j]++;
//                totalCount[j]++;
//                num /= prime[j];
//            }
//        }
//    }
//    for (int i = 0; i < prime.size(); i++) {
//        gcdCount[i] = totalCount[i] / n;
//    }
//    answer1 = 1;
//    for (int i = 0; i < prime.size(); i++) {
//        for (int j = 0; j < gcdCount[i]; j++) {
//            answer1 *= prime[i];
//        }
//        // �� ���ڵ鿡 ���ؼ� GCD�Ǳ� ���ؼ� �Ҽ��� �󸶳� �������� Ȯ���غ��� 
//        for (int j = 0; j < n; j++) {
//            if (count[j][i] < gcdCount[i]) {
//                answer2 += gcdCount[i] - count[j][i];
//            }
//        }
//    }
//    printf("%d %d", answer1, answer2);
//
//}


//�����Ǯ��2
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//bool che[1000001];
//int n, a[100];
//vector<int> prime;
//int count[100][80000];  // �뷫 100�� ���� �Ҽ��� 7xxxx�� �ִµ�..... 
//
//int main() {
//    for (int i = 2; i <= 1000000; i++) {
//        if (che[i]) continue;
//        // i is prime 
//        for (int j = i + i; j <= 1000000; j += i) {
//            che[j] = true;
//        }
//    }
//    for (int i = 2; i <= 1000000; i++) {
//        if (!che[i]) {
//            prime.push_back(i);
//        }
//    }
//
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);
//    }
//
//    // �� ���ں��� �Ҽ��� ��� ������????? ==> ���μ����� 
//    for (int i = 0; i < n; i++) {
//        int num = a[i];
//        for (int j = 0; j < prime.size(); j++) {
//            while (num % prime[j] == 0) {
//                count[i][j]++;
//                num /= prime[j];
//            }
//        }
//    }
//    // debug
//    for (int i = 0; i < n; i++) {
//        printf("[%d] : ", a[i]);
//        for (int j = 0; j < prime.size(); j++) {
//            if (count[i][j] != 0) {
//                printf("prime %d %d, ", prime[j], count[i][j]);
//            }
//        }
//        printf("\n");
//    }
//}