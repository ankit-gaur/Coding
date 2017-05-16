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
  
   int n,m;
   cin>>n>>m;
   if(m>n||m<n-1)
   {
   	 cout<<"unknown topology";
   	 return 0;
   }	
   vi graph[n+1];
   rep(i,m)
   {
   	 int a,b;
   	 cin>>a>>b;
   	 graph[a].pb(b);
   	 graph[b].pb(a);
   }
   
   int adj[n];
   fill_n(adj,n,0);

   forup(i,1,n+1)
   {
       adj[graph[i].size()]++;
   }
   if(adj[2]==n-2&&adj[1]==2&&m==n-1)
   {
      cout<<"bus topology";

   }	
   else if(adj[2] == n && n == m)
   {
   	 cout<<"ring topology";
   }	
   else  if(adj[n-1] == 1 && adj[1] == n-1 && m == n-1)
   {
   	  cout<<"star topology";
   }else{
   	cout<<"unknown topology";
   }

   return 0;
}