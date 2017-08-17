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
	    int dist[n+1];
	    dist[0] = 1;
	    for(int i = 1;i<=n;i++){
	        dist[i] = dist[i-1];
	        if(i>=2)dist[i]+=dist[i-2];
	        if(i>=3)dist[i]+=dist[i-3];
	        
	    }
	    cout<<dist[n]<<endl;
	}
	return 0;
}
