
const int max_vertices = 50;
const int INF = 1e9;

struct Edge{ int to, dist; };

int d[max_vertices];
bool vis[max_vertices];
vector<Edge> G[max_vertices];

void init(){
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < max_vertices; i++) d[i] = INF;
}

void add_edge(int from, int to, int dist){
    G[from].emplace_back(Edge{to, dist});
    //G[to].emplace_back(Edge{from, dist});
}

void Dijkstra(int s){
    init();
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));
    d[s] = 0;
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < G[u].size(); i++){
            Edge e = G[u][i];
            if(d[e.to] > d[u] + e.dist){
                d[e.to] = d[u] + e.dist;
                pq.push(ii(d[e.to], e.to));
            }
        }
    }
}
