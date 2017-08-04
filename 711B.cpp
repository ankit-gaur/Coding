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
	int n;
	cin>>n;
	int  arr[n][n];
	int indi, indj;
	LL dig1sum = 0, dig2sum =0;
	rep(i,n){
		rep(j,n){
			int x; cin>>x;
			arr[i][j]=x;
			if(x==0){indi = i; indj=j;}
			if(i==j)dig1sum+=x;
			if(j==n-i-1)dig2sum+=x;
		}
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	LL sr = 0, sum = 0,rsum=0,csum=0;
	if(indi == 0)sr = 1;
	for(int j = 0;j<n; j++){
		sum+=arr[sr][j];
	}
	for(int j = 0; j<n; j++){
		rsum+=arr[indi][j];
	}
	for(int j = 0; j<n; j++){
		csum+=arr[j][indj];
	}
	if(n&1&&indi==n/2&&indj==n/2){
		
		if(rsum!=csum||rsum!=dig1sum||rsum!=dig2sum||rsum>=sum){
			cout<<-1;
		}else cout<<sum-rsum;

	}else if(indi==indj){
		//cout<<dig1sum<<" "<<rsum<<" "<<csum<<" "<<sum;
		if(dig1sum!=rsum||dig1sum!=csum||dig1sum>=sum){
			cout<<-1;
		}else cout<<sum - rsum;
	}else if(indj==n-indi-1){
		cout<<"here";
       if(dig2sum!=rsum||dig2sum!=csum||dig2sum>=sum){
       	cout<<-1;
       }else cout<<sum - rsum;
	} else{
		if(rsum!=csum||rsum>=sum){
			//cout<<"here";
			cout<<-1;
		}else cout<<sum-rsum;
	}

	//cout<<"csum and rsum "<<csum << " "<<rsum<<" sum is "<<sum<<" indi and ind j "<<indi<<" "<<indj ;

    return 0;
}