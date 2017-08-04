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
  
   LL n,l,r;
   cin>>n>>l>>r;
   
   vector< LL > v;
   
   v.pb(n);
    
   LL ptr = 0; LL size = 1;

   LL left = 0;

   while(ptr <= r+1)
   {   
   	  LL x  = v[ptr];
   	  if(x>1)
   	  {  
          v[ptr] = x%2;
          if(left<l&&)
          v.insert(v.begin()+ptr+1,x/2);
          v.insert(v.begin()+ptr,x/2);
          size = size + 2;
   	  }
      
   }	
   
   LL count = 0;

   for(LL i = 0 ; i <= r-l; i++)
   { 
   	 if(v[i]==1) count++; 
   }
   cout<<count;
  /* el;
   rep(i,size)
   { 
     cout<<v[i]<<" ";
   }	*/
   return 0;
}