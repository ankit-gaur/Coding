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
const int maxn = 1e9+7;

LL modPow(LL n)
{
	LL x = 2; LL p = maxn;

	LL res = 1;
   
    while(n>0)
    {
    	if(n&1)
    		res = (res*x)%p;

    	n  = n/2;
    	x = (x*x)%p;
    }	
  return (res-1)%p;
}

int main()
{

   string s;
   int n;
  // cin>>n;
  cin>>s;
   //cout<<modPow(n);
   LL ans = 0;
   LL acount = 0;
   fov(i,s)
   {
      if(s[i]=='a')
      	acount++;
      else{
      	ans = (ans + modPow(acount))%maxn;
      }
   }
   cout<<ans;
   return 0;
}