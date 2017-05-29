#include<bits/stdc++.h>
using namespace std;

#define V vector

typedef long long int LL;
typedef pair<int, int>  pii;
typedef pair<int, string> pis;

typedef V<int> vi;
typedef V<string> vs;
typedef V<LL> vl;
typedef V<double> vd;
typedef V<pii> vpii;
typedef V<vi> viv;  
typedef V<pis> vpis; //******************************************************************

#define forup(i,a,b) for(int i=(a); i<(b); ++i) 
#define fordn(i,a,b) for(int i=(a); i>(b); --i) 
#define rep(i,a) for(int i=0; i<(a); ++i) 
#define fov(i,a) rep(i,(a).size()) 
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)  //???????????????????????????????

#define pb push_back
#define mp make_pair

#define fs first
#define sc second

#define el cout<<endl 

#define all(x) (x).begin(), (x).end()  //***************************************************

const int inf = numeric_limits<int>::max(); 
const LL linf = numeric_limits<LL>::max(); 
const double EPS = 1e-7;  
const int MAXN = 10000001; 
const int LOGMAXN = log2(MAXN) + 3;

int *segtree;
int *arr;
int n;


int getNodeLevel(int node){
	int levelFromTop = ceil(log2(node+1));
	//cout<<"node "<<node<<" toplevel "<<levelFromTop; el;
	return n+2 - levelFromTop;
}

void buildNode(int node, int s, int e){

	if(s>e) return;

	if(s==e){ //leaf node
		segtree[node] = arr[s];
		//cout<<arr[s]<<" "<<node; el;
		return;
	}
	int mid = s + (e-s)/2;
	buildNode(2*node, s,mid);
	buildNode(2*node+1,mid+1, e);
	int level = getNodeLevel(node);
	//cout<<"node "<<node<<" "<<level<<" "; el;
	int childLevel = level-1;
	if(childLevel&1){
		segtree[node] = segtree[2*node]|segtree[2*node+1];
	}else{
		segtree[node] = segtree[2*node]^segtree[2*node+1];
	}
	return;
}

void updateNode(int node, int s, int e, int idx, int val){
	

	if(s==e){
		segtree[node] = val;
		//cout<<"updated "<<node<<" "<<segtree[node]<<" "<<s<<" "<<e; el;
		return;
	}



	int mid = s + (e-s)/2;

	if(mid>=idx){
		updateNode(2*node,s,mid,idx,val);
	}else{
		updateNode(2*node+1,mid+1,e,idx,val);
	}

	int level  = getNodeLevel(node);
	//cout<<"node "<<node<<" "<<level<<" "; el;
	int childLevel = level-1;


	if(childLevel&1){
		segtree[node] = segtree[2*node]|segtree[2*node+1];
	}else{
		segtree[node] = segtree[2*node]^segtree[2*node+1];
	}
	return;
}

void printTree(){
	int nodes = pow(2,(n+1)) - 1;
	for(int i = 1; i<=nodes; i++)
	{
		cout<<segtree[i]<<endl;
	}
}

int main()
{
	int q;	
	cin>>n>>q;
	arr = new int[200000];
	segtree = new int[500000];
	rep(i,pow(2,n))
	{
		int x;
		cin>>x;
		arr[i+1] = x;	
	}

	buildNode(1,1,pow(2,n));
	//printTree();

	while(q--){
		int idx, val;
		cin>>idx>>val;
		updateNode(1,1,pow(2,n),idx,val);
		cout<<segtree[1]; el;
		//printTree();
	}


	return 0;
}