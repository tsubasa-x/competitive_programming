struct Edge{
    int from, to, dist;
    bool operator < (const Edge &rhs) const {
        return dist < rhs.dist;
    }
}
int Kruskal(){
    sort(E.begin(), E.end());

    int cost = 0;
    for(int i = 0, cnt = 0; i < E.size() && cnt < vn; i++){
        Edge e = E[i];
        if(getP(e.from) != getP(e.to)){
            Union(e.from, e.to);
            cost += e.dist;
            cnt++;
        }
    }
    return cost;
}
