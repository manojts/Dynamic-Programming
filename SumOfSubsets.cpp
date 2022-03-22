#include <bits/stdc++.h>
using namespace std;
int main()
{
	int val[] = {2, 3, 5, 7, 8};
	int sum = 14;
	int size = 5;
	int table[size+1][sum+1];

	for(int i = 0;i < sum + 1; i++)
	{
		table[i][0] = 1;
	}
	for(int j = 1;j < sum + 1; j++)
	{
		table[0][j] = 0;
	}

	for(int i = 1;i < size + 1; i++)
	{
		for(int j = 1;j < sum + 1; j++)
		{
			table[i][j] = table[i-1][j] || table[i-1][j-val[i-1]];
		}
	}
	for(int i = 0;i < size + 1; i++)
	{
		for(int j = 0;j < sum + 1; j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	if(table[size][sum])
	{
		cout<<"Subset with sum "<<sum<<" is found";
	}
	else
	{
		cout<<"Subset with sum "<<sum<<" is not found";
	}
	return 0;

}