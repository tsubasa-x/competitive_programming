#include <bits/stdc++.h>
using namespace std;

bool vis[3][16] = {};
int C[8];
int total = 0;

void solve(int cur){
    //for(int i = 0; i < cur; i++) printf("(%d,%d) ", i, C[i]);
    //cout << '\n';
    if(cur == 8){
        printf("Case %d:\n", ++total);
        for(int i = 0; i < 8; i++) printf("(%d,%d) ", i, C[i]);
        cout << '\n';
        return;
    }
    bool flag = false;
    for(int col = 0; col < 8; col++){
        bool ok = true;
        if(vis[0][col] || vis[1][cur+col] || vis[2][cur-col+7]){
            ok = false;
        }
        if(ok){
            C[cur] = col;
            vis[0][col] = vis[1][cur+col] = vis[2][cur-col+7] = true;
            solve(cur+1);
            vis[0][col] = vis[1][cur+col] = vis[2][cur-col+7] = false;
        }
    }
}

int main(){
    solve(0);
}
