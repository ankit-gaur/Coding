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
//http://practice.geeksforgeeks.org/problems/subset-sum-problem/0
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
        cin>>n;
        int arr[n];
        int total = 0;
        rep(i,n){cin>>arr[i];total+=arr[i];}
        if(total&1){
            cout<<"NO"<<endl;
            continue;
        }
        bool dp[n+1][total/2+1];
        for(int i = 0; i<=n;i++)dp[i][0]=true;
        for(int i = 1;i<=total/2;i++)dp[0][i] = false;
        for(int i = 1;i<=n;i++){
            for(int j =1; j<=total/2; j++){
                dp[i][j] = dp[i-1][j];
                if(arr[i-1]<=j){
                    dp[i][j]|=dp[i-1][j-arr[i-1]];
                }
            }
        }
        if(dp[n][total/2])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
	}
	return 0;
}