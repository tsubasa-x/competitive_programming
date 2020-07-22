#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int maxn = 500 + 5;


set<ii> s;


int main(){
    int r, c; cin >> r >> c;

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;

        if(sr == er){
            for(int j = min(sc,ec); j <= max(sc,ec); j++){
                s.emplace(ii(sr,j));
            }
        }else if(sc == ec){
            for(int j = min(sr,er); j <= max(sr,er); j++){
                s.emplace(ii(j,sc));
            }
        }else{
            if(sr > er){
                for(int ur = er, uc = ec; ur <= sr; ur++){
                    s.emplace(ii())
                }
            }
        }
    }

}
