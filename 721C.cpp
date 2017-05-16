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

vpii graph[5001];
int n;
int route[5001];
int maxnodes = 0;
int T;

int dfs()
{
  stack< pair<pii, int> > s;
  s.push(mp(mp(1,0),1));
  
  while(!s.empty())
  {
      pair< pii ,int >  pi = s.top(); 
      s.pop();
      pii p = pi.fs;
      int l  = pi.sc;
      int parent = p.fs;
      int time = p.sc;
      if(parent == n && time<=T && maxnodes<l)
      {
          maxnodes = l;
          continue;
      }  
      fov(i,graph[parent])
      {
         pii p = graph[parent][i];

         int node = p.fs;
         int t = p.sc;
         s.push(mp(mp(node,time+t),l+1));
      }
  }  

}

int maxNodes(int start, int time)
{
 if(start==n)
  return 1;

int maxnodes = 0;
fov(i,graph[start])
{ 
  pii p  = graph[start][i];
  int node = p.fs;
  int t = p.sc;
  int leftTime = time - t;
  if(leftTime>=0)
  {  
   int nodes;

     nodes = maxNodes(node,leftTime);

   if(nodes>maxnodes){
    maxnodes = nodes;
  }
}
}


if(maxnodes!=0)
{    
  return maxnodes + 1;
}
return 0;

}

void fill_level(int levels)
{
   
   stack< pair<int, int> > s;
   s.push(mp(1,1));

   while(!s.empty())
   {
      pii p = s.top(); //no cycle in graph so no need for look up table
      s.pop();
      int parent = p.fs;
      int level = p.sc;
      route[level] = parent;
      if(parent == n && level == levels)
      {
         break;
      }  
      fov(i,graph[parent])
      {
         int node = graph[parent][i].fs;
         s.push(mp(node,level+1));
      }
   } 

}

int main()
{

 int m;
 cin>>n>>m>>T;

 fill_n(route,5001,0);

 rep(i,m)
 {
   int a,b,ti;
   cin>>a>>b>>ti;
   graph[a].pb(mp(b,ti));
      // cout<<a<<" "<<b<<" "<<ti; el;
 }

 dfs();
 route[1] = 1;
 int j = maxnodes;
 cout<<j;
 el;
 fill_level(j);
 
 rep(i,j)
 {
   cout<<route[i+1]<<" ";
 }
 
 return 0;
}