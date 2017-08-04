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
   LL t,k;
   cin>>t>>k;
   LL maxB = 100*1000;
   LL p = 1000*1000*1000+7;
   LL arr[maxB+1];
   for(int i = 0; i<k; i++){arr[i] = 1;}
   for(int i = k; i<=maxB; i++){
      arr[i] = (arr[i-1] + arr[i-k])%p;
   }
   LL cumsum[maxB];
   rep(i,maxB+1){
      if(i!=0)cumsum[i] = (cumsum[i-1]+arr[i])%p;
      else cumsum[i] = 0;
   }
   rep(i,t){
      int a,b;
      cin>>a>>b;
      if(cumsum[b]>=cumsum[a-1])cout<<cumsum[b]-cumsum[a-1]<<endl; 
      else cout<<cumsum[b]+p-cumsum[a-1]<<endl;
   }
   return 0;
}