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
   int n; 
   cin>>n;
   vi v;
   rep(i,n){
 	int x;
 	cin>>x;
 	v.pb(x);
   } 
   int ctf=0, cf=0;
   fov(i,v){
   	if(v[i]==25){
   		ctf++;
   	}
   	if(v[i]==50){
   		cf++;
   		if(ctf>0){
   			ctf--;
   		}else{
   			cout<<"NO";
   			return 0;
   		}
   	}
   	if(v[i]==100){
   		if(cf>0&&ctf>0){
   			cf--; ctf--;
   		}else if(ctf>2){
   			ctf -=3;
   		}else if(ctf<=2){
   			cout<<"NO";
   			return 0;
   		}
   	}
   } 
   cout<<"YES";
   return 0;
}