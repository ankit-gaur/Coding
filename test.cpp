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
	string s;
	cin>>s;
	int n = s.size();
	int as[n+2];
	int bs[n+2];
	as[0] = 0;
	bs[0] = 0;
	for(int i = 0; i<n; i++){
		if(s[i]=='a')
			as[i+1] = as[i] + 1;
		else as[i+1] = as[i];
		if(s[i]=='b'){
			bs[i+1] = bs[i]+1;
		}else bs[i+1] = bs[i];	
	}	
	as[n+1] = as[n];
	bs[n+1] = bs[n];
	/*for(int i = 0; i<=n+1; i++){
		cout<<bs[i]<<" ";
	}
	cout<<endl;*/
	int maxl = 0;
	for(int i = 0; i<=n; i++){
		for(int j = n; j>=i; j--){
			int alen = as[i] + as[n+1] - as[j];
			int blen = bs[j] - bs[i];
			int l = alen + blen;
			if(maxl<l)maxl = l;
			//cout<<l<<endl;
		}
	}
	cout<<maxl;
	return 0;
}
