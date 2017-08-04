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
LL csum = linf;
LL s;
bool check(V<LL> v, LL k){
	V<LL> t; 
	rep(i,v.size()){
	LL x = v[i]+k*(i+1);// 1 indexed 
	t.pb(x);
	}
	sort(t.begin(),t.end());
	LL sum = 0;
	for(int i =0; i<k; i++){
		sum+= t[i];
	}
	if(sum<=s) csum = sum;
	return sum<=s;
}
int main()
{  
 int n;
 cin>>n>>s;
 V<LL> v;
 rep(i,n){
 	int x; cin>>x;
 	v.pb(x);
 }  
 int l = 0, r = n, k;
 int ans = 0;
 while(l<=r){
 	k = l + (r-l)/2;
 	if(check(v,k)){//feasible shift left index
 		l = k+1;
 		ans = k;
 	}else{//not feasible shift right index
 	    r = k-1;
 	}
 }
 cout<<ans<<" "<<csum; 
}