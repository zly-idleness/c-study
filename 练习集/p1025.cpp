#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n,k;

int dfs(int step,int m,int a)
{
	int i;
	if(step == 1)return 1;
	int s=0;
	for(i = m;i <= (n-a)/step ;i++)
	{
		s += dfs(step-1,i,a+i);
	}
	return s;
}

int main(void)
{
	cin>>n>>k;
	
	cout<<dfs(k,1,0);
	return 0;
}
