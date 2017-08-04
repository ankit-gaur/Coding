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

vl v;
vl cumsum;
int n,m,k;
bool isPresent[5001];
int previous[5001];
LL minimal(int n, int k){

	if(k==0){ 
		return 0;
	}
	if(n<=0) return -1; 
	int l1 = previous[n];
	if(l1==-1)return -1;
	int r1 = l1+m-1;
	LL sum = cumsum[r1] - cumsum[l1-1];
	LL sum1 = minimal(l1-1,k-1);
	LL sum2 = minimal(l1-1,k);
	//cout<<n<<" "<<k<<" "<< l1<<" "<<r1<<" "<<sum1<< " "<<sum2<<" "<<sum<<endl;
	if(sum1==-1&&sum2==-1) return -1;
	if(sum1==-1)return sum2;
	if(sum2==-1)return sum1+sum;
	return max(sum1+sum,sum2);
}

int main(){
	
	cin>>n>>m>>k;
	fill_n(isPresent,5001,false);
	
	rep(i,n){
		LL x;
		cin>>x;
		if(x<=5000)isPresent[x] = true;
		v.pb(x);
	}
	cumsum.pb(0);
	for(int i = 0; i<n; i++) cumsum.pb(cumsum[i]+v[i]);

		int count = 0;
	for(int i = 1; i<=n;i++){

		if(i+m-1<=n&&isPresent[i]&&isPresent[i+m-1]){
			previous[i] = i;
			count++;
		}else{
			if(count>0){
				previous[i] = previous[i-1];
			}else{
				previous[i] = -1;
			}
		}
	}	
	cout<<minimal(n,k);	
	return 0;
}
