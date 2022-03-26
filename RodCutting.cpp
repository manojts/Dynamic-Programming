#include<bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}
int main()
{
	int value[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int size = 8;
	int table[size+1][size+1];
	for(int i=0;i<size+1;i++)
	{
		table[0][i] = 0;
	}
	for(int i=0;i<size+1;i++)
	{
		table[i][0] = 0;
	}
	for(int i = 1;i < size+1 ;i++)
	{
		for(int j = 1;j < size+1;j++)
		{
			if(i>j)
			{
				table[i][j] = table[i-1][j];
			}
			else
			{
				table[i][j] =  max(table[i-1][j], value[i-1] + table[i][j-i]);
			}
			cout<<table[i][j]<<"	";
		}
		cout<<endl;
	}
	cout<<"Max Profit is "<<table[size][size];
}