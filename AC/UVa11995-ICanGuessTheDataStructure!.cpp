#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;

        bool possible[3] = {1,1,1};
        int tot_ans = 3;
        int in_temp = 0;
        bool flag = false;

        while(n--){
            int op, num;
            cin >> op >> num;

            if(flag) continue;

            if(op == 1){
                st.push(num);
                q.push(num);
                pq.push(num);
                in_temp++;
            }else{
                if(in_temp == 0){
                    flag = true;
                    continue;
                }
                if(possible[0]){
                    int u = st.top(); st.pop();
                    if(u != num) possible[0] = 0, tot_ans--;
                }
                if(possible[1]){
                    int u = q.front(); q.pop();
                    if(u != num) possible[1] = 0, tot_ans--;
                }
                if(possible[2]){
                    int u = pq.top(); pq.pop();
                    if(u != num) possible[2] = 0, tot_ans--;
                }
                in_temp--;
            }

        }
        if(tot_ans <= 0 || flag) cout << "impossible\n";
        else if(tot_ans > 1) cout << "not sure\n";
        else{
            if(possible[0]) cout << "stack\n";
            if(possible[1]) cout << "queue\n";
            if(possible[2]) cout << "priority queue\n";
        }
    }
}
