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
vi maxset(vector<int> &A) {
    int j = 0, k = 0,temp = 0,maxsum = -1,cursum  = 0;
   
    for(int i = 0; i<A.size(); i++){
        if(A[i]>=0){
        	cout<<A[i];
            cursum+=A[i];
            if(cursum>maxsum){
            	maxsum = cursum;
                j = temp;
                k = i;
                //cout<<"max at "<<j<<" "<<k; el;
            }else if(cursum==maxsum&&maxsum>-1){
                if(k-j<i-temp){
                    j = temp;
                    k = i;
                }
            }
        }else{
            cursum = 0;
            temp = i+1;
        }
    }
    vector<int> v; 
    if(maxsum>=0){
        for(int i = j; i<=k; i++){
            v.push_back(A[i]);
        }
        return v;
    }
    return v;
}
int main(){
		int n;
		cin>>n;
		vi v;
		rep(i,n){
			int x;
			cin>>x;
			v.pb(x);
		}
		vi m = maxset(v);
		fov(i,m)cout<<m[i]<<" ";
}
