#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int c=10,n=5;//c为容量，n为物品个数
	//w为物品占用的容量，V为物品的价值
	int w[5]={2,2,6,5,4},v[5]={6,3,5,4,6};
	string s="11111";
	int i,j=0,cc=0,vv=0,maxv=0;
	string str;
	for(i=0;i<n;i++)
	{
		//sort(s.begin(),s.end());
		do
		{
			//cout<<s<<endl;
			for(j=0;j<n;j++)
			{
				cc=cc+(s[j]-'0')*w[j];
				vv=vv+(s[j]-'0')*v[j];
			}
			//cout<<cc<<' '<<vv<<endl;
			if(cc<=c&&vv>maxv)
			{
				maxv=vv;
				str=s;
			}
			//cout<<maxv<<endl;
			vv=0;
			cc=0;
		}
		while(next_permutation(s.begin(),s.end()));
		s[i]='0';  //每次加一个0,
	}
	cout<<str<<endl;
	cout<<maxv<<endl;
}
