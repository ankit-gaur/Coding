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
LL gcdx(LL a, LL b){n
	if(a==0)return b;
	else return gcdx(b%a,a);
}
int main(){
	string s;
	vl countv;
	cin>>s;
	LL i = 0;
	while(i<s.size()){
		char c = s[i];
		LL count = 0;
		while(c==s[i]&&i<s.size()){
			count++;
			i++;
		}
			countv.pb(count);
		}
		LL maxx = countv[0];
		fov(i,countv){
			maxx = max(maxx,countv[i]);
		}
		cout<<maxx;
		return 0;
	}
