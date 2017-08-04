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

const LL nMax  = 1000*1000*1000;
int main()
{  
	LL n,k; cin>>n>>k;
	vl v;
	rep(i,n){
		LL x; cin>>x;
		v.pb(x);
	}
	sort(v.begin(),v.end());

	int count = 0;

	for(int i = 0; i<v.size()-2; i++){
		LL a = v[i];
		if(a*k<=nMax)
		{
			if(a*k*k<=nMax)
			{
				if(binary_search(v.begin()+i+1,v.end(),a*k)&&binary_search(v.begin()+i+1,v.end(),a*k*k)){
					int cf = (upper_bound(v.begin()+i+1,v.end(),a*k)-v.begin()) - (lower_bound(v.begin()+i+1,v.end(),a*k)-v.begin());
					int cs =  (upper_bound(v.begin()+i+2,v.end(),a*k*k)-v.begin()) - (lower_bound(v.begin()+i+2,v.end(),a*k*k)-v.begin());
					if(k!=1)
						count+=cf*cs;
					else count+= (cf*(cf-1)/2);
				}
			}
		}
	}
	cout<<count;
    return 0;
}