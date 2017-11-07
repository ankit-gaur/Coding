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
		int n;
		cin>>n;
		int m;
		cin>>m;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		if(n==2){
			cout<<m<<endl;
			continue;
		}
		if(n==3){
			cout<<2*m<<endl;
			continue;
		}
		cout<<(n-1 + 2*(m-1))<<endl;
	}	
	return 0;
}
