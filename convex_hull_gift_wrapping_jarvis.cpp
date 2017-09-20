#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long int LL;
typedef V<int> vi;
typedef V<LL> vl;
typedef pair<int,int> pii;
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
int orientation(pii p1, pii p2, pii p3){
    int z = (p2.fs-p1.fs)*(p3.sc - p2.sc) - (p3.fs - p2.fs)*(p2.sc - p1.sc);//z component of A cross B, thumb rule
    if(z==0)return 0;
    if(z>0)return 1; //clockwise;
    else return 2;//counterclockwise;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    vector<pair<int,int>> points;
	    rep(i,n){
	        int x,y; cin>>x>>y;
	        points.pb(mp(x,y));
	    }
	    if(n<3){
	        cout<<"-1"<<endl; continue;
	    }
	    
	    int minx = 10001;
	    pair<int,int> p0;
	    vpii ans;
	    int minind = -1;
	    fov(i,points){
	        if(points[i].fs<minx){
	            minx = points[i].fs;
	            minind = i;
	        }
	    }
	    ans.pb(points[minind]);
	    int p = minind,q;
	    while(true){
	        q = (p+1)%n;//don't take q as p initially because it will always give 0;
	        for(int i = 0; i<n; i++){
	            if(orientation(points[p],points[i],points[q])==2)
	            q = i;
	        }
	        p = q;
	        if(p==minind)break;
	        ans.pb(points[p]);
	    }
	    sort(ans.begin(),ans.end());
	    fov(i,ans){
	        cout<<ans[i].fs<<" "<<ans[i].sc;
	        if(i!=ans.size()-1)cout<<", ";
	        }
	        cout<<endl;
	}
	return 0;
}