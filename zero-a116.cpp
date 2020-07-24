#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;

int day_per_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int n, m = 0;
int days[maxn];
int year, month, day;
int min_days;

void get_min(){
    bool flag = true;
    min_days = 0;
    while(flag){
        min_days += m;
        for(int i = 0; i < n; i++){
            if(!(min_days % days[i])) flag = false;
            else{
                flag = true;
                break;
            }
        }
    }
}

bool year_check(int y){
    if(!(y % 4)){
        if(!(y % 100)){
            if(!(y % 400)) return true;
        }else return true;
    }
    return false;
}

void solve(){
    day += min_days;
    while(day > day_per_month[month-1]){
        //printf("%d/%d/%d\n", year, month, day);
        if(month == 2){
            if(year_check(year)) day -= 29;
            else day -= 28;
        }else day -= day_per_month[month-1];
        month++;
        if(month > 12){
            year++; month -= 12;
        }
    }
    printf("%d/%02d/%02d\n", year, month, day);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> days[i];
        m = max(m, days[i]);
    }
    scanf("%d/%d/%d", &year, &month, &day);

    get_min();
    solve();
}
