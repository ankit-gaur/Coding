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
int maximumGap(const vector<int> &A) {
    vector<pair<int,int>> v;
    //cout<<1; el;
    for(int i = 0; i<A.size();i++){
    //	cout<<2; el;
        v.push_back(make_pair(A.at(i),i));
    }
    int n = v.size();
    sort(v.begin(),v.end());
    //cout<<3; el;
    int arr[n];  
    int maxj  = v[n-1].second;
    arr[n-1] = maxj;
    for(int i  = n-2; i>=0; i--){
    //	cout<<4; el;
        int j = v[i].second;
        arr[i] = maxj;
        maxj = max(maxj,j);
    }
    int ans = -1;
    for(int i = 0; i<n; i++){
    //	cout<<5; el;
        if(arr[i]-v[i].second>0){
            ans = max(ans,arr[i]-v[i].second);
        }
    }
    return ans;
}
int main(){
	int n;
	cin>>n;
	vi v;
	rep(i,n){
		int x;
		cin>>x; v.pb(x);
	}
	cout<<maximumGap(v);
	return 0;
}
