#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long int LL;
typedef V<int> vi;
typedef V<LL> vl;
typedef V<pair<int ,int>> vpii; 

#define rep(i,a) for(int i = 0; i<a ; i++)
#define fov(i,v) rep(i,v.size())
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#define el cout<<endl

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();
LL n,cl,cr,ql,qr;
vl vw;

LL minCostUtil(int l,int r, int d){
	
	if(l>=r){
		if(d==0)return min(ql+vw[l]*l,vw[l]*r);
		else return min(qr+vw[l]*r,vw[l]*l);
	}
	LL costL = vw[l];
	LL costR = vw[r];
	if(d==0)
	return min(costL*cl+ql+minCostUtil(l+1,r,0),costR*cr+minCostUtil(l,r-1,1));
	else return min(costL*cl+minCostUtil(l+1,r,0),costR*cr+qr+minCostUtil(l,r-1,1));
}
LL minCost(){
	LL costL = vw[0];
	LL costR = vw[n-1];
	return min(costL*cl+minCostUtil(1,n-1,0),costR*cr+minCostUtil(0,n-2,1));
}
int main(){
	
	cin>>n>>cl>>cr>>ql>>qr;
	
	rep(i,n){
		LL w; cin>>w;
		vw.pb(w);
	}
	cout<<minCost();
	return 0;
	 
}
