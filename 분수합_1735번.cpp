#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A1, B1, A2, B2, A, B;
	cin >> A1 >> B1;
	cin >> A2 >> B2;

	A = A1 * B2 + B1 * A2;
	B = B1 * B2;

	if (A == B) {
		cout << 1 << " " << 1;
	}
	else if (A > B) {
		for (int i = 2; i <= B; i++) {
			if (A % i == 0 && B % i == 0) {
				A = A / i;
				B = B / i;
				i = 1;
			}
		}
		cout << A << " " << B;
	}
	else {
		for (int i = 2; i <= A; i++) {
			if (A % i == 0 && B % i == 0) {
				A = A / i;
				B = B / i;
				i = 1;
			}
		}
		cout << A << " " << B;
	}

	return 0;
}