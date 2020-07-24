#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;

int r[maxn]  ={};

int f91(int n){
    if(r[n]) return r[n];
    if(n <= 100) return r[n] = f91(f91(n+11));
    if(n >= 101) return r[n] = n-10;
}

int main(){
    int n;
    while(cin >> n, n){
        printf("f91(%d) = %d\n", n, f91(n));
    }
}
