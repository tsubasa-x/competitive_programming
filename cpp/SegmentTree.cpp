#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

const int maxn = 100*2;

struct Node{
    int l, r;
    int val = 0, chg = 0;
    Node *left = nullptr, *right = nullptr;
}seg[maxn];
int nodeCnt = 0;

Node* build(int l, int r){
    Node *n = &seg[nodeCnt++];
    n->l = l; n->r = r;
    //cout << "Built " << n->l << ' ' << n->r << '\n';
    return n;
}

void update(Node *pos, ii inv, int val){
    //printf("At %d %d, inv %d, %d\n", pos->l, pos->r, inv.first, inv.second);
    if(pos->l == inv.first && pos->r == inv.second){
        if(pos->l == pos->r) pos->val += val;
        else pos->chg += val;
        //printf("%d ~ %d : val = %d, chg = %d\n", pos->l, pos->r, pos->val, pos->chg);
        return;
    }
    int mid = (pos->l + pos->r) / 2;
    if(pos->left == nullptr) pos->left = build(pos->l, mid);
    if(pos->right == nullptr) pos->right = build(mid+1, pos->r);

    if(inv.second <= mid){
        update(pos->left, inv, val);
    }else if(inv.first > mid){
        update(pos->right, inv, val);
    }else{
        update(pos->left, ii(inv.first, mid), val);
        update(pos->right, ii(mid+1, inv.second), val);
    }
    pos->val = pos->left->val + pos->right->val;
}

int query(Node* pos, int x, int chg){
    if(pos->l == x && pos->r == x) return pos->val + chg;
    //cout << pos->l << ' ' << pos->r << '\n';
    int mid = (pos->l+pos->r)/2;
    //cout << x << ' ' << mid << '\n';
    if(x <= mid){
        if(pos->left == nullptr) return chg+pos->chg;
        return query(pos->left, x, chg+pos->chg);
    }else{
        if(pos->right == nullptr) return chg+pos->chg;
        return query(pos->right, x, chg+pos->chg);
    }
    return -1;
}

int main(){
    int l, r;
    Node* root = build(0, 100);
    while(cin >> l >> r, l != -1){
        update(root, ii(l,r), 1);
    }
    int x;
    /*
    while(cin >> x){
        cout << query(root, x, 0) << '\n';
    }*/

    for(int i = 0; i <= 16; i++){
        cout << query(root, i, 0) << '\n';
    }
}
