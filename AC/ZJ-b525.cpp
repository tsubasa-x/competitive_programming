#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e8 + 7;
const int maxn = 2;

struct Matrix{
    int h, w;
    long long m[maxn][maxn];
};

Matrix MatrixMul(Matrix A, Matrix B){
    Matrix tmp = {A.h, B.w};
    for(int i = 0; i < tmp.h; i++){
        for(int j = 0; j < tmp.w; j++){
            for(int k = 0; k < B.h; k++){
                tmp.m[i][j] = (tmp.m[i][j] + A.m[i][k]%MOD * B.m[k][j]%MOD)%MOD;
            }
        }
    }
    return tmp;
}

Matrix MatrixQPow(Matrix A, int n){
    Matrix r = {A.h, A.w};
    for(int i = 0; i < A.h; i++) r.m[i][i] = 1;
    while(n){
        if(n&1) r = MatrixMul(r, A);
        A = MatrixMul(A,A);
        n >>= 1;
    }
    return r;
}

void solve(Matrix init, int k){
    Matrix base = {2, 2, 1, 1, 1, 0};
    Matrix result = MatrixMul(MatrixQPow(base, k-1), init);
    cout << result.m[0][0] << '\n';
}

int main(){
    int m, f, k;
    while(cin >> m >> f >> k){
        int y0 = m + f;
        int y1 = m + f + f;
        Matrix init = {2, 1, y1, 0, y0, 0};
        solve(init, k);
    }
}
