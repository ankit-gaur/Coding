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
const int maxn = 3*100000;
int segtree[maxn*4+1];
int con[maxn+1];
void buildTree(int node,int start, int end){
	if(start==end){
		segtree[node]=start;
		return;
	}
	int mid = start+(end-start)/2;
	buildTree(2*node,start,mid);
	buildTree(2*node+1,mid+1,end);
	segtree[node] = 0;
}
void printNode(int node,int start, int end){
	if(start==end){
		cout<<segtree[node]<<" ";
		return;
	}
	int mid = start+(end-start)/2;
	printNode(2*node,start,mid);
	printNode(2*node+1,mid+1,end);
}
void printsegtree(int n){
	rep(i,n+1)cout<<segtree[i+1]<<" ";
	cout<<endl;
}
void conqer(int n){
	rep(i,n+1)cout<<con[i+1]<<" ";
	cout<<endl;
}
void conquerall(int node, int start, int end,int l,int r,int x){
	if(start==end){
		if(con[start]==0&&start!=x) con[start] = x;
		return;
	}
	if(segtree[node]!=0){ //range is already conquered by someone
		int val = segtree[node];
		if(con[val]==0&&l<=val&&r>=val&&val!=x){con[val]=x;} //only update when not defeated; and in the range of current knight
		if(l<=val&&r>=val)segtree[node] = x;
		return; 
	}else{ //first time;
		segtree[node] = x; 
	    int mid = start + (end-start)/2;
	    conquerall(2*node,start,mid,l,r,x);
	    conquerall(2*node+1,mid+1,end,l,r,x);
	}
}
void update(int node, int start, int end,int l, int r, int x){
	/*if(start==end){
		if(con[start]==0&&l<=start&&r>=start)
		con[start] = x;
		return;
	}	*/
	if(r<start||l>end)return; //out of range
	if(l<=start&&r>=end){//completely in range
		conquerall(node,start,end,l,r,x);
		return;
	}
	int mid = start+ (end-start)/2;
	update(2*node,start,mid,l,r,x);
	update(2*node+1,mid+1,end,l,r,x);

}
int main(){
	int n;
	cin>>n;
	fill_n(con,n+1,0);
	buildTree(1,1,n);
	int m;
	cin>>m;
	//conqer(n);
	rep(i,m){
		int l,r,x;
		cin>>l>>r>>x;
		update(1,1,n,l,r,x);
		//printsegtree(4*n);
		//conqer(n);
	}
	for(int i = 1;i<=n;i++){
		cout<<con[i]<<endl;
	}

	return 0;
}
