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
	rep(i,n){
		int x;
		cin>>x;
		v.push_back(x);
	}	
	
	int cgiven = 0;
	int days= 0;
	int sum = 0;
	rep(i,n){
		int take = v[i];
		if(take>8&&i<n-1){
			v[i+1] += take - 8;
		}
		take = min(8,take);
		cgiven += take;
		days++;
		if(cgiven>=k)break;
	}
	if(cgiven>=k)cout<<days;
	else cout<<-1;

	return 0;
}
