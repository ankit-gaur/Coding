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
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++) 

#define pb push_back
#define mp make_pair

#define fs first
#define sc second

#define el cout<<endl 

#define all(x) (x).begin(), (x).end()  //***************************************************

const int inf = numeric_limits<int>::max(); 
const LL linf = numeric_limits<LL>::max();

int main()
{  
	int n,x;
	cin>>n>>x;
	vi tree[n+1];
	rep(i,n-1){
		int a,b; cin>>a>>b;
		tree[b].pb(a); tree[a].pb(b);
	}	
	int adist[n+1]; 
	adist[1] = 0;
	stack<pair<int,int>> s;
	s.push(mp(1,0));
	bool isVisited[n+1];
	fill_n(isVisited,n+1,false);
	while(!s.empty()){
		//cout<<"loop1";
		pii top = s.top();
		s.pop();
		adist[top.fs] = top.sc;
		isVisited[top.fs] = true;
		fov(i,tree[top.fs]){
			if(!isVisited[tree[top.fs][i]])
			s.push(mp(tree[top.fs][i],top.sc+1));
		}
	}
	s.push(mp(x,0));
	int max = 0;
	fill_n(isVisited, n+1 , false);

	while(!s.empty()){
		//cout<<"loop2";
		pii top = s.top();
		s.pop();
		int moves = top.sc;
		isVisited[top.fs] = true;

		if(adist[top.fs]<=moves){
			
		}else{
			fov(i,tree[top.fs]){
				if(!isVisited[tree[top.fs][i]])
				s.push(mp(tree[top.fs][i],moves+1));
			}
		}
		if(max<=adist[top.fs])max = adist[top.fs];
	}
	cout<<2*max;

	return 0;

}	