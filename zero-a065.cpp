#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    int a = 0, b = 0;
    for(int i = 0; i < str.size(); i++){
        if(i % 2) a += str[i] - '0';
        else b += str[i] - '0';
    }
    cout << abs(a-b);
}
