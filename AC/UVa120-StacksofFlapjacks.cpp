#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;

void to_seq(vector<int>& v, string str){
    stringstream ss(str);
    int tmp;
    while(ss >> tmp) v.emplace_back(tmp);
}

int main(){
    string str;
    bool endline = false;
    while(getline(cin,str)){
        if(endline) cout << '\n';
        endline = true;
        cout << str << '\n';

        vector<int> pancakes;
        to_seq(pancakes, str);

        vector<int> sorted = pancakes;
        sort(sorted.begin(), sorted.end());

        for(int i = pancakes.size()-1; i >= 0; i--){
            //printf("origin : %d, sorted : %d\n", pancakes[i], sorted[i]);
            if(sorted[i] == pancakes[i]) continue;
            if(pancakes[0] != sorted[i]){
                auto idx = find(pancakes.begin(), pancakes.end(), sorted[i]);
                cout << pancakes.size() - (idx - pancakes.begin())<< ' ';
                reverse(pancakes.begin(), idx+1);
                //for(auto x : pancakes) cout << x << ' '; cout << '\n';
            }
            cout << pancakes.size() - i << ' ';
            reverse(pancakes.begin(), pancakes.begin()+i+1);
            //for(auto x : pancakes) cout << x << ' '; cout << '\n';
        }
        cout << 0 << '\n';
    }
}
