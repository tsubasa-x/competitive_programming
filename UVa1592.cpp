#include<bits/stdc++.h>
using namespace std;

int dataset[10000][10];

map<string, int> IDcache;
set<pair<int, int> > my_set;

void ID(string s){
    if(IDcache.count(s)) return;
    IDcache[s] = (int)IDcache.size();
}

int main(){
    string col[10];
    int n, m;
    while(cin >> n >> m){
        string str;
        for(int i = 0; i < n;i++){
            cin >> str;
            for(int j = 0, k = 0; j < str.size(); j++){
                if(str[j] == ',') k++;
                else col[k].push_back(str[j]);
            }

        }
    }
}
