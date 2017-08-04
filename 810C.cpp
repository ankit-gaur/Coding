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
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++) 

#define pb push_back
#define mp make_pair

#define fs first
#define sc second

#define el cout<<endl 

#define all(x) (x).begin(), (x).end()  //***************************************************

const int inf = numeric_limits<int>::max(); 
const LL linf = numeric_limits<LL>::max();

LL prime  = 1000*1000*1000 + 7;

LL fastexp(LL x, LL y){
	 LL res = 1;
	  x = x%prime;
	 while(y>0){
	 	if(y&1) res = (res*x)%prime;
	 	y = y>>1;
	 	x = (x*x)%prime;
	 }
	 return res;
}

int main()
{  
	int n;
	cin>>n;
	vi cords;
	rep(i,n){
		int x; cin>>x;
		cords.pb(x);
	}

	sort(cords.begin(),cords.end());

	LL summax = 0;
	fov(i,cords){
		summax = (summax + (fastexp(2,i)*cords[i])%prime)%prime;
	}
	LL summin = 0;
	fov(i,cords){
		summin = (summin + (fastexp(2,n-i-1)*cords[i])%prime)%prime;
	}
	if(summax<summin)cout<<summax-summin+prime;
	else cout<<summax-summin;

    return 0;
}