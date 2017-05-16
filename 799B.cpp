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
   
   set<int> tshirts[4];
   vi prices;
   
   int n;
   cin>>n;
   rep(i,n)
   {  
   	 int x; cin>>x;
     prices.pb(x);
   }
   rep(i,n)
   {
   	  int c; cin>>c;
   	  tshirts[c].insert(prices[i]);
   }
   rep(i,n)
   {
   	  int c; cin>>c;
   	  tshirts[c].insert(prices[i]);
   }
   int m;
   cin>>m;
   vi favs;
   rep(i,m)
   {
   	 int f; cin>>f;
   	 favs.pb(f);
     
     if(!tshirts[f].empty())
     {
     	 int price  = *tshirts[f].begin();
     	 cout<<price;
     	 rep(i,4)
     	 {
     	 	 if(tshirts[i].count(price)>0)
     	 	 {
     	 	 	tshirts[i].erase(price);
     	 	 }	
     	 }
     	 el;

     }else{
     	cout<<-1; el;
     }

   }
   


   return 0;
}