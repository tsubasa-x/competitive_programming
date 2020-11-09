/*
tarjan算法的步驟是(當dfs到節點u時):

在並查集中建立僅有u的集合,設置該集合的祖先為u
對u的每個孩子v:
遞迴處理v
合併v的集合到父節點u的集合,確保集合的祖先是u
設置u為已遍歷
處理關於u的查詢,若查詢(u,x)中的x已遍歷過,則LCA(u,x) = x所在的集合的祖先

因為只進行過一次DFS，所以複雜度為O((N+Q)∗α(N))，為了優化並查集，這裡採用啟發式合併，因此為了記錄集合的祖先而外增加了一個數組head
其雖為線性，但是效率並不怎麼好，跟倍增法的效能差不多
*/
#define MAXN 100000
#define MAXQ 100000
typedef vector<int >::iterator VIT;
typedef vector<pair<int,int> >::iterator VPIT;
int tr[MAXN+5],siz[MAXN+5];/*並查集，dfs前必須初始化*/
int head[MAXN+5],ans[MAXQ+5];
bool v[MAXN+5];/*走訪標記*/
vector<int >G[MAXN+5];
vector<pair<int,int> >Q[MAXN+5];
inline void init(int n){/*初始化並查集*/
	for(int i=1;i<=n;++i){
		tr[i]=i;
		siz[i]=1;
	}
}
int find(int x){
	return tr[x]==x?x:tr[x]=find(tr[x]);
}
inline void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b)return;
	if(siz[a]<siz[b])swap(a,b);
	tr[b]=a;
	siz[a]+=siz[b];
}
void dfs(int u,int pa){
	head[u]=u;
	for(VIT i=G[u].begin();i!=G[u].end();++i){
		if(*i==pa)continue;
		dfs(*i,u);
		merge(u,*i);
		head[find(u)]=u;/*記錄u所在集合的頭為u*/
	}
	v[u]=1;
	for(VPIT i=Q[u].begin();i!=Q[u].end();++i){
		if(v[i->first])ans[i->second]=head[find(i->first)];
	}
}

/*
使用方法也很簡單，只需要將每個詢問的兩點記錄起來即可
*/

int n,m,a,b;
scanf("%d%d",&n,&m);
for(int i=1;i<n;++i){
	scanf("%d%d",&a,&b);
	G[a].push_back(b);
	G[b].push_back(a);
}
for(int i=0;i<m;++i){/*紀錄詢問*/
	scanf("%d%d",&a,&b);
	Q[a].push_back(make_pair(b,i));
	Q[b].push_back(make_pair(a,i));
}
init(n);
dfs(1,-1);/*假設編號為1~n，root=1*/
for(int i=0;i<m;++i)printf("%d\n",ans[i]);
