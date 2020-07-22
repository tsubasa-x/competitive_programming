#include <bits/stdc++.h>
using namespace std;

int main(){
    char ch;
    while(cin >> noskipws >> ch){
        if(isupper(ch)){
            cout << char('A' + (ch - 'A' + 13) % 26);
        }else if(islower(ch)){
            cout << char('a' + (ch - 'a' + 13) % 26);
        }else cout << ch;
    }
}
