#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long int LL;
typedef V<int> vi;
typedef V<LL> vl;
typedef V<pair<int ,int>> vpii;

typedef unordered_map< int, pair< pair<int,int>,pair<int,int> > > umap;

#define rep(i,a) for(int i = 0; i<a ; i++)
#define fov(i,v) rep(i,v.size())
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#define el cout<<endl

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();

int main(){
	int n,m;
	cin>>n>>m;
	int skills[n+1];
	rep(i,n){
		cin>>skills[i+1];
	}	
	umap childs[n+1];
	childs[0].insert(mp(1,mp(mp(1,skills[1]), mp(-1,-1))));
	rep(i,n-1){
		int u,v;
		cin>>u>>v;
		int p;
		int tp;
		if(childs[0].count(u)==0){
			p = v;
			tp = u;
		}
		else{
			p = u;
			tp = v;
		}

		int t = 0;
		int z = 1;
		do{	
			childs[t][].fs.fs += skills[tp];

		}while(childs[t].count(p)>0);
			
	}

	return 0;
}
