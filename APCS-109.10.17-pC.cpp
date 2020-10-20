#include <bits/stdc++.h>
using namespace std;

const int maxm = 50 + 5;
const int maxn = 1e5 + 5;

int m, n;

int maze[maxm][maxn] = {};
int prefix[maxm][maxn] = {};

int range_sum(int r, int c){
    int best = -1e8;
    for(int i = 0; i <= c; i++){
        best = max(best, prefix[r][c] - prefix[r][i]);
    }
    for(int i = c+2; i <= n; i++){
        best = max(best, prefix[r][i] - prefix[r][c]);
    }
    return best;
}

int main(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            cin >> maze[i][j];
            prefix[i][j] = sum += maze[i][j];
        }
    }
    vector<vector<int> > dp(m+2, vector<int>(n, 0));
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = dp[i][j] + range_sum(i-1, j);
        }
    }
    for(auto i : dp){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }

}
