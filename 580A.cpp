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
   int cats[n+1];
   rep(i,n)
   {
   	  int x; cin>>x;
   	  if(x==0) cats[i+1] = 0; else cats[i+1] = 1;
   }
   
   bool isVisited[n+1];
   fill_n(isVisited,n+1,false);

   viv tree(n+1);

   rep(i,n-1)
   {
   	   int a,b; 
   	   cin>>a>>b;
   	   tree[a].pb(b);
   	   tree[b].pb(a);
   }

   
   fill_n(cats,n+1,0);

   stack<int> s;

   int count = 0;

   s.push(1);

   while(!s.empty())
   {
   	  int t = s.top();
      s.pop();
      bool hasChild = false;
      fov(i,tree[t])
      {
      	   if(!isVisited[tree[t][i]])
      	   {    
      	   	    hasChild = true;
                s.push(tree[t][i]);
                if(cats[t]!=0&&cats[tree[t][i]]!=0)
                {
                	cats[tree[t][i]] = cats[t]+cats[tree[t][i]];
                }	


      	   }
      }
      if(!hasChild&&cats[t]<=m&&!isVisited[t]) count++; 
      isVisited[t] = true;
   }	

   cout<<count;

   return 0;
}