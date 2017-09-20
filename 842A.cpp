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
#define sc second1 5 6 10 1
#define mp make_pair
#define pb push_back

#define el cout<<endl

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();

int main(){
	LL l,r,x,y,k;
	cin>>l>>r>>x>>y>>k;
	for(LL i = x;i<=y; i++){
		if(k*i>=l&&k*i<=r){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}
