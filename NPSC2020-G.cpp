#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

int main(){
//    fstream input;
//    input.open("data/03.in", ios::in);
//    fstream output;
//    output.open("data/out.txt", ios::out);
//    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
//    input >> N >> Q;

    priority_queue<ii, vector<ii>, greater<ii> > q;

    for(int i = 0; i < Q; i++){
        int k;
        cin >> k;
//        input >> k;
        int num = k;
        ll d = 0;
        int spaces = 0, s = 0, e;
        bool flag = 1;

        printf("[%d]  q is empty : %d\n", i, q.empty());
        if(q.empty() || q.top().first != 0){
            if(!q.empty() && q.top().first <= 1){
                printf("Section A : ");
                ii u = q.top(); q.pop();
                q.push(ii(0, u.second+1));
                printf("pushed (%d, %d)\n", 0, u.second+1);
                //s = u.first + u.second;
            }else{
                printf("Section B : ");
                q.push(ii(0, 1));
                printf("pushed (%d, %d)\n", 0, 1);
                //s = 1;
            }
            flag = 0;
        }else k++;

        if(!q.empty()){
//            if(q.top().first == 0){
//                ii u = q.top(); q.pop();
//                spaces += u.second;
//                s = u.first + u.second;
//            }
            while(!q.empty()){
                printf("s:%d, k:%d, spaces:%d, [%d,%d]\n", s, k, spaces, q.top().first, q.top().second);
                if(s + k > q.top().first){
                    ii u = q.top(); q.pop();

                    int mov = u.first - s;
                    //printf("mov = %d, spaces = %d\n", mov, spaces);
                    k -= mov;
                    d += (ll)mov * (spaces);
                    spaces += u.second;
                    s = u.first + u.second;
                    e = u.first - 1;
                    printf("At i = %d, d += %d\n", i, mov * (spaces));
                }else break;
            }
            d += (k) * (spaces);
            //printf("At i = %d, d += %d\n", i, (k) * (spaces));
            e = s+k;
            if(num != 0 && spaces+flag != 0){
                printf("Section C : ");
                q.push(ii(num, spaces+flag));
                printf("pushed (%d, %d)\n", num, spaces + flag);
            }
        }else{
            printf("Section D : ");
            d += k;
            q.push(ii(k, 1));
            printf("pushed (%d, %d)\n", k, 1);
        }
        if(q.size()){
            int a = q.top().first, b = q.top().second;
            q.pop();
            while(!q.empty()){
                if(a+b == q.top().first){ b += q.top().second; q.pop(); }
                else break;
            }
            q.push(ii(a,b));
        }
        if(flag) d += num;
        cout << d << " \n"[i==Q-1];
//        output << d << " \n"[i==Q-1];
        cout << "####################\n";
    }
    //cout << '\n';
}


