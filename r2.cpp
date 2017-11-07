#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long int LL;
typedef V<int> vi;
typedef V<LL> vl;
typedef V<pair<int ,int>> vpii;

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
		long double n,k;
		cin>>n>>k;
		long double ans = 2 + (1 - (1/k))*(long double)2*(n-1);
		cout<<fixed<<setprecision(10)<<ans<<endl;
	}	
	return 0;
}
