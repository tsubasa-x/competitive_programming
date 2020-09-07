#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

const int maxn = 750 + 5;

int n;

void merge_sum(int arr1[], int arr2[]){
    //for(int i = 0; i < n; i++) cout << arr1[i] << " \n"[i==n-1];
    //for(int i = 0; i < n; i++) cout << arr2[i] << " \n"[i==n-1];
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for(int i = 0; i < n; i++){
        pq.push(ii(arr1[i]+arr2[0], 0));
    }
    for(int i = 0; i < n; i++){
        ii u = pq.top(); pq.pop();
        arr1[i] = u.first;
        if(u.second + 1 < n) pq.push(ii(u.first - arr2[u.second] + arr2[u.second+1], u.second+1));
    }
}

int main(){
    while(cin >> n){
        int arr1[maxn], arr2[maxn];
        for(int i = 0; i < n; i++) cin >> arr1[i];
        sort(arr1, arr1+n);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++) cin >> arr2[j];
            sort(arr2, arr2+n);
            merge_sum(arr1, arr2);
        }
        for(int i = 0; i < n; i++) cout << arr1[i] << " \n"[i==n-1];
    }
}
