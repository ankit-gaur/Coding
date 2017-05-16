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

int main()
{
	vi va,vb,vc,vd;
	int n; cin>>n;
	rep(i,n)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
        va.pb(a);
        vb.pb(b);
        vc.pb(c);
        vd.pb(d);
	}
	vi lhs,rhs;

	int a,b,c,d;
	fov(i,va)
	{    
		a = va[i];
		b = vb[i];

        fov(i,va)
        {
        	c = vc[i];
        	d = vd[i];
             
             lhs.pb(a+c);
             rhs.pb(-(b+d));
        }
	}
	sort(rhs.begin(),rhs.end());
	int count = 0;
	fov(i,lhs)
	{
		if(binary_search(rhs.begin(),rhs.end(),lhs[i])){        
          int lb = lower_bound(rhs.begin(),rhs.end(),lhs[i]) - rhs.begin();
          int ub = upper_bound(rhs.begin(),rhs.end(),lhs[i])- rhs.begin();
          count+= ub-lb;
        }
	}
	cout<<count;
	return 0;
}
