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
//http://practice.geeksforgeeks.org/problems/path-in-matrix/0
int n;
int calc(int i, int j, int mat[][20], int path[][20]){
    int a = 0,b,c = 0;
    if(i==n-1){
        return mat[i][j];
    }
    
    if(path[i+1][j]==mat[i+1][j]){
        path[i+1][j] = calc(i+1,j,mat,path);
    }
    b = path[i+1][j];
    if(j!=0){
        if(path[i+1][j-1]==mat[i+1][j-1])path[i+1][j-1] = calc(i+1,j-1,mat,path);
        a = path[i+1][j-1];
    }
    if(j!=n-1){
        if(path[i+1][j+1]==mat[i+1][j+1])path[i+1][j+1] = calc(i+1,j+1,mat,path);
        c = path[i+1][j+1];
    }
    return mat[i][j] + max(a,max(b,c)); 
}


int main(){
	int t;
	cin>>t;
	while(t--){
	    cin>>n;
	    int mat[n][20];
	    int path[n][20];
	    rep(i,n){
	        rep(j,n){
	            cin>>mat[i][j];
	            path[i][j] = mat[i][j];
	        }
	    }
	    int maxpath = 0;
	    
	    for(int i = 0; i<n;i++){
	        maxpath = max(maxpath,calc(0,i,mat,path));
	    }
	    cout<<maxpath<<endl;
	}
	return 0;
}