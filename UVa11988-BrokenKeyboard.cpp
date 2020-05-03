#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;

    while(cin >> str){
        list<char> word;
        list<char>::iterator cur = word.begin();
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '[') cur = word.begin();
            else if(str[i] == ']') cur = word.end()--;
            else{
                word.insert(cur, str[i]);
//                cur++;
            }
        }
        for(const char c : word) cout << c;
        cout << '\n';
    }
}
