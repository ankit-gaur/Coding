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
	int arr[n];
	rep(i,n){
		cin>>arr[i];
	}
	if(n==2){
		cout<<arr[1]-arr[0]+arr[1];
		return 0;
	}
	bool isAp = true;
	int d = arr[1] - arr[0];
	for(int i = 2;i<n; i++){
		if(arr[i]!=arr[i-1]+d){
			isAp = false;
			break;
		}
	}
	if(d==0)isAp  = false;
	if(isAp)cout<<arr[n-1]+d;
	else cout<<arr[n-1];
	return 0;
}
