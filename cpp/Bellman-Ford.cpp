const int max_vertices = 50;
const int INF = 1e9;

struct Edge{ int to, dist; };

vector<Edge> G[max_vertices];
int d[max_vertices];
bool inq[max_vertices];

int v, e;

void init(){
    memset(inq, false, sizeof(inq));
    for(int i = 0; i < max_vertices; i++) d[i] = INF;
}
void add_edge(int from, int to, int dist){
    G[from].emplace_back((Edge){to,dist});
}
void bellman_ford(int s){
    init();
    queue<int> q; q.push(s);
    d[s] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        inq[u] = false;

        for(int i = 0; i < G[u].size(); i++){
            Edge e = G[u][i];
            if(d[e.to] > d[u] + e.dist){
                d[e.to] = d[u] + e.dist;
                if(!inq[e.to]){
                    q.push(e.to);
                    inq[e.to] = true;
                }
            }
        }
    }
}
