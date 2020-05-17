#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    while(cin >> t, t != -1){
        while(t--){
            int d, I;
            cin >> d >> I;
            int ans = 1;
            for(int i = 0; i < d-1; i++){
                if(I%2){ ans *= 2; I = (I+1)/2; }
                else { ans = ans*2 + 1; I /= 2; };
            }
            cout << ans << '\n';
        }
    }
}
