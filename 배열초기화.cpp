#include <iostream>
#include <string.h> // string.h 파일이 필요합니다.

using namespace std;

int main() {
    char a[20];

    // 1바이트마다 모두 10로 초기화
    // 배열을 채울 때는 sizeof()함수를 사용하면 됩니다.
    // sizeof 함수 - 배열의 전체 바이트 크기를 반환합니다.
    memset(a, 65, sizeof(a));
    //아스키 코드로 65인 A가 출력됩니다.

    for(int i = 0;i<20;i++)
        cout << a[i];

    return 0;
}