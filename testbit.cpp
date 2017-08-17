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
int cntBits(vector<int> &B) {
    long long int p = 1000*1000*1000+7;
     long long int ans = 0;
     vi A = B;
    for(int i =0; i<31; i++){
         long long int cnt1 = 0;
        for(int j = 0; j<A.size(); j++){
            if(A[j]&1)cnt1++;
            A[j] = A[j]>>1;
        }
       // cout<<cnt1<<endl;
        ans += (((2*cnt1)%p)*(A.size()-cnt1)%p)%p; 
    }
    return ans;
}
int main(){
	int n;
	cin>>n;
	vi v; 
	while(n--){
		int x; cin>>x;
		v.push_back(x);
	}
	cout<<cntBits(v);
}
