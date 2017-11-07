#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long int LL;
typedef V<int> vi;
typedef V<LL> vl;
typedef V<pair<int ,int>> vpii;
#define all(v) v.rbegin(),v.rend()
#define rep(i,a) for(int i = 0; i<a ; i++)
#define fov(i,v) rep(i,v.size())
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#define el cout<<endl

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		LL A[n];
		LL B[n];
		rep(i,n){
			cin>>A[i];
		}
		rep(i,n){
			cin>>B[i];
		}
		LL Bmin = linf;
		LL Amin = 0;
		LL fans = 0;
		rep(i,n){
			A[i] = A[i]%B[i];
		}
		rep(i,n){
			if(Bmin>=B[i]){
				Bmin = B[i];
			}
		}
		rep(i,n){
			if(A[i]>=Bmin){
				fans+= B[i] - A[i];
				A[i] = 0;
			}
		}
		LL sum = 0;
		rep(i,n) sum+= A[i];
		vpii v;
		rep(i,n){
			v.pb(mp(A[i],B[i]));
		}
		sort(all(v));
		LL ans = linf;
		LL tcost = 0;
		LL pa = 0;
		for(int i =0;i<n; i++){
			int ta = v[i].fs;
			int tb = v[i].sc;
			ans = min(ans,tcost + n*ta - sum );
			sum = sum - ta;
			tcost += tb - ta;
			pa = ta;
			if(ta==0)break;
		}
		cout<<ans+fans<<endl;
	}	
	return 0;
}
