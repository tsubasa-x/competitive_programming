#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;

//bool v[maxn][maxn] = {};

int r[maxn] = {}, c[maxn] = {};

int main(){
    int n;
    while(cin >> n, n){
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                bool tmp;
                cin >> tmp;
                if(tmp){
                    r[i]++; c[j]++;
                }
            }
        }
        bool flag = false;
        int change_r = -1, change_c = -1;
        for(int i = 0; i < n; i++){
            if(r[i] & 1){
                if(change_r >= 0){
                    cout << "Corrupt\n";
                    flag = true;
                    break;
                }
                change_r = i;
            }
            if(c[i] & 1){
                if(change_c >= 0){
                    cout << "Corrupt\n";
                    flag = true;
                    break;
                }
                change_c = i;
            }
        }
        if(!flag){
            if(change_r == -1 && change_c == -1) cout << "OK\n";
            else printf("Change bit (%d,%d)\n", change_r+1, change_c+1);
        }
    }
}
