#include <string>
#include <vector>

using namespace std;

bool notPrime[101];
vector<int>prime;//1~100���� �Ҽ��� ������������ �־��

int LCD(long long a, int b) {
    int GCD = 1;
    for (int i = 0; i < prime.size(); i++) {
        //�ִ����� ���ϱ�
        if (a % prime[i] == 0 && b % prime[i] == 0) {
            a = a / prime[i];
            b = b / prime[i];
            GCD *= prime[i];
            i = i - 1;
        }
    }
    return a * b * GCD;
}

int solution(vector<int> arr) {
    int answer = 0;

    //1~100������ �Ҽ� Ȯ��
    for (int i = 2; i <= 10; i++) {
        for (int j = 2; i * j <= 100; j++)
            notPrime[i * j] = true;
    }

    for (int i = 2; i <= 100; i++) {
        if (notPrime[i] == false)
            prime.push_back(i);
    }

    if (arr.size() == 1)
        answer = arr[0];
    else {
        int temp = LCD(arr[0], arr[1]);//�ּҰ����
        for (int i = 2; i < arr.size(); i++)
            temp = LCD(temp, arr[i]);

        answer = temp;
    }
    return answer;
}