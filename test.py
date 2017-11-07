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
	as[0] = 0;
	for(int i = 0; i<n; i++){
		if(s[i]=='a')
			as[i+1] = as[i] + 1;
		else as[i+1] = as[i];	
	}	
	as[n+1] = as[n];
	for(int i = 0; i<=n+1; i++){
		cout<<as[i]<<" ";
	}
	cout<<endl;
	return 0;
}
