#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Jewelry
{
	int M;
	int V;
};

bool compareJ(Jewelry a, Jewelry b){
	if (a.V == b.V) return a.M < b.M;
	else
		return a.V > b.V;
}

int main(void) {
	int N, K, m, v, c;
	cin >> N >> K;
	vector<Jewelry>JewelryList;
	multiset<int>bags;// multiset은 중복이 허용됨 / set은 기본족으로 이진트리 구조임
	long long answer = 0;
	for (int i = 0; i < N; i++) {
		cin >> m >> v;
		JewelryList.push_back({ m,v });
	}

	sort(JewelryList.begin(), JewelryList.end(), compareJ);

	for (int i = 0; i < K; i++) {
		cin >> c;
		bags.insert(c);
	}
	
	for (int i = 0; i < N; i++) {
		auto Bag = bags.lower_bound(JewelryList[i].M);
		//key값에 해당하는 원소가 시작되는 주소를 가리키는 반복자 반환 // upper는 해당원소가 끝나는 다음 주소를 가리킴
		//아래의 경우는 O(N)의 시간복잡도를 위는 O(log(N))의 시간복잡도를 가짐
		//auto Bag = lower_bound(bags.begin(), bags.end(), JewelryList[i].M);
		if (Bag != bags.end()) {
			answer += JewelryList[i].V;
			bags.erase(Bag); // erase(key) : 반복자가 가르키는 원소 제거
		}
		if (bags.size() == 0)
			break;
	}

	cout << answer;

	return 0;
}