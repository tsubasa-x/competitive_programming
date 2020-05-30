#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000+10;
int inorder[maxn], postorder[maxn], lch[maxn], rch[maxn];
int best, best_sum = 999999;
int n = 0;
bool readline(int *order){
    string order_str;
    if(!getline(cin, order_str)) return false;
    stringstream sstr(order_str);
    n = 0;
    int v;
    while(sstr >> v) order[n++] = v;
    return n > 0;
}

int build(int L1, int R1, int L2, int R2){
    if(L1 > R1) return 0;
    int root = postorder[R2];
    int index = L1;
    while(inorder[index] != root) index++;
    int cnt  = index - L1;

    lch[root] = build(L1, index-1, L2, L2+cnt-1);
    rch[root] = build(index+1, R1, L2+cnt, R2-1);
    return root;
}

void dfs(int root, int sum){
    sum += root;
    if(!lch[root] && !rch[root]){
        if(best_sum == sum) best = min(best, root);
        else if(best_sum > sum){
            best = root;
            best_sum = sum;
        }
    }
    if(lch[root]) dfs(lch[root], sum);
    if(rch[root]) dfs(rch[root], sum);
}


int main(){
    while(readline(inorder)){
        best_sum = 9999999;
        readline(postorder);
        build(0, n-1, 0, n-1);
        dfs(postorder[n-1], postorder[n-1]);
        cout << best << '\n';
    }
}
