struct Edge{
    int from, to, dist;
    bool operator < (const Edge &rhs) const {
        return dist < rhs.dist;
    }
}
int Prim(){
    int cost = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
    vector<bool> vis(vn, false); vis[0] = true;

    for(auto v : G[0]) pq.push(v);

    while(!pq.empty){
        Edge e = pq.top(); pq.pop();
        if(vis[e.to]) continue;
        vis[e.to] = true;
        cost += e.dist;
        for(auto v : G[e.to]) pq.push(v);
    }
    return cost;
}
