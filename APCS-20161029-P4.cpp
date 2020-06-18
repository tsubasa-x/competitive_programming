#include <bits/stdc++.h>
using namespace std;

const int maxa = 5 + 5;
const int maxm = 10;

int maxfail;
string rec[maxm][maxa];
bool have_people[3];
int score = 0;

void init(){
    memset(rec, 0, sizeof(rec));
    memset(have_people, 0, sizeof(have_people));
    score = 0;
}
void clear_people(){
    memset(have_people, 0, sizeof(have_people));
}

void solve(){
    int fails = 0;
    int i = 0;
    while(fails < maxfail){
        if(rec[i%10][i/10][2] = 'O'){
            if(!(++fails%3)) clear_people();
        }else{
            char ch = rec[i%10][i/10][1];
            if(ch == 'H') step
            int step = stoi(rec[i%10][i/10][1]);
            for(int i = 2; i >= 0; i--){
                if(have_people[i]){
                    if(i+step > 2) score++;
                    else have_people[i+step] = 1;
                }
            }
            if()
        }

        i++;
    }
}

int main(){
    int a;
    while(cin >> a){
        for(int i = 0; i < a; i++) cin >> rec[0][i];
        for(int i = 1; i < maxm; i++){
            cin >> a;
            for(int j = 0; j < a; j++) cin >> rec[i][j];
        }
        cin >> maxfail;


    }
}
