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
   
   int n;
   cin>>n;
   vi v;
   rep(i,n)
   {
   	 int x; cin>>x;
   	 v.pb(x);
   } 
   
   int lis[n]; //lis(i) is the length of longest increasing subsequence of v(0,i) end at v[i];
   lis[0] = 1;

   for(int i = 1; i<n; i++)
   { 
   	 int max = 0;
   	 for(int j =0; j<i; j++)
   	 {
         if(v[i]>v[j]&&max<lis[j]) max = lis[j];
   	 }	

   	 lis[i] = 1 + max;
   }	
   
   //rep(i,n) cout<<lis[i]<<endl;
   sort(lis,lis+n);


   cout<<lis[n-1];


   return 0;
}