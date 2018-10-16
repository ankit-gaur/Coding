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

vpii graph;
stack<int> route;
int n;

int maxNodes(int start, int time)
{
   
   if(start==n)
      return 1;

   if(time<0)
      return 0;


   int maxnodes = 0;
   int nodei = -1;

   fov(i,graph[start])
   { 
      pii p  = graph[start][i];
      int node = p.fs;
      int t = p.sc;
      int leftTime = time - t;
      if(leftTime>0)
      {
         int nodes = maxNodes(node,leftTime);
         if(nodes>maxnodes){
            maxnodes = nodes;
            nodei = i;
         }

      }   
   }

   if(nodei!=-1)
   {
      route.push(nodei);
      return maxnodes + 1;
   }

   return 0;

}

int main()
{
    
   int N,m,T;
   cin>>N>>m>>T;
   el;
   rep(i,m)
   {
       int a,b,ti;
       cin>>a>>b>>ti;
       graph[a].pb(mp(b,ti));
       cout<<a<<" "<<b<<" "<<ti; el;
   }

   cout<<N<<" "<<m<<" "<<T; 
   el;

  n = N;
   rep(i,N+1)
   { 
      cout<<i<<" -->";
     fov(j,graph[i])
     { 
       cout<<graph[i][j].fs<<" ";
     }
     el;
   }
   cout<<graph[4].size();
   cout<<maxNodes(1,T)<<endl;
   return 0;
}
