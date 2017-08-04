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
	int n,k;
	cin>>n>>k;
	vi v;
	int minsum  = inf, ksum = 0;
	rep(i,n){
		int x; cin>>x; 
		v.pb(x);
	}	
	rep(i,k){
		ksum+=v[i];
	}
	minsum = ksum;
	int j = k-1;
	for(int i = k; i<n; i++){
		ksum = ksum - v[i-k] + v[i];
		if(ksum<minsum){
			minsum = ksum;
			j = i;
		}
	}
	cout<<j-k+2;
	return 0;
}
