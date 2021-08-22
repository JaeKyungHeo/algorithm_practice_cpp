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
	multiset<int>bags;// multiset�� �ߺ��� ���� / set�� �⺻������ ����Ʈ�� ������
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
		//key���� �ش��ϴ� ���Ұ� ���۵Ǵ� �ּҸ� ����Ű�� �ݺ��� ��ȯ // upper�� �ش���Ұ� ������ ���� �ּҸ� ����Ŵ
		//�Ʒ��� ���� O(N)�� �ð����⵵�� ���� O(log(N))�� �ð����⵵�� ����
		//auto Bag = lower_bound(bags.begin(), bags.end(), JewelryList[i].M);
		if (Bag != bags.end()) {
			answer += JewelryList[i].V;
			bags.erase(Bag); // erase(key) : �ݺ��ڰ� ����Ű�� ���� ����
		}
		if (bags.size() == 0)
			break;
	}

	cout << answer;

	return 0;
}