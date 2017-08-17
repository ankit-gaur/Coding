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

int lcs[101][101];

void track(stack<int> &s, vi &a, vi &b, int m, int n)
{
	if(m<1||n<1) return;

	if(a[m-1]==b[n-1])
	{
		s.push(a[m-1]);
		track(s,a,b,m-1,n-1);
	}	
	else if(lcs[m][n-1]>lcs[m-1][n])
	{
          track(s,a,b,m,n-1);
	}else{
           track(s,a,b,m-1,n);
	}
}
int main()
{
  
   int n,m;
   cin>>n;
   cin>>m;
   vi a,b;

   rep(i,n)
   { int x; cin>>x;
   	  a.pb(x);
   }

   rep(i,m)
   {
   	  int y; 
   	  cin>>y;
   	  b.pb(y);
   }
    
   
   rep(i,n+1) lcs[i][0] = 0;
   rep(i,m+1) lcs[0][i] = 0;

   for(int i = 1; i<n+1; i++)
   	for(int j = 1; j<m+1; j++)
   	{

   		if(a[i-1]==b[j-1])
   		{
            lcs[i][j] = lcs[i-1][j-1] + 1;  
   		}else{
   			lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
   		}
          
   	}
   stack<int> s;
   
   track(s,a,b,n,m);
   
   rep(i,lcs[n][m])
   {
   	 cout<<s.top()<<" "; s.pop();
   }
   

   return 0;
}