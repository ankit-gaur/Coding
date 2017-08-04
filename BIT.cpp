#include<bits/stdc++.h>
using namespace std;

int *BIT;
int *arr;
int n;


void updateTree(int idx, int value){

	for(	; idx<=n ; idx += idx&-idx){
		int x = idx&(-idx);

		cout<<idx<<" "<<x<<endl;
		BIT[idx]+=value;
	}

	return;
}

void buildTree(){
	
	for(int i = 1; i<=n; i++){
		BIT[i] = 0;
	}

	for(int i=1; i<=n; i++){
		updateTree(i,arr[i]);
	}

	return;

}

int  queryBIT(int idx){

	int sum = 0;
	for( ; idx>0; idx -= idx&-idx){

		sum += BIT[idx];

	}

	return sum;

}


void printBIT(){
	for(int i=1; i<=n; i++) cout<<BIT[i]<<" "; 
	cout<<endl;	
}

int main()
{

	cin>>n;
	arr = new int[n+1];
	BIT = new int[n+1];
	for(int i = 0 ; i<n; i++)
	{
		int x; cin>>x;
		arr[i+1] = x;
	}

	buildTree();
	printBIT();

	int q; cin>>q;

	while(q--){

		char what; cin>>what;
		if(what=='u'){

			int idx, value; cin>>idx>>value;
			updateTree(idx,value);
			printBIT();

		}else{
			int idx; //1 indexed index
			cin>>idx;
			cout<<queryBIT(idx)<<endl;
		}
	}

	return 0;
	
}