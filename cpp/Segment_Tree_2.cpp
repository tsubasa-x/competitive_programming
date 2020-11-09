#include <bits/stdc++.h>
using namespace std;

int a[maxn], t[4*maxn], laz[4*maxn];

void build(int rt, int l, int r){
	if(l == r){
		t[rt] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(rt<<1, l, mid);
	build(rt<<1|1, mid+1, r);
	t[rt] = t[rt<<1] + t[rt<<1|1];
}
void pushdown(int rt, int l, int r){  //對結點rt向下更新一層
	if(laz[rt] == 0)        //laz[rt]==0直接返回
		return;
	//向下更新
	//令左右子結點加上 laz[rt]*區間的數量
	//令左右子結點的懶標記加上 laz[rt]
	int mid= (l+r)>>1;
	t[rt<<1] += laz[rt]*(mid-l+1);
	laz[rt<<1] += laz[rt];
	t[rt<<1|1] += laz[rt]*(r-mid);
	laz[rt<<1|1] += laz[rt];
	laz[rt]=0;            //懶標記置零
}
void updata(int rt,int l,int r,int a,int b,int c){
	if(a<=l && r<=b){         //當前區間[l,r]∈待更新區間[a,b]
		t[rt] += c*(r-l+1);  //更新當前結點，並加上懶標記
		laz[rt] += c;
		return;	           //返回
	}
	pushdown(rt, l, r);      //因爲還要向下一層遍歷，所有要先更新下一層
	int mid = (l+r)>>1;
	if(b <= mid)             //待更新區間在中點（包括中點）左側 —— 向左遍歷
		updata(rt<<1, l, mid, a, b, c);
	else if(a > mid)         //待更新區間在中點（不包括中點）右側 —— 向右遍歷
			updata(rt<<1|1, mid+1, r, a, b, c);
	else{                   //否則
		updata(rt<<1, l, mid, a, b, c);
		updata(rt<<1|1, mid+1, r, a, b, c);
	}
	t[rt] = t[rt<<1] + t[rt<<1|1];      //不要漏了這條
}
int query(int rt, int l, int r, int ql, int qr){
	if(ql<=l && r<=qr)     //當前區間[l,r]∈待查詢區間[ql,qr]
		return t[rt];
	if(r<ql || l>qr)       //區間無重合
		return 0;
	//區間部分重合
	pushdown(rt, l, r);    //先向下更新
	int mid = (l+r)>>1;
	return query(rt<<1, l, mid, ql, qr) + query(rt<<1|1, mid+1, r, ql, qr);
}

int main(){

}
