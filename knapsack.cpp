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

bool comp(pii p1, pii p2)
{
	 if(p1.fs==p2.fs)
	 {
	 	 return p1.sc>p2.sc;
	 }
	 else return p1.fs<p2.fs;	
}

int main()
{
   int s,n;

   cin>>s>>n;

   V< pii > items;
   rep(i,n)
   { 
   	  int size,value;
   	  cin>>size>>value;
   	  items.pb(mp(size,value));
   }
   
    
   int dp[n+1][s+1];
   
   rep(i,n+1) dp[i][0] = 0;
   rep(i,s+1) dp[0][i] = 0;

   for(int i = 1; i<n+1 ; i++)
   {
   	  for(int j = 1; j<s+1; j++)
   	  {  
   	  	  if(j<items[i-1].fs) dp[i][j] = dp[i-1][j];
   	  	  else
   	  	  dp[i][j] = max(dp[i-1][j],items[i-1].sc+dp[i-1][j-items[i-1].fs]);
   	  }	
   } 

   cout<<dp[n][s];

   return 0;
}