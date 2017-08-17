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

void fillMat(V<vi> &mat, int n){
	int count = 1;
	int t = n; 
	while(t>0&&count<=n){
		int rounds = n-t;
		cout<<rounds<<" "<<endl;

		int tr = rounds, rc = n-1-rounds, br = n-1-rounds, lc = rounds;
		for(int c = lc;c<=rc;c++){//fill top row;
			mat[tr][c] = count;
			count++;
		}
		for(int r= tr+1;r<=br; r++){
			mat[r][rc] = count;
			count++;
		}
		for(int c = rc-1; c>=lc; c--){
			mat[br][c] = count;
			count++;
		}
		for(int r = br+1; r>tr; r--){
			mat[r][lc] = count;
			count++;
		}
		t--;
	}
}
int main(){
	int n;
	cin>>n;
	V<vi> mat(n,vector<int>(n));
	fillMat(mat,n);
	rep(i,n){rep(j,n){cout<<mat[i][j]<<" ";} el;}
	return 0;
}
