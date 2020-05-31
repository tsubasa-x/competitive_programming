#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int n, m;
int t;
bool graph[maxn][maxn];
int visit[maxn];
int order[maxn];

bool dfs(int u){
    visit[u] = -1;
    for(int i = 1; i <= n; i++){
        if(graph[u][i]){
            if(visit[i] < 0) return false;
            if(!visit[i] && !dfs(i)) return false;
        }
    }
    visit[u] = 1;
    order[--t] = u;
    return true;
}

bool topo(){
    memset(visit, 0, sizeof(visit));
    memset(order, 0, sizeof(order));
    t = n;
    for(int i = 1; i <= n; i++){
        if(!visit[i])
            if(!dfs(i)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m, n != 0 || m != 0){
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            graph[a][b] = 1;
        }
        if(topo()){
            cout << order[0];
            for(int i = 1; i < n; i++) cout << ' ' << order[i];
            cout << '\n';
        }
    }
}
