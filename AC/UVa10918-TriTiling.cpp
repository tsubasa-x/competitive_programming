#include <bits/stdc++.h>
using namespace std;

const int maxn = 30 + 3;

int f[maxn] = {1, 0};
int g[maxn] = {0, 1};

int get_f(int);
int get_g(int);

int main(){
    int n;
    while(cin >> n, n != -1){
        cout << get_f(n) << '\n';
    }
}

int get_f(int n){
    if(f[n] || n <= 1) return f[n];
    return f[n] = get_f(n-2) + 2*get_g(n-1);
}

int get_g(int n){
    if(g[n] || n <= 1) return g[n];
    return g[n] = get_f(n-1) + get_g(n-2);
}
