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
	int t; 
	cin>>t;
	rep(i,t)
	{
		int n,m,a,b,r;
		cin>>n>>m;
		vpii  map[n+1];
		rep(i,m)
		{
			cin>>a>>b>>r;
			map[a].pb(mp(r,b));
		    map[b].pb(mp(r,a));
		}

        int s; cin>>s;

       bool isVisited[n+1]; fill_n(isVisited,n+1,false);

       vi distance(n+1,MAXN);
       distance[s] = 0;

       vector<int> q;
       q.push(s);
       
       int shortestNode = s,index = 0;

       while(!q.empty())
       {
       	  
       	  int f = shortestNode;
       	  q.erase(q.begin()+index);
       	  fov(i,map[f])
       	  {    int node  = map[f][i].sc;
       	  	   int distanceFromParent  = map[f][i].fs;
              if(isVisited[node])
              {
              	//
              }
              else{
              	 q.push(node);
              	 distance[node] = min(distance[f]+distanceFromParent,distance[node]);
              }
       	  }
           int min = MAXN; 
       	  fov(i,q)
       	  {
              if(distance[i]<min) {
              	index = i; shortestNode = q[i];
              	isVisited[q[i]] = true;
              }
       	  }
       }

       fov(i,distance)
       {
       	 if(i!=0&&i!=s)
       	 {
       	 	 cout<<distance[i]<<" ";
       	 }	
       }     
       el;
	}
	return 0;
}