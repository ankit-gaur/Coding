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
	int t;
	do{
		cin>>t;
		if(t==0) break;
		vi v;
		rep(i,t)
		{
			int x; cin>>x;
            v.pb(x);
		}
		sort(v.begin(),v.end());

        int a,b; LL sum = 0;
		rep(j,t)
		{   a = v[j];
			for(int i = j+1 ; i<v.size(); i++)
			{
				b = v[i];
				int c = a + b;
				int ub = upper_bound(v.begin(),v.end(),c) - v.begin();
				if(ub!=v.size())
                sum+= v.size() - ub;
			}
		}
		cout<<sum; el;

	}while(t!=0);
	return 0;
}