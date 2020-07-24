#include <bits/stdc++.h>
using namespace std;

bool check(unsigned long long int num){
    string str = to_string(num);
    for(int i = 0; i < str.size(); i++){
        if((str[i] - '0') & 1) return true;
    }
    return false;
}

int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;

        long long int a = ceil(sqrt(pow(10,k-1)));
        //cout << a << '\n';
        while(true){
            unsigned long long int num = a*a;
            if(check(num)) a++;
            else{
                //cout << a << '\n';
                cout << num << '\n';
                break;
            }
        }

    }
}
