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
	int n,m;
	cin>>n>>m;

	bool isCatHome[n+1];

	rep(i,n){
		int x; cin>>x;
		if(x==0){
			isCatHome[i+1] = false;
		}else{
			isCatHome[i+1] = true;
		}
	}

	vi tree[n+1];
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		tree[a].pb(b);
		tree[b].pb(a);
	}
	stack<pair<int,int>> st;
	bool isVisited[n+1];
	fill_n(isVisited,n+1,false);
	if(isCatHome[1])st.push(mp(1,1));
	else st.push(mp(1,0));
	int ans = 0;
	while(!st.empty()){
		pii top = st.top();
		st.pop();
		if(!isVisited[top.fs]){
			isVisited[top.fs] = true;
		}else{
			continue;
		}

		if(top.sc>m){
			continue;
		}

		if(tree[top.fs].size()==1&&top.fs!=1){
			ans++;
		}



		fov(i,tree[top.fs]){
			if(!isVisited[tree[top.fs][i]]){
				int n = 0;
				if(isCatHome[tree[top.fs][i]]){
					st.push(mp(tree[top.fs][i],top.sc+1));
				}else{
					st.push(mp(tree[top.fs][i],0));
				}
			}
		}

	}

	cout<<ans;

    return 0;
}