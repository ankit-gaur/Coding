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

class Comp
{
	 public :
	     bool operator()(pii p1, pii p2){
	     	return p1.sc<=p2.sc;
	     }  
};

int main()
{
   int n,m;
   cin>>n>>m;
   V< V < pii > > graph;
   
   V < pii > v;

   bool isVisited[n+1];
   fill_n(isVisited,n+1,false);

   rep(i,n+1)
   graph.pb(v);

   rep(i,m)
   {
   	   int a,b, c;
   	   cin>>a>>b>>c;
   	   graph[a].pb(mp(b,c));
   	   graph[b].pb(mp(a,c));
   }

   priority_queue< pii , V< pii > , Comp > pq;

   pq.push(mp(1,0));

   while(!pq.empty())
   {
   	   pii t = pq.top();
   	   pq.pop();

   	   int sum   = t.sc;
   	   isVisited[t.fs] = true;

   	   if(t.fs == n)
   	   {
   	   	   cout<<t.sc;
   	   	   break;
   	   }

   	   fov(i,graph[t.fs])
   	   {
   	   	    pii p = graph[t.fs][i];

   	   	    if(!isVisited[p.fs])
   	   	    {
   	   	    	  pq.push(p.fs,t.sc+p.sc);
   	   	    }	
   	   }
   }	

   return 0;
}