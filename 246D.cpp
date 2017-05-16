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
   int color[n+1];
   forup(i,1,n+1)
   {
      int a; 
      cin>>a;
      color[i] = a;  
   }

   viv mymap;
   vi temp;
   rep(i,n+1) mymap.pb(temp);
  // cout<<n<<" "<<m; el;
   rep(i,m)
   {
   	   int x,y;
   	   cin>>x>>y;
   	   mymap[x].pb(y);
   	   mymap[y].pb(x);
   }
  
   //cout<<"reached";

   set<int> adjColors[100001];

   forup(i,1,n+1)
   {
   	  vi v = mymap[i];
      int col = color[i];
     // cout<<col;
      adjColors[col].insert(col);
      fov(j,v)
      {
      	 adjColors[col].insert(color[v[j]]);
      }
   }

  int maxindex = 0; 
  int max = 0;
   forup(i,1,n+1)
   { 
   	 // cout<<"color"<<color[i]<<" : "<<adjColors[color[i]].size()-1; el;
   	  if(adjColors[color[i]].size()>max) 
   	  {
   	  	max = adjColors[color[i]].size();
   	  	//if(color[i]<color[maxindex]) maxindex = i;

   	  	maxindex = i;

   	  }
   	  if(adjColors[color[i]].size()==max)
   	  {
   	  	 if(color[i]<color[maxindex]) maxindex = i;
   	  }	
   }

   //cout<<maxindex; el;

   cout<< color[maxindex];
   
   return 0;
}