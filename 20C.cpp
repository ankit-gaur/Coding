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



void dfs(viv v, int a, int n)
{
	 stack< pii >  s;
	 s.push(mp(a,0));
	 bool isVisited[n+1];
     fill_n(isVisited,n+1, false);
     int path[n+1];
     fill_n(path,n+1,0);
     path[0] = a;
	 while(!s.empty())
	 {
         pii p = s.top();
         int node = p.fs;   // n is node;
         int l = p.sc;  // l is level from a the starting point;
         s.pop();
         isVisited[node] = true;
         path[l] = node;
         if(node == n)
         {
         	forup(i,0,n+1)
         	{
         		cout<<path[i]<<" ";
         		if(path[i]==n)
         			break;
         	}
         	return;
         }          


         fov(i,v[node])
         {
         	 int nd = v[node][i];
         	 if(!isVisited[nd])
         	 {
         	 	 s.push(mp(nd,l+1));
         	 }	
         	 
         }    
	 }

	 cout<<"-1";	

}

class Comp
{
	 public :
	     bool operator()(pair< pii, int > p1 , pair< pii, int > p2){
	     	return p1.fs.sc>=p2.fs.sc;
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

   priority_queue< pair< pii, int >  , V< pair< pii, int > > , Comp > pq;

   pq.push(mp(mp(1,0),1)); // 1 has no parent

   viv mst;
   vi x;
   rep(i,n+1) mst.pb(x);

   while(!pq.empty())
   {
   	   pii t = pq.top().fs;
   	   int p = pq.top().sc;
   	   pq.pop();

   	   int sum   = t.sc;
   	   if(isVisited[t.fs])
   	   	continue;
   	   else
   	   isVisited[t.fs] = true;
    
   	  // cout<<t.fs<<" ";

   	   if(t.fs!=p)
   	   {
   	   	 // mst[t.fs].pb(p);
   	   	  mst[p].pb(t.fs);
   	   	 // cout<<p<<" "<<t.fs;
   	   	  
     	   }	

   	   if(t.fs == n)
   	   {
   	   	   //cout<<t.sc; el;
   	   	   break;
   	   }

   	   fov(i,graph[t.fs])
   	   {
   	   	    pii p = graph[t.fs][i];

   	   	    if(!isVisited[p.fs])
   	   	    {
   	   	    	  pq.push(mp(mp(p.fs,t.sc+p.sc),t.fs));
   	   	    }	
   	   }
   }	

/*   rep(i,n+1)
   {
   	  fov(j,mst[i])
   	  {
   	  	 cout<<i<<" "<<mst[i][j]; el;
   	  }

   }*/

   dfs(mst,1,n);

   return 0;
}