#include<bits/stdc++.h>
using namespace std;

#define V vector

typedef long long int LL;
typedef pair<int, int>  pii;
typedef pair<int, string> pis;

typedef V<int> vi;
typedef V<string> vs;
typedef V<LL> vl;
typedef V<double> vd;
typedef V<pii> vpii;
typedef V<vi> viv;  
typedef V<pis> vpis; //******************************************************************

#define forup(i,a,b) for(int i=(a); i<(b); ++i) 
#define fordn(i,a,b) for(int i=(a); i>(b); --i) 
#define rep(i,a) for(int i=0; i<(a); ++i) 
#define fov(i,a) rep(i,(a).size()) 
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++) 

#define pb push_back


#define fs first
#define sc second

#define el cout<<endl 

#define all(x) (x).begin(), (x).end()  //***************************************************

const int inf = numeric_limits<int>::max(); 
const LL linf = numeric_limits<LL>::max();

const LL nMax  = 1000*1000*1000;
map<LL, int> mp;
vl v;
int main()
{  
	LL n,k,ans = 0;
	cin>>n>>k;
	v.pb(0);
	for(int i = 1; i<=n ; i++){
		int x; cin>>x;
		v.pb(x);
		v[i]+=v[i-1];
		if(mp.count(v[i])>0)mp[v[i]]++;
		else mp[v[i]] = 1;

	}
	//fov(i,v)cout<<v[i]<<" ";
	for(LL i = 1; i<=n; i++){
		if(k==1) ans+=mp[v[i-1]+1];
		else if(k==-1) {
			ans+=mp[v[i-1]+1];
			ans+=mp[v[i-1]-1]; 
		}else for(LL z = 1; z<=1e14; z*=k){
			if(mp.count(v[i-1]+z)>0)ans+=mp[v[i-1]+z];
		}
		mp[v[i]]--;
	}
	cout<<ans;
	return 0;
}