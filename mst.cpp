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
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)  //???????????????????????????????

#define pb push_back
#define mp make_pair

#define fs first
#define sc second

#define el cout<<endl 

#define all(x) (x).begin(), (x).end()  //***************************************************

const int inf = numeric_limits<int>::max(); 
const LL linf = numeric_limits<LL>::max(); 
const double EPS = 1e-7;  
const int MAXN = 10000001; 
const int LOGMAXN = log2(MAXN) + 3;

bool sortfunc(pii a, pii b)
{
   return a.sc<b.sc;
}

int main()
{
	int n,m;
	cin>>n>>m;
    
    vpii map[n+1];
    bool isVisited[n+1];
    fill_n(isVisited,n+1,false);
	rep(i,m)
	{
		int a,b,r;
		cin>>a>>b>>r;
		map[a].pb(mp(b,r));
		map[b].pb(mp(a,r));
	}
      
    int s; cin>>s;
    
    rep(i,n+1)
    {
    	sort(map[i].begin(),map[i].end(),sortfunc);
    }

    queue<int> q;
    
    q.pb(s);

	return 0;
}