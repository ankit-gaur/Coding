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

LL ways[101];
LL waysd[101];
LL k,d;
LL moder = 1000*1000*1000+7;

LL paths(LL n)
{
	if(n<=0) return 0;

	LL numpath = 0;

	forup(i,1,k+1)
	{
		if(n==i) //neeche index  positive hi rahegi
		{
			numpath++;
			numpath = numpath%moder;
			break;
		}
		
		if(ways[n-i]!=-1)
		{
			numpath = (numpath%moder +  ways[n-i]%moder)%moder;
		}
		else 
		{
			LL x = paths(n-i);
			ways[n-i] = x%moder;
			numpath = (numpath%moder +  x%moder)%moder;
			
		}	
	}

	return numpath%moder;

}

LL alllessdpath(LL n)
{
if(n<=0) return 0;

	LL numpath = 0;

	forup(i,1,d)
	{
		if(n==i) //neeche index  positive hi rahegi
		{
			numpath++;
			numpath = numpath%moder;
			break;
		}
	
		if(waysd[n-i]!=-1)
		{
			numpath = (numpath%moder +  waysd[n-i]%moder)%moder;
		}
		else 
		{
			LL x = alllessdpath(n-i);
			waysd[n-i] = x%moder;
			numpath = (numpath%moder +  x%moder)%moder;
		}	
	}

	return numpath%moder;
}

int main()
{
	fill_n(ways,101,-1);
	LL n;
	fill_n(waysd,101,-1);
	cin>>n>>k>>d;
	
    LL ans = paths(n)-alllessdpath(n);

	if(ans<0)
    cout<<ans+moder;
    else
	cout<<ans;
	return 0;
}