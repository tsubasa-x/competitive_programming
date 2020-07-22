#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;

char result[maxn];
int r_size;

void to_bin(int len, int& cur){
    for(int i = 2; i >= 0; i--){
        char r;
        if(len & 1) r = '1';
        else r = '0';
        result[cur + i] = r;
        len >>= 1;
    }
    cur += 3;
    r_size += 4;
}

int main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n >> ws;
    string str;
    for(int t = 0; t < n; t++){
        getline(cin,str);

        bool flag = false;
        char ch = 'a';
        int cur = 0;
        int len = 0;
        r_size = 0;

        for(int i = 0; i < str.size(); i++){
            if(str[i] != '0' && str[i] != '1'){
                cout << "-1\n";
                flag = true;
                break;
            }

            if(ch == str[i] && len < 7){
                if(len < 7) len++;
            }else{
                if(ch != 'a'){
                    to_bin(len, cur);
                    result[cur++] = ' ';
                    len = 0;
                }
                result[cur++] = ch = str[i];
                len++;
            }
        }
        if(flag) continue;
        to_bin(len,cur);
        result[cur++] = ' ';
        for(int i = 0; i < cur; i++){
            cout << result[i];
        }

        double percent = (double)r_size / (double)str.size() * 100;
        int r_percent = (int)round(percent);
        printf("%d%%\n", r_percent);
    }
}
