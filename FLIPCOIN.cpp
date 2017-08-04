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

int n;
int *segtree;
bool *lazy;

void updateNode(int node, int s, int e, int l, int r){

	

	if(lazy[node]!=0){
		if(lazy[node]){
			segtree[node] = e-s+1 - segtree[node]; 
			if(s!=e){
    			lazy[2*node+1] = !lazy[2*node+1];
          lazy[2*node+2] = !lazy[2*node+2];
    		}
    	}
    	lazy[node] = false;
    }

    if(s>e||r<s||l>e) return;

    if(s>=l&&e<=r){
    	segtree[node] = e-s+1 - segtree[node];
    	if(s!=e){
    		lazy[2*node+1] = !lazy[2*node+1];
          lazy[2*node+2] = !lazy[2*node+2];

    	}
    	return;
    }

    int mid = s + (e-s)/2;

    updateNode(2*node+1,s,mid,l,r);
    updateNode(2*node+2, mid+1, e, l, r);
    if(s<=e)
    segtree[node] = segtree[2*node+1] + segtree[2*node+2];

}

int query(int node, int s, int e, int l, int r){
		
	if(lazy[node]!=0){
		if(lazy[node]) segtree[node] = e-s+1 - segtree[node];
        if(s!=e){
          lazy[2*node+1] = !lazy[2*node+1];
          lazy[2*node+2] = !lazy[2*node+2];
        }

		lazy[node] = false;
	}
	if(s>e||r<s||l>e) return 0;
	if(l<=s&&e<=r) return segtree[node];
	int mid = s + (e-s)/2;
	return query(2*node+1,s,mid,l,r) + query(2*node+2,mid+1,e,l,r);

}

int main()
{
	int q;	
	cin>>n>>q;
	segtree = new int[4*n];
	lazy = new bool[4*n];
	fill_n(lazy,4*n,false);
	fill_n(segtree,4*n,0);
	while(q--){

		int x,l,r;
		cin>>x>>l>>r;
		if(x==0)
			updateNode(0,0,n-1,l,r);
		else 
			cout<<query(0,0,n-1,l,r)<<endl;

	}
	return 0;
}