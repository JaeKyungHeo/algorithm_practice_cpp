#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
// 음의 사이클이 없는 한 일차원 배열로 선언해도 답을 도출해내는 것엔 지장이 없다.
int city[501], n;
int INF = 5000001;
// 간선의 정보를 담아둘 구조체
struct Edge {
    int s;
    int e;
    int val;
    // 간선의 정보를 저장할 생성자
    Edge(int a, int b, int c) {
        s = a;
        e = b;
        val = c;
    }
};

vector<Edge> Ed;

int BellmanFord(int e) {// s:시작 지점, e:끝 지점, n:노드 수
    // 출력할 배열을 일단 가장 큰 값으로 초기화
    memset(city, 0, sizeof(city));
    for (int i = 1; i <= n; i++) {
        city[i] = INF;
    }

    // 출발 정점의 경우 0으로 초기화
    city[1] = 0;
    // n - 1번까지 간선을 선택하면서 해당 지점에서의 값을 기존 값과 비교하며 최소값을 저장.
    for (int i = 1; i < n; i++) // i가 1일때 부터 시작해서 n-1번까지 반복하게 됨. 간선을 1개만 고르고, 2개 고르고, 3개고르고 ,, n-1개까지 고르는 과정
    {
        // 모든 간선 돌며 해당 정점까지의 최소 비용
        for (int j = 0; j < Ed.size(); j++)
        {
            int u = Ed[j].s; // 해당 간선의 시작점을 저장
            int v = Ed[j].e; // 해당 간선의 종료점을 저장
            int w = Ed[j].val; // 해당 간선의 가중치를 저장
            // 시작점까지 최소값이 무한대값이 아니고 
            // 시작점까지의 최소값에 현재 선택한 간선의 가중치값을 더한 것이 현재 선택한 간선의 
            // 종료점까지의 최소비용보다 작은 경우에만 아래의 논리를 적용
            // why? 시작지점까지의 최소비용이 무한대란 말은 그 지점까지 도달할 수 없단 말이니까 더이상 할 필요x
            // 시작 지점까지의 최소비용에 가중치를 더한 건? 현재 간선을 선택하기 바로 직전까지의 최소비용이란 의미
            // 때문에 지금까지의 최소비용에 현재 선택한 간선의 가중치를 더한 것이 간선의 종료지점까지의 최소비용을 비교
            // 간선의 시작점까지 최소비용에 현재 선택한 간선의 가중치를 더한 게 간선의 종료지점까지 이미 구해진 최소비용 값보다 크다는 건 최소비용이 될 수 없음
            // 요약하면 기존에 e(종료지점)로 가는 최소비용이 있었는데 u를 통해서 현재 간선의 값을 더해 v로 가는 값 비교
            if (city[u] != INF && city[u] + w < city[e])
                city[v] = city[u] + w; // 간선의 종료지점까지의 최소비용을 지금까지의 최소비용 + 현재 선택한 간선의 가중치를 더한 값으로 바꿈
        }
    }
    // 지금까지 n - 1 번 반복을 했고 다음에 이어지는 반복문은 n 번째의 반복
    // 즉 n-1까지 해야하는 데 간선의 개수가 N개로 된  것이 있는지 체크
    // 음의 사이클 체크
    for (int j = 0; j < Ed.size(); j++)
    {
        int u = Ed[j].s;
        int v = Ed[j].e;
        int w = Ed[j].val;
        if (city[u] != INF && city[u] + w < city[v])
            return -1;
    }
    // 종료 지점까지의 최소 간선 비용을 출력
    return city[e];
}

int main(void){
    int m, a, b, c;
    
    cin >> n >> m;
    // 입력되는 그래프의 정보를 구조체 벡터를 사용해서 저장한다.
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        Ed.push_back(Edge(a, b, c)); // 굳이 정렬할 필요도 없고, 인접리스트로 받아야할 이유도 없다.그냥 간선의 정보를 하나씩 적용해버리면 된다.
    }
    
    for (int i = 2; i <= n; i++) {
        if (BellmanFord(i)==-1 || BellmanFord(i) == INF) {
            cout << -1;
            break;
        }
        cout << BellmanFord(i) << '\n';
    }

    return 0;
}