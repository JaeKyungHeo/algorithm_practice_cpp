#include <iostream>
#include <string.h> // string.h ������ �ʿ��մϴ�.

using namespace std;

int main() {
    char a[20];

    // 1����Ʈ���� ��� 10�� �ʱ�ȭ
    // �迭�� ä�� ���� sizeof()�Լ��� ����ϸ� �˴ϴ�.
    // sizeof �Լ� - �迭�� ��ü ����Ʈ ũ�⸦ ��ȯ�մϴ�.
    memset(a, 65, sizeof(a));
    //�ƽ�Ű �ڵ�� 65�� A�� ��µ˴ϴ�.

    for(int i = 0;i<20;i++)
        cout << a[i];

    return 0;
}