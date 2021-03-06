#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[1001][1001] = {0,};
int visit[1001] = {0,};
queue<int> q;
int n, m, v;
/*
void init() {   // 노드의 방문 여부를 초기화
    for(int i=0; i<=n; i++) {
        visit[i] = 0;
    }
}
void init() {   // 노드의 방문 여부를 초기화
    memset(visit, 0, sizeof(visit));
}
*/
void init() {   // 노드의 방문 여부를 초기화
    for(int i=0; i<=n; i++) {
        *(visit + i) = 0;
    }
}
void dfs(int v) {
    printf("%d ", v);   // 시작 노드를 출력
    visit[v] = 1;   // 해당 노드에 방문함을 나타냄
    for(int i=1; i<=n; i++) {   // 모든 노드를 탐색
        if(map[v][i]==1 && visit[i]==0) {   // 노드간 연결되어있고 방문한 적 없다면
            dfs(i); // 재귀를 돌린다.
        }
    }
}

void bfs(int v) {
    // 시작 노드를 출력하고 Q에 PUSH
    printf("%d ", v);
    q.push(v);
    visit[v] = 1;

    while(!q.empty()) { // 큐가 비어있을 때까지 모든 노드를 탐색
        int node = q.front();   // 큐에서 노드를 꺼냄.
        q.pop();
        
        for(int i=0; i<=n; i++) {    // 모든 노드를 탐색
            // 연결되어있으면서 방문 안한 노드가 있으면 노드 출력, 큐에 push
            if(map[node][i]==1 && visit[i]==0) {
                visit[i] = 1;   // 노드에 방문 했음을 표시
                printf("%d ", i);
                q.push(i);
            }
        }
    }
}

int main() {
    // 정점의 개수, 간선의 개수, 탐색 시작 번호
    scanf("%d %d %d", &n, &m, &v);
    for(int i=0; i<m; i++) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        map[num1][num2] = 1;
        map[num2][num1] = 1;
    }
    dfs(v);
    printf("\n");
    init();
    bfs(v);

    return 0;
}