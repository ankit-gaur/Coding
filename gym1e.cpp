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
	// freopen("express.in","r",stdin);
	// freopen("express.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	LL a = n - 2 + 1,a1 = n-2-1;
	LL k = 2,k1 = 0;
	LL f = (a*(a-1))/2;
	LL s = 1;
	LL ss = 1;
	LL fs = f%m;
	while(k<(n+1)/2&&a!=0&&a1!=0&&k!=0&&k1!=0){
		LL t = (f*(a-k)*(a-k-1))/(a*k);
		f = t%m;
		fs = (fs%m + t%m)%m;
		LL t1 = (s*(a1-k1)*(a1-k1-1))/(a1*k1);
		s = t1%m;
		ss = (ss%m + t1%m)%m;
		k1++;
		a1--;
		k++;
		a--;
	}
	cout<<(fs-ss+m)%m;
	return 0;
}	

