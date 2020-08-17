#include <bits/stdc++.h>
#include <fstream>
using namespace std;

const int maxn = 16 + 5;

int n, t = 0;
bool endline = false;

//fstream f;

bool is_prime(int num){
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}

bool check(int num, int arr[]){
    //if(num == 0) return false;
    for(int i = 0; i < num-1; i++){
        if(!is_prime(arr[i] + arr[i+1])) return false;
    }
    if(num == n && !is_prime(arr[0] + arr[num-1])) return false;
    return true;
}

void solve(int cur, int saved[]){
    //cout << cur << '\n';
    if(cur && !check(cur, saved)) return;
    if(cur == n){
        //cout << '\n';
        for(int i = 0; i < cur; i++) cout << saved[i] << " \n"[i==cur-1];
        return;
    }
    for(int i = 1; i <= n; i++){
        bool ok = true;
        for(int j = 0; j < cur; j++){
            if(i == saved[j]){
                ok = false;
                break;
            }
        }
        if(ok){
            saved[cur] = i;
            solve(cur+1, saved);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //f.open("output.txt", ios::out);
    while(cin >> n){
        int save[maxn] {1};
        if(endline) cout << '\n';
        endline = true;
        //cout << "Case " << ++t << ":\n";
        printf("Case %d:\n",++t);
        solve(1, save);
        //f << '\n';
    }
    //f.close();
}
