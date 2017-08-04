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
#define mp make_pair

#define fs first
#define sc second

#define el cout<<endl 

#define all(x) (x).begin(), (x).end()  //***************************************************

const int inf = numeric_limits<int>::max(); 
const LL linf = numeric_limits<LL>::max();

int main()
{  
	int n,m;
	vi newtoys;
	map<int,int> mp;
	cin>>n>>m;
	rep(i,n){
		int x; cin>>x;
		mp[x] = 1;
	}
	int i = 1; 
	while(m>=i&&i<=1e9){
		if(mp.count(i)==0){
			newtoys.pb(i);
			m = m - i;
		}
		i++;
	}
	cout<<newtoys.size(); el;
	fov(i,newtoys){
		cout<<newtoys[i]<<" ";
	}
	return 0;
}