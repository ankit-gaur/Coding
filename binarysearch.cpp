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

bool binarySearch(vector<int> v, int value)
{
	int l= 0;
	int h = v.size()-1;
	while(l<=h)
	{
		int mid = (l+h)/2;
		if(v[mid]==value)
			return true;
		else if(v[mid]<value)
		{
			l = mid+1;
		}else {
			h = mid-1;
		}
	}
	return false;	
}
int main()
{
	int n; cin>>n;
	vi v;

	rep(i,n)
	{ int x; cin>>x; 
		v.pb(x);
	}
	sort(v.begin(),v.end());
	cout<<"Enter number of checks\n";
	int m; cin>>m;
	vi ch;
	rep(i,m)
	{
		int c; 
		cin>>c;
		ch.pb(c);
	}
	fov(i,ch)
	if(binarySearch(v,ch[i]))
	{
		cout<<ch[i]<<" exits"; el;
	}
	else{
		cout<<ch[i]<<" doesnt exits"; el;
	}
} 