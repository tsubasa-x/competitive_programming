#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;

//string clause[5] = {"�~��","�~��","�ۥ���","����","����"};

struct Circle{
    int x, y;
    double r;
}circle[maxn];

void get_clause(int a, int b){
    Circle ca = circle[a], cb = circle[b];
    int a_to_b = pow(ca.x-cb.x,2) + pow(ca.y-cb.y,2);
    int r_square = pow(ca.r + cb.r, 2);
    if      (a_to_b > r_square)                             cout << "�~��\n";
    else if(a_to_b == r_square)                             cout << "�~��\n";
    else if(a_to_b < r_square && a_to_b > pow(ca.r-cb.r,2)) cout << "�ۥ���\n";
    else if(a_to_b == pow(ca.r-cb.r,2))                     cout << "����\n";
    else                                                       cout << "����\n";
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> circle[i].x >> circle[i].y >> circle[i].r;
    }

    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        get_clause(a-1,b-1);
        //int idx = get_clause(a-1,b-1);
        //cout << clause[idx] << '\n';

    }
}
