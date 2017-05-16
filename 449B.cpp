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
	    bool operator()(pii p1, pii p2)
	    {
	    	return p1.sc>p2.sc;
	    }
};

int main()
{
   int n,m,k;
   cin>>n>>m>>k;
   vpii graph[n+1];
   
   priority_queue< pii , vpii, Comp> trs;

   rep(i,m)
   { 
   	  int a,b, x;
   	  cin>>a>>b>>x;
   	  graph[a].pb(mp(b,x));
   	  graph[b].pb(mp(a,x));
   }

   rep(i,k)
   {
   	  int s,y;
   	  cin>>s>>y;
   	  trs.push(mp(s,y));
   }

   int isTaken[n+1];
   fill_n(isTaken,n+1,false);

   priority_queue< pii, vpii, Comp > roads;

   roads.push(mp(1,0));

   vpii reds;

   while(!roads.empty()||!trs.empty())
   {
       pii p1, p2,p;
       if(trs.empty())
       {
       	  cout<<reds.size(); return 0;
       }
       if(!roads.empty())
       {

       	  p1 = roads.top();
       	  p2 = trs.top();
          
         // cout<<p1.fs<<" "<<p1.sc<<" | "<<p2.fs<<" "<<p2.sc; el;

          if(p1.sc<=p2.sc)
          {
          	 p = p1;
          	 roads.pop();
          }else{
          	p = p2;
          	trs.pop();
          	if(isTaken[p.fs]) reds.pb(p);
          }	
       }else{
            p = trs.top();
            trs.pop();
            if(isTaken[p.fs]) reds.pb(p);
       }
      
      int parent = p.fs;
      int lenp = p.sc;

      if(isTaken[parent])
      {
      	continue;
      }else{
      	isTaken[parent] = true;
      }

      fov(i,graph[parent])
      {
      	 pii p = graph[parent][i];
      	 int node = p.fs;
      	 int len = p.sc;
      	 if(!isTaken[node])
      	 {
      	 	roads.push(mp(node,len+lenp));
      	 }	
      }

   }

   cout<<reds.size();	
   
   return 0;
}