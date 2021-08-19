#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct pointIndex//각각의 x,y,z 좌표별 거리를 구하기
{
	int point;
	int index;
};

struct D// 각 인덱스별 좌표 거리
{
	int distance;
	int index1;
	int index2;
};


int parent[100001];

int find(int index) {
	if (parent[index] == index) return index;
	return parent[index] = find(parent[index]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

//사이클 유무 확인
bool isCycle(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return true;
	else
		return false;
}

bool compareP(pointIndex a, pointIndex b) {//x,y,z 좌표별 1차원 정렬
	return a.point < b.point;
}

bool compare(D a, D b) {//각 x,y,z 좌표별 거리 정렬
	return a.distance < b.distance;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pointIndex>X, Y, Z;
	vector<D>D;

	int N;
	int x, y, z;
	cin >> N;

	for (int i = 0; i < N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		X.push_back({ x,i });
		Y.push_back({ y,i });
		Z.push_back({ z,i });
	}
	
	sort(X.begin(), X.end(), compareP);
	sort(Y.begin(), Y.end(), compareP);
	sort(Z.begin(), Z.end(), compareP);


	for (int i = 1; i < X.size(); i++) {
		D.push_back({ abs(X[i].point - X[i - 1].point),X[i - 1].index,X[i].index });
		D.push_back({ abs(Y[i].point - Y[i - 1].point),Y[i - 1].index,Y[i].index });
		D.push_back({ abs(Z[i].point - Z[i - 1].point),Z[i - 1].index,Z[i].index });
	}

	sort(D.begin(), D.end(), compare);

	long long answer = 0;

	for (int i = 0; i < D.size(); i++) {
		if (isCycle(D[i].index1, D[i].index2) == false) {
			answer += D[i].distance;
			uni(D[i].index1, D[i].index2);
		}
	}

	cout << answer;

	return 0;
}


//메모리 오류난 코드
//오류분석
//각각의 edge 타입이 계속해서 사이거리를 모든행성과 구하기되므로 무수히 많은 메모리를 사용하게됨

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//class edge {
//public:
//	int node[2];
//	int distance;
//
//	edge(int a, int b, int c) {
//		this->node[0] = a;
//		this->node[1] = b;
//		this->distance = c;
//	}
//
//	bool operator <(edge& edge) {
//		return this->distance < edge.distance;
//	}
//};
//
//struct X
//{
//	int x;
//	int index;
//};
//
//struct Y
//{
//	int y;
//	int index;
//};
//
//
//struct Z
//{
//	int z;
//	int index;
//};
//
//
//struct D
//{
//	int d;
//	int index1;
//	int index2;
//};
//
//
//int parent[100001];
//
//int find(int index) {
//	if (parent[index] == index) return index;
//	return parent[index] = find(parent[index]);
//}
//
//void uni(int a, int b) {
//	a = find(a);
//	b = find(b);
//	if (a < b)
//		parent[b] = a;
//	else
//		parent[a] = b;
//}
//
////사이클 유무 확인
//bool isCycle(int a, int b) {
//	a = find(a);
//	b = find(b);
//	if (a == b)
//		return true;
//	else
//		return false;
//}
//
//struct planet
//{
//	int a;
//	int b;
//	int c;
//};
//
//int Distance(planet a, planet b) {
//	int x;
//	int y;
//	int z;
//
//	if (a.a > b.a) x = a.a - b.a;
//	else
//		x = b.a - a.a;
//	if (a.b > b.b) y = a.b - b.b;
//	else
//		y = b.b - a.b;
//	if (a.c > b.c) z = a.c - b.c;
//	else
//		z = b.c - a.c;
//
//	int Min;
//
//	if (x > y)
//		Min = y;
//	else
//		Min = x;
//	if (Min > z)
//		Min = z;
//
//	return Min;
//}
//
//int main(void) {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	vector<edge>v;
//	vector<planet>star;
//
//	int V;
//	int x, y, z;
//	cin >> V;
//
//	for (int i = 0; i < V; i++)
//		parent[i] = i;
//
//	for (int i = 0; i < V; i++) {
//		cin >> x >> y >> z;
//
//		star.push_back({ x,y,z });
//	}
//
//	for (int i = 0; i < V; i++) {
//		for (int j = i; j < V; j++) {
//			v.push_back(edge(i, j, Distance(star[i], star[j])));
//		}
//	}
//
//	//거리순 정렬
//	sort(v.begin(), v.end());
//
//	int answer = 0;
//
//	for (int i = 0; i < v.size(); i++) {
//		if (isCycle(v[i].node[0], v[i].node[1]) == false) {
//			answer += v[i].distance;
//			uni(v[i].node[0], v[i].node[1]);
//		}
//	}
//
//	cout << answer;
//
//	return 0;
//}