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
map<int,LL> ans;
LL maxc(vpii &vp,int i){
	if(i<0)return 0;
	LL x = vp[i].fs;
	LL c  = vp[i].sc;
	if(i==0)return x*c;
	//i>=1 now
	if(ans.count(i)!=0)return ans[i];

	LL x2 = vp[i-1].fs;
	if(x-x2==1){
		ans[i] =  max(x*c+maxc(vp,i-2),maxc(vp,i-1));
		return ans[i];
	}else {
		ans[i] = x*c+maxc(vp,i-1);
		return ans[i];
	}
}
int main(){
	int n;
	cin>>n;
	vi v;
	rep(i,n){
		int x; cin>>x;
		v.pb(x);
	}
	sort(v.begin(),v.end());
	vpii vp;
	int i = 0;
	while(i<v.size()){
		int x = v[i];
		int ub = upper_bound(v.begin(),v.end(),x)-v.begin();
		vp.pb(mp(x,ub-i));
		i = ub;
	}
	cout<<maxc(vp,vp.size()-1);
	return 0;
}
