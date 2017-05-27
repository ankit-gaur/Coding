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
int iterations = 0;
int n;
void buildNode(int node, int start, int end){

	if(start == end){
		segtree[node] = arr[start];
		return;
	}
 
	int left = end - start + 1; // mid = (start + end)/2 will be better 
	buildNode(2*node+1, start, start + (left-1)/2);
	buildNode(2*node+2, start +  (left-1)/2 + 1 , end);
	segtree[node] = segtree[2*node +1] + segtree[2*node + 2];
}

void updateNode(int node, int start, int end, int idx, int value){
	
	if(start==end){ //leaf node, star == end == idx
		arr[idx] = value;
		segtree[idx] = value;
		return;
	}

	int mid = start + (end-start)/2;

	if(idx>=start && idx<= mid){
		
		updateNode(2*node + 1, start, mid,idx, value );// update left child

	}else{

		updateNode(2*node+2, mid+1, end, idx, value); // update right child;

	}

	segtree[node] = segtree[2*node+1] + segtree[2*node + 2]; //update the parent

	return;
}

int query(int node, int start, int end, int left, int right){


	if(left>end||right<start){ //out of range of this  node;
       return 0;
	}



	if(left<=start&&right>=end){ //this node will be included in the sum as it is inside the given range;

		return segtree[node];

	} 

	//node range covers the given range completely or partially then traverse on the left and right child

	int mid = start + (end - start)/2;

	return query(2*node+1,start, mid, left, right) + query(2*node+2, mid+1, end, left,right);

}


void printTree(){
	rep(i,2*n-1)cout<<segtree[i]<<" ";
	el;
}
int main()
{

	cin>>n;
	arr = new int[n];
	rep(i,n){
		int x; cin>>x;
		arr[i] = x;
	}

	segtree = new int[2*n-1];

	buildNode(0,0,n-1);

	printTree();

	int q; cin>>q;

	
	while(q--){
		
		char what;
		cin>>what;

		if(what=='u'){

			int idx,value;
			cin>>idx>>value;
			updateNode(0,0,n-1,idx,value);
			printTree();
		}
		else{

			int left,right;
			cin>>left>>right;
			cout<<query(0,0,n-1,left,right);
		}



	}

	return 0;
}
