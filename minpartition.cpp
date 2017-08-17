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
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	int arr[n];
	int total = 0;
	rep(i,n){
		int x; 
		cin>>x;
		arr[i] = x;
		total+=x;
	}	
    int dp[n+1][total+1];
    for(int i =0; i<n+1; i++)dp[i][0] = 1;
    for(int i = 1;i<total+1;i++)dp[0][i] = 0;
    for(int i = 1; i<n+1; i++){
        for(int s = 1; s<total+1;s++){
            dp[i][s] = dp[i-1][s];
            //to include arr[i-1] in sum it should be less than sum
            if(arr[i-1]<=s){
                dp[i][s]|=dp[i-1][s-arr[i-1]];
            }
        }
    }
    int mins = total;
    for(int i = total/2; i>=0; i--){
        if(dp[n][i]){
            cout<<abs(total-2*i)<<endl;
            break;
        }
    }    
    

    }
    return 0;
}
