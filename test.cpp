#include<bits/stdc++.h>
using namespace std;
int main()

{
	long long int t,i,s1,s2,j,k,sum;
	string str1,str2;
	cin>>t;
	int loc = 0,t1,t2;
	while(t--)
	{
		cin>>str1>>str2;
		string str3="",str4;
		cout<<"input taken"<<endl;
		j=str1.size();
		k=str2.size();
		i=0; s1=0;s2=0;
		sum=str1.size()+str2.size();
		for(i=0;i<sum;i++)
		{ 
			cout<<"inside loop1 ";
			if(s1==j)
			{ 
				cout<<"s1==j ";
				str4.assign(str2,s2,k-s2); 
				str3=str3+str4;
				break;
			}
			if(s2==k)
			{
				cout<<"s2==k ";
				str4.assign(str1,s1,j-s1); 
				str3=str3+str4; 
				break;
				
			}
			int temp1,temp2;
			temp1=str1[s1];
			temp2=str2[s2];
			if(temp2==temp1)
				{   cout<<"equal  ";
			int  z = 1;
			int f = 1;
			int s = 0;
			string tstr = ""+str1[s1];
			while(1){
				if(s1+f>=j){
					s1 = j;
					s2 += s;    
					str3 += tstr;
					break;
				}
				if(s2+s>=k){
					s2 = k;
					s1+= f;
					str3+=tstr;
					break;
				}
				
				if(str1[s1+z]==str2[s2+z]){
					int t1 = (int)str1[s1+f];
					int t2 = (int)str2[s2+s];
					if(t1<=t2){
						tstr += str1[s1+f];
						f++;
					}else{
						tstr += str2[s1+s];
						s++;
					}
					
				}else {
					if((int)str1[s1+z]<(int)str2[s2+z]){
						s1 = s1 + f;
						s2 = s2 + s;
					}else{
						s2 = s2 + f;
						s1 = s2+s;
					}
					str3 += tstr;
					break;
				}
				z = max(f,s);
			}
			continue;
		}
		if(temp1>temp2)
			{   cout<<"str1>str2 "<<s1<<" "<<s2<<endl;
		str3=str3+str2[s2]; s2++;
		continue;
	}
	if(temp2>temp1) {
		cout<<"str1<str2 "<<s1<<" "<<s2<<endl;
		str3=str3+str1[s1];   
		s1++; 
		continue;
	} 
	
}
cout<<str3<<endl;
}
}