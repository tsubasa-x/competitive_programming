#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;

int m, n;
bool maze[maxn][maxn];
bool vis[maxn][maxn][maxn];
int k;
int best;

struct Node{
    int r;
    int c;
    int obs = 0;
    int steps = 0;
};

int dr[] = {-1, 0, 1, 0},
    dc[] = {0, 1, 0, -1};

void bfs(){
    queue<Node> q;
    Node u;
    u.r = u.c = u.obs = u.steps = 0;
    q.push(u);
    while(!q.empty()){
        Node u = q.front();
        q.pop();
        int r = u.r, c = u.c, obs = u.obs, steps = u.steps;
        if(obs > k || vis[r][c][obs]) continue;
        vis[r][c][obs] = 1;
        if(r == m-1 && c == n-1){ best = steps; return; }
        //cout << r << ' ' << c << ' ' << obs << ' ' << steps << '\n';
        for(int i = 0; i < 4; i++){
            int next_r = r + dr[i], next_c = c + dc[i], next_obs;
            if(next_r >= m || next_r < 0 || next_c >= n || next_c < 0) continue;

            if(maze[next_r][next_c]) next_obs = obs+1;
            else next_obs = 0;

            u.r = next_r, u.c = next_c, u.obs = next_obs, u.steps = steps+1;
            q.push(u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        memset(vis, 0, sizeof(vis));
        best = -1;

        cin >> m >> n;
        cin >> k;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) cin >> maze[i][j];
        }
        bfs();
        cout << best << '\n';
    }
}
