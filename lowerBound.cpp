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

int lowerBnd(vi &v,int l,int r,int key){
	bool found =  false;
	if(l==r){
		if(v[l]>=key)return l;
	}
	while(l<r){
		int mid = l + (r-l)/2;
		if(mid<key){
			l = mid;
		}else{
			r=midf;
			found = true;
		} 
	}
	if(found)return l;
	return r+1;
}

int main(){
	int n;
	cin>>n;
	vi v;
	rep(i,n){
		int x; cin>>x;
		v.pb(x);
	}	
	fov(i,v){
		int x = lowerBnd(v,0,n-1,v[i]);
		int y = lower_bound(v.begin(),v.end(),v[i])-v.begin();
	if(x==y){
		cout<<"equal"<<endl;
	}else{
		 cout<<x<<" "<<y;
		cout<<"not equal"<<endl;
	}
}
	return 0;
}
