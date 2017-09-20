#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long int LL;
typedef V<int> vi;
typedef V<LL> vl;
typedef V<pair<int ,int>> vpii;
typedef pair<int,int> pii;

#define rep(i,a) for(int i = 0; i<a ; i++)
#define fov(i,v) rep(i,v.size())
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#define el cout<<endl

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();
bool comp(pii p1, pii p2){
	if(p1.sc!=p2.sc)return p1.sc<p2.sc;
	else return p1.fs<p2.fs;
}
int main(){
	int n,q;
	cin>>n>>q;
	vpii v;
	vi time;
	rep(i,n){
		int t; 
		cin>>t; time.push_back(t);
	}	
	rep(i,n){
		int p;
		cin>>p; 
		v.push_back(mp(time[i],p));
	}
	vpii x = v;
	vi maxv(n);
	int mx = 0;
	for(int i = n-1;i>=0; i--){
		mx = max(mx,v[i].sc);
		maxv[i] = mx;
	}
	vi temp(n);
	int mn = 0;
	rep(i,n){
		mn = max(mn,v[i].sc);
		temp[i] = mn;
	}
	rep(i,q){
		int q; cin>>q;
		if(q==1){
			int val; cin>>val;
			int ub = lower_bound(temp.begin(),temp.end(),val) - temp.begin();
			if(ub==n)cout<<-1<<endl;
			else cout<<time[ub]<<endl;
		}else{
			int val; cin>>val;
			int lb = lower_bound(time.begin(),time.end(),val) - time.begin();
			if(lb==n)cout<<-1<<endl;
			else cout<<maxv[lb]<<endl;
		}
	}
	return 0;
}
