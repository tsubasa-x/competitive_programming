#include <bits/stdc++.h>
using namespace std;

const int maxn = 30 + 5;

int fib[maxn] = {};

int f(int n){
    if(fib[n]) return fib[n];
    if(n == 0 || n == 1) return n;
    return fib[n] = f(n-1) + f(n-2);
}

int main(){
    int n;
    while(cin >> n){
        cout << f(n) << '\n';
    }

}
