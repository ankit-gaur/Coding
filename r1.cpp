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
		int n,sgm;
		cin>>n>>sgm;
		if(n%2==0){
			for(int i = 1; i<=n; i++){
				if(i%2==1)cout<<sgm<<" ";
				else cout<<-1*sgm<<" ";
			}
		}else{
			if(n==1){
				cout<<-1<<endl;
				continue;
			}
			for(int i = 1; i<=n-3; i++){
				if(i%2==1)cout<<sgm<<" ";
				else cout<<-1*sgm<<" ";
			}
			double sq2 = sqrt(2);
			double k = sgm/sq2;
			cout<<setprecision(10)<<k<<" ";
			cout<<setprecision(10)<<-1*2*k<<" ";
			cout<<setprecision(10)<<k<<" ";
		}
		cout<<endl;
	}	
	return 0;
}
