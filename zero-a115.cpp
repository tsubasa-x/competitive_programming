#include <bits/stdc++.h>
using namespace std;

int table[5][5];

int row[5] = {}, col[5] = {}, t[2] = {};
int sum = 0;

bool vis[5][5] = {};

int called(int num){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(table[i][j] == num){
                vis[i][j] = true;
                if(++row[i] == 5) sum++;
                if(++col[j] == 5) sum++;
                if(i == j && ++t[0] == 5) sum++;
                if(i == 4-j && ++t[1] == 5) sum++;
            }
        }

    }
}

int solve(){
    int best_num = -1;
    int best_sum = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(!vis[i][j]){
                int sum = 0;
                if(row[i] + 1 == 5) sum++;
                if(col[j] + 1 == 5) sum++;
                if(i == j   && t[0] + 1 == 5) sum++;
                if(i == 4-j && t[1] + 1 == 5) sum++;

                if(sum == best_sum) best_num = min(table[i][j], best_num);
                if(sum > best_sum){
                    best_sum = sum;
                    best_num = table[i][j];
                }
            }
        }
    }
    return best_num;
}

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> table[i][j];
        }
    }
    int num;
    while(cin >> num, num != -1) called(num);

    cout << solve();

}
