#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

constexpr int maxn = 1e6 + 5;

int tot[maxn << 2] = {}, cnt[maxn << 2] = {};

struct Edge{
    int x;
    ii y;
    int val;
    Edge(int a, int b, int c, int d) : x(a), y(ii(b,c)), val(d) {}
    bool operator < (const Edge &rhs) const{
        if(x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
};
vector<Edge> v;

void pull(int x, int l, int r){
    if(cnt[x]) tot[x] = r-l+1;
    else if(l != r) tot[x] = tot[x<<1] + tot[x<<1|1];
    else tot[x] = 0;
}

void update(int x, int l, int r, int ul, int ur, int val){
    if(ul <= l && r <= ur){
        cnt[x] += val;
        pull(x, l, r);
        return;
    }
    int mid = (r+l)>>1;
    if(ul <= mid) update(x<<1, l, mid, ul, ur, val);
    if(mid < ur) update(x<<1|1, mid+1, r, ul, ur, val);
    pull(x, l, r);
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int L, R, D, U;
        cin >> L >> R >> D >> U;
        v.emplace_back(L, D+1, U, 1);
        v.emplace_back(R, D+1, U, -1);
    }
    sort(v.begin(), v.end());

    int last = v[0].x;
    long long ans = 0;
    for(auto i : v){
        //printf("Edge(%d, %d~%d) %d\n", i.x, i.y.first, i.y.second, i.val);
        ans += (long long)(tot[1])*(i.x-last);
        update(1, 1, maxn, i.y.first, i.y.second, i.val);
        last = i.x;
        //printf("last %d, tot %d, area %d\n", last, tot[1], ans);
    }
    cout << ans << '\n';
}
