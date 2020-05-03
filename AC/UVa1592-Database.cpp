#include<bits/stdc++.h>
using namespace std;

int dataset[10000][10];

map<string, int> IDcache;

int ID(string s){
    if(IDcache.count(s)) return IDcache[s];
    return IDcache[s] = (int)IDcache.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    bool l = 0;
    int n, m;
    while(cin >> n >> m >> ws){
//        if(l){
//            cout << '\n';
//        }
//        l = 1;
        bool flag = 1;
        for(int i = 0; i < n;i++){
            string col[10];
            string str;
            getline(cin,str);
            for(int j = 0, k = 0; j < str.size(); j++){
                if(str[j] != ','){
                    col[k].push_back(str[j]);
                    if(j != str.size()-1) continue;
                }
                dataset[i][k] = ID(col[k]);
                k++;
            }
        }
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < m; j++){
//                cout << dataset[i][j] << ' ';
//            }
//            cout << '\n';
//        }
        for(int i = 0; i < m-1; i++){
            for(int j = i+1; j < m; j++){
                set<pair<int, int> > IDset;
                map<pair<int, int>, int> IDrow;
                for(int k = 0; k < n; k++){
                    pair<int, int> my_pair = make_pair(dataset[k][i], dataset[k][j]);
                    if(IDset.count(my_pair)){
                        cout << "NO\n";
                        cout << IDrow[my_pair]+1 << " " << k+1 << '\n';
                        cout << i+1 << " " << j+1 << '\n';
                        i = j = m;
                        flag = 0;
                        break;
                    }else{
                        IDset.emplace(my_pair);
                        IDrow[my_pair] = k;
                    }
                }
            }
        }
        if(flag) cout << "YES\n";
    }
}
