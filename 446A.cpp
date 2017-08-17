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
	int n;
	cin>>n;
	int l=0,m=0,r=0,maxlen=1;
	int p = 0;
	bool isused = false;
	rep(i,n){
		int x;
		cin>>x;	
		if(x<=p){
			if(!isused){
				m = i;
				isused = true;
			}else{
				int len = r-l;
				maxlen = max(len,maxlen);
				l = m+1;
				m = i;
			} 
			x = p+1;
		}
		r++;
		p = x;

	}
	cout<<maxlen;
	return 0;
}
