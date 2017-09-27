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

const int n = 8;

void fill_all(int arr[n][n]){
	for(int i  = 0; i<n ; i++){
		for(int j = 0; j<n ; j++)
			arr[i][j] = -1;
	}
}
int isSafe(int x,int y, int sol[n][n]){
	if(x>=0&&y>=0&&x<n&&y<n&&sol[x][y]==-1)return true;
	return false;
}
int counts = 0;
void printSol(int sol[][n]){
	for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n; j++)
				cout<<sol[i][j]<<" ";
			cout<<endl;
	  }
	  cout<<counts;
}

bool kT(int x,int y, int move, int sol[n][n],int xmoves[],int ymoves[]){
	//cout<<move<<endl;
	counts++;
	if(move==n*n)return true; //all places filled;
	for(int i = 0; i<8; i++){
		int xn = x + xmoves[i];
		int yn = y+ ymoves[i];
		if(isSafe(xn,yn,sol)){
			sol[xn][yn] = move;
			if(kT(xn,yn,move+1,sol,xmoves,ymoves))return true;
			sol[xn][yn] = -1;
		}
	}
	return false;
}
void solve(){
	/*int xmoves[8] = {2,2,-2,-2,1,1,-1,-1};
	int ymoves[8] = {1,-1,1,-1,2,-2,2,-2};*/ //not able to solve for 8 in time
	int xmoves[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int ymoves[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; //make it symmetric so that moves doesn't become clustered
	int sol[n][n];
	fill_all(sol);
	sol[0][0] = 0;
	if(kT(0,0,1,sol,xmoves,ymoves))printSol(sol);
	else cout<<"Not possible";
	return;
}
int main(){
	solve();		
	return 0;
}
