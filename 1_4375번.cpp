#include <iostream>

using namespace std;

// 무작정 11...11인 수를 n으로 나누려한다면 런타임 에러가 발생한다.
// 이유: 계속 안나눠 진다면 11...11의 길이가 무한정 커져서 계산 자체에 오류가 발생하기 때문
// 길이(자리수)가 2000이라면 계산이 될 수 없기 때문이다.
// 문제에서 어떤 수로 나누어진다는 것을 판별 할때는 커지는 수를 계속해서 나누려는 수로 나눈나머지로 한정시켜줌
// 작은 자리숫자 중 나누어진 것은 더 이상 계산할 필요가 없다.
void solve(int n) {
	int count = 0;
	int num = 0;
	while (true) {
		num = (num * 10 + 1)%n; // (a+b)%c = (a%c+b%c)%c (나머지는 같음을 이용함 계속해서 나머지만을 이용)
		count++;
		if (num == 0) break;
	}
	cout << count << endl;
}

int main() {

	int n;
	while(cin>>n)// 테스트 케이스 제한이 없다면
		solve(n);

	return 0;
}