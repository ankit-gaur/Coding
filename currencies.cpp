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
LL n,x,s,f,m;
const LL prime = 1000*1000*1000+7;
void printmat(vector<vector<pair<long double , LL>>> mat){
	rep(i,n){
		rep(j,n){
			cout<<mat[i][j].sc<<" ";
		}
		cout<<endl;
	}
}
void multiply(bool itself,vector<vector<pair<long double , LL>>> &ans,vector<vector<pair<long double , LL>>> &mat){
    //cout<<"multiply";

	if(itself){
		vector<vector<pair<long double , LL>>> temp = mat;
		for(int i = 0; i<n; i++){//row of first matrix
			for(int j = 0;j<n; j++){//column of second matrix
				pair<long double,LL>  maxp = mp(-1.0,0);
				for(int k = 0; k<n; k++){ //column of first matrix
					pair<long double,LL> p1,p2;
					p1 = mat[i][k];
					p2 = mat[k][j];
					long double a = p1.fs+p2.fs;
					LL b = ((p1.sc%prime)*(p2.sc%prime))%prime;
					if(a>=maxp.fs){
						maxp.fs = a;
						maxp.sc = b;	
					}
				}
				temp[i][j] = maxp;
			}
		}
		mat = temp;
	}else{
		vector<vector<pair<long double , LL>>> temp = ans;
		for(int i = 0; i<n; i++){//row of first matrix
			for(int j = 0;j<n;j++){//column of second matrix
				pair<long double,LL>  maxp = mp(-1,0);
				for(int k = 0; k<n; k++){ //column of first matrix
					pair<long double,LL> p1,p2;
					p1 = ans[i][k];
					p2 = mat[k][j];
					long double a = p1.fs+p2.fs;
					LL b = ((p1.sc%prime)*(p2.sc%prime))%prime;
					if(a>maxp.fs){
						maxp.fs = a;
						maxp.sc = b;	
					}
				}
				temp[i][j] = maxp;
			}
		}
		ans = temp;
	}
}
LL power(vector<vector<pair<long double , LL>>> mat){
	//m>=2;
	vector<vector<pair<long double , LL>>> ans = mat;
	m = m-1;
	while(m>0){
		if(m&1) multiply(false,ans,mat);
		m = m/2;
		multiply(true,ans,mat);
	}
	//printmat(ans);
	return (x*ans[s][f].sc)%prime;
}

int main(){

	cin >> n;
	cin >> x >> s >> f >> m;
	vector< vector< pair< long double, LL > > > mat(n,vector<pair<long double,LL>>(n));
	rep(i,n){
		rep(j,n){
			int x; cin>>x;
			mat[i][j] = mp(max((long double)-1.0,log2((long double)x)),x);
		}
	}
	cout<<power(mat);
    /*rep(i,n){
    	rep(j,n){
    		cout<<mat[i][j].sc<<","<<mat[i][j].fs<<" ";
    	}
    	cout<<endl;
    }*/
	return 0;
}
