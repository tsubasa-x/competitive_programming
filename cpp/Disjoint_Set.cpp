int dj[maxn];
int parent[maxn];

void init(){
    for(int i = 0; i < maxn; i++) dj[i] = i;
}

int getP(int a){
    if(a == parent[a]) return a;
    return parent[a] = getP(parent[a]);
}

void Union(int a, int b){
    a = getP(a);
    b = getP(b);
    if(a != b){
        parent[b] = a;
    }
}
