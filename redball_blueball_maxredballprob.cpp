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
	double maxn = 0.0,x = 0,y=0;
	rep(i,51){
		rep(j,51){
			double z = ((double)i)/(i+j) + ((double)(50-i))/(100-i-j);
			if(z>maxn){
				maxn = z;
				x = i; y = j;
			}
		}
	}
	cout<<x<<" "<<y<<" "<<maxn;
	return 0;
}
