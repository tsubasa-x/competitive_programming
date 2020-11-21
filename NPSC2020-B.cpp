#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

const int maxn = 2e5 + 5;

ll arr[maxn];
ll prefix[maxn];

int main(){
    int n; cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);


    for(int i = 1; i <= n; i++) prefix[i] = sum += arr[i];
    sum = 0;
    for(int i = 1; i <= n; i++){
        ll current = arr[i];
        //printf("sum += %d - %d - %d", prefix[n], prefix[i], (n-i)*current);
        sum += prefix[n] - prefix[i] - (n-i)*current;
    }
    cout << sum << '\n';
}

